// Imported from kiwi515/ogws (CC0), src/revolution/IPC/ipcclt.c
// The ogws IPC types are kept local: this SDK revision predates the IOS types in private/ios.h.
#include <revolution/os.h>
#include <private/os.h>

#define DECOMP_INLINE inline

// This revision has these as inline functions, not macros.
#undef OSPhysicalToCached
#undef OSCachedToPhysical
static inline void* OSPhysicalToCached(u32 ofs) {
    return (void*)(ofs + 0x80000000);
}

static inline void* OSCachedToPhysical(const void* ofs) {
    return (u8*)ofs - 0x80000000;
}

typedef enum {
    IPC_RESULT_FATAL_ERROR = -119,
    IPC_RESULT_BUSY,
    IPC_RESULT_NOTEMPTY = -115,
    IPC_RESULT_ECC_CRIT,
    IPC_RESULT_OPENFD = -111,
    IPC_RESULT_MAXFD = -109,
    IPC_RESULT_MAXBLOCKS,
    IPC_RESULT_MAXFILES,
    IPC_RESULT_NOEXISTS,
    IPC_RESULT_EXISTS,
    IPC_RESULT_CORRUPT = -103,
    IPC_RESULT_ACCESS,
    IPC_RESULT_INVALID,

    IPC_RESULT_ALLOC_FAILED = -22,
    IPC_RESULT_ECC_CRIT_INTERNAL = -12,
    IPC_RESULT_BUSY_INTERNAL = -8,
    IPC_RESULT_NOEXISTS_INTERNAL = -6,
    IPC_RESULT_CONN_MAX_INTERNAL = -5,
    IPC_RESULT_INVALID_INTERNAL = -4,
    IPC_RESULT_EXISTS_INTERNAL = -2,
    IPC_RESULT_ACCESS_INTERNAL = -1,

    IPC_RESULT_OK = 0
} IPCResult;

typedef enum {
    IPC_REQ_NONE,
    IPC_REQ_OPEN,
    IPC_REQ_CLOSE,
    IPC_REQ_READ,
    IPC_REQ_WRITE,
    IPC_REQ_SEEK,
    IPC_REQ_IOCTL,
    IPC_REQ_IOCTLV
} IPCRequestType;

typedef s32 IPCOpenMode;
typedef s32 IPCSeekMode;

typedef s32 (*IPCAsyncCallback)(s32 result, void* arg);

typedef struct IPCIOVector {
    void* base; // at 0x0
    u32 length; // at 0x4
} IPCIOVector;

typedef struct IPCOpenArgs {
    const char* path; // at 0x0
    IPCOpenMode mode; // at 0x4
} IPCOpenArgs;

typedef struct IPCReadWriteArgs {
    void* data; // at 0x0
    u32 length; // at 0x4
} IPCReadWriteArgs;

typedef struct IPCSeekArgs {
    s32 offset;       // at 0x0
    IPCSeekMode mode; // at 0x4
} IPCSeekArgs;

typedef struct IPCIoctlArgs {
    s32 type;    // at 0x0
    void* in;    // at 0x4
    s32 inSize;  // at 0x8
    void* out;   // at 0xC
    s32 outSize; // at 0x10
} IPCIoctlArgs;

typedef struct IPCIoctlvArgs {
    s32 type;             // at 0x0
    u32 inCount;          // at 0x4
    u32 outCount;         // at 0x8
    IPCIOVector* vectors; // at 0xC
} IPCIoctlvArgs;

typedef struct IPCRequest {
    IPCRequestType type; // at 0x0
    s32 ret;             // at 0x4
    s32 fd;              // at 0x8
    union {
        IPCOpenArgs open;
        IPCReadWriteArgs rw;
        IPCSeekArgs seek;
        IPCIoctlArgs ioctl;
        IPCIoctlvArgs ioctlv;
    }; // at 0xC
} IPCRequest;

