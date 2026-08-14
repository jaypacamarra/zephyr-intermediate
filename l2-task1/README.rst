l2-task1
********

Goal: Observe and fix a real race condition

Tasks:
* Create two equal-priority threads
* Both increment a shared counter
* Observe inconsistent results

Fix using mutex

Push tag: l2-task1

Learnings:
**********

The variable ``shared_counter`` is initially unprotected and both
equal-priority threads ``t1_fn`` and ``t1_fn`` increment it. After
one-million increment iterations, it is obvious there is a race
condition. To fix this, we define a mutex called ``lock`` that
prevents thread access to the shared counter variable. The consequence
of using a mutex is that the total execution time drastically increases.

The tradeoff is correctness over performance.
