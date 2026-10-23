#include ".unsorted/80211A04.hpp"

#include "common.hpp"

extern "C" {

f32 fn_80211AF8(f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    f32 temp_f7;
    f32 temp_f8;
    f32 temp_f9;

    temp_f7 = farg0 * farg0;
    temp_f8 = (1.0f) - farg0;
    temp_f9 = temp_f8 * temp_f8;
    return (farg4 * (temp_f7 * farg0)) + ((farg3 * ((3.0f) * temp_f7 * temp_f8)) + ((farg1 * (temp_f9 * temp_f8)) + (farg2 * ((3.0f) * farg0 * temp_f9))));
}
}
