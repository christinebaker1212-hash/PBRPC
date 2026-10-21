#include <private/cx.h>
#include <revolution/cx.h>

#define LZ_WINDOW_SIZE 4096
#define LZ_MAX_LENGTH (0xF + 3)

typedef struct LZCompressInfo {
    /* 0x00 */ u16 windowPos;
    /* 0x02 */ u16 windowLen;
    /* 0x04 */ s16* LZOffsetTable;
    /* 0x08 */ s16* LZByteTable;
    /* 0x0C */ s16* LZEndTable;
} LZCompressInfo;  // size: 0x10

static u8 SearchLZ(LZCompressInfo* info, const u8* nextp, u32 remainSize, u16* offset);
static void SlideByte(LZCompressInfo* info, const u8* srcp);

static inline void LZInitTable(LZCompressInfo* info, void* work) {
    u16 i;

    info->LZOffsetTable = (s16*)work;
    info->LZByteTable = (s16*)((u32)work + LZ_WINDOW_SIZE * sizeof(s16));
    info->LZEndTable = (s16*)((u32)work + (LZ_WINDOW_SIZE + 256) * sizeof(s16));

    for (i = 0; i < 256; i++) {
        info->LZByteTable[i] = -1;
        info->LZEndTable[i] = -1;
    }

    info->windowPos = 0;
    info->windowLen = 0;
}

static inline void LZSlide(LZCompressInfo* info, const u8* srcp, u32 n) {
    u32 i;

    for (i = 0; i < n; i++) {
        SlideByte(info, srcp++);
    }
}

u32 CXCompressLZ(const u8* srcp, u32 size, u8* dstp, void* work) {
    u32 LZDstCount;
    u8 LZCompFlags;
    u8* LZCompFlagsp;
    u16 lastOffset;
    u8 lastLength;
    u32 i;
    u8 j;
    u32 dstMax;
    LZCompressInfo info;

    if (size < 0x1000000) {
        *(u32*)dstp = CXiConvertEndian32_(size << 8 | CX_COMPRESSION_TYPE_LZ);
        dstp += 4;
        LZDstCount = 4;
    } else {
        *(u32*)dstp = CXiConvertEndian32_(CX_COMPRESSION_TYPE_LZ);
        dstp += 4;
        *(u32*)dstp = CXiConvertEndian32_(size);
        dstp += 4;
        LZDstCount = 8;
    }
    dstMax = size;
    LZInitTable(&info, work);

    while (size > 0) {
        LZCompFlags = 0;
        LZCompFlagsp = dstp++;
        LZDstCount++;

        for (i = 0; i < 8; i++) {
            LZCompFlags <<= 1;
            if (size <= 0) {
                continue;
            }

            if ((lastLength = SearchLZ(&info, srcp, size, &lastOffset)) != 0) {
                LZCompFlags |= 1;
                if (LZDstCount + 2 >= dstMax) {
                    return 0;
                }

                *dstp++ = (u8)((lastLength - 3) << 4 | (lastOffset - 1) >> 8);
                *dstp++ = (u8)(lastOffset - 1);
                LZDstCount += 2;
                LZSlide(&info, srcp, lastLength);
                srcp += lastLength;
                size -= lastLength;
            } else {
                if (LZDstCount + 1 >= dstMax) {
                    return 0;
                }

                LZSlide(&info, srcp, 1);
                *dstp++ = *srcp++;
                size--;
                LZDstCount++;
            }
        }
        *LZCompFlagsp = LZCompFlags;
    }

    j = 0;
    while ((LZDstCount + j) & 3) {
        *dstp++ = 0;
        j++;
    }

    return LZDstCount;
}

static u8 SearchLZ(LZCompressInfo* info, const u8* nextp, u32 remainSize, u16* offset) {
    const u8* searchp;
    const u8* headp;
    const u8* searchHeadp;
    u16 maxOffset;
    u8 maxLength = 2;
    u8 tmpLength;
    s32 w_offset;
    s16* const LZOffsetTable = info->LZOffsetTable;
    const u16 windowPos = info->windowPos;
    const u16 windowLen = info->windowLen;

    if (remainSize < 3) {
        return 0;
    }

    w_offset = info->LZByteTable[*nextp];

    while (w_offset != -1) {
        if (w_offset < windowPos) {
            searchp = nextp - windowPos + w_offset;
        } else {
            searchp = nextp - windowLen - windowPos + w_offset;
        }

        if (*(searchp + 1) != *(nextp + 1) || *(searchp + 2) != *(nextp + 2)) {
            w_offset = LZOffsetTable[w_offset];
            continue;
        }

        if (nextp - searchp < 2) {
            break;
        }

        tmpLength = 3;
        searchHeadp = searchp + 3;
        headp = nextp + 3;

        while ((u32)(headp - nextp) < remainSize && *headp == *searchHeadp) {
            headp++;
            searchHeadp++;
            tmpLength++;

            if (tmpLength == LZ_MAX_LENGTH) {
                break;
            }
        }

        if (tmpLength > maxLength) {
            maxLength = tmpLength;
            maxOffset = (u16)(nextp - searchp);
            if (maxLength == LZ_MAX_LENGTH) {
                break;
            }
        }

        w_offset = LZOffsetTable[w_offset];
    }

    if (maxLength < 3) {
        return 0;
    }

    *offset = maxOffset;
    return maxLength;
}

static void SlideByte(LZCompressInfo* info, const u8* srcp) {
    s16 offset;
    u8 in_data = *srcp;
    u16 insert_offset;
    s16* const LZByteTable = info->LZByteTable;
    s16* const LZOffsetTable = info->LZOffsetTable;
    s16* const LZEndTable = info->LZEndTable;
    const u16 windowPos = info->windowPos;
    const u16 windowLen = info->windowLen;

    if (windowLen == LZ_WINDOW_SIZE) {
        u8 out_data = *(srcp - LZ_WINDOW_SIZE);

        if ((LZByteTable[out_data] = LZOffsetTable[LZByteTable[out_data]]) == -1) {
            LZEndTable[out_data] = -1;
        }
        insert_offset = windowPos;
    } else {
        insert_offset = windowLen;
    }

    offset = LZEndTable[in_data];
    if (offset == -1) {
        LZByteTable[in_data] = insert_offset;
    } else {
        LZOffsetTable[offset] = insert_offset;
    }
    LZEndTable[in_data] = insert_offset;
    LZOffsetTable[insert_offset] = -1;

    if (windowLen == LZ_WINDOW_SIZE) {
        info->windowPos = (u16)((windowPos + 1) % LZ_WINDOW_SIZE);
    } else {
        info->windowLen++;
    }
}
