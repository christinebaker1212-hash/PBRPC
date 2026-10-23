#include ".unsorted/801166F8.hpp"

#include "common.hpp"

extern "C" {

void fn_80116708(void) {}
void fn_80116DC4(void) {}
void fn_8011838C(void) {}
}

#include "common.hpp"

extern "C" {

extern u8 lbl_8041B894[];

void fn_801166F8(u8 *p) {
    *(u8 **)(p + 0x0) = lbl_8041B894;
}
}

extern "C" {

extern u8 *lbl_8063D544;

void fn_80116344(void) {
    (*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) = (u16) ((*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) & 0xFFFFFDFF);
}
}

extern "C" {

void fn_80116358(void) {
    (*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) = (u16) ((*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) | 0x200);
}
}

extern "C" {

s32 fn_80117FDC(u8 *, s32);
s32 fn_80118070(u8 *, s32);
s32 fn_80118CDC(u8 *, s32);

void fn_801163C8(void) {
    fn_80118070(lbl_8063D544, 0);
    fn_80117FDC(lbl_8063D544, 4);
    fn_80118CDC(lbl_8063D544, 0);
    (*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) = (u16) ((*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) | 0x1000);
    (*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) = (u16) ((*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) | 0x800);
    (*(s16 *)((u8 *)(lbl_8063D544) + (0x20E))) = 0;
}
}

extern "C" {

void fn_801164A0(void) {
    fn_80118070(lbl_8063D544, 0);
    fn_80117FDC(lbl_8063D544, 7);
    fn_80118CDC(lbl_8063D544, 0);
    (*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) = (u16) ((*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) | 0x1000);
    (*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) = (u16) ((*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) | 0x800);
    (*(s16 *)((u8 *)(lbl_8063D544) + (0x20E))) = 0;
    (*(s32 *)((u8 *)(lbl_8063D544) + (0xDC))) = 0x281;
}
}

extern "C" {

void fn_80116684(void) {

}
}

extern "C" {

void fn_801166A4(s32 arg0, s32 arg1, s32 arg2);      /* extern */
s32 fn_801172A4(u8 *, s32);               /* extern */
s32 fn_80253DB0(s16, s32, s32);         /* extern */
s32 fn_80253E4C(s16, s32, s32 *);           /* extern */

s32 fn_80118070(u8 *arg0, s32 arg1) {
    s32 sp8;

    if (arg1 != 0) {
        fn_80253E4C((*(s16 *)((u8 *)(lbl_8063D544) + (0x92))), 8, &sp8);
        if (sp8 == 0) {
            fn_801166A4((s32)(lbl_8063D544), (s32)(7), (s32)(1));
            fn_80253DB0((*(s16 *)((u8 *)(lbl_8063D544) + (0x92))), 4, 0);
        }
        fn_80253E4C((*(s16 *)((u8 *)(lbl_8063D544) + (0x96))), 8, &sp8);
        if (sp8 == 0) {
            fn_801166A4((s32)(lbl_8063D544), (s32)(9), (s32)(1));
            fn_80253DB0((*(s16 *)((u8 *)(lbl_8063D544) + (0x96))), 2, 0);
        }
    }
    (*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) = (u16) ((*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) | 0x8000);
    return fn_801172A4(lbl_8063D544, 1);
}
}

extern "C" {

s32 fn_8000A72C(s32, s32);
s32 fn_8000A734(void);
s32 fn_8011636C(s32);

s32 fn_8011636C(s32 arg0) {
    return fn_8000A72C(fn_8000A734(), arg0);
}
}

extern "C" {

s32 fn_801163A0(s32);

s32 fn_801163A0(s32 arg0) {
    return fn_8000A72C((s32)(fn_8000A734()), (s32)(0));
}
}

extern "C" {

s32 fn_80116688(s32, s32, s32);

s32 fn_80116688(s32 arg0, s32 arg1, s32 arg2) {
    return fn_80253DB0((s16)((s32) (*(s16 *)((u8 *)((lbl_8063D544 + (arg1 * 2))) + (0x84)))), (s32)(arg2), (s32)(0));
}
}

