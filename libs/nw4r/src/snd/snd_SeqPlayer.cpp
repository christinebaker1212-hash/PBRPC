// Imported from doldecomp/ogws (CC0), src/nw4r/snd/snd_SeqPlayer.cpp
// This nw4r revision locks the player's own mutex and counts ticks in a fixed-point fraction.
#include <nw4r/snd.h>
#include <nw4r/ut.h>

namespace nw4r {
namespace snd {
namespace detail {

volatile s16 SeqPlayer::mGlobalVariable[GLOBAL_VARIABLE_NUM];
bool SeqPlayer::mGobalVariableInitialized = false;

SeqPlayer::SeqPlayer() : mActiveFlag(false) {
    OSInitMutex(&mMutex);

    mStartedFlag = false;
    mPauseFlag = false;
    mReleasePriorityFixFlag = false;

    mTempoRatio = 1.0f;
    mTickFraction = 0;
    mSkipTickCounter = 0;
    mSkipTimeCounter = 0.0f;
    mPanRange = 1.0f;
    mTickCounter = 0;
    mVoiceOutCount = 0;

    mParserParam.tempo = DEFAULT_TEMPO;
    mParserParam.timebase = DEFAULT_TIMEBASE;
    mParserParam.volume = 127;
    mParserParam.priority = DEFAULT_PRIORITY;
    mParserParam.callback = NULL;

    for (int i = 0; i < LOCAL_VARIABLE_NUM; i++) {
        mLocalVariable[i] = DEFAULT_VARIABLE_VALUE;
    }
    for (int i = 0; i < TRACK_NUM; i++) {
        mTracks[i] = NULL;
    }
}

SeqPlayer::~SeqPlayer() {
    FinishPlayer();
}

void SeqPlayer::InitParam(int voices, NoteOnCallback *pCallback) {
    BasicPlayer::InitParam();

    mStartedFlag = false;
    mPauseFlag = false;
    mTempoRatio = 1.0f;
    mSkipTickCounter = 0;
    mSkipTimeCounter = 0.0f;
    mPanRange = 1.0f;
    mTickCounter = 0;
    mVoiceOutCount = voices;

    mParserParam.tempo = DEFAULT_TEMPO;
    mParserParam.timebase = DEFAULT_TIMEBASE;
    mParserParam.volume = 127;
    mParserParam.priority = 64;
    mParserParam.callback = pCallback;

    mTickFraction = GetTickPerFrame();

    for (int i = 0; i < LOCAL_VARIABLE_NUM; i++) {
        mLocalVariable[i] = DEFAULT_VARIABLE_VALUE;
    }
    for (int i = 0; i < TRACK_NUM; i++) {
        mTracks[i] = NULL;
    }
}

SeqPlayer::SetupResult
SeqPlayer::Setup(SeqTrackAllocator *pAllocator, u32 allocTrackFlags, int voices, NoteOnCallback *pCallback) {
    ut::detail::AutoLock<OSMutex> lock(mMutex);

    FinishPlayer();
    InitParam(voices, pCallback);
    {
        ut::AutoInterruptLock lock;
        int tracks = 0;

        {
            u32 trackFlags = allocTrackFlags;

            for (; trackFlags != 0; trackFlags >>= 1) {
                if (trackFlags & 1) {
                    tracks++;
                }
            }
        }

        if (tracks > pAllocator->GetAllocatableTrackCount()) {
            return SETUP_ERR_CANNOT_ALLOCATE_TRACK;
        }

        {
            u32 trackFlags = allocTrackFlags;

            for (int i = 0; trackFlags != 0; trackFlags >>= 1, i++) {
                if (trackFlags & 1) {
                    SeqTrack *pTrack = pAllocator->AllocTrack(this);
                    SetPlayerTrack(i, pTrack);
                }
            }
        }
    }
    DisposeCallbackManager::GetInstance().RegisterDisposeCallback(this);

    mSeqTrackAllocator = pAllocator;
    mActiveFlag = true;

    return SETUP_SUCCESS;
}

void SeqPlayer::SetSeqData(const void *pBase, s32 offset) {
    ut::detail::AutoLock<OSMutex> lock(mMutex);

    SeqTrack *pTrack = GetPlayerTrack(0);

    if (pBase != NULL) {
        pTrack->SetSeqData(pBase, offset);
        pTrack->Open();
    }
}

bool SeqPlayer::Start() {
    ut::detail::AutoLock<OSMutex> lock(mMutex);

    SoundThread::GetInstance().RegisterPlayerCallback(this);
    mStartedFlag = true;

    return true;
}

void SeqPlayer::Stop() {
    ut::detail::AutoLock<OSMutex> lock(mMutex);

    FinishPlayer();
}

void SeqPlayer::Pause(bool flag) {
    ut::detail::AutoLock<OSMutex> lock(mMutex);

    mPauseFlag = static_cast<u8>(flag);

    for (int i = 0; i < TRACK_NUM; i++) {
        SeqTrack *pTrack = GetPlayerTrack(i);

        if (pTrack != NULL) {
            pTrack->PauseAllChannel(flag);
        }
    }
}

void SeqPlayer::Skip(OffsetType type, int offset) {
    if (!mActiveFlag) {
        return;
    }

    ut::detail::AutoLock<OSMutex> lock(mMutex);

    switch (type) {
        case OFFSET_TYPE_TICK: {
            mSkipTickCounter += offset;
            break;
        }

        case OFFSET_TYPE_MILLISEC: {
            mSkipTimeCounter += offset;
            break;
        }
    }
}

void SeqPlayer::SetTempoRatio(f32 tempo) {
    ut::detail::AutoLock<OSMutex> lock(mMutex);
    mTempoRatio = tempo;
}

void SeqPlayer::SetChannelPriority(int priority) {
    ut::detail::AutoLock<OSMutex> lock(mMutex);
    mParserParam.priority = priority;
}

void SeqPlayer::SetReleasePriorityFix(bool flag) {
    ut::detail::AutoLock<OSMutex> lock(mMutex);
    mReleasePriorityFixFlag = flag;
}

void SeqPlayer::SetLocalVariable(int idx, s16 value) {
    mLocalVariable[idx] = value;
}

void SeqPlayer::SetGlobalVariable(int idx, s16 value) {
    if (!mGobalVariableInitialized) {
        InitGlobalVariable();
    }

    mGlobalVariable[idx] = value;
}

void SeqPlayer::SetTrackVolume(u32 trackFlags, f32 volume) {
    SetTrackParam<f32>(trackFlags, &SeqTrack::SetVolume, volume);
}

void SeqPlayer::SetTrackPitch(u32 trackFlags, f32 pitch) {
    SetTrackParam<f32>(trackFlags, &SeqTrack::SetPitch, pitch);
}

void SeqPlayer::InvalidateData(const void *pStart, const void *pEnd) {
    ut::detail::AutoLock<OSMutex> lock(mMutex);

    if (mActiveFlag) {
        for (int i = 0; i < TRACK_NUM; i++) {
            SeqTrack *pTrack = GetPlayerTrack(i);
            if (pTrack == NULL) {
                continue;
            }

            const u8 *pBase = pTrack->GetParserTrackParam().baseAddr;
            if (pStart <= pBase && pBase <= pEnd) {
                FinishPlayer();
                break;
            }
        }
    }
}

SeqTrack *SeqPlayer::GetPlayerTrack(int idx) {
    if (idx > TRACK_NUM - 1) {
        return NULL;
    }

    return mTracks[idx];
}

void SeqPlayer::CloseTrack(int idx) {
    SeqTrack *pTrack = GetPlayerTrack(idx);
    if (pTrack == NULL) {
        return;
    }

    pTrack->Close();

    mSeqTrackAllocator->FreeTrack(mTracks[idx]);
    mTracks[idx] = NULL;
}

void SeqPlayer::SetPlayerTrack(int idx, SeqTrack *pTrack) {
    if (idx > TRACK_NUM - 1) {
        return;
    }

    mTracks[idx] = pTrack;
    pTrack->SetPlayerTrackNo(idx);
}

void SeqPlayer::FinishPlayer() {
    if (mStartedFlag) {
        SoundThread::GetInstance().UnregisterPlayerCallback(this);
        mStartedFlag = false;
    }

    if (mActiveFlag) {
        DisposeCallbackManager::GetInstance().UnregisterDisposeCallback(this);
        mActiveFlag = false;
    }

    for (int i = 0; i < TRACK_NUM; i++) {
        CloseTrack(i);
    }
}

void SeqPlayer::UpdateChannelParam() {
    for (int i = 0; i < TRACK_NUM; i++) {
        SeqTrack *pTrack = GetPlayerTrack(i);

        if (pTrack != NULL) {
            pTrack->UpdateChannelParam();
        }
    }
}

int SeqPlayer::ParseNextTick(bool doNoteOn) {
    bool active = false;

    for (int i = 0; i < TRACK_NUM; i++) {
        SeqTrack *pTrack = GetPlayerTrack(i);
        if (pTrack == NULL) {
            continue;
        }

        pTrack->UpdateChannelLength();

        if (pTrack->ParseNextTick(doNoteOn) < 0) {
            CloseTrack(i);
        }

        if (pTrack->IsOpened()) {
            active = true;
        }
    }

    if (!active) {
        return 1;
    }

    return 0;
}

volatile s16 *SeqPlayer::GetVariablePtr(int idx) {
    if (idx < LOCAL_VARIABLE_NUM) {
        return &mLocalVariable[idx];
    }

    if (idx < VARIABLE_NUM) {
        return &mGlobalVariable[idx - LOCAL_VARIABLE_NUM];
    }

    return NULL;
}

void SeqPlayer::Update() {
    if (!mActiveFlag) {
        return;
    }

    if (!mStartedFlag) {
        return;
    }

    UpdateTick();
    UpdateChannelParam();
}

void SeqPlayer::UpdateTick() {
    if (!mActiveFlag) {
        return;
    }

    if (!mStartedFlag) {
        return;
    }

    if (mSkipTickCounter != 0 || mSkipTimeCounter > 0.0f) {
        for (int i = 0; i < TRACK_NUM; i++) {
            SeqTrack *pTrack = GetPlayerTrack(i);

            if (pTrack != NULL) {
                pTrack->ReleaseAllChannel(127);
                pTrack->FreeAllChannel();
            }
        }
    }

    int skipCount = 0;

    while (mSkipTickCounter != 0 && skipCount < MAX_SKIP_TICK_PER_FRAME) {
        mSkipTickCounter--;

        if (ParseNextTick(false) != 0) {
            FinishPlayer();
            return;
        }

        skipCount++;
        mTickCounter++;
    }

    while (mSkipTimeCounter > 0.0f && skipCount < MAX_SKIP_TICK_PER_FRAME) {
        mSkipTimeCounter -= 60000.0f / (mParserParam.timebase * mParserParam.tempo);

        if (mSkipTimeCounter < 0.0f) {
            mSkipTimeCounter = 0.0f;
        }

        if (ParseNextTick(false) != 0) {
            FinishPlayer();
            return;
        }

        skipCount++;
        mTickCounter++;
    }

    if (mPauseFlag) {
        return;
    }

    if (mSkipTickCounter != 0) {
        return;
    }

    if (mSkipTimeCounter != 0.0f) {
        return;
    }

    int tickPerFrame = GetTickPerFrame();
    while (mTickFraction >= tickPerFrame) {
        if (ParseNextTick(true) != 0) {
            FinishPlayer();
            return;
        }

        mTickCounter++;
        mTickFraction -= tickPerFrame;
        tickPerFrame = GetTickPerFrame();
    }

    mTickFraction += static_cast<int>(mParserParam.tempo * mTempoRatio);
}

void SeqPlayer::InitGlobalVariable() {
    for (int i = 0; i < GLOBAL_VARIABLE_NUM; i++) {
        mGlobalVariable[i] = DEFAULT_VARIABLE_VALUE;
    }

    mGobalVariableInitialized = true;
}

Channel *SeqPlayer::NoteOn(int bankNo, const NoteOnInfo &rInfo) {
    return mParserParam.callback->NoteOn(this, bankNo, rInfo);
}

void SeqPlayer::ChannelCallback(Channel * /* pChannel */) {}

} // namespace detail
} // namespace snd
} // namespace nw4r
