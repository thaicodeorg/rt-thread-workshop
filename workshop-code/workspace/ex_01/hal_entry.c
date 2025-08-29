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

#define LED_PIN    BSP_IO_PORT_01_PIN_02 /* Onboard LED pins */

#define IRQ_TEST_PIN "p907"

void irq_callback_test(void *args) {
    rt_kprintf("\n IRQ10 triggered \n");
}

void hal_entry(void)
{
    rt_kprintf("\nHello RT-Thread!\n");
    /* init */
    rt_uint32_t pin = rt_pin_get(IRQ_TEST_PIN);
    rt_kprintf("\n pin number : 0x%04X \n", pin);
    rt_err_t err = rt_pin_attach_irq(pin, PIN_IRQ_MODE_FALLING, irq_callback_test, RT_NULL);
    if (RT_EOK != err) {
        rt_kprintf("\n attach irq failed. \n");
    }
    err = rt_pin_irq_enable(pin, PIN_IRQ_ENABLE);
    if (RT_EOK != err) {
        rt_kprintf("\n enable irq failed. \n");
    }

    while (1) {
        rt_pin_write(LED_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED_PIN, PIN_LOW);
        rt_thread_mdelay(500);
    }
}