typedef struct IPCRequestEx {
    IPCRequest base;           // at 0x0
    IPCAsyncCallback callback; // at 0x20
    void* callbackArg;         // at 0x24
    BOOL reboot;               // at 0x28
    OSThreadQueue queue;       // at 0x2C
    char padding[64 - 0x34];
} IPCRequestEx;

enum {
    IPC_IPC_PPCMSG = 0,
    IPC_IPC_PPCCTRL = 1,
    IPC_IPC_ARMMSG = 2,
    ACR_PPCIRQFLAG = 0x30
};

#define ACRWriteReg(reg, val) (*(volatile u32*)(0xCD000000 + (reg)) = (val))

void IPCInit(void);
u32 IPCReadReg(s32 index);
void IPCWriteReg(s32 index, u32 value);
void* IPCGetBufferHi(void);
void* IPCGetBufferLo(void);
void IPCSetBufferLo(void* lo);
s32 iosCreateHeap(void* base, u32 size);
void* iosAllocAligned(s32 handle, u32 size, u32 align);
s32 iosFree(s32 handle, void* block);
void IPCiProfInit(void);
void IPCiProfQueueReq(IPCRequestEx* req, s32 fd);
void IPCiProfAck(void);
void IPCiProfReply(IPCRequestEx* req, s32 fd);

#define IPC_QUEUE_CAPACITY 16
#define IPC_HEAP_SIZE 0x800

typedef struct IPCRequestQueue {
    u32 sent;                                // at 0x0
    u32 queued;                              // at 0x4
    u32 front;                               // at 0x8
    u32 back;                                // at 0xC
    IPCRequestEx* queue[IPC_QUEUE_CAPACITY]; // at 0x10
} IPCRequestQueue;

static s32 __mailboxAck = 1;
static s32 hid = -1;

static BOOL __relnchFl = FALSE;
static IPCRequestEx* __relnchRpc = NULL;

static IPCRequestQueue __responses;

size_t strnlen(const char* s, size_t maxlen);

size_t strnlen(const char* s, size_t maxlen) {
    const u8* p = (const u8*)s;
    while (*p && maxlen-- > 0) {
        p++;
    }
    return (u32)p - (u32)s;
}

static IPCRequestEx* ipcAllocReq(void) {
    return (IPCRequestEx*)iosAllocAligned(hid, sizeof(IPCRequestEx), 32);
}

static s32 ipcFree(void* block) {
    iosFree(hid, block);
    return IPC_RESULT_OK;
}

static DECOMP_INLINE s32 __ipcQueueRequest(IPCRequestEx* req) {
    s32 ret = IPC_RESULT_OK;
    s32 waiting;

    waiting =
        (__responses.queued < __responses.sent)
            // Difference of count
            ? __responses.queued - __responses.sent
            // Is queue full?
            : (__responses.queued - __responses.sent) >= IPC_QUEUE_CAPACITY;

    if (waiting != 0) {
        ret = IPC_RESULT_BUSY_INTERNAL;
    } else {
        __responses.queue[__responses.back] = req;
        __responses.back = (__responses.back + 1) % IPC_QUEUE_CAPACITY;
        __responses.queued++;
        IPCiProfQueueReq(req, req->base.fd);
    }

    return ret;
}

static DECOMP_INLINE s32 __ipcSendRequest(void) {
    s32 ret = IPC_RESULT_OK;
    IPCRequestEx* req;
    s32 waiting;

    waiting = (__responses.queued < __responses.sent)
                  // Difference of sent/queued
                  ? __responses.queued - __responses.sent
                  // Are no requests waiting
                  : (__responses.queued - __responses.sent) == 0;

    if (waiting != 0) {
        ret = IPC_RESULT_BUSY_INTERNAL;
    } else {
        req = __responses.queue[__responses.front];
        if (req == NULL) {
            goto exit;
        }

        if (req->reboot) {
            __relnchFl = TRUE;
            __relnchRpc = req;
            __mailboxAck--;
        }

        IPCWriteReg(IPC_IPC_PPCMSG, (u32)OSCachedToPhysical(req));
        __responses.front = (__responses.front + 1) % IPC_QUEUE_CAPACITY;
        __responses.sent++;
        __mailboxAck--;
        IPCWriteReg(IPC_IPC_PPCCTRL, (IPCReadReg(IPC_IPC_PPCCTRL) & 0x30) | 1);
    }

exit:
    return ret;
}

