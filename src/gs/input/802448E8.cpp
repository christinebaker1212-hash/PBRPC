#include "common.hpp"
#include "gs/GSinput.hpp"


void GSinput::fn_802448E8(GSinputUnkStruct5 *param1) {
    param1->_8 = NULL;
    param1->_C = NULL;
    param1->_0 = 0f;
    param1->_5 = false;
}

void GSinput::fn_80244904(GSinputUnkStruct5 *param1, f32 param2) {
    param1->_5 = false;

    if (param1->_C == NULL) {
        return;
    }

    if (param1->_0 > 0f) {
        param1->_0 -= param2;
    }

    if (param1->_0 <= 0) {
        switch ((param1->_C->_0 & 0xf0)) {
            case 0:
                param1->_4 = param1->_C->_0 & 0x3;
                param1->_0 = ((param1->_C->_1 << 8) | param1->_C->_2) / 4096f;
                param1->_C++;
                break;

            case 0x10: param1->_C = param1->_8; break;

            case 0x20:
                param1->_4 = 0;
                param1->_C = NULL;
                break;

            default:
                param1->_4 = 0;
                param1->_C = NULL;
                break;
        }

        param1->_5 = true;
    }
}

extern "C" {

struct S_lbl_80627AA8 { s8 f_0; u8 pad_1[1]; s16 f_2; s8 f_4; };
extern struct S_lbl_80627AA8 lbl_80627AA8;

void fn_802449F8() {
    lbl_80627AA8.f_0 = 1;
    lbl_80627AA8.f_2 = 4;
    lbl_80627AA8.f_4 = 0;
}
}
