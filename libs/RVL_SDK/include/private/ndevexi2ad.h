// Declarations for the NDEV EXI2 debugger driver, from kiwi515/ogws (CC0),
// include/revolution/NdevExi2AD/*.h, with the ogws hardware names mapped to
// this SDK's.
#ifndef PRIVATE_NDEVEXI2AD_H
#define PRIVATE_NDEVEXI2AD_H

#include <private/exi.h>
#include <private/os.h>
#include <revolution/os.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef __OSInterruptHandler OSInterruptHandler;

#ifndef ROUND_UP
#define ROUND_UP(x, align) (((x) + (align) - 1) & (-(align)))
#endif

static u32 __EXISwap32(u32 val) {
    return val >> 24 & 0x000000FF | val >> 8 & 0x0000FF00 | val << 8 & 0x00FF0000 | val << 24 & 0xFF000000;
}

#define OS_INTR_MASK OS_INTERRUPTMASK
#define OS_INTR_EXI_2_EXI __OS_INTERRUPT_EXI_2_EXI
#define OS_INTR_EXI_2_TC __OS_INTERRUPT_EXI_2_TC
#define OS_INTR_PI_DEBUG __OS_INTERRUPT_PI_DEBUG

typedef struct EXIChannelParam {
    u32 cpr;    // at 0x0
    void* mar;  // at 0x4
    u32 length; // at 0x8
    u32 cr;     // at 0xC
    u32 data;   // at 0x10
} EXIChannelParam;

volatile EXIChannelParam EXI_CHAN_PARAMS[EXI_CHAN_MAX] : 0xCD006800;
volatile u32 PI_HW_REGS[] : 0xCC003000;

#define PI_INTSR 0
#define PI_INTSR_DEBUG (1 << 12)

#define EXI_CPR_EXIINTMASK (1 << 0)
#define EXI_CPR_EXIINT (1 << 1)
#define EXI_CPR_TCINTMASK (1 << 2)
#define EXI_CPR_TCINT (1 << 3)
#define EXI_CPR_CLK (1 << 4 | 1 << 5 | 1 << 6)
#define EXI_CPR_CS0B (1 << 7)
#define EXI_CPR_CS1B (1 << 8)
#define EXI_CPR_CS2B (1 << 9)
#define EXI_CPR_EXTINTMASK (1 << 10)
#define EXI_CPR_EXTINT (1 << 11)
#define EXI_CPR_EXT (1 << 12)
#define EXI_CPR_ROMDIS (1 << 13)

#define EXI_CR_TSTART (1 << 0)
#define EXI_CR_DMA (1 << 1)
#define EXI_CR_RW (1 << 2 | 1 << 3)
#define EXI_CR_TLEN (1 << 4 | 1 << 5)

BOOL __EXI2Imm(void* mem, s32 size, u32 type);
void __DBEXIInit(void);
BOOL __DBEXIReadReg(u32 cmd, void* mem, s32 size);
BOOL __DBEXIWriteReg(u32 cmd, const void* mem, s32 size);
BOOL __DBEXIReadRam(u32 cmd, void* mem, s32 size);
BOOL __DBEXIWriteRam(u32 cmd, const void* mem, s32 size);

void DBInitComm(u8** flagOut, OSInterruptHandler handler);
void DBInitInterrupts(void);
u32 DBQueryData(void);
BOOL DBRead(void* dst, u32 size);
BOOL DBWrite(const void* src, u32 size);
void DBOpen(void);
void DBClose(void);

static BOOL __DBReadMailbox(u32* mailOut) {
    return __DBEXIReadReg(0x34000200, mailOut, sizeof(*mailOut));
}

static BOOL __DBRead(u32 ofs, void* dest, u32 size) {
    return __DBEXIReadRam(((ofs + 0xD10000) * 0x40) & 0x3FFFFF00, dest, size);
}

static BOOL __DBWriteMailbox(u32 mail) {
    return __DBEXIWriteReg(0xB4000100, &mail, sizeof(mail));
}

static BOOL __DBWrite(u32 ofs, const void* src, u32 size) {
    return __DBEXIWriteRam((((ofs + 0xD10000) * 0x40) & 0x3FFFFF00) | 0x80000000, src, size);
}

static u32 ODEMUGenMailData(u32 ofs, u32 size) {
    return (ofs & 0xff) << 0x10 | 0x1f000000 | size & 0x1fff;
}

static u32 ODEMUGetPage(u32 mail) {
    return (mail & 0xFF0000) >> 16;
}

static u32 ODEMUGetPc2NngcOffset(u32 mail) {
    if (!(ODEMUGetPage(mail) & 0x1)) {
        return 0;
    }

    return 0x800;
}

static BOOL ODEMUIsValidMail(u32 mail) {
    return (mail & 0x1F000000) == 0x1F000000;
}

static u32 ODEMUGetSize(u32 mail) {
    return mail & 0x1FFF;
}

#ifdef __cplusplus
}
#endif

#endif  // PRIVATE_NDEVEXI2AD_H
