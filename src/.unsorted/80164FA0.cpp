#include ".unsorted/80164FA0.hpp"

#include "common.hpp"

extern "C" {

s32 fn_80164FA0(void);
s32 fn_8025DFD0(void);
s32 fn_8025E31C(void);
s32 fn_802644F0__Q25gsapi11WiFiNetworkFv(void);

s32 fn_80165070(void) {
    if (fn_80164FA0() != 0) {
        fn_8025DFD0();
        fn_8025E31C();
        return fn_802644F0__Q25gsapi11WiFiNetworkFv();
    }
    return 0;
}
}

extern "C" {

s32 fn_802648FC__Q25gsapi11WiFiNetworkFv(void);

void fn_80165110(void) {
    fn_8025DFD0();
    fn_8025E31C();
    fn_802648FC__Q25gsapi11WiFiNetworkFv();
}
}

extern "C" {

s32 fn_802645EC__Q25gsapi11WiFiNetworkFv(void);

s32 fn_80165138(void) {
    fn_8025DFD0();
    fn_8025E31C();
    return fn_802645EC__Q25gsapi11WiFiNetworkFv() != 0;
}
}

extern "C" {

s32 fn_80266F7C__Q25gsapi11WiFiNetworkFv(void);

s32 fn_801651D4(void) {
    fn_8025DFD0();
    fn_8025E31C();
    if (fn_80266F7C__Q25gsapi11WiFiNetworkFv() > 0) {
        fn_8025DFD0();
        fn_8025E31C();
        return fn_80266F7C__Q25gsapi11WiFiNetworkFv();
    }
    fn_8025DFD0();
    fn_8025E31C();
    return -fn_80266F7C__Q25gsapi11WiFiNetworkFv();
}
}

extern "C" {

s32 fn_80265DEC__Q25gsapi11WiFiNetworkFv(void);

void fn_8016532C(void) {
    fn_8025DFD0();
    fn_8025E31C();
    fn_80265DEC__Q25gsapi11WiFiNetworkFv();
}
}

extern "C" {

s32 fn_801650AC(void);
s32 fn_80165258(void);
s32 fn_80165354(void);
s32 fn_80168C48(void);
s32 fn_801694A0(void);
s32 fn_80265BB0__Q25gsapi11WiFiNetworkFUc(s32, s32);

s32 fn_80165354(void) {
    if ((fn_801650AC() == 0) || (fn_80165258() != 0)) {
        return -1;
    }
    fn_80168C48();
    fn_801694A0();
    return fn_80265BB0__Q25gsapi11WiFiNetworkFUc(((s32 (*)(s32))fn_8025E31C)(fn_8025DFD0()), 2);
}
}

extern "C" {

s32 fn_801653A8(s32);
s32 fn_80265C1C__Q25gsapi11WiFiNetworkFl(s32, s32);

s32 fn_801653A8(s32 arg0) {
    if ((fn_801650AC() == 0) || (fn_80165258() != 0)) {
        return -1;
    }
    fn_80168C48();
    fn_801694A0();
    return fn_80265C1C__Q25gsapi11WiFiNetworkFl(((s32 (*)(s32))fn_8025E31C)(fn_8025DFD0()), arg0);
}
}

extern "C" {

s32 fn_80265488__Q25gsapi11WiFiNetworkFPll(s32, s32, s32);

s32 fn_801652E8() {
    s32 sp8[10];

    if (fn_80265488__Q25gsapi11WiFiNetworkFPll(((s32 (*)(s32))fn_8025E31C)(fn_8025DFD0()), (s32) sp8, 8) <= 0) {
        return -1;
    }
    return sp8[0];
}
}
