// Imported from zeldaret/tp (CC0), libs/revolution/src/wud/WUDHidHost.c
#include <private/wud.h>

#include <private/bte/bta_hh_co.h>
#include <private/bte/bta_dm_co.h>

#include <revolution/os.h>

#include <string.h>

#define DEBUGPrint WUD_DEBUGPrint

void WUDHidHostCallback(tBTA_HH_EVT event, tBTA_HH* pData) {
    WUDCB* p = &_wcb;
    WUDDevInfo* pInfo;
    tBTA_HH_CONN* pConn;
    tBTA_HH_CBDATA* pCbData;
    tBTA_HH_ACL_QUEUE_INFO* pQueue;
    int i;

    switch (event) {
    case BTA_HH_ENABLE_EVT: {
        DEBUGPrint("BTA_HH_ENABLE_EVT\n");

        p->hhFlags |= 1;
        break;
    }

    case BTA_HH_DISABLE_EVT: {
        DEBUGPrint("BTA_HH_DISABLE_EVT\n");
        break;
    }

    case BTA_HH_OPEN_EVT: {
        pConn = &pData->conn;

        DEBUGPrint("BTA_HH_OPEN_EVT\n");

        DEBUGPrint("handle: %d, addr: %02x:%02x:%02x:%02x:%02x:%02x\n", pConn->handle, pConn->bda[0], pConn->bda[1], pConn->bda[2], pConn->bda[3],
                   pConn->bda[4], pConn->bda[5]);

        if (pConn->status == BTA_HH_OK) {
            pInfo = &_work;

            if (WUD_BDCMP(pInfo->devAddr, pConn->bda) != 0) {
                pInfo = WUDiGetDevInfo(pConn->bda);
            }

            switch (pInfo->status) {
            case 12: {
                p->syncState = WUD_STATE_SYNC_REGISTER_DEVICE;
                break;
            }

            case 2: {
                p->syncState = WUD_STATE_SYNC_COMPLETE;
                break;
            }
            }

            pInfo->status = 8;
            pInfo->devHandle = pConn->handle;
            p->connectedNum++;

            pInfo = WUDiGetDevInfo(pConn->bda);
            if (pInfo == NULL) {
                pInfo = &_work;
            }

            _dev_handle_to_bda[pConn->handle] = pInfo->devAddr;
            _dev_handle_queue_size[pConn->handle] = 0;
            _dev_handle_notack_num[pConn->handle] = 0;

            if (pInfo->UNK_0x5B == 3 || pInfo->UNK_0x5B == 1) {
                WUDiMoveTopSmpDevInfoPtr(pInfo);
            } else {
                WUDiMoveTopStdDevInfoPtr(pInfo);
            }

            WUDSetSniffMode(pInfo->devAddr, 8);

            if (p->hidConnCB != NULL) {
                p->hidConnCB(pConn->handle, TRUE);
            }
        } else {
            DEBUGPrint("error code: %d\n", pConn->status);

            if (!memcmp(pConn->bda, _work.devAddr, 6)) {
                if (p->syncState != 0) {
                    if (_work.status == 2) {
                        if (WUDiGetDevInfo(pConn->bda) && pConn->status == 12) {
                            WUDiRemoveDevice(pConn->bda);
                            p->linkedNum--;
                        }

                        p->syncState = 255;
                    }
                }
            }
        }
    }

    break;
    case BTA_HH_CLOSE_EVT: {
        pCbData = &pData->dev_status;

        DEBUGPrint("BTA_HH_CLOSE_EVT\n");

        p->connectedNum--;

        DEBUGPrint("device handle : %d   status = %d\n", pCbData->handle, pCbData->status);

        pInfo = WUDiGetDevInfo(_dev_handle_to_bda[pCbData->handle]);
        if (pInfo != NULL) {
            if (pInfo->UNK_0x5B == 3 || pInfo->UNK_0x5B == 1) {
                WUDiMoveTopOfDisconnectedSmpDevice(pInfo);
            } else {
                WUDiMoveTopOfDisconnectedStdDevice(pInfo);
            }
        }

        _dev_handle_to_bda[pCbData->handle] = NULL;
        _dev_handle_queue_size[pCbData->handle] = 0;
        _dev_handle_notack_num[pCbData->handle] = 0;

        if (p->hidConnCB != NULL) {
            p->hidConnCB(pCbData->handle, FALSE);
        }
        break;
    }

    case BTA_HH_SET_RPT_EVT: {
        DEBUGPrint("BTA_HH_SET_RPT_EVT\n");
        break;
    }
    case BTA_HH_GET_RPT_EVT: {
        DEBUGPrint("BTA_HH_GET_RPT_EVT\n");
        break;
    }

    case BTA_HH_SET_PROTO_EVT: {
        DEBUGPrint("BTA_HH_SET_PROTO_EVT\n");
        break;
    }
    case BTA_HH_GET_PROTO_EVT: {
        DEBUGPrint("BTA_HH_GET_PROTO_EVT\n");
        break;
    }

    case BTA_HH_SET_IDLE_EVT: {
        DEBUGPrint("BTA_HH_SET_IDLE_EVT\n");
        break;
    }
    case BTA_HH_GET_IDLE_EVT: {
        DEBUGPrint("BTA_HH_GET_IDLE_EVT\n");
        break;
    }

    case BTA_HH_GET_DSCP_EVT: {
        DEBUGPrint("BTA_HH_GET_DCSP_EVT\n");
        break;
    }

    case BTA_HH_ADD_DEV_EVT: {
        pConn = &pData->dev_info;

        DEBUGPrint("BTA_HH_ADD_DEV_EVT\n");

        // clang-format off
        DEBUGPrint("result: %d, handle: %d, addr: %02x:%02x:%02x:%02x:%02x:%02x\n",
                   pConn->status, pConn->handle,
                   pConn->bda[0], pConn->bda[1], pConn->bda[2],
                   pConn->bda[3], pConn->bda[4], pConn->bda[5]);
        // clang-format on

        pInfo = WUDiGetDevInfo(pConn->bda);
        pInfo->devHandle = pConn->handle;
        break;
    }

    case BTA_HH_RMV_DEV_EVT: {
        pConn = &pData->dev_info;

        DEBUGPrint("BTA_HH_RMV_DEV_EVT\n");

        // clang-format off
        DEBUGPrint("result: %d, handle: %d, addr: %02x:%02x:%02x:%02x:%02x:%02x\n",
            pConn->status, pConn->handle,
            pConn->bda[0], pConn->bda[1], pConn->bda[2],
            pConn->bda[3], pConn->bda[4], pConn->bda[5]);
        // clang-format on
        break;
    }

    case BTA_HH_VC_UNPLUG_EVT: {
        DEBUGPrint("BTA_HH_VS_UNPLUG_EVT\n");
        break;
    }

    case BTA_HH_GET_ACL_Q_EVT: {
        pQueue = &pData->acl_queue_info;

        p->bufferStatus0 = pQueue->num_avail_buffs;
        p->bufferStatus1 = pQueue->num_buffs;

        if (p->linkedNum < pQueue->num_links) {
            OSReport("WARNING: link num count is modified.\n");
            p->linkedNum = pQueue->num_links;
        }

        for (i = 0; i < pQueue->num_links; i++) {
            if (pQueue->queue_info[i].handle < WUD_MAX_DEV_ENTRY) {
                _dev_handle_queue_size[pQueue->queue_info[i].handle] = pQueue->queue_info[i].num_queued;

                _dev_handle_notack_num[pQueue->queue_info[i].handle] = pQueue->queue_info[i].num_not_acked;
            }
        }

        break;
    }
    }
}

void bta_hh_co_data(UINT8 handle, UINT8* pReport, UINT16 len, tBTA_HH_PROTO_MODE mode, UINT8 subClass, UINT8 appId) {
#pragma unused(mode)
#pragma unused(subClass)

    WUDCB* p = &_wcb;

    if (appId == 3) {
        if (p->hidRecvCB != NULL) {
            p->hidRecvCB(handle, pReport, len);
        }
    } else {
        DEBUGPrint("Invalid app_id [%d]\n", appId);
    }
}

void bta_hh_co_open(UINT8 handle, UINT8 subClass, UINT16 attrMask, UINT8 appId) {
#pragma unused(handle)
#pragma unused(subClass)
#pragma unused(attrMask)
#pragma unused(appId)

    DEBUGPrint("bta_hh_co_open()\n");
}

void bta_hh_co_close(UINT8 handle, UINT8 appId) {
#pragma unused(handle)
#pragma unused(appId)

    DEBUGPrint("bta_hh_co_close()\n");
}

BOOLEAN bta_dm_co_get_compress_memory(tBTA_SYS_ID id, UINT8** ppMemory, UINT32* memorySize) {
#pragma unused(id)
#pragma unused(ppMemory)
#pragma unused(memorySize)

    return FALSE;
}
