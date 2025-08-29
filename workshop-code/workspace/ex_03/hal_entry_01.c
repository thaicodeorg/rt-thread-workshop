/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author        Notes
 * 2023-12-17     Rbb666        first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include "hal_data.h"

#include <wlan_mgnt.h>
#include <wlan_prot.h>
#include <wlan_cfg.h>

#define LED_PIN    BSP_IO_PORT_01_PIN_02 /* Onboard LED pins */

#define WIFI_SSID       "<WIFI_SSID>"
#define WIFI_PASSWD     "<WIFI_PASSWD>"

typedef enum {
    WLAN_IDLE_STATUS = 0,
    WLAN_NO_SSID_AVAIL,
    WLAN_SCAN_COMPLETED,
    WLAN_CONNECTED,
    WLAN_CONNECT_FAILED,
    WLAN_CONNECTION_LOST,
    WLAN_DISCONNECTED
} wlan_status_t;

static wlan_status_t wlan_status = WLAN_IDLE_STATUS;

void wifi_event_handler(int event, struct rt_wlan_buff *buff, void *parameter) {
    switch(event) {
    case RT_WLAN_EVT_READY:
        rt_kprintf("Event RT_WLAN_EVT_READY\n");
        wlan_status = WLAN_CONNECTED;
        break;
    case RT_WLAN_EVT_STA_CONNECTED:
        rt_kprintf("Event RT_WLAN_EVT_STA_CONNECTED\n");
        break;
    case RT_WLAN_EVT_SCAN_REPORT:
        rt_kprintf("Event RT_WLAN_EVT_SCAN_REPORT\n");
        if ((buff != RT_NULL) && (buff->len == sizeof(struct rt_wlan_info))) {
            const char *wifi_ssid = ((struct rt_wlan_info *)buff->data)->ssid.val;
            int wifi_rssi = ((struct rt_wlan_info *)buff->data)->rssi;
            rt_kprintf("Connecting ssid : %s at %d \n", wifi_ssid, wifi_rssi);
            if (strcmp(wifi_ssid, WIFI_SSID) == 0) {
                rt_wlan_connect(WIFI_SSID, WIFI_PASSWD);
            }
        }
        break;
    case RT_WLAN_EVT_STA_CONNECTED_FAIL:
        rt_kprintf("Event RT_WLAN_EVT_STA_CONNECTED_FAIL\n");

        break;
    case RT_WLAN_EVT_STA_DISCONNECTED:
        rt_kprintf("Event RT_WLAN_EVT_STA_DISCONNECTED\n");

        break;
    default:
        rt_kprintf("Unsupported WLAN code: %d\n", event);
    }
}

void wifi_begin(const char *ssid, const char *passwd) {
    rt_wlan_set_mode(RT_WLAN_DEVICE_STA_NAME, RT_WLAN_STATION);
    rt_wlan_register_event_handler(RT_WLAN_EVT_READY, wifi_event_handler, RT_NULL);
    rt_wlan_register_event_handler(RT_WLAN_EVT_STA_CONNECTED, wifi_event_handler, RT_NULL);
    rt_wlan_register_event_handler(RT_WLAN_EVT_SCAN_REPORT, wifi_event_handler, RT_NULL);
    rt_wlan_register_event_handler(RT_WLAN_EVT_STA_CONNECTED_FAIL, wifi_event_handler, RT_NULL);
    rt_wlan_register_event_handler(RT_WLAN_EVT_STA_DISCONNECTED, wifi_event_handler, RT_NULL);
    rt_wlan_scan();
}

wlan_status_t wifi_status(void) {
    return wlan_status;
}

void hal_entry(void) {
    rt_kprintf("\nHello RT-Thread!\n");
    wifi_begin(WIFI_SSID, WIFI_PASSWD);

    while (1) {
        rt_pin_write(LED_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED_PIN, PIN_LOW);
        rt_thread_mdelay(500);
    }
}
