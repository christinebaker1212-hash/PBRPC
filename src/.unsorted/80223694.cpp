#include ".unsorted/80223694.hpp"

#include "common.hpp"

extern "C" {

s32 C_MTXFrustum(void);

void fn_80223694(void) {
    C_MTXFrustum();
}
}

extern "C" {

s32 C_MTXOrtho(void);

void fn_80223698(void) {
    C_MTXOrtho();
}
}

extern "C" {

s32 C_MTXPerspective(void);

void fn_8022369C(void) {
    C_MTXPerspective();
}
}
