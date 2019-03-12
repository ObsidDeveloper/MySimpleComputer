#ifndef MYTERMINAL_H
#define MYTERMINAL_H

#define TERM "/dev/tty"

#define BGCOLOR "\E[4%dm"
#define FGCOLOR "\E[3%dm"
#define CLS "\E[H\E[J"
#define POS "\E[%d;%dH"

enum Colors {
	DEFAULT = 9,
	BLACK = 0,
	YELLOW = 3,
	VIOLET = 5,
	AQUAMARINE = 6,
	WHITE = 7,
	GREEN = 2,
	RED = 1,
	BLUE = 4
};

int mt_clrscr(void);
int mt_gotoXY(int x,int y);
int mt_getscreensize(int *rows,int *cols);
int mt_setfgcolor(enum Colors color);
int mt_setbgcolor(enum Colors color);

#endif
