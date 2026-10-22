#include "gs/render/GSrenderPass.hpp"

extern "C" {

extern u8 *lbl_8063F700;
extern u8 *lbl_8063F704;

void fn_80236BF0(u8 *arg0) {
    if ((u8 *) lbl_8063F700 == NULL) {
        lbl_8063F700 = arg0;
    }
    if ((u8 *) lbl_8063F704 != NULL) {
        (*(u8 **)((u8 *)(lbl_8063F704) + (0xC))) = arg0;
    }
    lbl_8063F704 = arg0;
}
}

extern "C" {

extern s32 sActiveRenderPass__12GSrenderPass;

void fn_80236C88(s32 arg0) {
    sActiveRenderPass__12GSrenderPass = arg0;
}
}

extern "C" {

void fn_80236C90(void) {
    sActiveRenderPass__12GSrenderPass = 0;
}
}
