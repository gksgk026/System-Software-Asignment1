#include <stdio.h>
#include <unistd.h>

int main(void)
{	printf("pid = %d\n", getpid());
    	while(1);
}

//kill -STOP pid to kill running process

