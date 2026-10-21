/* HCI over the Wii's USB transport (H2), written for this repository to
 * match the Wii BTE library. The BTE stack is the Broadcom code also
 * published as bluedroid
 * <android.googlesource.com/platform/external/bluetooth/bluedroid>,
 * Copyright (C) 1999-2012 Broadcom Corporation, Apache License 2.0.
 */

#include <private/bte/bt_trace.h>
#include <private/bte/bt_types.h>
#include <private/bte/gki.h>
#include <private/bte/hci.h>
#include <private/bte/btu.h>
#include <private/bte/l2c_int.h>
#include <private/bte/misc.h>
#include <private/bte/uusb.h>

enum {
    H2_RX_MSGTYPE_ST,
    H2_RX_LEN_ST,
    H2_RX_IGNORE_LEN_ST,
    H2_RX_DATA_ST,
    H2_RX_IGNORE_ST,
};

typedef struct {
    /* 0x00 */ BT_HDR* p_rcv_msg[3];
    /* 0x0C */ UINT16 rcv_len[3];
    /* 0x12 */ UINT16 offset;
    /* 0x14 */ UINT8 rcv_msg_type[3];
    /* 0x17 */ UINT8 rcv_len_lsb[3];
    /* 0x1A */ UINT8 rcv_state[3];
    /* 0x1D */ UINT8 unk_0x1d;
    /* 0x1E */ UINT8 state;
    /* 0x1F */ UINT8 task_id;
    /* 0x20 */ UINT8 port;
} tHCISU_H2_CB; // size: 0x24

const UINT8 hcisu_preamble_table[] = {3, 4, 3, 2};
const UINT16 hcisu_msg_evt_table[] = {
    MSG_HC_TO_STACK_HCI_ERR,
    MSG_HC_TO_STACK_HCI_ACL,
    MSG_HC_TO_STACK_HCI_SCO,
    MSG_HC_TO_STACK_HCI_EVT,
};

tHCISU_H2_CB hcisu_h2_cb;

tHCI_IF const hcisu_h2 = {
    hcisu_h2_init, hcisu_h2_open, hcisu_h2_close, hcisu_h2_send, hcisu_h2_handle_event,
};

void hcisu_h2_usb_cback(UINT8 event, INT8 param) {
    switch (event) {
    case 0:
        break;

    case 4:
        bta_usb_close_evt(param);
        break;
    }
}