static void IpcReplyHandler(s16 intr, OSContext* ctx) {
#pragma unused(intr)

    IPCRequestEx* req;
    IPCIoctlvArgs* args;
    u32 reg;
    OSContext temp;
    int i;

    reg = IPCReadReg(IPC_IPC_ARMMSG);
    if (reg != 0) {
        req = (IPCRequestEx*)OSPhysicalToCached(reg);

        IPCWriteReg(IPC_IPC_PPCCTRL, (IPCReadReg(IPC_IPC_PPCCTRL) & 0x30) | 4);
        ACRWriteReg(ACR_PPCIRQFLAG, 0x40000000);
        DCInvalidateRange(&req->base, sizeof(IPCRequest));

        // Not type??
        switch (req->base.fd) {
        case IPC_REQ_READ:
            req->base.rw.data = (req->base.rw.data != NULL)
                                    ? OSPhysicalToCached((u32)req->base.rw.data)
                                    : NULL;

            if (req->base.ret > 0) {
                DCInvalidateRange(req->base.rw.data, req->base.ret);
            }
            break;
        case IPC_REQ_IOCTL:
            req->base.ioctl.out =
                (req->base.ioctl.out != NULL)
                    ? OSPhysicalToCached((u32)req->base.ioctl.out)
                    : NULL;

            DCInvalidateRange(req->base.ioctl.in, req->base.ioctl.inSize);
            DCInvalidateRange(req->base.ioctl.out, req->base.ioctl.outSize);
            break;
        case IPC_REQ_IOCTLV:
            args = &req->base.ioctlv;

            req->base.ioctlv.vectors =
                (req->base.ioctlv.vectors != NULL)
                    ? OSPhysicalToCached((u32)req->base.ioctlv.vectors)
                    : NULL;

            DCInvalidateRange(req->base.ioctlv.vectors,
                              (args->inCount + args->outCount) *
                                  sizeof(IPCIOVector));

            for (i = 0; i < args->inCount + args->outCount; i++) {
                // Just trust me
                i++;
                i--;

                req->base.ioctlv.vectors[i].base =
                    (args->vectors[i].base != NULL)
                        ? OSPhysicalToCached((u32)args->vectors[i].base)
                        : NULL;
                DCInvalidateRange(args->vectors[i].base,
                                  req->base.ioctlv.vectors[i].length);
            }

            if (__relnchFl && __relnchRpc == req) {
                __relnchFl = FALSE;
                if (__mailboxAck < 1) {
                    __mailboxAck++;
                }
            }
            break;
        }

        if (req->callback != NULL) {
            OSClearContext(&temp);
            OSSetCurrentContext(&temp);
            req->callback(req->base.ret, req->callbackArg);
            OSClearContext(&temp);
            OSSetCurrentContext(ctx);
            ipcFree(req);
        } else {
            OSWakeupThread(&req->queue);
        }

        IPCWriteReg(IPC_IPC_PPCCTRL, (IPCReadReg(IPC_IPC_PPCCTRL) & 0x30) | 8);
        IPCiProfReply(req, req->base.fd);
    }
}

