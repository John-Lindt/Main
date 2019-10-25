#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<time.h>
/* Simple shell program that run ls command
 - Create a child process 
 - Parent wait child process to terminate 
 - calls the ls command */
int main() {
	int rep=0;
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo=localtime(&rawtime);
	String comm="";
	while(rep==0) {
	printf("John Lindt, %s.\nEnter your command: ",asctime(timeinfo);
	scanf("%s",&comm);
      pid_t  pid;
	/* fork another process */
	pid = fork();
	if (pid < 0) { /* error occurred */
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	else if (pid == 0) { /* child process */
		if(comm.equals("quit")) {
			rep++;
		}
		else if(comm.equals("ls")) {
		execlp("usr/bin/ls", "ls", NULL);
		}
		else if(comm.equals("ps")) {
		execlp("usr/bin/ps", "cd", NULL);
		}
		else if(comm.equals("dd")) {
		execlp("/bin/dd", "dd", NULL);
		}
		else if(comm.equals("fdisk")) {
		execlp("/bin/ls", "fdisk", NULL);
		}
	}
	else { /* parent process */
		/* parent will wait for the child to complete */
		wait (NULL);
		printf ("Child Complete");
		exit(0);
	       }
	}
}