UINT16 hcisu_h2_receive_msg(UINT16 idx, tHCISU_H2_CB* p_cb) {
    UINT8 byte;
    UINT16 total = 0;
    UINT16 len;
    BOOLEAN msg_received;
    UINT16 n;
    UINT16 ch;

    if (p_cb->state != 2) {
        return 0;
    }

    ch = idx + 1;

    while (TRUE) {
        if (UUSB_Read(ch, &byte, 1) == 0) {
            break;
        }

        msg_received = FALSE;
        total++;

        switch (p_cb->rcv_state[idx]) {
        case H2_RX_MSGTYPE_ST:
            if (ch == 1) {
                p_cb->p_rcv_msg[idx] = GKI_getpoolbuf(2);
                p_cb->rcv_msg_type[idx] = 4;
            } else if (ch == 2) {
                p_cb->p_rcv_msg[idx] = GKI_getpoolbuf(3);
                p_cb->rcv_msg_type[idx] = 2;
            } else if (ch == 3) {
                p_cb->p_rcv_msg[idx] = GKI_getpoolbuf(1);
                p_cb->rcv_msg_type[idx] = 3;
            } else {
                break;
            }

            if (p_cb->p_rcv_msg[idx] != NULL) {
                p_cb->p_rcv_msg[idx]->len = 0;
                p_cb->p_rcv_msg[idx]->event = hcisu_msg_evt_table[p_cb->rcv_msg_type[idx] - 1];
                p_cb->p_rcv_msg[idx]->offset = 0;
                p_cb->rcv_state[idx] = H2_RX_LEN_ST;
            } else {
                BT_TRACE(HCI, ERROR, "HCIS: Unable to allocate buffer for incoming HCI message.");
                p_cb->rcv_state[idx] = H2_RX_IGNORE_LEN_ST;
            }

            p_cb->rcv_len[idx] = hcisu_preamble_table[p_cb->rcv_msg_type[idx] - 1];

        case H2_RX_LEN_ST:
            *((UINT8*)(p_cb->p_rcv_msg[idx] + 1) + p_cb->p_rcv_msg[idx]->len++) = byte;

            if (--p_cb->rcv_len[idx] == 0) {
                len = byte;

                if (p_cb->rcv_msg_type[idx] == 2) {
                    len = (UINT16)((len << 8) + p_cb->rcv_len_lsb[idx]);

                    p_cb->p_rcv_msg[idx] = l2cap_link_chk_pkt_start(p_cb->p_rcv_msg[idx]);
                    if (p_cb->p_rcv_msg[idx] == NULL) {
                        p_cb->rcv_len[idx] = len;

                        if (len == 0) {
                            p_cb->rcv_state[idx] = H2_RX_MSGTYPE_ST;
                        } else {
                            p_cb->rcv_state[idx] = H2_RX_IGNORE_ST;
                        }
                        break;
                    }
                }

                p_cb->rcv_len[idx] = len;

                if ((len + hcisu_preamble_table[p_cb->rcv_msg_type[idx] - 1] + BT_HDR_SIZE) > GKI_get_buf_size(p_cb->p_rcv_msg[idx])) {
                    GKI_freebuf(p_cb->p_rcv_msg[idx]);
                    p_cb->p_rcv_msg[idx] = NULL;
                    p_cb->rcv_state[idx] = H2_RX_IGNORE_ST;
                    BT_TRACE(HCI, ERROR, "HCIS: Invalid length for incoming HCI message.");
                } else if (len != 0) {
                    p_cb->rcv_state[idx] = H2_RX_DATA_ST;
                } else {
                    p_cb->rcv_state[idx] = H2_RX_MSGTYPE_ST;
                    msg_received = TRUE;
                }
            } else {
                p_cb->rcv_len_lsb[idx] = byte;
            }
            break;

        case H2_RX_IGNORE_LEN_ST:
            if (--p_cb->rcv_len[idx] == 0) {
                len = byte;

                if (p_cb->rcv_msg_type[idx] == 2) {
                    len = (UINT16)((len << 8) + p_cb->rcv_len_lsb[idx]);
                }

                p_cb->rcv_len[idx] = len;
                p_cb->rcv_state[idx] = H2_RX_IGNORE_ST;
            } else {
                p_cb->rcv_len_lsb[idx] = byte;
            }
            break;

        case H2_RX_DATA_ST:
            *((UINT8*)(p_cb->p_rcv_msg[idx] + 1) + p_cb->p_rcv_msg[idx]->len++) = byte;
            p_cb->rcv_len[idx]--;

            n = UUSB_Read(idx + 1, (UINT8*)(p_cb->p_rcv_msg[idx] + 1) + p_cb->p_rcv_msg[idx]->len, p_cb->rcv_len[idx]);
            total += n;
            p_cb->p_rcv_msg[idx]->len += n;

            if ((p_cb->rcv_len[idx] -= n) == 0) {
                if (p_cb->rcv_msg_type[idx] == 2 && !l2cap_link_chk_pkt_end()) {
                    p_cb->rcv_state[idx] = H2_RX_MSGTYPE_ST;
                } else {
                    p_cb->rcv_state[idx] = H2_RX_MSGTYPE_ST;
                    msg_received = TRUE;
                }
            }
            break;

        case H2_RX_IGNORE_ST:
            if (--p_cb->rcv_len[idx] == 0) {
                p_cb->rcv_state[idx] = H2_RX_MSGTYPE_ST;
            }
            break;
        }

        if (msg_received) {
            GKI_send_msg(hcisu_h2_cb.task_id, 0, p_cb->p_rcv_msg[idx]);
            p_cb->p_rcv_msg[idx] = NULL;
        }
    }

    return total;
}

