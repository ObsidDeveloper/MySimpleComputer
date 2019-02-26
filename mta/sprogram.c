#include <stdio.h>
#include "MyTerminal.h"

int main() {
	int r, c;
	mt_getscreensize(&r, &c);
	printf("\nOkey, your terminal have %d rows and %d cols", r, c);
	r = r/2;
	c = c/2;
	printf("goto %d, %d", r, c);
	mt_gotoXY(r, c);
	printf("print any key to clear");
	getchar();
	mt_clrscr();
	printf("Screen is clear\nPrint anykey to set bgcolor RED");
	getchar();
	mt_setbgcolor(RED);
	printf("\nPrint anykey to set fgcolor green");
	getchar();
	mt_setfgcolor(BLUE);
	printf("\nShit");
}
