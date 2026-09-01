TASK 1
******

.. code-block:: console

        *** Booting Zephyr OS build v4.4.0 ***
        [00:00:00.251,129] <inf> homework: === L3 Homework: Polling to Workqueue ===
        [00:00:00.251,129] <inf> homework: Starter: polling every 10ms, sensor fires every 100ms
        [00:00:00.251,159] <inf> homework: Expected wasted wakeups: ~9 per event
        [00:00:00.251,159] <inf> homework: Run this, count wakeups, then convert to workqueue.
        [00:00:00.351,318] <inf> homework: [SENSOR] event 0  tick=351
        [00:00:00.352,172] <inf> homework: [CONSUMER] processed event 1  wakeups_so_far=10  tick=352
        [00:00:00.451,416] <inf> homework: [SENSOR] event 1  tick=451
        [00:00:00.453,125] <inf> homework: [CONSUMER] processed event 2  wakeups_so_far=20  tick=453
        [00:00:00.551,513] <inf> homework: [SENSOR] event 2  tick=551
        [00:00:00.554,077] <inf> homework: [CONSUMER] processed event 3  wakeups_so_far=30  tick=554
        [00:00:00.651,611] <inf> homework: [SENSOR] event 3  tick=651
        [00:00:00.655,029] <inf> homework: [CONSUMER] processed event 4  wakeups_so_far=40  tick=655
        [00:00:00.751,708] <inf> homework: [SENSOR] event 4  tick=751
        [00:00:00.755,981] <inf> homework: [CONSUMER] processed event 5  wakeups_so_far=50  tick=755
        [00:00:00.851,806] <inf> homework: [SENSOR] event 5  tick=851
        [00:00:00.856,964] <inf> homework: [CONSUMER] processed event 6  wakeups_so_far=60  tick=856
        [00:00:00.951,904] <inf> homework: [SENSOR] event 6  tick=951
        [00:00:00.957,916] <inf> homework: [CONSUMER] processed event 7  wakeups_so_far=70  tick=957
        [00:00:01.052,001] <inf> homework: [SENSOR] event 7  tick=1052
        [00:00:01.058,868] <inf> homework: [CONSUMER] processed event 8  wakeups_so_far=80  tick=1058
        [00:00:01.152,099] <inf> homework: [SENSOR] event 8  tick=1152
        [00:00:01.159,820] <inf> homework: [CONSUMER] processed event 9  wakeups_so_far=90  tick=1159
        [00:00:01.252,197] <inf> homework: [SENSOR] event 9  tick=1252
        [00:00:01.252,227] <inf> homework: [SENSOR] all events produced
        [00:00:01.260,772] <inf> homework: [CONSUMER] processed event 10  wakeups_so_far=100  tick=1260
        [00:00:01.260,803] <inf> homework:
        
        [00:00:01.260,803] <inf> homework: [SUMMARY] events=10  total_wakeups=100  wasted=90
        [00:00:01.260,803] <inf> homework: [SUMMARY] wasted wakeups = 90% of all wakeups

TASK 3
******

.. code-block:: console

        *** Booting Zephyr OS build v4.4.0 ***
        [00:00:00.251,190] <inf> homework: === L3 Homework: Workqueue + Debounce ===
        [00:00:00.251,190] <inf> homework: Sensor burst: 5 events, 4ms apart
        [00:00:00.251,190] <inf> homework: Debounce delay: 30ms — expect 1 consumer run after burst
        [00:00:00.255,371] <inf> homework: [SENSOR] event 0  tick=255
        [00:00:00.259,521] <inf> homework: [SENSOR] event 1  tick=259
        [00:00:00.263,671] <inf> homework: [SENSOR] event 2  tick=263
        [00:00:00.267,822] <inf> homework: [SENSOR] event 3  tick=267
        [00:00:00.271,972] <inf> homework: [SENSOR] event 4  tick=271
        [00:00:00.272,003] <inf> homework: [SENSOR] all events produced
        [00:00:00.302,062] <inf> homework: [CONSUMER] 5 sensor burst handled (run #1)  tick=302


