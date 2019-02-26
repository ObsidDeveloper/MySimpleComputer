#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

#include "mta/MyTerminal.h"
#include "rk/ReadKey.h"

struct termios const _term_st;
struct termios term;

int rk_myTermSave(void) {
	return tcgetattr(1, term);
}

int rk_myTermRestore(void) {
	return tcsetattr(1, TCSADRAIN, &term);
}

int rk_myTermRegine(struct termios const *current, int regime, int vtime, int vmin, int echo, int sigint) {
	if (CHECK_REG_ECH_SIG) return -1;
	
	struct termios newstate = *current;

	if (regime) newstate.c_lflag |= ICANOW;
		else newstate.c_lflag &= ~ICANOW;

	if (echo) newstate.c_lflag |= ECHO;
		else newstate.c_lflag &= ~ECHO;

	if (sigint) newstate.c_lflag |= ISIG;
		else newstate.c_lflag &= ~ISIG;

	newstate.c_cc[VMIN] = vmin;
	newstate.c_cc[VTIME] = vtime;
	tcsetattr(0, TSCANOW, &newstate);

	return 0;
}

/*Thank you, Mioko!*/