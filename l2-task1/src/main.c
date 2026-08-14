#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(main, LOG_LEVEL_DBG);

#define STACK_SIZE	1024
#define PRIO		5
#define INCREMENTS	1000000

volatile static size_t shared_counter = 0;
K_SEM_DEFINE(t1sem, 0, 1);
K_SEM_DEFINE(t2sem, 0, 1);
K_MUTEX_DEFINE(lock);

void t1_fn(void *a, void *b, void *c)
{
	for (size_t i = 0; i < INCREMENTS; i++) {
		(void)k_mutex_lock(&lock, K_FOREVER);
		shared_counter++;
		(void)k_mutex_unlock(&lock);
	}
	k_sem_give(&t1sem);
}

void t2_fn(void *a, void *b, void *c)
{
	for (size_t i = 0; i < INCREMENTS; i++) {
		(void)k_mutex_lock(&lock, K_FOREVER);
		shared_counter++;
		(void)k_mutex_unlock(&lock);
	}
	k_sem_give(&t2sem);
}

K_THREAD_DEFINE(t1, STACK_SIZE, t1_fn, NULL, NULL, NULL, PRIO, 0, 0);
K_THREAD_DEFINE(t2, STACK_SIZE, t2_fn, NULL, NULL, NULL, PRIO, 0, 0);

int main(void)
{
	int ret;

	k_sem_take(&t1sem, K_FOREVER);
	k_sem_take(&t2sem, K_FOREVER);

	LOG_INF("shared_counter: %u", shared_counter);

        return 0;
}
