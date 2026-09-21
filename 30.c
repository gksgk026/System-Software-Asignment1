#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main() {

    if (!fork()) {

        setsid();
        chdir("/");
        umask(0);

        while (1) {

            time_t now = time(NULL);//fetching current time
            struct tm *t = localtime(&now); //converting time into readable format, using structure tm


            if (t->tm_hour == 17 && t->tm_min == 10) {

                system("/home/gaurav026/files/script1.sh");

		sleep(60); //to avoid multiple execution, we are putting it on halt for 60 second
            }

            sleep(1);
        }
    }
    else {
        exit(0);
    }

    return 0;
}
