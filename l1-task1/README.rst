l1-task1
********

Which threads runs most often?

Thread execution frequency is the highest on ``t_high_fn`` because one, it
has the highest preemptive priority and two, it's thread loop has the smallest
blocking delay ``k_msleep(100)``.

Does priority affect interleaving?

Yes it does. In theory, the priority will be used to determine the next
thread to execute in the ready list if there are more than one threads
ready to run. The higher priority thread will win and get CPU time.

The effect of adding a cooperative thread at priority -1.

The cooperative thread ``t_coop_fn`` execution ran to completion. After
completing the 5 iterations of busy work explicitly yielding then the
preemptive threads ran.

