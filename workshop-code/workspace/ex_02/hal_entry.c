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

#define LOG_TAG "drv_test.app"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>
#define LED_PIN BSP_IO_PORT_01_PIN_02 /* Onboard LED pins */

void hal_entry(void) {
    rt_kprintf("\nHello RT-Thread!\n");

    while (1) {
        rt_pin_write(LED_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED_PIN, PIN_LOW);
        rt_thread_mdelay(500);
    }
}

static rt_err_t drv_test_init(rt_device_t dev) {
    LOG_I("test drv init\n");
    return RT_EOK;
}

static rt_err_t drv_test_open(rt_device_t dev, rt_uint16_t oflag) {
    LOG_I("test drv open flag = %d\n", oflag);
    return RT_EOK;
}

static rt_err_t drv_test_close(rt_device_t dev) {
    LOG_I("test drv close");
    return RT_EOK;
}

static rt_ssize_t drv_test_read(rt_device_t dev, rt_off_t pos, void *buffer, rt_size_t size) {
    LOG_I("test drv read pos = %d, size = %d\n", pos, size);
    return size;
}

static rt_ssize_t drv_test_write(rt_device_t dev, rt_off_t pos, const void *buffer, rt_size_t size) {
    LOG_I("test drv write pos = %d, size = %d\n", pos, size);
    return size;
}

static rt_err_t drv_test_control(rt_device_t dev, int cmd, void *args) {
    LOG_I("test drv control cmd = %d\n", cmd);
    return RT_EOK;
}

static int rt_dev_test_init(void) {
    rt_device_t test_dev = rt_device_create(RT_Device_Class_Char, 0);
    if (!test_dev) {
        LOG_E("test_dev create failed");
        return -RT_ERROR;
    }
    test_dev->init = drv_test_init;
    test_dev->open = drv_test_open;
    test_dev->close = drv_test_close;
    test_dev->read = drv_test_read;
    test_dev->write = drv_test_write;
    test_dev->control = drv_test_control;
    if (rt_device_register(test_dev, "test_dev", RT_DEVICE_FLAG_RDWR) != RT_EOK) {
        LOG_E("test_dev register failed!");
        return -RT_ERROR;
    }

    return RT_EOK;
}
INIT_DEVICE_EXPORT(rt_dev_test_init);

static int drv_test_app(void) {
    rt_device_t test_dev = rt_device_find("test_dev");
    if (test_dev == RT_NULL) {
        LOG_E("can not find test drv!");
        return -RT_ERROR;
    }
    rt_device_open(test_dev, RT_DEVICE_OFLAG_RDWR);
    rt_device_control(test_dev, RT_DEVICE_CTRL_CONFIG, RT_NULL);
    rt_device_write(test_dev, 100, RT_NULL, 1024);
    rt_device_read(test_dev, 20, RT_NULL, 128);
    rt_device_close(test_dev);
    return RT_EOK;
}
MSH_CMD_EXPORT(drv_test_app, enable test drv app);

