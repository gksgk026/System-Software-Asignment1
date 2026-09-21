#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main(void)
{
    printf("The priority of the current process is = %d\n", getpriority(PRIO_PROCESS, 0));

    setpriority(PRIO_PROCESS, 0, -10);

    printf("The modified priority = %d\n", getpriority(PRIO_PROCESS, 0));
}

//to get priority of current process we use: getpid() or in same process you can use 0
//here, insted of setpriority() we can also use nice()
//nice(x): do relative change of priority [cp += x]
//setpriority(_,pid,x): do direct assignment [c = x]
