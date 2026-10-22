// From doldecomp/ogws (CC0), src/nw4r/snd/snd_SeqSoundHandle.cpp
// Only DetachSound is present in this binary.
#include <nw4r/snd.h>
#include <nw4r/ut.h>

namespace nw4r {
namespace snd {

void SeqSoundHandle::DetachSound() {
    if (IsAttachedSound()) {
        if (mSound->mTempSpecialHandle == this) {
            mSound->mTempSpecialHandle = NULL;
        }
    }

    if (mSound != NULL) {
        mSound = NULL;
    }
}

} // namespace snd
} // namespace nw4r
