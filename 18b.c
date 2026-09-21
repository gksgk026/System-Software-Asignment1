#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

struct {
    int train_num;
    int ticket_count;
} db;

int main() {

    int fd, input;

    fd = open("../files/record.txt", O_RDONLY);

    printf("Select train number (1, 2, 3): ");
    scanf("%d", &input);

    struct flock lock;

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (input - 1) * sizeof(db);
    lock.l_len = sizeof(db);
    lock.l_pid = getpid();

    // Lock selected record
    fcntl(fd, F_SETLKW, &lock);

    lseek(fd, (input - 1) * sizeof(db), SEEK_SET);//moving file pointer to read the record
    read(fd, &db, sizeof(db));//reading record from file and stroing it to db

    printf("Train number: %d\n", db.train_num);
    printf("Ticket count: %d\n", db.ticket_count);

    getchar();   // remove leftover \n from scanf
    getchar();   // wait for Enter

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Lock released\n");

    close(fd);

    return 0;
}
