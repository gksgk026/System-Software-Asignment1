#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct {
    int ticket_no;
} db;

int main() {

    int fd;

    fd = open("../files/db", O_RDWR);

    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    printf("Waiting for lock\n");

    fcntl(fd, F_SETLKW, &lock);

    read(fd, &db, sizeof(db));//reading the file and storing it to db

    printf("Current ticket number: %d\n", db.ticket_no);

    db.ticket_no++;

    lseek(fd, 0, SEEK_SET);//after read file pointer is moved to last, bringing it back because we need to write 

    write(fd, &db, sizeof(db));//writing back from db to file

    printf("New ticket number: %d\n", db.ticket_no);

    printf("Press Enter to unlock\n");
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);

    return 0;
}
