#ifndef READKEY_H
#define READKEY_H
#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
enum Keys {
	NONE,
	F5,
	F6,
	KLOAD,
	SAVE,
	RUN,
	STEP,
	RESET,
	EXIT,
	UP,
	LEFT,
	RIGHT,
	DOWN,
	EDIT,
	ENTER,
	CONS
};
void termInit();
int rk_readKey(enum Keys *key);
int rk_myTermRegime(struct termios *currState, int regime, int vtime, int vmin, int echo, int sigint);
int rk_myTermSave(struct termios *termState);
int rk_myTermRestore(struct termios *currState);

#define CHECK_REG_ECH_SIG (regime < 0 || regime > 1 || echo < 0 || echo > 1 || sigint < 0 || sigint > 1)
#endif
