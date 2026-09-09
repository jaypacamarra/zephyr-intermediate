#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/zbus/zbus.h>
#include <sensor_iface.h>

LOG_MODULE_REGISTER(logger);
ZBUS_SUBSCRIBER_DEFINE(logger_sub, 4);

void logger_thread_fn(void *a, void *b, void *c)
{
        int ret;
        const struct zbus_channel *chan;
        struct sensor_data msg = {0};
        
        while (1) {
                ret = zbus_sub_wait(&logger_sub, &chan, K_FOREVER);
                if (ret < 0) {
                        continue;
                }

                zbus_chan_read(chan, &msg, K_MSEC(100));
                LOG_INF("Encoder data: %d", msg.encoder_pos);
                k_sleep(K_MSEC(1000));
        }
}

K_THREAD_DEFINE(logger_thread, 1024, logger_thread_fn, NULL, NULL, NULL, 5, 0, 0);
