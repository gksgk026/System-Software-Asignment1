#include <stdio.h>
#include <sched.h>

int main(void)
{
    printf("The maximum priority of SCHED_FIFO = %d\n", sched_get_priority_max(SCHED_FIFO));

    printf("The minimum priority of SCHED_FIFO = %d\n", sched_get_priority_min(SCHED_FIFO));

    printf("The maximum priority of SCHED_RR = %d\n", sched_get_priority_max(SCHED_RR));

    printf("The minimum priority of SCHED_RR = %d\n", sched_get_priority_min(SCHED_RR));

    printf("The maximum priority of SCHED_OTHER = %d\n", sched_get_priority_max(SCHED_OTHER));

    printf("The minimum priority of SCHED_OTHER = %d\n", sched_get_priority_min(SCHED_OTHER));
}

//SCHED_FIFO and SCHED_RR are real-time policies, therefore their range is same as of real time priority

//SCHED_OTHER normal scheduling policy, does not use this real-time priority range