extern "C" {

s32 fn_80117630(s32, s32);
s32 fn_80253E8C(s32, s32, s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);

s32 fn_80117630(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;

    temp_r3 = fn_80253E8C(arg0, arg1, 3, (s32) &sp8);
    if (sp8 != 0xE) {
        if (sp8 < 0xE) {
            if (sp8 != 0xB) {
                return temp_r3;
            }
            goto block_6;
        }
        if (sp8 != 0x11) {
            return temp_r3;
        }
        goto block_6;
    }
block_6:
    return fn_80253EB4(arg0, arg1, 1, 0);
}
}

extern "C" {

s32 fn_80118790(s32, s32);

s32 fn_80118790(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;

    temp_r3 = fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    if (sp8 != 0xE) {
        if (sp8 < 0xE) {
            if (sp8 != 0xB) {
                return temp_r3;
            }
            goto block_6;
        }
        if (sp8 != 0x11) {
            return temp_r3;
        }
        goto block_6;
    }
block_6:
    return fn_80253EB4(arg0, arg1, 1, 0);
}
}

extern "C" {

s32 fn_80253DF0(s32, s32, s32);

void fn_801166A4(s32 arg0, s32 arg1, s32 arg2) {
    fn_80253DF0((s32) (*(s16 *)((u8 *)((lbl_8063D544 + ((arg1 * 2) & 0x1FFFE))) + (0x84))), 8, arg2);
}
}

extern "C" {

s32 fn_8015C308(s32, s32);
s32 fn_802502F4(s32);

void fn_80116518() {
    s32 temp_r4;
    s32 var_r31;
    s32 var_r3;
    u8 temp_r0;
    u8 *temp_r5;

    var_r3 = 0;
    var_r31 = 0;
    temp_r5 = (*(u8 **)((u8 *)(lbl_8063D544) + (0xD8)));
    temp_r4 = (*(s32 *)((u8 *)(temp_r5) + (0x585FC)));
    switch (temp_r4) {                              /* switch 1 */
    case 0x3E8:                                     /* switch 1 */
        var_r3 = 0x29C6;
        break;
    case 0x3E9:                                     /* switch 1 */
        var_r3 = 0x29C7;
        break;
    case 0x3EA:                                     /* switch 1 */
        var_r3 = 0x29C8;
        break;
    case 0x3EB:                                     /* switch 1 */
        var_r3 = 0x29C9;
        break;
    case 0x3EC:                                     /* switch 1 */
        var_r3 = 0x29CA;
        break;
    case 0x3ED:                                     /* switch 1 */
        var_r3 = 0x29CB;
        break;
    case 0x3EE:                                     /* switch 1 */
        var_r3 = 0x29CC;
        break;
    case 0x3EF:                                     /* switch 1 */
        var_r3 = 0x29CE;
        break;
    case 0x3F0:                                     /* switch 1 */
        var_r3 = 0x29CD;
        break;
    case 0x3F1:                                     /* switch 1 */
        var_r3 = 0x29CF;
        break;
    }
    temp_r0 = (*(u8 *)((u8 *)(temp_r5) + (0x58600)));
    switch (temp_r0) {                              /* switch 2 */
    case 0:                                         /* switch 2 */
        var_r31 = 0x29E6;
        break;
    case 1:                                         /* switch 2 */
        var_r31 = 0x29E7;
        break;
    case 2:                                         /* switch 2 */
        var_r31 = 0x29E8;
        break;
    case 3:                                         /* switch 2 */
        var_r31 = 0x29E9;
        break;
    case 4:                                         /* switch 2 */
        var_r31 = 0x29EA;
        break;
    case 5:                                         /* switch 2 */
        var_r31 = 0x29EB;
        break;
    case 6:                                         /* switch 2 */
        var_r31 = 0x29EC;
        break;
    case 7:                                         /* switch 2 */
        var_r31 = 0x29ED;
        break;
    case 8:                                         /* switch 2 */
        var_r31 = 0x29EE;
        break;
    case 9:                                         /* switch 2 */
        var_r31 = 0x29EF;
        break;
    case 10:                                        /* switch 2 */
        var_r31 = 0x29F0;
        break;
    case 11:                                        /* switch 2 */
        var_r31 = 0x29F1;
        break;
    case 12:                                        /* switch 2 */
        var_r31 = 0x29F2;
        break;
    case 13:                                        /* switch 2 */
        var_r31 = 0x29F3;
        break;
    case 14:                                        /* switch 2 */
    case 15:                                        /* switch 2 */
    case 16:                                        /* switch 2 */
    case 17:                                        /* switch 2 */
    case 18:                                        /* switch 2 */
    case 19:                                        /* switch 2 */
    case 20:                                        /* switch 2 */
        var_r31 = 0;
        break;
    }
    fn_8015C308(0xE, fn_802502F4(var_r3));
    fn_8015C308(0xF, fn_802502F4(var_r31));
}
}

