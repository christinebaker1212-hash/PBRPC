#include ".unsorted/80240060.hpp"

#include "common.hpp"

extern "C" {

s32 DBIsDebuggerPresent(void);
s32 OSRebootSystem(void);
s32 OSRestart(s32);
s32 OSReturnToMenu(void);
s32 OSShutdownSystem(void);
s32 fn_802310C0__8GSrenderFv(u8 *);

void fn_80240388(u8 *arg0) {
    s32 temp_r0;

    if (DBIsDebuggerPresent() == 1) {
        (*(s8 *)((u8 *)(arg0) + (0x171B))) = 0;
        return;
    }
    fn_802310C0__8GSrenderFv(arg0);
    temp_r0 = (*(s32 *)((u8 *)(arg0) + (0x171C)));
    switch (temp_r0) {                              /* irregular */
    case 0:
        OSRestart(0);
        return;
    case 1:
        OSRebootSystem();
        return;
    case 2:
        OSReturnToMenu();
        return;
    case 3:
        OSShutdownSystem();
        return;
    }
}
}
