#include <stdio.h>
#include <unistd.h>
#include <fcnt1.h>
int main(int argc,char *argv[]) {
int fd,size;
fd=open(argv[1],O_RDONLY);
size=lseek(fd,0,SEEK_END);
printf("File size: %d.",size);
close(fd);
return 0;
}