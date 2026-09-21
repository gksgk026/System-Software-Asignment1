#include <stdio.h>
#include <unistd.h>
#include <sched.h>

int main(void)
{
    struct sched_param p;

    p.sched_priority = 26;

    printf("ret = %d\n", sched_setscheduler(getpid(), SCHED_FIFO, &p));

    printf("The scheduling policy is = %d\n",sched_getscheduler(getpid()));

    printf("ret = %d\n",sched_setscheduler(getpid(), SCHED_RR, &p)); //getpid() gives pid of current process

    printf("The scheduling policy is = %d\n",sched_getscheduler(getpid()));
}
//scheduling policy
//0 → SCHED_OTHER
//1 → SCHED_FIFO
//2 → SCHED_RR