static void IpcAckHandler(u8 intr, OSContext* ctx) {
#pragma unused(intr)
#pragma unused(ctx)

    IPCWriteReg(IPC_IPC_PPCCTRL, (IPCReadReg(IPC_IPC_PPCCTRL) & 0x30) | 2);
    ACRWriteReg(ACR_PPCIRQFLAG, 0x40000000);

    if (__mailboxAck < 1) {
        __mailboxAck++;
        IPCiProfAck();
    }

    if (__mailboxAck > 0) {
        if (__relnchFl) {
            __relnchRpc->base.ret = IPC_RESULT_OK;
            __relnchFl = FALSE;
            OSWakeupThread(&__relnchRpc->queue);
            IPCWriteReg(IPC_IPC_PPCCTRL,
                        (IPCReadReg(IPC_IPC_PPCCTRL) & 0x30) | 8);
        }
        __ipcSendRequest();
    }
}

static void IPCInterruptHandler(s16 intr, OSContext* ctx) {
    if ((IPCReadReg(IPC_IPC_PPCCTRL) & 0x14) == 0x14) {
        IpcReplyHandler(intr, ctx);
    }

    if ((IPCReadReg(IPC_IPC_PPCCTRL) & 0x22) == 0x22) {
        IpcAckHandler(intr, ctx);
    }
}

s32 IPCCltInit(void) {
    static BOOL initialized = FALSE;

    s32 err = 0;
    void* lo;

    if (!initialized) {
        initialized = TRUE;
        IPCInit();

        lo = IPCGetBufferLo();
        if ((char*)lo + IPC_HEAP_SIZE > (char*)IPCGetBufferHi()) {
            err = IPC_RESULT_ALLOC_FAILED;
        } else {
            hid = iosCreateHeap(lo, IPC_HEAP_SIZE);
            IPCSetBufferLo((char*)lo + IPC_HEAP_SIZE);
            __OSSetInterruptHandler(__OS_INTERRUPT_PI_ACR, IPCInterruptHandler);
            __OSUnmaskInterrupts(OS_INTERRUPTMASK_PI_ACR);
            IPCWriteReg(IPC_IPC_PPCCTRL, 0x38);
            IPCiProfInit();
        }
    }

    return err;
}

static s32 __ios_Ipc1(s32 fd, IPCRequestType type, IPCAsyncCallback callback,
                      void* callbackArg, IPCRequestEx** out) {
    IPCRequest* req;
    s32 ret = IPC_RESULT_OK;

    if (out == NULL) {
        ret = IPC_RESULT_INVALID_INTERNAL;
    } else {
        *out = ipcAllocReq();
        if (*out == NULL) {
            ret = IPC_RESULT_ALLOC_FAILED;
        } else {
            req = &(*out)->base;

            (*out)->callback = callback;
            (*out)->callbackArg = callbackArg;
            (*out)->reboot = FALSE;

            req->type = type;
            req->fd = fd;
        }
    }

    return ret;
}

static s32 __ios_Ipc2(IPCRequestEx* req, IPCAsyncCallback callback) {
    s32 ret = IPC_RESULT_OK;
    BOOL enabled;

    if (req == NULL) {
        ret = IPC_RESULT_INVALID_INTERNAL;
    } else {
        if (callback == NULL) {
            OSInitThreadQueue(&req->queue);
        }
        DCFlushRange(&req->base, sizeof(IPCRequest));

        enabled = OSDisableInterrupts();

        ret = __ipcQueueRequest(req);
        if (ret != IPC_RESULT_OK) {
            OSRestoreInterrupts(enabled);
            if (callback != NULL) {
                ipcFree(req);
            }
        } else {
            if (__mailboxAck > 0) {
                __ipcSendRequest();
            }

            if (callback == NULL) {
                OSSleepThread(&req->queue);
            }

            OSRestoreInterrupts(enabled);

            if (callback == NULL) {
                ret = req->base.ret;
            }
        }
    }

    if (req != NULL && callback == NULL) {
        ipcFree(req);
    }

    return ret;
}

