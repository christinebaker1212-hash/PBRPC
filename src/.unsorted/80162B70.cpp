#include ".unsorted/80162B70.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_8063D5BC;
extern u8 lbl_8063D5B8;
void fn_80162EDC();

void fn_80162B88(void) {}
void fn_80162B8C(void) {}
void fn_80162C70(u32 v) {
    lbl_8063D5BC = v;
}
void fn_80162F14(void) {
    fn_80162EDC();
}
void fn_80162F18(void) {
    fn_80162EDC();
}
void fn_80162F1C(void) {
    fn_80162EDC();
}
u8 fn_801633E4(void) {
    return lbl_8063D5B8;
}
}

extern "C" {

extern s32 lbl_8063F048;
extern s32 lbl_8063F050;

s32 fn_80162B70(void) {
    if ((s32) lbl_8063F050 != 0) {
        return lbl_8063F050;
    }
    return lbl_8063F048;
}
}

extern "C" {

extern s32 lbl_8063F054;
extern s32 lbl_8063F058;

void fn_80162C64(s32 arg0, s32 arg1) {
    lbl_8063F054 = arg0;
    lbl_8063F058 = arg1;
}
}

extern "C" {

extern s32 lbl_8063D5D4;
extern s32 lbl_8063D5D8;

void fn_80162D6C(s32 arg0, s32 arg1) {
    lbl_8063D5D8 = arg0;
    lbl_8063D5D4 = arg1;
}
}

extern "C" {

s32 fn_80163674(void);

void fn_80162FD4(void) {
    fn_80163674();
    lbl_8063F048 = 0;
    lbl_8063F050 = 0;
}
}

extern "C" {

s32 fn_80009838(void);

void fn_80163098(void) {
    if (fn_80009838() == 0) {
        fn_80163674();
        lbl_8063F048 = 3;
    }
}
}

extern "C" {

void fn_80163134(void) {
    fn_80163674();
    lbl_8063F048 = 5;
}
}
