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

#include <paho_mqtt.h>
#include <cJSON.h>

#define LED_PIN    BSP_IO_PORT_01_PIN_02 /* Onboard LED pins */

#define WIFI_SSID       "<WIFI_SSID>"
#define WIFI_PASSWD     "<WIFI_PASSWD>"

#define MQTT_BROKER     "tcp://broker.emqx.io:1883"
#define MQTT_CLIENT_ID  "<MQTT CLIENT ID>"
#define MQTT_PUB_TOPIC  "<MQTT PUB TOPIC>"
#define MQTT_SUB_TOPIC  "<MQTT SUB TOPIC>"


static MQTTClient   mqttClient;

static bool wifiConnected = false;

void wifi_event_handler(int event, struct rt_wlan_buff *buff, void *parameter) {
    wifiConnected = true;
}

static void mqtt_msg_cb(MQTTClient *client, MessageData *msg_data) {
    char topic_txt[256];
    char payload_txt[256];
    memcpy(topic_txt, msg_data->topicName->lenstring.data, strlen(msg_data->topicName->lenstring.data));
    topic_txt[msg_data->topicName->lenstring.len] = 0;
    memcpy(payload_txt, msg_data->message->payload, strlen((char*)msg_data->message->payload));
    payload_txt[msg_data->message->payloadlen] = 0;
    rt_kprintf("Got msg %s from %s\n", payload_txt, topic_txt);
}

static void mqtt_connect_cb(MQTTClient *client) {
    rt_kprintf("\nMQTT connected\n");
}

static void mqtt_online_cb(MQTTClient *client) {
    rt_kprintf("\nDevice online\n");
    client->isconnected = true;
}

static void mqtt_offline_cb(MQTTClient *client) {
    rt_kprintf("\nDevice offline\n");
}

void hal_entry(void) {
    rt_kprintf("\nHello RT-Thread!\n");

    // WiFi
    rt_wlan_set_mode(RT_WLAN_DEVICE_STA_NAME, RT_WLAN_STATION);
    rt_wlan_register_event_handler(RT_WLAN_EVT_READY, wifi_event_handler, RT_NULL);
    rt_wlan_connect(WIFI_SSID, WIFI_PASSWD);
    rt_kprintf("Waiting WiFi: ");
    while(!wifiConnected) {
        rt_kprintf(".");
        rt_thread_mdelay(500);
    }
    rt_kprintf("\nWiFi connected!\n");

    // MQTT
    mqttClient.uri = MQTT_BROKER;

    MQTTPacket_connectData mqttCfg = MQTTPacket_connectData_initializer;
    mqttCfg.clientID.cstring = MQTT_CLIENT_ID;
    mqttCfg.keepAliveInterval = 30;
    mqttCfg.cleansession = 1;
    mqttCfg.username.cstring = RT_NULL;
    mqttCfg.password.cstring = RT_NULL;
    memcpy(&mqttClient.condata, &mqttCfg, sizeof(mqttCfg));

    mqttClient.buf_size = 128;
    mqttClient.buf = rt_calloc(1, mqttClient.buf_size);
    mqttClient.readbuf_size = 128;
    mqttClient.readbuf = rt_calloc(1, mqttClient.readbuf_size);

    mqttClient.connect_callback = mqtt_connect_cb;
    mqttClient.online_callback = mqtt_online_cb;
    mqttClient.offline_callback = mqtt_offline_cb;
    mqttClient.defaultMessageHandler = mqtt_msg_cb;

    mqttClient.isconnected = false;
    paho_mqtt_start(&mqttClient);
    while(!mqttClient.isconnected) {
        rt_thread_mdelay(500);
    }
    paho_mqtt_subscribe(&mqttClient, QOS1, MQTT_SUB_TOPIC, mqtt_msg_cb);

    while (1) {
        rt_pin_write(LED_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED_PIN, PIN_LOW);
        rt_thread_mdelay(500);
        paho_mqtt_publish(&mqttClient, QOS1, MQTT_PUB_TOPIC, "hello");
        rt_kprintf("\nMQTT published\n");
    }
}
