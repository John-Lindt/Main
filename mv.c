#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#define isSame(a,b) ((a).st_ino==(b).st_ino && (a).st_dev==(b).st_dev)
int main(int argc, char ** argv) {
struct stat buf_src,buf_dest;
char *src,*dest,*2src,*2dest,*nowdir;
src=malloc(strlen(argv[1])+1);
dest=malloc(strlen(argv[2])+1);
strcpy(src,argv[1]);
strcpy(dest,argv[2]);
stat(src,&buf_src);
stat(dest,&buf_dest);
nowdir=getenv("PWD");
2src=malloc(strlen(src)+1+strlen(nowdir)+1);
strcpy(2src,nowdir);
strcat(2src,"/");
strcat(2src,src);
2dest=malloc(strlen(dest)+1+strlen(nowdir)+1+strlen(src)+1);
strcpy(2dest,nowdir);
strcat(2dest,"/");
strcat(2dest,dest);
strcat(2dest,"/");
strcat(2dest,src);
free(2src);
free(2dest);
free(src);
free(dest);
return 0;
}