static s32 __ios_Open(IPCRequestEx* req, const char* path, IPCOpenMode mode) {
    s32 ret = IPC_RESULT_OK;

    if (req == NULL) {
        ret = IPC_RESULT_INVALID_INTERNAL;
    } else {
        DCFlushRange((void*)path, strnlen(path, 64) + 1);
        req->base.open.path = (const char*)OSCachedToPhysical(path);
        req->base.open.mode = mode;
    }

    return ret;
}

s32 IOS_OpenAsync(const char* path, IPCOpenMode mode, IPCAsyncCallback callback,
                  void* callbackArg) {
    IPCRequestEx* req;
    s32 ret = __ios_Ipc1(0, IPC_REQ_OPEN, callback, callbackArg, &req);
    if (ret == IPC_RESULT_OK) {
        ret = __ios_Open(req, path, mode);
        if (ret == IPC_RESULT_OK) {
            ret = __ios_Ipc2(req, callback);
        }
    }

    return ret;
}

s32 IOS_Open(const char* path, IPCOpenMode mode) {
    IPCRequestEx* req;
    s32 ret = __ios_Ipc1(0, IPC_REQ_OPEN, NULL, NULL, &req);
    if (ret == IPC_RESULT_OK) {
        ret = __ios_Open(req, path, mode);
        if (ret == IPC_RESULT_OK) {
            ret = __ios_Ipc2(req, NULL);
        }
    }

    return ret;
}

s32 IOS_CloseAsync(s32 fd, IPCAsyncCallback callback, void* callbackArg) {
    IPCRequestEx* req;
    s32 ret = __ios_Ipc1(fd, IPC_REQ_CLOSE, callback, callbackArg, &req);
    if (ret == IPC_RESULT_OK) {
        ret = __ios_Ipc2(req, callback);
    }

    return ret;
}

s32 IOS_Close(s32 fd) {
    IPCRequestEx* req;
    s32 ret = __ios_Ipc1(fd, IPC_REQ_CLOSE, NULL, NULL, &req);
    if (ret == IPC_RESULT_OK) {
        ret = __ios_Ipc2(req, NULL);
    }

    return ret;
}

static s32 __ios_Read(IPCRequestEx* req, void* buf, s32 len) {
    s32 ret = IPC_RESULT_OK;

    if (req == NULL) {
        ret = IPC_RESULT_INVALID_INTERNAL;
    } else {
        DCInvalidateRange(buf, len);
        req->base.rw.data = (buf != NULL) ? OSCachedToPhysical((void*)buf) : NULL;
        req->base.rw.length = len;
    }

    return ret;
}

s32 IOS_ReadAsync(s32 fd, void* buf, s32 len, IPCAsyncCallback callback,
                  void* callbackArg) {
    IPCRequestEx* req;
    s32 ret = __ios_Ipc1(fd, IPC_REQ_READ, callback, callbackArg, &req);
    if (ret == IPC_RESULT_OK) {
        ret = __ios_Read(req, buf, len);
        if (ret == IPC_RESULT_OK) {
            ret = __ios_Ipc2(req, callback);
        }
    }

    return ret;
}

s32 IOS_Read(s32 fd, void* buf, s32 len) {
    IPCRequestEx* req;
    s32 ret = __ios_Ipc1(fd, IPC_REQ_READ, NULL, NULL, &req);
    if (ret == IPC_RESULT_OK) {
        ret = __ios_Read(req, buf, len);
        if (ret == IPC_RESULT_OK) {
            ret = __ios_Ipc2(req, NULL);
        }
    }

    return ret;
}

static s32 __ios_Write(IPCRequestEx* req, const void* buf, s32 len) {
    s32 ret = IPC_RESULT_OK;

    if (req == NULL) {
        ret = IPC_RESULT_INVALID_INTERNAL;
    } else {
        req->base.rw.data = (buf != NULL) ? OSCachedToPhysical((void*)buf) : NULL;
        req->base.rw.length = len;
        DCFlushRange((void*)buf, len);
    }

    return ret;
}

