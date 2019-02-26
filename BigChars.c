#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h> 

#include "msca/MySimpleComputer.h"
#include "mta/MyTerminal.h"
#include "BigChars.h"

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
	mt_clrscr();
	mt_gotoXY(x, y);
	mt_setbgcolor(bgcolor);
	mt_setfgcolor(fgcolor);
	/*this - code*/
	int i, by, bi;
	int buf, bitbuf;
	for (i = 0; i < 2; i++) {
		for (by = 0; by < 4; by++) {
			buf = (symbol[i] >> (by * 8)) & bits8;
			for (bi = 0; bi < 8; bi++) {
				bitbuf = (buf >> (7 - bi)) & 0x1;
				if (bitbuf) {
					bc_printA(ACS_CKBOARD);
				} else printf(" ");
			}
			mt_gotoXY(++x, y);
		}
	}
	mt_setbgcolor(BLACK);
	mt_setfgcolor(GREEN);
	int xt, yt;
	mt_getscreensize(&xt, &yt);
	mt_gotoXY(xt, 3);
	return 0;
}

int bc_setbigcharpos(int *big, int x, int y, int value) {
	if (-1 < x && x < 8 && -1 < y && y < 8) {
		if (value) {
			big[x % 4] = big[x % 4] | (0x1 << (8 * (x + 1) - 1 - y));
		} else {
			big[x % 4] = big[x % 4] & (~(0x1 << (8 * (x + 1) - 1 - y)));
		}
		return 0;
	}
	return -1;
}

int bc_getbigcharpos(int *big, int x, int y, int *value) {
	if (-1 < x && x < 8 && -1 < y && y < 8) {
		*value = big[x % 4] & (0x1 << (8 * (x + 1) - 1 - y));
		return 0;
	}
	return -1;
}

int bc_bigcharwrite(int fd, int *big, int count) {
	if (fd != -1) {
		if (BC_SIZE == 0 || BC_SIZE < 0) BC_SIZE = BC_SIZE_DEFAULT;
		if (write(fd, big, count * BC_SIZE) == count * BC_SIZE) return 0;
		return -1;
	}
	return -1;
}

int bc_bigcharread(int fd, int *big, int need_count, int *count) {
	if (fd != -1) {
		if (BC_SIZE == 0 || BC_SIZE < 0) BC_SIZE = BC_SIZE_DEFAULT;
		*count = read(fd, big, need_count * BC_SIZE);
		return 0;
	}
	return -1;
}
