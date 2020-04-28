#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
	//check if correct number of arguments are entered
	if((argc>5) || (argc<2)) {
		printf("Incorrect number of files input.");
		return(-1);
	}
	//pipe array, iterator, second iterator, fork value
	int pipes[4][2], i, it;
	pid_t p;
	it=0;
	//argument for execvp
	char *args[]={"ls -l",NULL};
	//array for read/write
	char lsres[100];
	//fill array with appropriate number of pipes
	for(i=0;i<argc;i++) {
		//error checking
		if(pipe(&pipes[i][0])==-1) {
			printf("Pipe failed.");
			return -1;
		}
		p=fork();
		//fork failed
	}
	if(p<0) {
		printf("Fork failed.");
		return -2;
	}
	//parent process
	else if(p>0) {
		for(i=0;i<argc;i++) {
			//close writing end
			close(pipes[it][1]);
			//wait for child
			wait(NULL);
			//read pipe from child
			read(pipes[it][0],lsres,100);
			write(1,lsres,100);
		}
	}
	//child process
	else {
		//close reading end of pipe
		close(pipes[it][0]);
		//send result to pipe
		dup2(p, pipes[it][0]);
		//send exec() to pipe
		execvp(argv[it+1],args);
		it++;
	}
return 0;
}