s32 IOS_WriteAsync(s32 fd, const void* buf, s32 len, IPCAsyncCallback callback,
                   void* callbackArg) {
    IPCRequestEx* req;
    s32 ret = __ios_Ipc1(fd, IPC_REQ_WRITE, callback, callbackArg, &req);
    if (ret == IPC_RESULT_OK) {
        ret = __ios_Write(req, buf, len);
        if (ret == IPC_RESULT_OK) {
            ret = __ios_Ipc2(req, callback);
        }
    }

    return ret;
}

s32 IOS_Write(s32 fd, const void* buf, s32 len) {
    IPCRequestEx* req;
    s32 ret = __ios_Ipc1(fd, IPC_REQ_WRITE, NULL, NULL, &req);
    if (ret == IPC_RESULT_OK) {
        ret = __ios_Write(req, buf, len);
        if (ret == IPC_RESULT_OK) {
            ret = __ios_Ipc2(req, NULL);
        }
    }

    return ret;
}

static s32 __ios_Seek(IPCRequestEx* req, s32 offset, IPCSeekMode mode) {
    s32 ret = IPC_RESULT_OK;

    if (req == NULL) {
        ret = IPC_RESULT_INVALID_INTERNAL;
    } else {
        req->base.seek.offset = offset;
        req->base.seek.mode = mode;
    }

    return ret;
}

s32 IOS_SeekAsync(s32 fd, s32 offset, IPCSeekMode mode,
                  IPCAsyncCallback callback, void* callbackArg) {
    IPCRequestEx* req;
    s32 ret = __ios_Ipc1(fd, IPC_REQ_SEEK, callback, callbackArg, &req);
    if (ret == IPC_RESULT_OK) {
        ret = __ios_Seek(req, offset, mode);
        if (ret == IPC_RESULT_OK) {
            ret = __ios_Ipc2(req, callback);
        }
    }

    return ret;
}

s32 IOS_Seek(s32 fd, s32 offset, IPCSeekMode mode) {
    IPCRequestEx* req;
    s32 ret = __ios_Ipc1(fd, IPC_REQ_SEEK, NULL, NULL, &req);
    if (ret == IPC_RESULT_OK) {
        ret = __ios_Seek(req, offset, mode);
        if (ret == IPC_RESULT_OK) {
            ret = __ios_Ipc2(req, NULL);
        }
    }

    return ret;
}

static s32 __ios_Ioctl(IPCRequestEx* req, s32 type, void* in, s32 inSize,
                       void* out, s32 outSize) {
    s32 ret = IPC_RESULT_OK;

    if (req == NULL) {
        ret = IPC_RESULT_INVALID_INTERNAL;
    } else {
        req->base.ioctl.type = type;
        req->base.ioctl.out = (out != NULL) ? OSCachedToPhysical(out) : NULL;
        req->base.ioctl.outSize = outSize;
        req->base.ioctl.in = (in != NULL) ? OSCachedToPhysical(in) : NULL;
        req->base.ioctl.inSize = inSize;

        DCFlushRange(in, inSize);
        DCFlushRange(out, outSize);
    }

    return ret;
}

s32 IOS_IoctlAsync(s32 fd, s32 type, void* in, s32 inSize, void* out,
                   s32 outSize, IPCAsyncCallback callback, void* callbackArg) {
    IPCRequestEx* req;
    s32 ret = __ios_Ipc1(fd, IPC_REQ_IOCTL, callback, callbackArg, &req);
    if (ret == IPC_RESULT_OK) {
        ret = __ios_Ioctl(req, type, in, inSize, out, outSize);
        if (ret == IPC_RESULT_OK) {
            ret = __ios_Ipc2(req, callback);
        }
    }

    return ret;
}

