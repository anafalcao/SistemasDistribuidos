#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>

using namespace std;

void error(const char *msg)
{
    perror(msg);
    exit(2);
}

int main(int argc, char** argv) {
	int procnum, signum, err;

	if(argc != 3){
		cout << "Not enough arguments" << endl;
		cout << "Usage: " << argv[0] << " procnum signum" << endl;
		exit(1);
	}

	err = kill(atoi(argv[1]), atoi(argv[2]));

	switch(errno){
		case EINVAL:
			error("ERROR Invalid signal");
			break;
		case EPERM:
			error("ERROR No permission to transmit");
			break;
		case ESRCH:
			error("ERROR Invalid process");
			break;
	}

	return 0;
}
