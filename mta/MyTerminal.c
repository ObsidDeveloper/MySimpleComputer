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

int mt_getscreensize(int *rows,int *cols) {
	struct winsize w;
	if (!ioctl(1, TIOCGWINSZ, &w)) {
		*rows = w.ws_row;
		*cols = w.ws_col;
		return 0;
	}
	return -1;
}

int mt_setfgcolor(enum Colors color) {
	printf(FGCOLOR, color);
	return 0;
}


int mt_setbgcolor(enum Colors color) {
	printf(BGCOLOR, color);
	return 0;
}
