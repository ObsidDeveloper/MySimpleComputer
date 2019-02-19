#ifndef MYTERMINAL_H
#define MYTERMINAL_H

#define BGCOLOR "\E[4%dm"
#define FGCOLOR "\E[3%dm"
#define CLS "\E[H\E[J"
#define POS "\E[%d;%dH"

enum Colors {
	DEFAULT = 9,
	BLACK = 0,
	WHITE = 7,
	GREEN = 2,
	RED = 1,
	BLUE = 4
};

#endif
