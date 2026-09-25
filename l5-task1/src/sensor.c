#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/zbus/zbus.h>
#include <sensor_iface.h>

LOG_MODULE_REGISTER(sensor_sim);

/**
 * @brief Sensor simulator thread.
 */
void sensor_sim_fn(void *a, void *b, void *c)
{
        struct sensor_data data = {0};

        while (1) {
                data.encoder_pos += 10;
                data.timestamp_ms = k_uptime_get();

                (void)zbus_chan_pub(&sensor_chan, &data, K_MSEC(100)); 
                LOG_INF("sensor sim published data");

                k_sleep(K_MSEC(100));

        }
}

K_THREAD_DEFINE(sensor_thread,  1024, sensor_sim_fn, NULL, NULL, NULL, 2, 0, 0);
