#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define DEV_EXAMPLE "/dev/example"

int main(int argc, char *argv[]){

    int fd = open(DEV_EXAMPLE, O_RDWR);

    for(int i=0; i<5; i++){
        char buf[256] = {'\0'};
        int len = read(fd, buf, 20);
        printf("len = %d, buf = %s\n", len, buf);
    }

    lseek(fd, 0, SEEK_SET);
    for(int i=0; i<15; i++){
        char buf[256] = {'\0'};
        int len = read(fd, buf, 20);
        lseek(fd, i+1, SEEK_SET);
        printf("len = %d, buf = %s\n", len, buf);
    }

    return 0;
}
