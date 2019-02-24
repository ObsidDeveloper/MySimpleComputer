#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

#include "mta/MyTerminal.h"
#include "rk/ReadKey.h"

int rk_myTermRegine(struct termios const *current, int regime, int vtime, int vmin, int echo, int sigint) {
	if (CHECK_REG_ECH_SIG) return -1;
}
