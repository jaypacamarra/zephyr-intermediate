#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/zbus/zbus.h>
#include <sensor_iface.h>

LOG_MODULE_REGISTER(main_thread, LOG_LEVEL_DBG);

ZBUS_CHAN_DEFINE(sensor_chan, struct sensor_data, NULL, NULL,
                ZBUS_OBSERVERS(display_lis, logger_sub),
                ZBUS_MSG_INIT(.encoder_pos = 0))

int main(void)
{
    LOG_INF("=== L4 Homework: Event Driven Zbus System With Simulated Sensor Data ===");

    return 0;
}
