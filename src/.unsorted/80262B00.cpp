#include ".unsorted/80262B00.hpp"

#include "common.hpp"

extern "C" {

void fn_8025B6E8();

void fn_80262B00(void) {
    fn_8025B6E8();
}
}

extern "C" {

s32 fn_8025B6EC(s32, s32 *);
s32 fn_8025B720(s32 *);
s32 fn_8025B7F0(s32 *);
void fn_80262B48(void);
void fn_80262BDC(void);
void fn_80262D68(void);

void fn_80262B04() {
    fn_8025B720((s32 *)(&fn_80262B48));
    fn_8025B6EC((s32)(4), (s32 *)(&fn_80262BDC));
    fn_8025B7F0((s32 *)(&fn_80262D68));
}
}
