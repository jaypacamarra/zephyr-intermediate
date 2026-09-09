#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/zbus/zbus.h>
#include <sensor_iface.h>

LOG_MODULE_REGISTER(display);

void display_callback(const struct zbus_channel *chan)
{
        const struct sensor_data *data = zbus_chan_const_msg(chan);

        LOG_INF("Encoder data: %d", data->encoder_pos);
}

ZBUS_LISTENER_DEFINE(display_lis, display_callback);
