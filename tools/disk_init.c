// tools/disk_init.c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define DISK_SIZE 1048576  // 1MB

int main() {
    int fd = open("disk.sim", O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (fd < 0) {
        perror("disk.sim oluşturulamadı");
        return 1;
    }

    if (ftruncate(fd, DISK_SIZE) != 0) {
        perror("ftruncate başarısız");
        close(fd);
        return 1;
    }

    printf("disk.sim başarıyla oluşturuldu (%.2f MB).\n", DISK_SIZE / (1024.0 * 1024.0));
    close(fd);
    return 0;
}

