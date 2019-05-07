#include "computer.h"
#include <signal.h>

#include <unistd.h>
#include <sys/time.h> 

struct itimerval nval;
struct itimerval oval;

void signHandler(int signo) {
	cu();
}

void siginit() {
	signal(SIGALRM, signHandler);
}

void setTimer(long it_sec, long it_usec, long val_sec, long val_usec) {
	nval.it_interval.tv_sec = it_sec;
	nval.it_interval.tv_usec = it_usec;
	nval.it_value.tv_sec = val_sec;
	nval.it_value.tv_usec = val_usec;
	setitimer(ITIMER_REAL, &nval, &oval);
}