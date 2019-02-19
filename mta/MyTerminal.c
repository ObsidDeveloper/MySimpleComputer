#include <stdio.h>
#include <termios.h>
#include <sys/ioctl.h>

#include "MyTerminal.h"

int mt_clrscr(void) {
	printf(CLS);
	return 0;
}

int mt_gotoXY(int x,int y) {
	if (x >= 0 && y >= 0) {
		printf(POS, x, y);
		return 0;
	}
	return -1;
}
