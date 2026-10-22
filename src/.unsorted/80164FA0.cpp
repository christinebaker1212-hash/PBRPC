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
