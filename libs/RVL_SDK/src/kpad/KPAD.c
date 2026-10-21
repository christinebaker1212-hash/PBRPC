// Based on zeldaret/tp (CC0), libs/revolution/src/kpad/KPAD.c, rewritten for the Nov 30 2006 (0x4199_60831) release
#include <revolution/kpad.h>
#include <revolution/os.h>
#include <revolution/wpad.h>

#include <math.h>
#include <string.h>

#define KPAD_BUTTON_MASK 0x0000FFFF
#define KPAD_BUTTON_RPT 0x80000000

#define KPAD_BTN_RPT_TIME_MAX 20000
#define KPAD_BTN_NO_RPT_DELAY 40000

#define KPAD_DPD_RESO_WX 1024
#define KPAD_DPD_RESO_WY 768

#define KPAD_USE_OBJECTS 2
#define KPAD_RING_BUFS 16

// Value in [lo, hi], tested as one unsigned byte comparison
#define KPAD_IN_RANGE(x, lo, hi) ((u8)((x) + (u8)-(lo)) <= (hi) - (lo))

typedef struct KPADUnifiedWpadStatus {
    /* 0x00 */ union {
        WPADStatus core;
        WPADFSStatus fs;
        WPADCLStatus cl;
    } u;
    /* 0x36 */ u8 fmt;
} KPADUnifiedWpadStatus;  // size: 0x38

typedef struct KPADObject {
    /* 0x00 */ Vec2 center;
    /* 0x08 */ s8 error_fg;
    /* 0x09 */ s8 state_fg;
} KPADObject;  // size: 0xC

typedef void (*KPADControlDpdCallback)(s32 chan, s32 reason);

typedef struct KPADInsideStatus {
    /* 0x000 */ KPADStatus status;
    /* 0x084 */ f32 pos_play_radius;
    /* 0x088 */ f32 pos_sensitivity;
    /* 0x08C */ f32 hori_play_radius;
    /* 0x090 */ f32 hori_sensitivity;
    /* 0x094 */ f32 dist_play_radius;
    /* 0x098 */ f32 dist_sensitivity;
    /* 0x09C */ f32 acc_play_radius;
    /* 0x0A0 */ f32 acc_sensitivity;
    /* 0x0A4 */ f32 dist_org;
    /* 0x0A8 */ Vec2 accXY_nrm_hori;
    /* 0x0B0 */ Vec2 sec_nrm_hori;
    /* 0x0B8 */ Vec2 center_org;
    /* 0x0C0 */ f32 dpd2pos_scale;
    /* 0x0C4 */ KPADObject kobj_sample[WPAD_MAX_DPD_OBJECTS];
    /* 0x0F4 */ KPADObject kobj_regular[KPAD_USE_OBJECTS];
    /* 0x10C */ s16 valid_objs;
    /* 0x10E */ u8 wpad_ring_idx;
    /* 0x10F */ u8 wpad_ring_cnt;
    /* 0x110 */ KPADUnifiedWpadStatus wpad_ring_bf[KPAD_RING_BUFS];
    /* 0x490 */ f32 sec_length;
    /* 0x494 */ Vec2 sec_nrm;
    /* 0x49C */ f32 sec_dist;
    /* 0x4A0 */ f32 trust_sec_length;
    /* 0x4A4 */ Vec hard_acc;
    /* 0x4B0 */ Vec2 obj_horizon;
    /* 0x4B8 */ Vec2 acc_horizon;
    /* 0x4C0 */ Vec2 ah_circle_pos;
    /* 0x4C8 */ u16 ah_circle_ct;
    /* 0x4CA */ u8 dpd_valid2_ct;
    /* 0x4CC */ u16 btn_repeat_time;
    /* 0x4CE */ u16 btn_repeat_next;
    /* 0x4D0 */ u16 btn_repeat_delay;
    /* 0x4D2 */ u16 btn_repeat_pulse;
    /* 0x4D4 */ u16 btn_cl_repeat_time;
    /* 0x4D6 */ u16 btn_cl_repeat_next;
    /* 0x4D8 */ KPADControlDpdCallback dpd_ctrl_callback;
    /* 0x4DC */ Vec acc_scale;
    /* 0x4E8 */ Vec fs_acc_scale;
    /* 0x4F4 */ Vec2 kobj_frame_min;
    /* 0x4FC */ Vec2 kobj_frame_max;
    /* 0x504 */ f32 err_dist_speed_1;
    /* 0x508 */ f32 err_dist_speedM_1;
    /* 0x50C */ f32 ah_circle_radius2;
    /* 0x510 */ f32 dist_vv1;
    /* 0x514 */ f32 err_dist_min;
    /* 0x518 */ WPADSamplingCallback sampling_callback;
    /* 0x51C */ u8 reading;
    /* 0x51D */ u8 reset_req;
    /* 0x51E */ u8 ex_reset_req;
    /* 0x51F */ u8 dpd_ctrl_busy;
    /* 0x520 */ u8 dpd_enable;
    /* 0x521 */ u8 dpd_command;
    /* 0x522 */ u8 dpd_ctrl_started;
    /* 0x523 */ u8 dpd_ctrl_ended;
} KPADInsideStatus;  // size: 0x524

static const char* __KPADVersion = "<< RVL_SDK - KPAD \trelease build: Nov 30 2006 03:30:56 (0x4199_60831) >>";

static Vec2 icenter_org = {0.000f, 0.000f};
static f32 idist_org = 1.000f;
static Vec2 iaccXY_nrm_hori = {0.000f, -1.000f};
static Vec2 isec_nrm_hori = {1.000f, 0.000f};
f32 kp_obj_interval = 0.200f;

f32 kp_acc_horizon_pw = 0.050f;
f32 kp_ah_circle_radius = 0.070f;
f32 kp_ah_circle_pw = 0.060f;
u16 kp_ah_circle_ct = 100;

f32 kp_err_outside_frame = 0.050f;
f32 kp_err_dist_max = 3.000f;
f32 kp_err_dist_speed = 0.040f;
f32 kp_err_first_inpr = 0.900f;
f32 kp_err_next_inpr = 0.900f;
f32 kp_err_acc_inpr = 0.900f;
f32 kp_err_up_inpr = 0.700f;
f32 kp_err_near_pos = 0.100f;

static s32 kp_fs_fstick_min = 15;
static s32 kp_fs_fstick_max = 71;
static s32 kp_cl_stick_min = 60;
static s32 kp_cl_stick_max = 308;
static s32 kp_cl_trigger_min = 30;
static s32 kp_cl_trigger_max = 180;
static f32 kp_rm_acc_max = 3.4f;
static f32 kp_fs_acc_max = 2.1f;

// TODO Selects clamp_stick_circle instead of clamp_stick_cross when nonzero; its setter is not in the binary
static s32 kp_stick_clamp_mode;

static Vec2 Vec2_0 = {0.0f, 0.0f};
static f32 kp_dist_vv1;
static f32 kp_err_dist_min;

KPADInsideStatus inside_kpads[WPAD_MAX_CONTROLLERS];

void KPADiControlDpdCallback(s32 chan, s32 result);
static void KPADiSamplingCallback(s32 chan);

void KPADSetFSStickClamp(s8 min, s8 max) {
    kp_fs_fstick_min = min;
    kp_fs_fstick_max = max;
}

