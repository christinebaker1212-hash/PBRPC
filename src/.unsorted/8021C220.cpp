#include ".unsorted/8021C220.hpp"

#include "common.hpp"

extern "C" {

void fn_8021C58C();

void fn_8021C220(void) {
    fn_8021C58C();
}
s32 fn_8021CA78(void) {
    return 2;
}
}

extern "C" {

s32 fn_8021C75C(void);
s32 fn_8021CA78(void);
extern u8 lbl_8063F52E;

void fn_8021C224(void) {
    if ((s32) lbl_8063F52E != 0) {
        fn_8021CA78();
        fn_8021C75C();
    }
}
}

extern "C" {

s32 allocAndClear__5GSmemFUl(s32);
void fn_8021C254();
s32 fn_8021C274(s32);
s32 fn_8021C388(void);
extern u8 lbl_8063F52F;
extern s16 lbl_8063F536;
extern s32 lbl_8063F538;

s32 fn_8021C274(s32 arg0) {
    s32 temp_r3;

    lbl_8063F52E = 0;
    fn_8021C388();
    if ((s32) lbl_8063F52F == 0) {
        fn_8021C254();
        lbl_8063F52F = 1;
    }
    temp_r3 = allocAndClear__5GSmemFUl((arg0 * 4) & 0x3FFFC);
    lbl_8063F538 = temp_r3;
    if (temp_r3 == 0) {
        lbl_8063F536 = 0;
        return 0;
    }
    lbl_8063F536 = (s16) arg0;
    return 1;
}
}

extern "C" {

s32 fn_8023EB58(s32, s32 *, s32 *, s32, s32);
extern s32 lbl_8063F778;

void fn_8021C254() {
    fn_8023EB58((s32)(lbl_8063F778), (s32 *)(&fn_8021C220), (s32 *)(&fn_8021C224), (s32)(2), (s32)(8));
}
}

extern "C" {

s32 alloc__5GSmemFUl(s32);
s32 fn_80219E48(s32);
s32 fn_8021A254(s32, s32);
s32 free__5GSmemFPv(s32);

s32 fn_8021C2EC(u32 arg0, s32 arg1) {
    s32 temp_r31;
    s32 temp_r3;
    s32 temp_r3_2;

    if (arg0 >= (u16) (*(u16 (*))&lbl_8063F536)) {
        return 0;
    }
    temp_r31 = (arg0 * 4) & 0x3FFFC;
    temp_r3 = *(s32 *)((u8 *)0 + (lbl_8063F538 + temp_r31));
    if (temp_r3 != 0) {
        free__5GSmemFPv(temp_r3);
    }
    *(s32 *)((u8 *)0 + (lbl_8063F538 + temp_r31)) = alloc__5GSmemFUl(0xD64);
    temp_r3_2 = *(s32 *)((u8 *)0 + (lbl_8063F538 + temp_r31));
    if (temp_r3_2 == 0) {
        return 0;
    }
    fn_80219E48(temp_r3_2);
    fn_8021A254(*(s32 *)((u8 *)0 + (lbl_8063F538 + temp_r31)), arg1);
    return 1;
}
}

extern "C" {

s32 fn_8021AA88(s32, s32, f32);

void fn_8021C428(u32 arg0, s32 arg1, f32 farg0) {
    s32 temp_r3;

    if (arg0 < (u16) (*(u16 (*))&lbl_8063F536)) {
        temp_r3 = *(s32 *)((u8 *)0 + (lbl_8063F538 + ((arg0 * 4) & 0x3FFFC)));
        if (temp_r3 != 0) {
            fn_8021AA88(temp_r3, arg1, farg0);
        }
    }
}
}

extern "C" {

s32 fn_80219FBC(s32);

void fn_8021C478(u32 arg0) {
    s32 temp_r31;
    s32 temp_r3;

    if (arg0 < (u16) (*(u16 (*))&lbl_8063F536)) {
        temp_r31 = (arg0 * 4) & 0x3FFFC;
        temp_r3 = *(s32 *)((u8 *)0 + (lbl_8063F538 + temp_r31));
        if (temp_r3 != 0) {
            fn_80219FBC(temp_r3);
            free__5GSmemFPv((s32)(*(s32 *)((u8 *)0 + (lbl_8063F538 + temp_r31))));
            *(s32 *)((u8 *)0 + (lbl_8063F538 + temp_r31)) = 0;
        }
    }
}
}

extern "C" {

s32 fn_8021BBE4(s32, s32, s32);

s32 fn_8021C52C(u32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;

    if (arg0 >= (u16) (*(u16 (*))&lbl_8063F536)) {
        return -1;
    }
    temp_r3 = *(s32 *)((u8 *)0 + (lbl_8063F538 + ((arg0 * 4) & 0x3FFFC)));
    if (temp_r3 == 0) {
        return -1;
    }
    return fn_8021BBE4(temp_r3, lbl_8063F538, arg2);
}
}

extern "C" {

s32 fn_8021BE4C(s32, s32, s32);

void fn_8021C564(u32 arg0, s32 arg1) {
    s32 temp_r3;

    if (arg0 < (u16) (*(u16 (*))&lbl_8063F536)) {
        temp_r3 = *(s32 *)((u8 *)0 + (lbl_8063F538 + ((arg0 * 4) & 0x3FFFC)));
        if (temp_r3 != 0) {
            fn_8021BE4C(temp_r3, arg1, lbl_8063F538);
        }
    }
}
}
