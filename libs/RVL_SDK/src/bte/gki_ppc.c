/* Wii (PPC) port of the GKI operating system layer, written for this
 * repository to match the Wii BTE library. Based on the GKI interface of
 * bluedroid <android.googlesource.com/platform/external/bluetooth/bluedroid>,
 * Copyright (C) 1999-2012 Broadcom Corporation, Apache License 2.0.
 */

#include <private/bte/gki.h>
#include <private/bte/gki_common.h>
#include <private/bte/gki_int.h>
#include <private/bte/gki_target.h>

#include <revolution/os.h>

#include <string.h>

void* App_MEMalloc(u32 size);
BOOL App_MEMfree(void* pBlock);

tGKI_CB gki_cb;

void GKI_init(void) {
    memset(&gki_cb, 0, sizeof(gki_cb));

    gki_buffer_init();
    gki_timers_init();

    gki_cb.com.OSRdyTbl[BTU_TASK] = TASK_READY;
    gki_cb.com.OSTName[BTU_TASK] = NULL;
    gki_cb.com.OSWaitTmr[BTU_TASK] = 0;
    gki_cb.com.OSWaitEvt[BTU_TASK] = 0;

    gki_cb.os.int_index = 0;
    gki_cb.os.int_state[gki_cb.os.int_index] = OSEnableInterrupts();
    gki_cb.os.int_index++;
}

void GKI_shutdown(void) {
    GKI_disable();

    gki_cb.com.OSRdyTbl[BTU_TASK] = TASK_DEAD;

    GKI_enable();

    while (gki_cb.os.int_index != 0) {
        GKI_enable();
    }
}

void GKI_run(void* p_task_id) {
#pragma unused(p_task_id)
}

void GKI_sched_lock(void) {}

void GKI_sched_unlock(void) {}

void GKI_delay(UINT32 timeout) {
#pragma unused(timeout)
}

UINT8 GKI_send_event(UINT8 task_id, UINT16 event) {
    if (task_id >= GKI_MAX_TASKS) {
        return GKI_FAILURE;
    }

    GKI_disable();

    gki_cb.com.OSWaitEvt[task_id] |= event;

    GKI_enable();

    return GKI_SUCCESS;
}

UINT8 GKI_get_taskid(void) {
    return BTU_TASK;
}

void GKI_enable(void) {
    gki_cb.os.int_index--;
    OSRestoreInterrupts(gki_cb.os.int_state[gki_cb.os.int_index]);
}

void GKI_disable(void) {
    gki_cb.os.int_state[gki_cb.os.int_index] = OSDisableInterrupts();
    gki_cb.os.int_index++;
}

void GKI_exception(UINT16 code, char* msg) {
#pragma unused(code)
#pragma unused(msg)
}

void* GKI_os_malloc(UINT32 size) {
    void* p_mem = App_MEMalloc(size);

    if (p_mem == NULL) {
        return NULL;
    }

    return p_mem;
}

void GKI_os_free(void* p_mem) {
    App_MEMfree(p_mem);
}
