// Imported from koopthekoopa/wii-ipl (CC0), libs/RVL_SDK/src/cx/CXUncompression.c
#include <private/cx.h>
#include <revolution/cx.h>

u32 CXGetUncompressedSize(const void* src) {
    u32 size = CXiConvertEndian32_(IN_BUFFER_AT(u32, src, 0)) >> 8;
    if (!size) {
        size = CXiConvertEndian32_(IN_BUFFER_AT(u32, src, 4));
    }

    return size;
}

void CXUncompressLZ(const void* src, void* dst) {
    s32 length;
    const u8* pSrc = src;
    u32 size;
    u32 i;
    u8 flags;
    s32 offset;
    u8* pDst = dst;

    size = CXiConvertEndian32_(IN_BUFFER_AT(u32, pSrc, 0)) >> 8;
    pSrc += sizeof(u32);

    if (!size) {
        size = CXiConvertEndian32_(IN_BUFFER_AT(u32, pSrc, 0));
        pSrc += sizeof(u32);
    }

    while (size) {
        flags = *pSrc++;

        for (i = 0; i < 8; ++i) {
            if (!(flags & 0x80)) {
                *pDst++ = *pSrc++;
                size--;
            } else {
                length = (*pSrc >> 4) + 3;
                offset = (*pSrc++ & 0x0F) << 8;
                offset |= *pSrc++;
                offset++;

                size -= length;
                do {
                    *pDst = pDst[-offset];
                    pDst++;
                } while (--length > 0);
            }

            if (!size) {
                break;
            }

            flags <<= 1;
        }
    }
}
