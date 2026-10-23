#include ".unsorted/8027738C.hpp"

#include "common.hpp"

extern "C" {

s32 SISetSamplingRate(s32);
extern s32 SamplingRate_80627E60;

void SIRefreshSamplingRate(void) {
    SISetSamplingRate(SamplingRate_80627E60);
}
}
