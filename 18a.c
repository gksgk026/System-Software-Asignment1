#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

struct {
    int train_num;
    int ticket_count;
} db;

int main() {

    int fd, input;

    fd = open("../files/record.txt", O_RDWR);

    printf("Select train number(1,2,3): \n");
    scanf("%d", &input);

    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;//l_whence tells initial pos of l_start
    lock.l_start = (input - 1) * sizeof(db);
    lock.l_len = sizeof(db);//record length
    lock.l_pid = getpid();

    fcntl(fd,F_SETLKW,&lock);

    lseek(fd, (input - 1) * sizeof(db), SEEK_SET);//moving file pointer to record location from start
    read(fd, &db, sizeof(db));//reading current value of record using fd and storing it to db

    printf("Ticket number: %d\n", db.ticket_count);

    db.ticket_count++;//updating ticket count

    lseek(fd, -1 * sizeof(db), SEEK_CUR);//after reading file pointer has moved to next record, bringing it back to previous record

    write(fd, &db, sizeof(db));//writing back data from db to record

    printf("To Book Ticket, press Enter:\n");

    getchar();
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Booked\n");
}
