// Imported from doldecomp/ogws (CC0), src/nw4r/snd/snd_DisposeCallbackManager.cpp.
// This revision locks a mutex around the callback list.
#include <nw4r/snd.h>

namespace nw4r {
namespace snd {
namespace detail {

DisposeCallbackManager& DisposeCallbackManager::GetInstance() {
    ut::AutoInterruptLock lock;
    static DisposeCallbackManager instance;
    return instance;
}

DisposeCallbackManager::DisposeCallbackManager() {
    OSInitMutex(&mMutex);
}

void DisposeCallbackManager::RegisterDisposeCallback(
    DisposeCallback* pCallback) {
    OSLockMutex(&mMutex);
    mCallbackList.PushBack(pCallback);
    OSUnlockMutex(&mMutex);
}

void DisposeCallbackManager::UnregisterDisposeCallback(
    DisposeCallback* pCallback) {
    OSLockMutex(&mMutex);
    mCallbackList.Erase(pCallback);
    OSUnlockMutex(&mMutex);
}

void DisposeCallbackManager::Dispose(void* pData, u32 size, void* pArg) {
#pragma unused(pArg)

    const void* pStart = pData;
    const void* pEnd = static_cast<u8*>(pData) + size;

    OSLockMutex(&mMutex);

    DisposeCallbackList::Iterator it =
        GetInstance().mCallbackList.GetBeginIter();

    while (it != GetInstance().mCallbackList.GetEndIter()) {
        DisposeCallbackList::Iterator curr = it++;
        curr->InvalidateData(pStart, pEnd);
    }

    OSUnlockMutex(&mMutex);
}

void DisposeCallbackManager::DisposeWave(void* pData, u32 size, void* pArg) {
#pragma unused(pArg)

    const void* pStart = pData;
    const void* pEnd = static_cast<u8*>(pData) + size;

    OSLockMutex(&mMutex);

    DisposeCallbackList::Iterator it =
        GetInstance().mCallbackList.GetBeginIter();

    while (it != GetInstance().mCallbackList.GetEndIter()) {
        DisposeCallbackList::Iterator curr = it++;
        curr->InvalidateWaveData(pStart, pEnd);
    }

    OSUnlockMutex(&mMutex);
}

} // namespace detail
} // namespace snd
} // namespace nw4r
