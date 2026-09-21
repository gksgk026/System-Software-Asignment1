#include <stdio.h>
#include <unistd.h>

int main(void)
{
	printf("pid=%d\n", getpid());
   	while(1);
}

//killall -9 a.out to kill all running process named a.out
