#include ".unsorted/80164CE8.hpp"

#include "common.hpp"

extern "C" {

void fn_80164CE8(u8 *arg0) {
    (*(s16 *)((u8 *)(arg0) + (0))) = 0;
    (*(s16 *)((u8 *)(arg0) + (2))) = 0;
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    (*(s32 *)((u8 *)(arg0) + (8))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x4C))) = 0;
}
}

extern "C" {

s32 fn_80163764(void);
s32 fn_8025DFD0(void);
s32 fn_8025E0A8(void);
s32 fn_8025E314(void);
s32 fn_80263960(void);
s32 fn_80263A70(void);

s32 fn_80164D04(void) {
    fn_8025DFD0();
    if (fn_8025E0A8() != 2) {
        return -1;
    }
    fn_8025DFD0();
    fn_8025E314();
    if (fn_80263960() <= 0) {
        return -1;
    }
    fn_8025DFD0();
    fn_8025E314();
    if (fn_80263A70() != 0) {
        return -2;
    }
    fn_80163764();
    return 0;
}
}

extern "C" {

s32 fn_80164D78(void) {
    fn_8025DFD0();
    return (fn_8025E0A8() - 2) == 0;
}
}

extern "C" {

s32 fn_80163794(void);
s32 fn_801638B4(void);
s32 fn_8025E30C(void);
s32 fn_80261ADC(void);
u32 fn_80263674(void);

s32 fn_80164DA8(void) {
    if ((fn_80163794() != 0) && (fn_801638B4() != 0)) {
        fn_8025DFD0();
        fn_8025E30C();
        fn_80261ADC();
        return 1;
    }
    fn_8025DFD0();
    fn_8025E314();
    if (fn_80263674() > 0x1EU) {
        fn_8025DFD0();
        fn_8025E30C();
        fn_80261ADC();
        return 1;
    }
    return 0;
}
}