void hcisu_h2_send_msg_now(tHCISU_H2_CB* p_cb, BT_HDR* p_msg) {
    UINT16 handle;
    UINT8* p = (UINT8*)(p_msg + 1) + p_msg->offset;
    UINT8 ch;

    if (p_msg->event == MSG_STACK_TO_HC_HCI_ACL) {
        ch = 2;
    } else if (p_msg->event == MSG_STACK_TO_HC_HCI_SCO) {
        ch = 3;
    } else if (p_msg->event == MSG_STACK_TO_HC_HCI_CMD) {
        ch = 0;
    }

    if (p_msg->event == MSG_STACK_TO_HC_HCI_ACL && p_msg->len > btu_cb.hcit_acl_pkt_size) {
        STREAM_TO_UINT16(p, &handle);
        handle = (handle & 0xCFFF) | 0x1000;

        while (p_msg->len > btu_cb.hcit_acl_pkt_size) {
            UUSB_Write(ch, p, btu_cb.hcit_acl_pkt_size, p_msg);

            p_msg->offset += btu_cb.hcit_acl_data_size;
            p_msg->len -= btu_cb.hcit_acl_data_size;

            p = (UINT8*)(p_msg + 1) + p_msg->offset;
            UINT16_TO_STREAM(p, handle);

            if (p_msg->len > btu_cb.hcit_acl_pkt_size) {
                UINT16_TO_STREAM(p, btu_cb.hcit_acl_data_size);
            } else {
                UINT16_TO_STREAM(p, p_msg->len - 4);
            }

            if (p_msg->layer_specific != 0 && --p_msg->layer_specific == 0) {
                p_msg->event = MSG_HC_TO_STACK_L2C_SEG_XMIT;
                GKI_send_msg(hcisu_h2_cb.task_id, 0, p_msg);
                return;
            }
        }
    }

    UUSB_Write(ch, p, p_msg->len, p_msg);
    GKI_freebuf(p_msg);
}

void hcisu_h2_init(UINT8 task_id, UINT8 port, UINT16 offset) {
    tHCISU_H2_CB* p_cb = &hcisu_h2_cb;

    p_cb->state = 0;
    p_cb->rcv_state[0] = H2_RX_MSGTYPE_ST;
    p_cb->rcv_state[1] = H2_RX_MSGTYPE_ST;
    p_cb->rcv_state[2] = H2_RX_MSGTYPE_ST;
    p_cb->task_id = task_id;
    p_cb->port = port;
    p_cb->offset = offset;
}

BOOLEAN hcisu_h2_open(tHCI_CFG* p_cfg) {
    tUUSB uusb;

    uusb.at_0x0b = 0;
    uusb.at_0x04 = p_cfg->at_0x00;
    uusb.at_0x06 = p_cfg->at_0x02;
    uusb.at_0x08 = hcisu_h2_cb.task_id;
    hcisu_h2_cb.state = 2;

    UUSB_Register(&uusb);
    UUSB_Open(&uusb, hcisu_h2_usb_cback);

    return TRUE;
}

void hcisu_h2_close(void) {
    hcisu_h2_cb.state = 0;

    UUSB_Close();
    UUSB_Unregister();
}

BOOLEAN hcisu_h2_send(BT_HDR* p_msg) {
    hcisu_h2_send_msg_now(&hcisu_h2_cb, p_msg);
    return TRUE;
}

int hcisu_h2_handle_event(UINT16 len) {
    hcisu_h2_receive_msg(len - BT_HDR_SIZE - hcisu_h2_cb.offset, &hcisu_h2_cb);
    return 0;
}