void KPADSetBtnRepeat(s32 chan, f32 delay_sec, f32 pulse_sec) {
    KPADInsideStatus* kp = &inside_kpads[chan];

    if (pulse_sec) {
        kp->btn_repeat_delay = (u16)(s32)(delay_sec + 0.5f);
        kp->btn_repeat_pulse = (u16)(s32)(pulse_sec + 0.5f);
    } else {
        kp->btn_repeat_delay = KPAD_BTN_NO_RPT_DELAY;
        kp->btn_repeat_pulse = 0;
    }

    kp->btn_repeat_time = 0;
    kp->btn_repeat_next = kp->btn_repeat_delay;
    kp->btn_cl_repeat_time = 0;
    kp->btn_cl_repeat_next = kp->btn_repeat_delay;
}

void KPADSetObjInterval(f32 interval) {
    BOOL enabled = OSDisableInterrupts();

    kp_obj_interval = interval;
    kp_dist_vv1 = kp_err_dist_min = interval / 0.383864f;

    OSRestoreInterrupts(enabled);
}

void KPADSetPosParam(s32 chan, f32 play_radius, f32 sensitivity) {
    inside_kpads[chan].pos_play_radius = play_radius;
    inside_kpads[chan].pos_sensitivity = sensitivity;
}

void KPADSetHoriParam(s32 chan, f32 play_radius, f32 sensitivity) {
    inside_kpads[chan].hori_play_radius = play_radius;
    inside_kpads[chan].hori_sensitivity = sensitivity;
}

void KPADSetDistParam(s32 chan, f32 play_radius, f32 sensitivity) {
    inside_kpads[chan].dist_play_radius = play_radius;
    inside_kpads[chan].dist_sensitivity = sensitivity;
}

void KPADSetAccParam(s32 chan, f32 play_radius, f32 sensitivity) {
    inside_kpads[chan].acc_play_radius = play_radius;
    inside_kpads[chan].acc_sensitivity = sensitivity;
}

static inline void calc_dpd2pos_scale(KPADInsideStatus* kp) {
    f32 sx, sy, scale;

    sx = 1.0f;
    sy = (f32)KPAD_DPD_RESO_WY / (f32)KPAD_DPD_RESO_WX;

    scale = sqrt(sx * sx + sy * sy);

    if (kp->center_org.x < 0.0f) {
        sx += kp->center_org.x;
    } else {
        sx -= kp->center_org.x;
    }

    if (kp->center_org.y < 0.0f) {
        sy += kp->center_org.y;
    } else {
        sy -= kp->center_org.y;
    }

    kp->dpd2pos_scale = scale / (sx < sy ? sx : sy);
}

void reset_kpad(KPADInsideStatus* kp) {
    KPADObject* op;
    KPADStatus* sp = &kp->status;

    kp->reset_req = FALSE;

    kp->kobj_frame_min.x = -1.0f + kp_err_outside_frame;
    kp->kobj_frame_max.x = 1.0f - kp_err_outside_frame;
    kp->kobj_frame_min.y = -((f32)KPAD_DPD_RESO_WY / KPAD_DPD_RESO_WX) + kp_err_outside_frame;
    kp->kobj_frame_max.y = ((f32)KPAD_DPD_RESO_WY / KPAD_DPD_RESO_WX) - kp_err_outside_frame;
    kp->err_dist_speed_1 = 1.0f / kp_err_dist_speed;
    kp->err_dist_speedM_1 = -1.0f / kp_err_dist_speed;
    kp->ah_circle_radius2 = kp_ah_circle_radius * kp_ah_circle_radius;
    kp->err_dist_min = kp_err_dist_min;
    kp->dist_vv1 = kp_dist_vv1;

    sp->hold = sp->trig = sp->release = 0;
    kp->btn_repeat_time = 0;
    kp->btn_repeat_next = kp->btn_repeat_delay;

    kp->status.dpd_valid_fg = 0;
    kp->dpd_valid2_ct = 0;

    sp->pos = sp->vec = Vec2_0;
    sp->speed = 0.0f;

    sp->horizon.x = kp->acc_horizon.x = kp->obj_horizon.x = 1.0f;
    sp->horizon.y = kp->acc_horizon.y = kp->obj_horizon.y = 0.0f;
    sp->hori_vec = Vec2_0;
    sp->hori_speed = 0.0f;

    sp->acc_vertical.x = 1.0f;
    sp->acc_vertical.y = 0.0f;

    sp->dist = kp->dist_org;
    sp->dist_vec = sp->dist_speed = 0.0f;

    kp->sec_dist = sp->dist;
    kp->sec_length = kp->trust_sec_length = kp->dist_vv1 / kp->sec_dist;
    kp->sec_nrm = kp->sec_nrm_hori;

    sp->acc.x = sp->acc.z = 0.0f;
    sp->acc.y = -1.0f;
    sp->acc_value = 1.0f;
    sp->acc_speed = 0.0f;
    kp->hard_acc = sp->acc;

    kp->ah_circle_pos = kp->acc_horizon;
    kp->ah_circle_ct = kp_ah_circle_ct;

    kp->valid_objs = 0;

    op = &kp->kobj_sample[WPAD_MAX_DPD_OBJECTS - 1];
    do {
        op->error_fg = -1;
    } while (--op >= kp->kobj_sample);

    op = &kp->kobj_regular[KPAD_USE_OBJECTS - 1];
    do {
        op->error_fg = -1;
    } while (--op >= kp->kobj_regular);

    kp->wpad_ring_cnt = 0;
    kp->ex_reset_req = TRUE;
}

void KPADSetSensorHeight(s32 chan, f32 level) {
    KPADInsideStatus* kp = &inside_kpads[chan];

    kp->center_org.x = 0.0f;
    kp->center_org.y = -level;
    calc_dpd2pos_scale(kp);
}

static void calc_button_repeat(KPADInsideStatus* kp, u32 dev_type, u32 count) {
    KPADStatus* sp = &kp->status;
    KPADEXStatus* ep = &kp->status.ex_status;

    if (sp->trig != 0 || sp->release != 0) {
        kp->btn_repeat_time = 0;
        kp->btn_repeat_next = kp->btn_repeat_delay;
        if (sp->trig && kp->btn_repeat_pulse) {
            sp->hold |= KPAD_BUTTON_RPT;
        }
    } else if (sp->hold != 0) {
        kp->btn_repeat_time += count;
        if (kp->btn_repeat_time >= KPAD_BTN_NO_RPT_DELAY) {
            kp->btn_repeat_time -= KPAD_BTN_NO_RPT_DELAY;
        }

        if (kp->btn_repeat_time >= kp->btn_repeat_next) {
            sp->hold |= KPAD_BUTTON_RPT;
            kp->btn_repeat_next += kp->btn_repeat_pulse;
            if (kp->btn_repeat_time >= KPAD_BTN_RPT_TIME_MAX) {
                kp->btn_repeat_time -= KPAD_BTN_RPT_TIME_MAX;
                kp->btn_repeat_next -= KPAD_BTN_RPT_TIME_MAX;
            }
        }
    }

    if (dev_type != WPAD_DEV_CLASSIC) {
        return;
    }

    if (ep->cl.trig != 0 || ep->cl.release != 0) {
        kp->btn_cl_repeat_time = 0;
        kp->btn_cl_repeat_next = kp->btn_repeat_delay;
        if (ep->cl.trig && kp->btn_repeat_pulse) {
            ep->cl.hold |= KPAD_BUTTON_RPT;
        }
    } else if (ep->cl.hold != 0) {
        kp->btn_cl_repeat_time += count;
        if (kp->btn_cl_repeat_time >= KPAD_BTN_NO_RPT_DELAY) {
            kp->btn_cl_repeat_time -= KPAD_BTN_NO_RPT_DELAY;
        }

        if (kp->btn_cl_repeat_time >= kp->btn_cl_repeat_next) {
            ep->cl.hold |= KPAD_BUTTON_RPT;
            kp->btn_cl_repeat_next += kp->btn_repeat_pulse;
            if (kp->btn_cl_repeat_time >= KPAD_BTN_RPT_TIME_MAX) {
                kp->btn_cl_repeat_time -= KPAD_BTN_RPT_TIME_MAX;
                kp->btn_cl_repeat_next -= KPAD_BTN_RPT_TIME_MAX;
            }
        }
    }
}

