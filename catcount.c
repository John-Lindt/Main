#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
string fileName;
pid_t pid;
printf("Enter the name of your desired file: ");
scanf("%s,fileName);
pid=fork();
if(pid<0) {
	printf("First fork failed.");
	exit(-1);
}
else if(pid==0) {
	execlp("/bin/cat",fileName,NULL);
}
else {
	wait(NULL);
	printf("First child finished.");
}
pid=fork();
if(pid<0) {
	printf("Second fork failed.");
	exit(-1);
}
else if(pid==0) {
	execlp("/usr/bin/wc",fileName,NULL);
}
else {
	wait(NULL);
	printf("Second child process finished.");
}
return 0;
}