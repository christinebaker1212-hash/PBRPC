#include "common.hpp"

extern "C" {

struct S_lbl_8063F680 { s8 f_0; u8 pad_1[1]; s16 f_2; s8 f_4; };
extern struct S_lbl_8063F680 lbl_8063F680;

void fn_80235454() {
    lbl_8063F680.f_0 = 1;
    lbl_8063F680.f_2 = 4;
    lbl_8063F680.f_4 = 0;
}
}
