#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/zbus/zbus.h>
#include <zephyr/task_wdt/task_wdt.h>
#include <sensor_iface.h>

#define QUEUE_DEPTH 32

LOG_MODULE_REGISTER(logger);
ZBUS_SUBSCRIBER_DEFINE(logger_sub, 32);

const struct device *wdg = DEVICE_DT_GET(DT_ALIAS(watchdog0));

void wdt_expired(int channel_id, void *user_data)
{
        ARG_UNUSED(channel_id);
        ARG_UNUSED(user_data);
}

void health_check_thread_fn(void *a, void *b, void *c)
{
        LOG_INF("health check thread started");
        while (1) {
                uint32_t used = k_msgq_num_used_get(logger_sub.queue);
                LOG_INF("used = %d", used);
                if (used > (QUEUE_DEPTH * 3 / 4)) {
                        LOG_WRN("Queue at %d/%d", used, QUEUE_DEPTH);
                }

                k_sleep(K_MSEC(50));
        }
}

void logger_thread_fn(void *a, void *b, void *c)
{
        int ret;
        const struct zbus_channel *chan;
        struct sensor_data msg = {0};

        if (!device_is_ready(wdg)) {
                LOG_ERR("%s not ready", wdg->name);
                return;
        }
        
        ret = task_wdt_init(wdg);
        if (ret < 0) {
                LOG_ERR("task watchdog failed to initialize");
                return;
        }

        int wdt_chan = task_wdt_add(2000, wdt_expired, (void *)k_current_get());
        if (wdt_chan < 0) {
                LOG_ERR("task watchdog failed to regster channel");
                return;
        }

        while (1) {
                ret = zbus_sub_wait(&logger_sub, &chan, K_FOREVER);
                if (ret < 0) {
                        continue;
                }

                zbus_chan_read(chan, &msg, K_MSEC(100));
                LOG_INF("Encoder data: %d", msg.encoder_pos);

                /* here we simulate a stuck consumer at the 20 second mark */
                if (k_uptime_seconds() <= 20) {
                        task_wdt_feed(wdt_chan);
                }

                k_sleep(K_MSEC(1000));
        }
}

K_THREAD_DEFINE(logger_thread, 1024, logger_thread_fn, NULL, NULL, NULL, 5, 0, 0);
K_THREAD_DEFINE(health_check_thread, 1024, health_check_thread_fn, NULL, NULL, NULL, 6, 0, 0);
