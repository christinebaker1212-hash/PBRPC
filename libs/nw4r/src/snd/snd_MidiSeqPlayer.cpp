// Imported from doldecomp/ogws (CC0), src/nw4r/snd/snd_MidiSeqPlayer.cpp
#include <nw4r/snd.h>
#include <nw4r/ut.h>

namespace nw4r {
namespace snd {
namespace detail {

/**
 * Dummy class to instantiate necessary weak functions
 */
#if !defined(NONMATCHING)
class MidiSeqPlayer : public SeqPlayer {
private:
    MidiSeqPlayer();

    // Dummy implementation, must prevent instantiating SeqPlayer version
    virtual void ChannelCallback(Channel* /* pChannel */) {}
};

MidiSeqPlayer::MidiSeqPlayer() {}
#endif

} // namespace detail
} // namespace snd
} // namespace nw4r

#include "common.hpp"

extern "C" {

s32 fn_80371E14(u8 *arg0) {
    return (*(u8 *)((u8 *)(arg0) + (0x8E))) != 0;
}
}

extern "C" {

s32 fn_80371E28(u8 *arg0) {
    return (*(u8 *)((u8 *)(arg0) + (0x8D))) != 0;
}
}

extern "C" {

s32 fn_80371E3C(u8 *arg0) {
    return (*(u8 *)((u8 *)(arg0) + (0x8C))) != 0;
}
}
