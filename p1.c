#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sighandler(int);
int data, pid;
int x = 0;
int main(int argc, char **argv){
	data = atoi(argv[2]);
        pid = atoi(argv[1]);
	signal(SIGINT,sighandler);
	while(1){
		printf("Going to sleep for a second...\n");
		sleep(1);
	}
	return(0);
}

void sighandler(int signum){
	printf("Caught signal %d, coming out...\n",signum);
	x = x+1;
	data = data+x;
	union sigval val = {.sival_int = data};
	sigqueue((pid_t)pid,SIGUSR1,val);
}
