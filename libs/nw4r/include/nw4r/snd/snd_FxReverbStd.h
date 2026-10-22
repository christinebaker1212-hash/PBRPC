// From koopthekoopa/wii-ipl (CC0), libs/NW4R/include/nw4r/snd/FxReverbStd.h,
// laid out like the other effect headers here.
#ifndef NW4R_SND_FX_REVERB_STD_H
#define NW4R_SND_FX_REVERB_STD_H
#include <nw4r/snd/snd_AxfxImpl.h>
#include <nw4r/snd/snd_FxBase.h>
#include <nw4r/types_nw4r.h>
#include <decomp.h>

#include <revolution/axfx.h>

namespace nw4r {
namespace snd {

class FxReverbStd : public FxBase {
public:
    struct ReverbStdParam {
        f32 preDelayTime; // at 0x0
        f32 fusedTime;    // at 0x4
        f32 coloration;   // at 0x8
        f32 damping;      // at 0xC
        f32 outGain;      // at 0x10
    };

public:
    FxReverbStd();

    virtual ~FxReverbStd() {
        Shutdown();
        ReleaseWorkBuffer();
    } // at 0x8

    virtual bool StartUp();  // at 0xC
    virtual void Shutdown(); // at 0x10

    virtual void UpdateBuffer(int channels,
                              void **ppBuffer,
                              u32 size,
                              SampleFormat format,
                              f32 sampleRate,
                              OutputMode mode); // at 0x14

    virtual bool AssignWorkBuffer(void *pBuffer, u32 size); // at 0x18
    virtual void ReleaseWorkBuffer();                       // at 0x1C

    u32 GetRequiredMemSize();
    bool SetParam(const ReverbStdParam &rParam) NO_INLINE;

private:
    detail::AxfxImpl mImpl;    // at 0xC
    ReverbStdParam mParam;     // at 0x18
    AXFX_REVERBSTD mAxfxParam; // at 0x2C
};

} // namespace snd
} // namespace nw4r

#endif
