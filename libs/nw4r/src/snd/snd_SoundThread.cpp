// Imported from doldecomp/ogws (CC0), src/nw4r/snd/snd_SoundThread.cpp
#include <nw4r/snd.h>
#include <nw4r/ut.h>
#include <revolution/OS.h>

namespace nw4r {
namespace snd {
namespace detail {

SoundThread::SoundThread() : mStackEnd(NULL), mCreateFlag(false) {
    OSInitMessageQueue(&mMsgQueue, mMsgBuffer, MSG_QUEUE_CAPACITY);
    OSInitThreadQueue(&mThreadQueue);
    OSInitMutex(&mMutex);
}

SoundThread &SoundThread::GetInstance() {
    static SoundThread instance;
    return instance;
}

bool SoundThread::Create(s32 priority, void *pStack, u32 stackSize) {
    if (mCreateFlag) {
        return true;
    }

    mCreateFlag = true;
    mStackEnd = pStack;

    BOOL success = OSCreateThread(&mThread,
                                  SoundThreadFunc,
                                  &GetInstance(),
                                  static_cast<u8 *>(pStack) + stackSize,
                                  stackSize,
                                  priority,
                                  0);

    if (success) {
        OSResumeThread(&mThread);
    }

    return success;
}

void SoundThread::Shutdown() {
    if (!mCreateFlag) {
        return;
    }

    OSJamMessage(&GetInstance().mMsgQueue, reinterpret_cast<OSMessage>(MSG_SHUTDOWN), OS_MESSAGE_BLOCK);

    OSJoinThread(&mThread, NULL);
    mCreateFlag = false;
}

void SoundThread::AxCallbackFunc() {
    GetInstance().AxCallbackProc();
}

void SoundThread::AxCallbackProc() {
    OSSendMessage(&mMsgQueue, reinterpret_cast<OSMessage>(MSG_AX_CALLBACK), 0);

    NW4R_UT_LINKLIST_FOREACH_SAFE (it, mPlayerCallbackList,
                                   { it->OnUpdateVoiceSoundThread(); })

    VoiceManager::GetInstance().NotifyVoiceUpdate();
}

void *SoundThread::SoundThreadFunc(void *pArg) {
    SoundThread *p = static_cast<SoundThread *>(pArg);

    AxManager::GetInstance().RegisterCallback(&p->mAxCallbackNode, AxCallbackFunc);

    p->SoundThreadProc();

    AxManager::GetInstance().UnregisterCallback(&p->mAxCallbackNode);

    return NULL;
}

void SoundThread::RegisterPlayerCallback(PlayerCallback *pCallback) {
    ut::AutoInterruptLock lock;
    mPlayerCallbackList.PushBack(pCallback);
}

void SoundThread::UnregisterPlayerCallback(PlayerCallback *pCallback) {
    ut::AutoInterruptLock lock;
    mPlayerCallbackList.Erase(pCallback);
}

// Calls FUNC on every callback in LIST, letting interrupts in around each
// call (the callbacks may unregister themselves).
#define CALL_EACH_UNLOCKED(LIST, TYPE, FUNC, ENABLED)                                                                \
    for (TYPE::Iterator it = (LIST).GetBeginIter(); it != (LIST).GetEndIter();) {                                    \
        TYPE::Iterator cur = it++;                                                                                    \
        OSRestoreInterrupts(ENABLED);                                                                                 \
        cur->FUNC();                                                                                                  \
        ENABLED = OSDisableInterrupts();                                                                              \
    }

void SoundThread::SoundThreadProc() {
    OSMessage msg;
    BOOL enabled;

    while (true) {
        OSReceiveMessage(&mMsgQueue, &msg, OS_MESSAGE_BLOCK);

        if (reinterpret_cast<u32>(msg) == MSG_AX_CALLBACK) {
            ut::detail::AutoLock<OSMutex> lock(mMutex);

            enabled = OSDisableInterrupts();
            {
                ut::AutoInterruptLock lock;
                CALL_EACH_UNLOCKED(mSoundFrameCallbackList, SoundFrameCallbackList, OnBeginSoundFrame, enabled)
                OSRestoreInterrupts(enabled);
            }

            u32 start = OSGetTick();
            {
                AxVoiceManager::GetInstance().FreeAllReservedAxVoice();
                AxManager::GetInstance().Update();

                if (!AxManager::GetInstance().IsDiskError()) {
                    BOOL enabled = OSDisableInterrupts();
                    CALL_EACH_UNLOCKED(mPlayerCallbackList, PlayerCallbackList, OnUpdateFrameSoundThread, enabled)
                    OSRestoreInterrupts(enabled);

                    ChannelManager::GetInstance().UpdateAllChannel();
                }

                (void)Util::CalcRandom();
                VoiceManager::GetInstance().UpdateAllVoices();
            }
            mProcessTick = OSGetTick() - start;

            enabled = OSDisableInterrupts();
            CALL_EACH_UNLOCKED(mSoundFrameCallbackList, SoundFrameCallbackList, OnEndSoundFrame, enabled)
            OSRestoreInterrupts(enabled);

        } else if (reinterpret_cast<u32>(msg) == MSG_SHUTDOWN) {
            enabled = OSDisableInterrupts();
            CALL_EACH_UNLOCKED(mPlayerCallbackList, PlayerCallbackList, OnShutdownSoundThread, enabled)
            OSRestoreInterrupts(enabled);

            break;
        }
    }
}

#undef CALL_EACH_UNLOCKED

} // namespace detail
} // namespace snd
} // namespace nw4r
