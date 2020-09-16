#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

using namespace std;

static volatile sig_atomic_t sig_caught = 0;

void signal_handler(int signum) {
	if(signum == 1)
		printf("Received signal %d...\n", signum);
	else if(signum == 2)
		printf("Received signal %d...\n", signum);
	else if(signum == 3)
		printf("Oh no, received signal %d... Bye bye!\n", signum);

	exit(signum);
}

int main(int argc, char** argv){
	signal(1,signal_handler);
	signal(2,signal_handler);
	signal(3,signal_handler);

	printf("Process number: %d\n", getpid());
	
	// Define here type of waiting
	int type = 1;

	if(type==1){
		printf("Busy wait\n");
            while(1){
                if(sig_caught){
                    sig_caught=0;
                    break;
                }
            }
        } else if(type==2){
		printf("Blocking wait\n");
            while(1){
                pause();
                if(sig_caught){
                    sig_caught=0;
                    break;
                }
            }
            
         }

	return 0;
}
