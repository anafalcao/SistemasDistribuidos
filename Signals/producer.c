#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int main(){
	pid_t pid;
	int signalToSend;
	printf("Insert the process id\n");
	scanf("%d",&pid);
	printf("Insert the signal to be sent\n");
	scanf("%d",&signalToSend);
	kill(pid,signalToSend);
	return 0;
}