static inline void calc_acc(KPADInsideStatus* kp, f32* acc, f32 acc2) {
    f32 f1, f2;

    f2 = acc2 - *acc;

    if (f2 < 0.0f) {
        f1 = -f2;
    } else {
        f1 = f2;
    }

    if (f1 >= kp->acc_play_radius) {
        f1 = 1.0f;
    } else {
        f1 /= kp->acc_play_radius;
        f1 *= f1;
        f1 *= f1;
    }
    f1 *= kp->acc_sensitivity;
    *acc += f1 * f2;
}

static void calc_acc_horizon(KPADInsideStatus* kp) {
    f32 f1, vx, vy, ax, ay;

    f1 = sqrt(kp->hard_acc.x * kp->hard_acc.x + kp->hard_acc.y * kp->hard_acc.y);
    if (f1 == 0.0f || f1 >= 2.0f) {
        return;
    }
    ax = kp->hard_acc.x / f1;
    ay = kp->hard_acc.y / f1;

    if (f1 > 1.0f) {
        f1 = 2.0f - f1;
    }
    f1 *= f1 * kp_acc_horizon_pw;

    vx = kp->accXY_nrm_hori.x * ax + kp->accXY_nrm_hori.y * ay;
    vy = kp->accXY_nrm_hori.y * ax - kp->accXY_nrm_hori.x * ay;
    ax = (vx - kp->acc_horizon.x) * f1 + kp->acc_horizon.x;
    ay = (vy - kp->acc_horizon.y) * f1 + kp->acc_horizon.y;

    f1 = sqrt(ax * ax + ay * ay);
    if (f1 == 0.0f) {
        return;
    }
    kp->acc_horizon.x = ax / f1;
    kp->acc_horizon.y = ay / f1;

    kp->ah_circle_pos.x += (kp->acc_horizon.x - kp->ah_circle_pos.x) * kp_ah_circle_pw;
    kp->ah_circle_pos.y += (kp->acc_horizon.y - kp->ah_circle_pos.y) * kp_ah_circle_pw;

    vx = kp->acc_horizon.x - kp->ah_circle_pos.x;
    vy = kp->acc_horizon.y - kp->ah_circle_pos.y;
    if (vx * vx + vy * vy <= kp->ah_circle_radius2) {
        if (kp->ah_circle_ct) {
            --kp->ah_circle_ct;
        }
    } else {
        kp->ah_circle_ct = kp_ah_circle_ct;
    }
}

static void calc_acc_vertical(KPADInsideStatus* kp) {
    KPADStatus* sp = &kp->status;
    f32 f1;
    f32 f2;
    f32 ax;
    f32 ay;

    ax = sqrt(f2 = kp->hard_acc.x * kp->hard_acc.x + kp->hard_acc.y * kp->hard_acc.y);
    ay = -kp->hard_acc.z;
    f1 = sqrt(f2 + ay * ay);
    if (f1 == 0.0f || f1 >= 2.0f) {
        return;
    }
    ax = ax / f1;
    ay /= f1;

    if (f1 > 1.0f) {
        f1 = 2.0f - f1;
    }
    f1 *= f1 * kp_acc_horizon_pw;

    ax = (ax - sp->acc_vertical.x) * f1 + sp->acc_vertical.x;
    ay = (ay - sp->acc_vertical.y) * f1 + sp->acc_vertical.y;

    f1 = sqrt(ax * ax + ay * ay);
    if (f1 == 0.0f) {
        return;
    }
    sp->acc_vertical.x = ax / f1;
    sp->acc_vertical.y = ay / f1;
}

static inline f32 clamp_acc(f32 acc, f32 clamp) {
    if (acc < 0.0f) {
        if (acc < -clamp) {
            return -clamp;
        }
    } else {
        if (acc > clamp) {
            return clamp;
        }
    }
    return acc;
}

