#include <stdio.h>

#include "msca/MySimpleComputer.h"
#include "mta/MyTerminal.h"
#include "mbca/BigChars.h"

int bc_printA (char *str) {
	printf(EN_ACS);
	printf(str);
	printf(DS_ACS);
	return 0;
}

int bc_box(int leftX, int leftY, int deltaX, int deltaY) {
	int i;
	mt_gotoXY(leftX, leftY);
	bc_printA(upleftcorner);

	for (i = 0; i < deltaY - 2; i++) {
		bc_printA(horline);
	}

	bc_printA(uprightcorner);

	for (i = 1; i <= deltaX - 2; i++) {
		mt_gotoXY(leftX + i, leftY);
		bc_printA(vertline);
		mt_gotoXY(leftX + i, leftY + deltaY - 1);
		bc_printA(vertline);
	}

	mt_gotoXY(leftX + deltaX - 1, leftY);
	bc_printA("m");

	for (i = 0; i < deltaY - 2; i++) {
		bc_printA(horline);
	}

	bc_printA(downrightcorner);

	return 0;
}

int bc_printbigchar (int symbol[2], int x, int y, enum Colors bgcolor, enum Colors fgcolor) {
	/*variables must be here*/
	mt_gotoXY(x, y);
	mt_setbgcolor(bgcolor);
	mt_setfgcolor(fgcolor);
	/*this - code*/
	mt_setbgcolor(BLACK);
	mt_setfgcolor(GREEN);
	mt_gotoXY(0, 0);
}
