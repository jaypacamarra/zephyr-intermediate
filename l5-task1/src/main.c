#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/zbus/zbus.h>
#include <zephyr/debug/thread_analyzer.h>
#include <zephyr/drivers/hwinfo.h>
#include <sensor_iface.h>

LOG_MODULE_REGISTER(main_thread, LOG_LEVEL_DBG);

ZBUS_CHAN_DEFINE(sensor_chan, struct sensor_data, NULL, NULL,
                ZBUS_OBSERVERS(display_lis, logger_sub),
                ZBUS_MSG_INIT(.encoder_pos = 0))

void print_reset_cause(uint32_t cause)
{
        LOG_INF("raw cause %u", cause);

        if (cause & RESET_PIN)
                LOG_INF("reset cause: external pin");
        if (cause & RESET_SOFTWARE)
                LOG_INF("reset cause: software reset");
        if (cause & RESET_BROWNOUT)
                LOG_INF("reset cause: brownout");
        if (cause & RESET_POR)
                LOG_INF("reset cause: power-on reset");
        if (cause & RESET_WATCHDOG)
                LOG_INF("reset cause: watchdog");
        if (cause & RESET_DEBUG)
                LOG_INF("reset cause: debug event");
        if (cause & RESET_SECURITY)
                LOG_INF("reset cause: security violations");
        if (cause & RESET_LOW_POWER_WAKE)
                LOG_INF("reset cause: waking up from low power mode");
        if (cause & RESET_CPU_LOCKUP)
                LOG_INF("reset cause: CPU lock-up detected");
        if (cause & RESET_PARITY)
                LOG_INF("reset cause: parity error");
        if (cause & RESET_PLL)
                LOG_INF("reset cause: PLL error");
        if (cause & RESET_CLOCK)
                LOG_INF("reset cause: Clock error");
        if (cause & RESET_HARDWARE)
                LOG_INF("reset cause: Hardware reset");
        if (cause & RESET_USER)
                LOG_INF("reset cause: User reset");
        if (cause & RESET_TEMPERATURE)
                LOG_INF("reset cause: Temperature reset");
        if (cause & RESET_BOOTLOADER)
                LOG_INF("reset cause: Bootloader reset (entry/exit)");
        if (cause & RESET_FLASH)
                LOG_INF("reset cause: Flash ECC reset");

        (void)hwinfo_clear_reset_cause();
}

int main(void)
{
        LOG_INF("=== L4 Homework: Event Driven Zbus System With Simulated Sensor Data ===");

        uint32_t cause;
        hwinfo_get_reset_cause(&cause);
        print_reset_cause(cause);

        while (1) {
                //thread_analyzer_print(0);
                k_sleep(K_MSEC(1000));
        }

        return 0;
}