static void read_kpad_acc(KPADInsideStatus* kp, KPADUnifiedWpadStatus* uwp) {
    KPADStatus* sp = &kp->status;
    Vec vec;

    switch (uwp->fmt) {
    case WPAD_FMT_CORE_BTN_ACC:
    case WPAD_FMT_CORE_BTN_ACC_DPD:
    case WPAD_FMT_FS_BTN_ACC:
    case WPAD_FMT_FS_BTN_ACC_DPD:
    case WPAD_FMT_CLASSIC_BTN_ACC:
    case WPAD_FMT_CLASSIC_BTN_ACC_DPD:
        break;
    default:
        return;
    }

    kp->hard_acc.x = clamp_acc((f32)(s32)-uwp->u.core.accX * kp->acc_scale.x, kp_rm_acc_max);
    kp->hard_acc.y = clamp_acc((f32)(s32)-uwp->u.core.accZ * kp->acc_scale.z, kp_rm_acc_max);
    kp->hard_acc.z = clamp_acc((f32)(s32)uwp->u.core.accY * kp->acc_scale.y, kp_rm_acc_max);

    vec = sp->acc;

    calc_acc(kp, &sp->acc.x, kp->hard_acc.x);
    calc_acc(kp, &sp->acc.y, kp->hard_acc.y);
    calc_acc(kp, &sp->acc.z, kp->hard_acc.z);
    sp->acc_value = sqrt(sp->acc.x * sp->acc.x + sp->acc.y * sp->acc.y + sp->acc.z * sp->acc.z);

    vec.x -= sp->acc.x;
    vec.y -= sp->acc.y;
    vec.z -= sp->acc.z;
    sp->acc_speed = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    calc_acc_horizon(kp);
    calc_acc_vertical(kp);

    if (uwp->u.core.err != WPAD_ERR_NONE || uwp->u.core.dev != WPAD_DEV_FREESTYLE ||
        (uwp->fmt != WPAD_FMT_FS_BTN_ACC && uwp->fmt != WPAD_FMT_FS_BTN_ACC_DPD)) {
        return;
    }

    vec = sp->ex_status.fs.acc;

    calc_acc(kp, &sp->ex_status.fs.acc.x, clamp_acc((f32)(s32)-uwp->u.fs.fsAccX * kp->fs_acc_scale.x, kp_fs_acc_max));
    calc_acc(kp, &sp->ex_status.fs.acc.y, clamp_acc((f32)(s32)-uwp->u.fs.fsAccZ * kp->fs_acc_scale.z, kp_fs_acc_max));
    calc_acc(kp, &sp->ex_status.fs.acc.z, clamp_acc((f32)(s32)uwp->u.fs.fsAccY * kp->fs_acc_scale.y, kp_fs_acc_max));

    sp->ex_status.fs.acc_value =
        sqrt(sp->ex_status.fs.acc.x * sp->ex_status.fs.acc.x + sp->ex_status.fs.acc.y * sp->ex_status.fs.acc.y +
             sp->ex_status.fs.acc.z * sp->ex_status.fs.acc.z);

    vec.x -= sp->ex_status.fs.acc.x;
    vec.y -= sp->ex_status.fs.acc.y;
    vec.z -= sp->ex_status.fs.acc.z;

    sp->ex_status.fs.acc_speed = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

static inline void get_kobj(KPADInsideStatus* kp, KPADUnifiedWpadStatus* uwp) {
    DPDObject* wobj_p = &uwp->u.core.obj[WPAD_MAX_DPD_OBJECTS - 1];
    const f32 dpd_scale = 2.0f / (f32)KPAD_DPD_RESO_WX;
    const f32 dpd_cx = (f32)(KPAD_DPD_RESO_WX - 1) / (f32)KPAD_DPD_RESO_WX;
    const f32 dpd_cy = (f32)(KPAD_DPD_RESO_WY - 1) / (f32)KPAD_DPD_RESO_WX;
    KPADObject* kobj_p;

    kobj_p = &kp->kobj_sample[WPAD_MAX_DPD_OBJECTS - 1];

    do {
        if (wobj_p->size) {
            kobj_p->center.x = (f32)(s32)wobj_p->x * dpd_scale - dpd_cx;
            kobj_p->center.y = (f32)(s32)wobj_p->y * dpd_scale - dpd_cy;

            kobj_p->error_fg = 0;
            kobj_p->state_fg = 0;
        } else {
            kobj_p->error_fg = -1;
        }

        --wobj_p;
    } while (--kobj_p >= kp->kobj_sample);
}

static inline f32 calc_horizon(KPADInsideStatus* kp, Vec2* p1, Vec2* p2, Vec2* hori) {
    f32 f1, f2, vx, vy;

    vx = p2->x - p1->x;
    vy = p2->y - p1->y;
    f2 = sqrt(vx * vx + vy * vy);
    f1 = 1.0f / f2;
    vx *= f1;
    vy *= f1;

    hori->x = kp->sec_nrm_hori.x * vx + kp->sec_nrm_hori.y * vy;
    hori->y = kp->sec_nrm_hori.y * vx - kp->sec_nrm_hori.x * vy;

    return kp->dist_vv1 * f1;
}

static s8 select_2obj_first(KPADInsideStatus* kp) {
    KPADObject *op1, *op2, *rp1, *rp2;
    Vec2 hori;
    f32 f1, max = kp_err_first_inpr;

    op1 = kp->kobj_sample;
    do {
        if (op1->error_fg != 0) {
            continue;
        }

        op2 = op1 + 1;
        do {
            if (op2->error_fg != 0) {
                continue;
            }

            f1 = calc_horizon(kp, &op1->center, &op2->center, &hori);

            if (f1 <= kp->err_dist_min || f1 >= kp_err_dist_max) {
                continue;
            }

            f1 = kp->acc_horizon.x * hori.x + kp->acc_horizon.y * hori.y;
            if (f1 < 0.0f) {
                if (-f1 > max) {
                    max = -f1;
                    rp1 = op2;
                    rp2 = op1;
                }
            } else {
                if (f1 > max) {
                    max = f1;
                    rp1 = op1;
                    rp2 = op2;
                }
            }
        } while (++op2 <= &kp->kobj_sample[WPAD_MAX_DPD_OBJECTS - 1]);
    } while (++op1 < &kp->kobj_sample[WPAD_MAX_DPD_OBJECTS - 1]);

    if (max == kp_err_first_inpr) {
        return 0;
    }

    kp->kobj_regular[0] = *rp1;
    kp->kobj_regular[1] = *rp2;

    return 2;
}

static s8 select_2obj_continue(KPADInsideStatus* kp) {
    KPADObject *op1, *op2, *rp1, *rp2;
    Vec2 nrm;
    s32 rev_fg;
    f32 f1, f2, f3, vx, vy, min = 2.0f;

    op1 = kp->kobj_sample;
    do {
        if (op1->error_fg != 0) {
            continue;
        }

        op2 = op1 + 1;
        do {
            if (op2->error_fg != 0) {
                continue;
            }

            vx = op2->center.x - op1->center.x;
            vy = op2->center.y - op1->center.y;
            f3 = sqrt(vx * vx + vy * vy);
            f1 = 1.0f / f3;
            nrm.x = vx * f1;
            nrm.y = vy * f1;

            f1 *= kp->dist_vv1;
            if (f1 <= kp->err_dist_min || f1 >= kp_err_dist_max) {
                continue;
            }

            f1 -= kp->sec_dist;
            if (f1 < 0.0f) {
                f1 *= kp->err_dist_speedM_1;
            } else {
                f1 *= kp->err_dist_speed_1;
            }
            if (f1 >= 1.0f) {
                continue;
            }

            f2 = kp->sec_nrm.x * nrm.x + kp->sec_nrm.y * nrm.y;
            if (f2 < 0.0f) {
                f2 = -f2;
                rev_fg = 1;
            } else {
                rev_fg = 0;
            }
            if (f2 <= kp_err_next_inpr) {
                continue;
            }
            f2 = (1.0f - f2) / (1.0f - kp_err_next_inpr);
            f1 += f2;
            if (f1 < min) {
                min = f1;
                if (rev_fg) {
                    rp1 = op2;
                    rp2 = op1;
                } else {
                    rp1 = op1;
                    rp2 = op2;
                }
            }
        } while (++op2 <= &kp->kobj_sample[WPAD_MAX_DPD_OBJECTS - 1]);
    } while (++op1 < &kp->kobj_sample[WPAD_MAX_DPD_OBJECTS - 1]);

    if (min == 2.0f) {
        return 0;
    }

    kp->kobj_regular[0] = *rp1;
    kp->kobj_regular[1] = *rp2;

    return 2;
}

static s8 select_1obj_first(KPADInsideStatus* kp) {
    KPADObject* op1;
    f32 vx, vy;
    Vec2 p1, p2;

    vx = kp->sec_nrm_hori.x * kp->acc_horizon.x + kp->sec_nrm_hori.y * kp->acc_horizon.y;
    vy = kp->sec_nrm_hori.y * kp->acc_horizon.x - kp->sec_nrm_hori.x * kp->acc_horizon.y;

    vx *= kp->trust_sec_length;
    vy *= kp->trust_sec_length;

    op1 = kp->kobj_sample;
    do {
        if (op1->error_fg != 0) {
            continue;
        }

        p1.x = op1->center.x - vx;
        p1.y = op1->center.y - vy;
        p2.x = op1->center.x + vx;
        p2.y = op1->center.y + vy;

        if (p1.x <= kp->kobj_frame_min.x || p1.x >= kp->kobj_frame_max.x || p1.y <= kp->kobj_frame_min.y ||
            p1.y >= kp->kobj_frame_max.y) {
            if (p2.x > kp->kobj_frame_min.x && p2.x < kp->kobj_frame_max.x && p2.y > kp->kobj_frame_min.y &&
                p2.y < kp->kobj_frame_max.y) {
                kp->kobj_regular[1] = *op1;
                kp->kobj_regular[0].center = p1;
                kp->kobj_regular[0].error_fg = 0;
                kp->kobj_regular[0].state_fg = -1;

                return -1;
            }
        } else {
            if (p2.x <= kp->kobj_frame_min.x || p2.x >= kp->kobj_frame_max.x || p2.y <= kp->kobj_frame_min.y ||
                p2.y >= kp->kobj_frame_max.y) {
                kp->kobj_regular[0] = *op1;
                kp->kobj_regular[1].center = p2;
                kp->kobj_regular[1].error_fg = 0;
                kp->kobj_regular[1].state_fg = -1;

                return -1;
            }
        }
    } while (++op1 < &kp->kobj_sample[WPAD_MAX_DPD_OBJECTS]);

    return 0;
}

static s8 select_1obj_continue(KPADInsideStatus* kp) {
    KPADObject *op1, *op2, *rp1, *rp2;
    f32 f1, vx, vy;
    f32 min = kp_err_near_pos * kp_err_near_pos;

    op1 = kp->kobj_regular;
    do {
        if (op1->error_fg != 0) {
            continue;
        }
        if (op1->state_fg != 0) {
            continue;
        }

        op2 = kp->kobj_sample;
        do {
            if (op2->error_fg != 0) {
                continue;
            }

            vx = op1->center.x - op2->center.x;
            vy = op1->center.y - op2->center.y;
            f1 = vx * vx + vy * vy;
            if (f1 < min) {
                min = f1;
                rp1 = op1;
                rp2 = op2;
            }
        } while (++op2 < &kp->kobj_sample[WPAD_MAX_DPD_OBJECTS]);
    } while (++op1 < &kp->kobj_regular[KPAD_USE_OBJECTS]);

    if (min == kp_err_near_pos * kp_err_near_pos) {
        return 0;
    }

    *rp1 = *rp2;
    kp->sec_nrm.x = kp->sec_nrm_hori.x * kp->acc_horizon.x + kp->sec_nrm_hori.y * kp->acc_horizon.y;
    kp->sec_nrm.y = kp->sec_nrm_hori.y * kp->acc_horizon.x - kp->sec_nrm_hori.x * kp->acc_horizon.y;

    vx = kp->sec_length * kp->sec_nrm.x;
    vy = kp->sec_length * kp->sec_nrm.y;
    if (rp1 == &kp->kobj_regular[0]) {
        kp->kobj_regular[1].center.x = rp1->center.x + vx;
        kp->kobj_regular[1].center.y = rp1->center.y + vy;
        kp->kobj_regular[1].error_fg = 0;
        kp->kobj_regular[1].state_fg = -1;
    } else {
        kp->kobj_regular[0].center.x = rp1->center.x - vx;
        kp->kobj_regular[0].center.y = rp1->center.y - vy;
        kp->kobj_regular[0].error_fg = 0;
        kp->kobj_regular[0].state_fg = -1;
    }

    if (kp->status.dpd_valid_fg < 0) {
        return -1;
    } else {
        return 1;
    }
}

static void calc_dpd_variable(KPADInsideStatus* kp, s8 valid_fg_next) {
    KPADStatus* sp = &kp->status;
    f32 f1, f2, f4, dist;
    Vec2 pos, vec;

    if (valid_fg_next == 0) {
        sp->dpd_valid_fg = 0;
        return;
    }

    pos.x = kp->sec_nrm_hori.x * kp->sec_nrm.x + kp->sec_nrm_hori.y * kp->sec_nrm.y;
    pos.y = kp->sec_nrm_hori.y * kp->sec_nrm.x - kp->sec_nrm_hori.x * kp->sec_nrm.y;

    if (!sp->dpd_valid_fg) {
        sp->horizon = pos;
        sp->hori_vec = Vec2_0;
        sp->hori_speed = 0.0f;
    } else {
        vec.x = pos.x - sp->horizon.x;
        vec.y = pos.y - sp->horizon.y;
        f1 = sqrt(vec.x * vec.x + vec.y * vec.y);

        if (f1 >= kp->hori_play_radius) {
            f4 = 1.0f;
        } else {
            f4 = f1 / kp->hori_play_radius;
            f4 *= f4;
            f4 *= f4;
        }
        f4 *= kp->hori_sensitivity;
        vec.x = f4 * vec.x + sp->horizon.x;
        vec.y = f4 * vec.y + sp->horizon.y;
        f4 = sqrt(vec.x * vec.x + vec.y * vec.y);
        vec.x /= f4;
        vec.y /= f4;

        sp->hori_vec.x = vec.x - sp->horizon.x;
        sp->hori_vec.y = vec.y - sp->horizon.y;
        sp->hori_speed = sqrt(sp->hori_vec.x * sp->hori_vec.x + sp->hori_vec.y * sp->hori_vec.y);

        sp->horizon = vec;
    }

    dist = kp->dist_vv1 / kp->sec_length;

    if (!sp->dpd_valid_fg) {
        sp->dist = dist;
        sp->dist_vec = 0.0f;
        sp->dist_speed = 0.0f;
    } else {
        f2 = dist - sp->dist;
        if (f2 < 0.0f) {
            f1 = -f2;
        } else {
            f1 = f2;
        }

        if (f1 >= kp->dist_play_radius) {
            f1 = 1.0f;
        } else {
            f1 /= kp->dist_play_radius;
            f1 *= f1;
            f1 *= f1;
        }
        f1 *= kp->dist_sensitivity;

        sp->dist_vec = f1 * f2;
        if (sp->dist_vec < 0.0f) {
            sp->dist_speed = -sp->dist_vec;
        } else {
            sp->dist_speed = sp->dist_vec;
        }

        sp->dist += sp->dist_vec;
    }

    pos.x = (kp->kobj_regular[0].center.x + kp->kobj_regular[1].center.x) * 0.5f;
    pos.y = (kp->kobj_regular[0].center.y + kp->kobj_regular[1].center.y) * 0.5f;

    f1 = kp->sec_nrm.x * kp->sec_nrm_hori.x + kp->sec_nrm.y * kp->sec_nrm_hori.y;
    f2 = -kp->sec_nrm.y * kp->sec_nrm_hori.x + kp->sec_nrm.x * kp->sec_nrm_hori.y;
    vec.x = f1 * pos.x - f2 * pos.y;
    vec.y = f2 * pos.x + f1 * pos.y;

    vec.x = (kp->center_org.x - vec.x) * kp->dpd2pos_scale;
    vec.y = (kp->center_org.y - vec.y) * kp->dpd2pos_scale;

    pos.x = -kp->accXY_nrm_hori.y * vec.x + kp->accXY_nrm_hori.x * vec.y;
    pos.y = -kp->accXY_nrm_hori.x * vec.x - kp->accXY_nrm_hori.y * vec.y;
    if (sp->dpd_valid_fg == 0) {
        sp->pos = pos;
        sp->vec = Vec2_0;
        sp->speed = 0.0f;
    } else {
        vec.x = pos.x - sp->pos.x;
        vec.y = pos.y - sp->pos.y;
        f1 = sqrt(vec.x * vec.x + vec.y * vec.y);

        if (f1 >= kp->pos_play_radius) {
            f4 = 1.0f;
        } else {
            f4 = f1 / kp->pos_play_radius;
            f4 *= f4;
            f4 *= f4;
        }
        f4 *= kp->pos_sensitivity;

        sp->vec.x = f4 * vec.x;
        sp->vec.y = f4 * vec.y;
        sp->speed = sqrt(sp->vec.x * sp->vec.x + sp->vec.y * sp->vec.y);

        sp->pos.x += sp->vec.x;
        sp->pos.y += sp->vec.y;
    }

    sp->dpd_valid_fg = valid_fg_next;
}

static inline void calc_obj_horizon(KPADInsideStatus* kp) {
    f32 vx, vy, f1;

    vx = kp->kobj_regular[1].center.x - kp->kobj_regular[0].center.x;
    vy = kp->kobj_regular[1].center.y - kp->kobj_regular[0].center.y;
    kp->sec_length = sqrt(vx * vx + vy * vy);

    f1 = 1.0f / kp->sec_length;
    vx *= f1;
    vy *= f1;
    kp->sec_dist = kp->dist_vv1 * f1;

    kp->sec_nrm.x = vx;
    kp->sec_nrm.y = vy;

    kp->obj_horizon.x = kp->sec_nrm_hori.x * vx + kp->sec_nrm_hori.y * vy;
    kp->obj_horizon.y = kp->sec_nrm_hori.y * vx - kp->sec_nrm_hori.x * vy;
}

static inline void check_kobj_outside_frame(KPADInsideStatus* kp, KPADObject* kobj_t) {
    KPADObject* kobj_p = &kobj_t[WPAD_MAX_DPD_OBJECTS - 1];

    do {
        if (kobj_p->error_fg < 0) {
            continue;
        }

        if (kobj_p->center.x <= kp->kobj_frame_min.x || kobj_p->center.x >= kp->kobj_frame_max.x ||
            kobj_p->center.y <= kp->kobj_frame_min.y || kobj_p->center.y >= kp->kobj_frame_max.y) {
            kobj_p->error_fg |= 1;
        }
    } while (--kobj_p >= kobj_t);
}

static inline void check_kobj_same_position(KPADObject* kobj_t) {
    KPADObject *op1, *op2;

    op1 = kobj_t;
    do {
        if (op1->error_fg != 0) {
            continue;
        }

        op2 = op1 + 1;
        do {
            if (op2->error_fg != 0) {
                continue;
            }

            if (op1->center.x == op2->center.x && op1->center.y == op2->center.y) {
                op2->error_fg |= 2;
            }
        } while (++op2 <= &kobj_t[WPAD_MAX_DPD_OBJECTS - 1]);
    } while (++op1 < &kobj_t[WPAD_MAX_DPD_OBJECTS - 1]);
}

static void read_kpad_dpd(KPADInsideStatus* kp, KPADUnifiedWpadStatus* uwp) {
    KPADStatus* sp = &kp->status;
    KPADObject* op1;
    s8 valid_fg_next;

    if (uwp->fmt == WPAD_FMT_CORE_BTN_ACC_DPD || uwp->fmt == WPAD_FMT_FS_BTN_ACC_DPD ||
        uwp->fmt == WPAD_FMT_CLASSIC_BTN_ACC_DPD) {
        get_kobj(kp, uwp);
    } else {
        op1 = &kp->kobj_sample[WPAD_MAX_DPD_OBJECTS - 1];
        do {
            op1->error_fg = -1;
        } while (--op1 >= kp->kobj_sample);
    }

    check_kobj_outside_frame(kp, kp->kobj_sample);
    check_kobj_same_position(kp->kobj_sample);

    kp->valid_objs = 0;
    op1 = &kp->kobj_sample[WPAD_MAX_DPD_OBJECTS - 1];
    do {
        if (op1->error_fg == 0) {
            ++kp->valid_objs;
        }
    } while (--op1 >= kp->kobj_sample);

    if (!(sp->acc_vertical.x <= kp_err_up_inpr)) {
        if (kp->status.dpd_valid_fg == 2 || kp->status.dpd_valid_fg == -2) {
            if (kp->valid_objs >= 2) {
                valid_fg_next = select_2obj_continue(kp);
                if (valid_fg_next) {
                    goto LABEL_select_OK;
                }
            }
            if (kp->valid_objs >= 1) {
                valid_fg_next = select_1obj_continue(kp);
                if (valid_fg_next) {
                    goto LABEL_select_OK;
                }
            }
        } else if (kp->status.dpd_valid_fg == 1 || kp->status.dpd_valid_fg == -1) {
            if (kp->valid_objs >= 2) {
                valid_fg_next = select_2obj_first(kp);
                if (valid_fg_next) {
                    goto LABEL_select_OK;
                }
            }
            if (kp->valid_objs >= 1) {
                valid_fg_next = select_1obj_continue(kp);
                if (valid_fg_next) {
                    goto LABEL_select_OK;
                }
            }
        } else {
            if (kp->valid_objs >= 2) {
                valid_fg_next = select_2obj_first(kp);
                if (valid_fg_next) {
                    goto LABEL_select_OK;
                }
            }
            if (kp->valid_objs == 1) {
                valid_fg_next = select_1obj_first(kp);
                if (valid_fg_next) {
                    goto LABEL_select_OK;
                }
            }
        }
    }

    valid_fg_next = 0;

LABEL_select_OK:
    if (valid_fg_next) {
        calc_obj_horizon(kp);
        if (kp->ah_circle_ct == 0) {
            if (kp->obj_horizon.x * kp->acc_horizon.x + kp->obj_horizon.y * kp->acc_horizon.y <= kp_err_acc_inpr) {
                valid_fg_next = 0;
                kp->kobj_regular[0].error_fg = kp->kobj_regular[1].error_fg = 1;
            }
        }

        if (sp->dpd_valid_fg == 2 && valid_fg_next == 2) {
            if (kp->dpd_valid2_ct == 200) {
                kp->trust_sec_length = kp->sec_length;
            } else {
                ++kp->dpd_valid2_ct;
            }
        } else {
            kp->dpd_valid2_ct = 0;
        }
    } else {
        kp->dpd_valid2_ct = 0;
    }

    calc_dpd_variable(kp, valid_fg_next);
}

static void clamp_stick_circle(Vec2* stick, s32 sx, s32 sy, s32 min, s32 max) {
    f32 length;
    f32 fx = (f32)sx;
    f32 fy = (f32)sy;
    f32 fmin = (f32)min;
    f32 fmax = (f32)max;

    length = sqrt(fx * fx + fy * fy);

    if (length <= fmin) {
        stick->x = stick->y = 0.0f;
    } else if (length >= fmax) {
        stick->x = fx / length;
        stick->y = fy / length;
    } else {
        length = (length - fmin) / (fmax - fmin) / length;
        stick->x = fx * length;
        stick->y = fy * length;
    }
}

static inline void clamp_trigger(f32* trigger, s32 tr, s32 min, s32 max) {
    if (tr <= min) {
        *trigger = 0.0f;
    } else if (tr >= max) {
        *trigger = 1.0f;
    } else {
        *trigger = (f32)(tr - min) / (f32)(max - min);
    }
}

static void clamp_stick_cross(Vec2* stick, s32 sx, s32 sy, s32 min, s32 max) {
    f32 length;

    if (sx < 0) {
        clamp_trigger(&stick->x, -sx, min, max);
        stick->x = -stick->x;
    } else {
        clamp_trigger(&stick->x, sx, min, max);
    }
    if (sy < 0) {
        clamp_trigger(&stick->y, -sy, min, max);
        stick->y = -stick->y;
    } else {
        clamp_trigger(&stick->y, sy, min, max);
    }

    length = stick->x * stick->x + stick->y * stick->y;
    if (length > 1.0f) {
        length = sqrt(length);
        stick->x /= length;
        stick->y /= length;
    }
}

static void read_kpad_stick(KPADInsideStatus* kp, KPADUnifiedWpadStatus* uwp) {
    void (*clamp_stick)(Vec2*, s32, s32, s32, s32) = clamp_stick_cross;
    KPADEXStatus* ep = &kp->status.ex_status;
    u8 dev;

    if (kp_stick_clamp_mode != 0) {
        clamp_stick = clamp_stick_circle;
    }

    dev = uwp->u.core.dev;
    if (dev == WPAD_DEV_FREESTYLE && KPAD_IN_RANGE(uwp->fmt, WPAD_FMT_FS_BTN, WPAD_FMT_FS_BTN_ACC_DPD)) {
        if (kp->ex_reset_req) {
            kp->ex_reset_req = FALSE;
            ep->fs.stick = Vec2_0;
            ep->fs.acc.x = ep->fs.acc.z = 0.0f;
            ep->fs.acc.y = -1.0f;
            ep->fs.acc_value = 1.0f;
            ep->fs.acc_speed = 0.0f;
        }

        clamp_stick(&ep->fs.stick, uwp->u.fs.fsStickX, uwp->u.fs.fsStickY, kp_fs_fstick_min, kp_fs_fstick_max);
    } else if (dev == WPAD_DEV_CLASSIC && KPAD_IN_RANGE(uwp->fmt, WPAD_FMT_CLASSIC_BTN, WPAD_FMT_CLASSIC_BTN_ACC_DPD)) {
        if (kp->ex_reset_req) {
            kp->ex_reset_req = FALSE;
            ep->cl.lstick = Vec2_0;
            ep->cl.rstick = Vec2_0;
            ep->cl.ltrigger = ep->cl.rtrigger = 0.0f;
            ep->cl.hold = ep->cl.trig = ep->cl.release = 0;
            kp->btn_cl_repeat_time = 0;
            kp->btn_cl_repeat_next = kp->btn_repeat_delay;
        }

        clamp_stick(&ep->cl.lstick, uwp->u.cl.clLStickX, uwp->u.cl.clLStickY, kp_cl_stick_min, kp_cl_stick_max);
        clamp_stick(&ep->cl.rstick, uwp->u.cl.clRStickX, uwp->u.cl.clRStickY, kp_cl_stick_min, kp_cl_stick_max);
        clamp_trigger(&ep->cl.ltrigger, uwp->u.cl.clTriggerL, kp_cl_trigger_min, kp_cl_trigger_max);
        clamp_trigger(&ep->cl.rtrigger, uwp->u.cl.clTriggerR, kp_cl_trigger_min, kp_cl_trigger_max);
    }
}

static inline u32 read_kpad_ring(KPADInsideStatus* kp, KPADStatus* bufs, u32 length, KPADUnifiedWpadStatus* last) {
    u32 count;
    s32 i;
    s32 idx;
    KPADStatus* sp;

    count = kp->wpad_ring_cnt;
    if (count > length) {
        count = length;
    }
    i = count;
    kp->wpad_ring_cnt -= count;
    sp = bufs + i;

    idx = kp->wpad_ring_idx - count;
    if (idx < 0) {
        idx += KPAD_RING_BUFS;
    }

    --sp;
    while (--i != 0) {
        --sp;
        *(KPADUnifiedWpadStatus*)sp = kp->wpad_ring_bf[idx];
        if (++idx >= KPAD_RING_BUFS) {
            idx = 0;
        }
    }
    *last = kp->wpad_ring_bf[idx];

    return count;
}

s32 KPADRead(s32 chan, KPADStatus* samplingBufs, u32 length) {
    KPADInsideStatus* kp = &inside_kpads[chan];
    u32 count = 0;
    BOOL enabled;
    s32 err;
    s32 idx;
    KPADStatus* sp;
    u32 i;
    KPADUnifiedWpadStatus* uwp;
    KPADUnifiedWpadStatus last;
    u32 hold, fsHold, clHold;
    u8 dev;
    u32 oldCl;
    u32 change;
    u32 old;

    enabled = OSDisableInterrupts();
    if (kp->reading) {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    kp->reading = TRUE;
    err = WPADProbe(chan, NULL);
    if (err == WPAD_ERR_NO_CONTROLLER && kp->dpd_ctrl_callback && kp->dpd_ctrl_started && !kp->dpd_ctrl_ended) {
        KPADiControlDpdCallback(chan, WPAD_ERR_NONE);
    }
    OSRestoreInterrupts(enabled);

    if (kp->reset_req) {
        kp->status.wpad_err = err;
        reset_kpad(kp);
    }

    WPADSetSamplingCallback(chan, KPADiSamplingCallback);

    if (kp->wpad_ring_cnt == 0 || samplingBufs == NULL || length == 0) {
        goto end;
    }

    enabled = OSDisableInterrupts();
    count = read_kpad_ring(kp, samplingBufs, length, &last);
    OSRestoreInterrupts(enabled);

    {
        WPADAccGravityUnit core1G = {1, 1, 1};
        WPADAccGravityUnit fs1G = {1, 1, 1};

        WPADGetAccGravityUnit(chan, WPAD_ACC_GRAVITY_UNIT_CORE, &core1G);
        if (core1G.x * core1G.y * core1G.z != 0) {
            kp->acc_scale.x = 1.0f / core1G.x;
            kp->acc_scale.y = 1.0f / core1G.y;
            kp->acc_scale.z = 1.0f / core1G.z;
        } else {
            kp->acc_scale.z = kp->acc_scale.y = kp->acc_scale.x = 0.01f;
        }

        WPADGetAccGravityUnit(chan, WPAD_ACC_GRAVITY_UNIT_FS, &fs1G);
        if (fs1G.x * fs1G.y * fs1G.z != 0) {
            kp->fs_acc_scale.x = 1.0f / fs1G.x;
            kp->fs_acc_scale.y = 1.0f / fs1G.y;
            kp->fs_acc_scale.z = 1.0f / fs1G.z;
        } else {
            kp->fs_acc_scale.z = kp->fs_acc_scale.y = kp->fs_acc_scale.x = 0.005f;
        }
    }

    hold = fsHold = clHold = 0xFFFF;
    dev = WPAD_DEV_NOT_FOUND;
    sp = samplingBufs + count;
    i = count;
    --sp;
    do {
        --sp;
        uwp = i > 1 ? (KPADUnifiedWpadStatus*)sp : &last;

        switch (uwp->u.core.err) {
        case WPAD_ERR_NONE:
            dev = uwp->u.core.dev;
            if (dev == WPAD_DEV_FREESTYLE) {
                fsHold = uwp->u.core.button;
                clHold = 0;
            } else if (dev == WPAD_DEV_CLASSIC) {
                clHold = uwp->u.cl.clButton;
                fsHold = 0;
            } else {
                clHold = 0;
                fsHold = 0;
            }
        case WPAD_ERR_BUSY:
        case WPAD_ERR_CORRUPTED:
            hold = uwp->u.core.button;
            break;
        }
    } while (--i != 0);

    if (hold == 0xFFFF) {
        do {
            memcpy(samplingBufs, &kp->status, sizeof(KPADStatus));
            samplingBufs++;
        } while (--count != 0);
        goto end;
    }

    if (fsHold == 0xFFFF) {
        fsHold = kp->status.hold;
    }
    if (clHold == 0xFFFF) {
        clHold = kp->status.ex_status.cl.hold;
    }

    old = kp->status.hold & KPAD_BUTTON_MASK;
    kp->status.hold = (hold & 0x9FFF) | (fsHold & 0x6000);
    change = kp->status.hold ^ old;
    kp->status.trig = change & kp->status.hold;
    kp->status.release = change & old;

    if (dev == WPAD_DEV_CLASSIC) {
        oldCl = kp->status.ex_status.cl.hold & KPAD_BUTTON_MASK;
        kp->status.ex_status.cl.hold = clHold & KPAD_BUTTON_MASK;
        change = kp->status.ex_status.cl.hold ^ oldCl;
        kp->status.ex_status.cl.trig = change & kp->status.ex_status.cl.hold;
        kp->status.ex_status.cl.release = change & oldCl;
    }

    calc_button_repeat(kp, dev, count);

    sp = samplingBufs + count;
    i = count;
    --sp;
    do {
        --sp;
        uwp = i > 1 ? (KPADUnifiedWpadStatus*)sp : &last;

        kp->status.wpad_err = uwp->u.core.err;
        if (kp->status.dev_type != uwp->u.core.dev &&
            KPAD_IN_RANGE(uwp->u.core.err, WPAD_ERR_BUSY, WPAD_ERR_NONE)) {
            kp->status.dev_type = uwp->u.core.dev;
            kp->ex_reset_req = TRUE;
        }
        kp->status.data_format = uwp->fmt;

        switch (uwp->u.core.err) {
        case WPAD_ERR_NONE:
            read_kpad_stick(kp, uwp);
        case WPAD_ERR_CORRUPTED:
            read_kpad_acc(kp, uwp);
            read_kpad_dpd(kp, uwp);
            break;
        default:
            kp->status.dpd_valid_fg = 0;
            break;
        }

        sp[1] = kp->status;
    } while (--i != 0);

end:
    kp->reading = FALSE;
    return count;
}

void KPADInit(void) {
    s32 i;
    u32 j;
    KPADInsideStatus* kp;

    WPADInit();
    while (WPADGetStatus() != WPAD_LIB_STATUS_3) {
    }

    memset(inside_kpads, 0, sizeof(inside_kpads));
    kp_err_dist_max = 1.0f + WPADGetDpdSensitivity();

    for (i = 0; i < WPAD_MAX_CONTROLLERS; i++) {
        kp = &inside_kpads[i];

        kp->dpd_enable = TRUE;
        kp->dpd_command = 0;
        kp->status.dev_type = WPAD_DEV_NOT_FOUND;
        kp->status.data_format = 0;

        kp->dist_org = idist_org;
        kp->accXY_nrm_hori = iaccXY_nrm_hori;
        kp->sec_nrm_hori = isec_nrm_hori;
        kp->center_org = icenter_org;

        calc_dpd2pos_scale(kp);

        kp->pos_play_radius = kp->hori_play_radius = kp->dist_play_radius = kp->acc_play_radius = 0.0f;
        kp->pos_sensitivity = kp->hori_sensitivity = kp->dist_sensitivity = kp->acc_sensitivity = 1.0f;

        kp->btn_repeat_delay = KPAD_BTN_NO_RPT_DELAY;
        kp->btn_repeat_pulse = 0;
        kp->btn_repeat_time = 0;
        kp->btn_repeat_next = KPAD_BTN_NO_RPT_DELAY;
        kp->btn_cl_repeat_time = 0;
        kp->btn_cl_repeat_next = KPAD_BTN_NO_RPT_DELAY;

        j = 0;
        do {
            kp->wpad_ring_bf[j].u.core.err = WPAD_ERR_NO_CONTROLLER;
        } while (++j < KPAD_RING_BUFS);
    }

    KPADSetObjInterval(kp_obj_interval);

    for (i = WPAD_MAX_CONTROLLERS - 1; i >= 0; i--) {
        WPADControlMotor(i, WPAD_MOTOR_STOP);
        inside_kpads[i].reset_req = TRUE;
    }

    OSRegisterVersion(__KPADVersion);
}

void KPADDisableDPD(s32 chan) {
    inside_kpads[chan].dpd_enable = FALSE;
}

void KPADEnableDPD(s32 chan) {
    inside_kpads[chan].dpd_enable = TRUE;
}

static void KPADiSamplingCallback(s32 chan) {
    KPADInsideStatus* kp = &inside_kpads[chan];
    u32 type;
    u8 ringIdx;
    u32 idx;
    u8 command;
    KPADUnifiedWpadStatus* uwp;
    static struct {
        u8 dpd;
        u8 fmt;
    } table[] = {
        {WPAD_DPD_DISABLE, WPAD_FMT_CORE_BTN_ACC},    {WPAD_DPD_STANDARD, WPAD_FMT_CORE_BTN_ACC_DPD},
        {WPAD_DPD_DISABLE, WPAD_FMT_FS_BTN_ACC},      {WPAD_DPD_BASIC, WPAD_FMT_FS_BTN_ACC_DPD},
        {WPAD_DPD_DISABLE, WPAD_FMT_CLASSIC_BTN_ACC}, {WPAD_DPD_BASIC, WPAD_FMT_CLASSIC_BTN_ACC_DPD},
    };

    if (WPADProbe(chan, &type) == WPAD_ERR_NONE) {
        ringIdx = kp->wpad_ring_idx;
        if (ringIdx >= KPAD_RING_BUFS) {
            ringIdx = 0;
        }

        uwp = &kp->wpad_ring_bf[ringIdx];
        WPADRead(chan, &uwp->u.core);
        uwp->fmt = WPADGetDataFormat(chan);
        kp->wpad_ring_idx = ringIdx + 1;
        if (kp->wpad_ring_cnt < KPAD_RING_BUFS) {
            kp->wpad_ring_cnt++;
        }

        switch ((s32)type) {
        case WPAD_DEV_CORE:
        case WPAD_DEV_FUTURE:
        case WPAD_DEV_NOT_SUPPORTED:
        case WPAD_DEV_UNKNOWN:
            idx = 0;
            break;
        case WPAD_DEV_FREESTYLE:
            idx = 2;
            break;
        case WPAD_DEV_CLASSIC:
            idx = 4;
            break;
        default:
            goto end;
        }

        if (kp->dpd_enable) {
            idx++;
        }

        command = WPADIsDpdEnabled(chan) ? kp->dpd_command : WPAD_DPD_DISABLE;

        if (command != table[idx].dpd) {
            if (kp->dpd_ctrl_callback && !kp->dpd_ctrl_started) {
                kp->dpd_ctrl_started = TRUE;
                kp->dpd_ctrl_callback(chan, 0);
                kp->dpd_ctrl_ended = FALSE;
            }

            if (!kp->dpd_ctrl_busy) {
                kp->dpd_ctrl_busy = TRUE;
                if (WPADControlDpd(chan, table[idx].dpd, KPADiControlDpdCallback) == WPAD_ERR_NONE) {
                    kp->dpd_command = table[idx].dpd;
                }
            }
        } else if (uwp->fmt != table[idx].fmt) {
            WPADSetDataFormat(chan, table[idx].fmt);
        }
    }

end:
    if (kp->sampling_callback) {
        kp->sampling_callback(chan);
    }
}

void KPADiControlDpdCallback(s32 chan, s32 result) {
    KPADInsideStatus* kp = &inside_kpads[chan];

    if (result == WPAD_ERR_NONE && kp->dpd_ctrl_callback && !kp->dpd_ctrl_ended) {
        kp->dpd_ctrl_ended = TRUE;
        kp->dpd_ctrl_callback(chan, 1);
        kp->dpd_ctrl_started = FALSE;
    }

    kp->dpd_ctrl_busy = FALSE;
}