s32 IOS_Ioctl(s32 fd, s32 type, void* in, s32 inSize, void* out, s32 outSize) {
    IPCRequestEx* req;
    s32 ret = __ios_Ipc1(fd, IPC_REQ_IOCTL, NULL, NULL, &req);
    if (ret == IPC_RESULT_OK) {
        ret = __ios_Ioctl(req, type, in, inSize, out, outSize);
        if (ret == IPC_RESULT_OK) {
            ret = __ios_Ipc2(req, NULL);
        }
    }

    return ret;
}

static s32 __ios_Ioctlv(IPCRequestEx* req, s32 type, s32 inCount, s32 outCount,
                        IPCIOVector* vectors) {
    int i;
    s32 ret = IPC_RESULT_OK;

    if (req == NULL) {
        ret = IPC_RESULT_INVALID_INTERNAL;
    } else {
        req->base.ioctlv.type = type;
        req->base.ioctlv.inCount = inCount;
        req->base.ioctlv.outCount = outCount;
        req->base.ioctlv.vectors = vectors;

        for (i = 0; i < req->base.ioctlv.outCount; i++) {
            DCFlushRange(req->base.ioctlv.vectors[inCount + i].base,
                         req->base.ioctlv.vectors[inCount + i].length);

            req->base.ioctlv.vectors[inCount + i].base =
                (req->base.ioctlv.vectors[inCount + i].base != NULL)
                    ? OSCachedToPhysical(
                          req->base.ioctlv.vectors[inCount + i].base)
                    : NULL;
        }

        for (i = 0; i < req->base.ioctlv.inCount; i++) {
            DCFlushRange(req->base.ioctlv.vectors[i].base,
                         req->base.ioctlv.vectors[i].length);

            req->base.ioctlv.vectors[i].base =
                (req->base.ioctlv.vectors[i].base != NULL)
                    ? OSCachedToPhysical(req->base.ioctlv.vectors[i].base)
                    : NULL;
        }

        DCFlushRange(req->base.ioctlv.vectors,
                     (req->base.ioctlv.inCount + req->base.ioctlv.outCount) *
                         sizeof(IPCIOVector));

        req->base.ioctlv.vectors =
            (vectors != NULL) ? OSCachedToPhysical(vectors) : NULL;
    }

    return ret;
}

s32 IOS_IoctlvAsync(s32 fd, s32 type, s32 inCount, s32 outCount,
                    IPCIOVector* vectors, IPCAsyncCallback callback,
                    void* callbackArg) {
    IPCRequestEx* req;
    s32 ret = __ios_Ipc1(fd, IPC_REQ_IOCTLV, callback, callbackArg, &req);
    if (ret == IPC_RESULT_OK) {
        ret = __ios_Ioctlv(req, type, inCount, outCount, vectors);
        if (ret == IPC_RESULT_OK) {
            ret = __ios_Ipc2(req, callback);
        }
    }

    return ret;
}

s32 IOS_Ioctlv(s32 fd, s32 type, s32 inCount, s32 outCount,
               IPCIOVector* vectors) {
    IPCRequestEx* req;
    s32 ret = __ios_Ipc1(fd, IPC_REQ_IOCTLV, NULL, NULL, &req);
    if (ret == IPC_RESULT_OK) {
        ret = __ios_Ioctlv(req, type, inCount, outCount, vectors);
        if (ret == IPC_RESULT_OK) {
            ret = __ios_Ipc2(req, NULL);
        }
    }

    return ret;
}

s32 IOS_IoctlvReboot(s32 fd, s32 type, s32 inCount, s32 outCount,
                     IPCIOVector* vectors) {
    IPCRequestEx* req;
    s32 ret = __ios_Ipc1(fd, IPC_REQ_IOCTLV, NULL, NULL, &req);
    if (ret == IPC_RESULT_OK) {
        req->reboot = TRUE;
        ret = __ios_Ioctlv(req, type, inCount, outCount, vectors);
        if (ret == IPC_RESULT_OK) {
            ret = __ios_Ipc2(req, NULL);
        }
    }

    return ret;
}
