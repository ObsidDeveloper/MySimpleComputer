#include <stdio.h>
#include "MyTerminal.h"

int main() {
	printf("goto 15, 15");
	mt_gotoXY(15, 15);
	getchar();
	mt_clrscr();
	printf("Screen is clear");
}
