#include "common.hpp"

extern "C" {

struct S_lbl_80627650 { s8 f_0; u8 pad_1[1]; s16 f_2; s8 f_4; };
extern struct S_lbl_80627650 lbl_80627650;

void fn_801E07C8() {
    lbl_80627650.f_0 = 1;
    lbl_80627650.f_2 = 4;
    lbl_80627650.f_4 = 0;
}
}