extern "C" {

s32 fn_8015F748(void);

void fn_8011986C(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;
    s32 var_r31;

    fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* switch 1 */
    case 5:                                         /* switch 1 */
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2F09));
        return;
    case 9:                                         /* switch 1 */
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2F2D));
        return;
    case 8:                                         /* switch 1 */
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2F2E));
        return;
    case 7:                                         /* switch 1 */
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2F2F));
        return;
    case 3:                                         /* switch 1 */
        var_r31 = 0;
        temp_r3 = fn_8015F748();
        switch (temp_r3) {                          /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            var_r31 = 0x2F29;
            break;
        case 1:                                     /* switch 2 */
            var_r31 = 0x2F2A;
            break;
        case 2:                                     /* switch 2 */
            var_r31 = 0x2F2B;
            break;
        case 3:                                     /* switch 2 */
            var_r31 = 0x2F2C;
            break;
        }
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(var_r31));
        /* fallthrough */
    default:                                        /* switch 1 */
        return;
    }
}
}

extern "C" {

void fn_80119B68(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;
    s32 var_r31;

    fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* switch 1 */
    case 5:                                         /* switch 1 */
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x522E));
        return;
    case 9:                                         /* switch 1 */
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2F2D));
        return;
    case 8:                                         /* switch 1 */
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2F2E));
        return;
    case 7:                                         /* switch 1 */
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2F2F));
        return;
    case 3:                                         /* switch 1 */
        var_r31 = 0;
        temp_r3 = fn_8015F748();
        switch (temp_r3) {                          /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            var_r31 = 0x2F29;
            break;
        case 1:                                     /* switch 2 */
            var_r31 = 0x2F2A;
            break;
        case 2:                                     /* switch 2 */
            var_r31 = 0x2F2B;
            break;
        case 3:                                     /* switch 2 */
            var_r31 = 0x2F2C;
            break;
        }
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(var_r31));
        /* fallthrough */
    default:                                        /* switch 1 */
        return;
    }
}
}

extern "C" {

void fn_80119C98(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;
    s32 var_r31;

    fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* switch 1 */
    case 5:                                         /* switch 1 */
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2F05));
        return;
    case 9:                                         /* switch 1 */
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2F2D));
        return;
    case 8:                                         /* switch 1 */
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2F2E));
        return;
    case 7:                                         /* switch 1 */
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2F2F));
        return;
    case 3:                                         /* switch 1 */
        var_r31 = 0;
        temp_r3 = fn_8015F748();
        switch (temp_r3) {                          /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            var_r31 = 0x2F29;
            break;
        case 1:                                     /* switch 2 */
            var_r31 = 0x2F2A;
            break;
        case 2:                                     /* switch 2 */
            var_r31 = 0x2F2B;
            break;
        case 3:                                     /* switch 2 */
            var_r31 = 0x2F2C;
            break;
        }
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(var_r31));
        /* fallthrough */
    default:                                        /* switch 1 */
        return;
    }
}
}

