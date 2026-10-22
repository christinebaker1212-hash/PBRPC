// Written after snd_FxReverbHi.cpp from doldecomp/ogws (CC0); the parameters
// follow koopthekoopa/wii-ipl (CC0), libs/NW4R/src/snd/snd_FxReverbStd.cpp
#include <nw4r/snd.h>
#include <nw4r/snd/snd_FxReverbStd.h>
#include <nw4r/ut.h>

namespace nw4r {
namespace snd {

FxReverbStd::FxReverbStd() {
    ReverbStdParam param = {0.02f, 3.0f, 0.6f, 0.4f, 1.0f};
    SetParam(param);
}

u32 FxReverbStd::GetRequiredMemSize() {
    u32 memSize = AXFXReverbStdGetMemSize(&mAxfxParam);
    return ut::RoundUp(memSize + detail::AxfxImpl::HEAP_SIZE_MIN, 32);
}

bool FxReverbStd::AssignWorkBuffer(void* pBuffer, u32 size) {
    return mImpl.CreateHeap(pBuffer, size);
}

void FxReverbStd::ReleaseWorkBuffer() {
    mImpl.DestroyHeap();
}

bool FxReverbStd::StartUp() {
    u32 memSize = GetRequiredMemSize();
    if (memSize > mImpl.GetHeapTotalSize()) {
        return false;
    }

    AXFXAllocHook allocHook;
    AXFXFreeHook freeHook;
    mImpl.HookAlloc(&allocHook, &freeHook);

    mImpl.mAllocatedSize = 0;
    BOOL success = AXFXReverbStdInit(&mAxfxParam);

    mImpl.RestoreAlloc(allocHook, freeHook);

    (void)AXFXReverbStdGetMemSize(&mAxfxParam); // debug leftover
    mImpl.mIsActive = true;

    return success;
}

void FxReverbStd::Shutdown() {
    mImpl.mIsActive = false;

    AXFXAllocHook allocHook;
    AXFXFreeHook freeHook;
    mImpl.HookAlloc(&allocHook, &freeHook);

    AXFXReverbStdShutdown(&mAxfxParam);

    mImpl.RestoreAlloc(allocHook, freeHook);
}

bool FxReverbStd::SetParam(const ReverbStdParam& rParam) {
    mParam = rParam;

    mAxfxParam.preDelay = ut::Clamp(rParam.preDelayTime, 0.0f, 0.1f);
    mAxfxParam.time = ut::Clamp(rParam.fusedTime, 0.0f, 10.0f);
    mAxfxParam.coloration = ut::Clamp(rParam.coloration, 0.0f, 1.0f);
    mAxfxParam.damping = ut::Clamp(rParam.damping, 0.0f, 1.0f);
    mAxfxParam.mix = ut::Clamp(rParam.outGain, 0.0f, 1.0f);

    if (!mImpl.mIsActive) {
        return true;
    }

    u32 memSize = GetRequiredMemSize();
    if (memSize > mImpl.GetHeapTotalSize()) {
        return false;
    }

    AXFXAllocHook allocHook;
    AXFXFreeHook freeHook;
    mImpl.HookAlloc(&allocHook, &freeHook);

    BOOL success = AXFXReverbStdSettings(&mAxfxParam);

    mImpl.RestoreAlloc(allocHook, freeHook);

    return success;
}

void FxReverbStd::UpdateBuffer(int channels, void** ppBuffer, u32 size,
                              SampleFormat format, f32 sampleRate,
                              OutputMode mode) {
#pragma unused(channels)
#pragma unused(size)
#pragma unused(format)
#pragma unused(sampleRate)
#pragma unused(mode)

    void* chans[AX_STEREO_MAX];
    chans[AX_STEREO_L] = ppBuffer[AX_STEREO_L];
    chans[AX_STEREO_R] = ppBuffer[AX_STEREO_R];
    chans[AX_STEREO_S] = ppBuffer[AX_STEREO_S];

    AXFXReverbStdCallback(chans, &mAxfxParam);
}

} // namespace snd
} // namespace nw4r
