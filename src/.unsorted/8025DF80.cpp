#include ".unsorted/8025DF80.hpp"

#include ".unsorted/8025E348.hpp"

#include "common.hpp"

extern "C" {

void fn_8025E370();

Unk8025DF80 *fn_8025DFD0(void) {
    return lbl_8063F998;
}
u32 fn_8025E0A8(Unk8025DF80 *obj) {
    return obj->_04;
}
void fn_8025E120(void) {}
void fn_8025E154(void) {}
void fn_8025E188(void) {}
u32 fn_8025E304(Unk8025DF80 *obj) {
    return obj->_14;
}
u32 fn_8025E30C(Unk8025DF80 *obj) {
    return obj->_08;
}
u32 fn_8025E314(Unk8025DF80 *obj) {
    return obj->_0C;
}
u8 *fn_8025E31C(Unk8025DF80 *obj) {
    return obj->_10;
}
void fn_8025E324(void) {
    fn_8025E370();
}
}

#include "common.hpp"

extern "C" {

void fn_8025DFC0(u32, u32 a) {
    fn_8025E474(a);
}
void fn_8025DFC8(u32, void *block) {
    fn_8025E4D0(block);
}
}

extern "C" {

s32 fn_8025E2B8(u8 *arg0) {
    s32 temp_r0;

    temp_r0 = (*(s32 *)((u8 *)(arg0) + (4)));
    switch (temp_r0) {                              /* irregular */
    case 1:
        return (*(s32 *)((u8 *)(arg0) + (8)));
    case 2:
        return (*(s32 *)((u8 *)(arg0) + (0xC)));
    case 3:
        return (*(s32 *)((u8 *)(arg0) + (0x10)));
    default:
    case 0:
        return 0;
    }
}
}