extern "C" {

void fn_80119F94(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r0_2;
    s32 temp_r0_4;
    u16 temp_r0;
    u16 temp_r0_3;

    fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* switch 1 */
    case 11:                                        /* switch 1 */
    case 14:                                        /* switch 1 */
    case 17:                                        /* switch 1 */
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(1), (s32)(0));
        return;
    case 7:                                         /* switch 1 */
        temp_r0 = (*(u16 *)((u8 *)(lbl_8063D544) + (0x20E)));
        switch ((s32) temp_r0) {                    /* switch 2; irregular */
        case 0x45D9:                                /* switch 2 */
            fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x45DA));
            return;
        case 0x45DF:                                /* switch 2 */
            fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x45E1));
            return;
        case 0x462D:                                /* switch 2 */
            fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x462E));
            return;
        case 0x5267:                                /* switch 2 */
        case 0x4630:                                /* switch 2 */
            fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x4631));
            return;
        case 0x5056:                                /* switch 2 */
            fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x5057));
            return;
        case 0x0:                                   /* switch 2 */
            temp_r0_2 = (*(s32 *)((u8 *)(lbl_8063D544) + (0x118)));
            switch (temp_r0_2) {                    /* switch 3; irregular */
            case 0x4639:                            /* switch 3 */
                fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x463A));
                return;
            case 0x4706:                            /* switch 3 */
                fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x463D));
                return;
            }
            break;
        }
        break;
    case 10:                                        /* switch 1 */
        temp_r0_3 = (*(u16 *)((u8 *)(lbl_8063D544) + (0x20E)));
        switch ((s32) temp_r0_3) {                  /* switch 4; irregular */
        case 0x45D9:                                /* switch 4 */
            fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x45DB));
            return;
        case 0x45DF:                                /* switch 4 */
            fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x45E2));
            return;
        case 0x462D:                                /* switch 4 */
            fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x462F));
            return;
        case 0x5267:                                /* switch 4 */
        case 0x4630:                                /* switch 4 */
            fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x4632));
            return;
        case 0x5056:                                /* switch 4 */
            fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x5058));
            return;
        case 0x0:                                   /* switch 4 */
            temp_r0_4 = (*(s32 *)((u8 *)(lbl_8063D544) + (0x118)));
            switch (temp_r0_4) {                    /* switch 5; irregular */
            case 0x4639:                            /* switch 5 */
                fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x463B));
                return;
            case 0x4706:                            /* switch 5 */
                fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x463E));
                break;
            }
            break;
        }
        break;
    }
}
}

extern "C" {

void fn_8011A2F0(s32 arg0, s32 arg1) {
    s32 sp8;

    fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {
    case 6:
    case 7:
    case 9:
    case 10:
    case 12:
    case 13:
    case 15:
    case 16:
    case 17:
        break;
    case 5:
    case 8:
    case 11:
    case 14:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(1), (s32)(0));
        break;
    }
}
}

extern "C" {

s32 fn_8005A9F8(s32);

void fn_80118138(s32 arg0, s32 arg1) {
    s32 sp8;

    fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {
    case 1:
        if (!(((u16) (*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) >> 8U) & 1)) {
            fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(1), (s32)(fn_8005A9F8(0x1A)));
        }
    }
    return;
}
}

extern "C" {

s32 fn_80059A3C(s32, s32);
s32 fn_80253EDC(s32, s32, s32, s32);

void fn_801181B4(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC(arg0, arg1, 3, (s32) &sp8);
    switch (sp8) {
    case 0:
        fn_80253EDC(arg0, arg1, 6, (s32) sp10);
        fn_80059A3C(0x63, (s32) sp10);
    }
    return;
}
}

extern "C" {

void fn_801182EC(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* irregular */
    case 0:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(7), (s32)((s32) sp10));
        return;
    case 1:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(8), (s32)((s32) sp10));
        return;
    }
}
}

extern "C" {

void fn_8011A250(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* irregular */
    case 1:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(1), (s32)((s32) sp10));
        return;
    case 2:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(2), (s32)((s32) sp10));
        return;
    }
}
}
