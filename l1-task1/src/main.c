#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(demo, LOG_LEVEL_DBG);

#define STACK_SIZE      (1024U)
#define PRIO_COOP       (-1)

void t_low_fn(void *p1, void *p2, void *p3)
{
        while (1) {
                LOG_INF("T_LOW");
                k_sleep(K_MSEC(300));
        }
}

void t_med_fn(void *p1, void *p2, void *p3)
{
        while (1) {
                LOG_INF("T_MED");
                k_sleep(K_MSEC(200));
        }
}

void t_high_fn(void *p1, void *p2, void *p3)
{
        while (1) {
                LOG_INF("T_HIGH");
                k_sleep(K_MSEC(100));
        }
}

K_THREAD_DEFINE(thread_low_prio, STACK_SIZE, t_low_fn,
                NULL, NULL, NULL, CONFIG_THREAD_LOW_PRIORITY_LEVEL, 0, 0);
K_THREAD_DEFINE(thread_med_prio, STACK_SIZE, t_med_fn,
                NULL, NULL, NULL, CONFIG_THREAD_MEDIUM_PRIORITY_LEVEL, 0, 0);
K_THREAD_DEFINE(thread_high_prio, STACK_SIZE, t_high_fn,
                NULL, NULL, NULL, CONFIG_THREAD_HIGH_PRIORITY_LEVEL, 0, 0);

#if IS_ENABLED(CONFIG_THREAD_COOP_ENABLE)
void t_coop_fn(void *p1, void *p2, void *p3)
{
        for (size_t i = 0; i < 5; i++) {
                LOG_INF("busy work %d", i);
                k_busy_wait(100);
        }
        k_yield();
}
K_THREAD_DEFINE(thread_coop, STACK_SIZE, t_coop_fn,
                NULL, NULL, NULL, PRIO_COOP, 0, 400);
#endif


int main(void)
{
        LOG_INF("=== L1 Task 1: Kernal and Scheduling ===");
        LOG_INF("Thread LOW: priority %d, sleeps 300ms",
                        CONFIG_THREAD_LOW_PRIORITY_LEVEL);
        LOG_INF("Thread MED: priority %d, sleeps 200ms",
                        CONFIG_THREAD_MEDIUM_PRIORITY_LEVEL);
        LOG_INF("Thread HIGH: priority %d, sleeps 100ms",
                        CONFIG_THREAD_HIGH_PRIORITY_LEVEL);
#if IS_ENABLED(CONFIG_THREAD_COOP_ENABLE)
        LOG_INF("Thread COOP: priority %d, does 5 busy iterations", -1);
#endif
        return 0;
}
