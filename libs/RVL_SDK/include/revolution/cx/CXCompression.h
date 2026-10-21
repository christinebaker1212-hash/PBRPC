#ifndef REVOLUTION_CX_COMPRESSION_H
#define REVOLUTION_CX_COMPRESSION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <revolution/types.h>

#define CX_LZ_COMPRESS_WORK_SIZE ((4096 + 256 + 256) * sizeof(s16))

u32 CXCompressLZ(const u8* srcp, u32 size, u8* dstp, void* work);

#ifdef __cplusplus
}
#endif

#endif  // REVOLUTION_CX_COMPRESSION_H
