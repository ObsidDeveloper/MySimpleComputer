#include <stdio.h>
#include <stdlib.h>
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
	int buf, bitbuf, bytebuf;
	for (i = 0; i < 2; i++) {
		for (by = 3; by > -1; by--) {
			bytebuf = symbol[i];
			buf = (bytebuf >> (by * 8)) & bits8;
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
			big[x / 4] = big[x / 4] | (0x1 << (8 * (4 - x) - 1 - y));
		} else {
			big[x / 4] = big[x / 4] & (~(0x1 << (8 * (4 - x) - 1 - y)));
		}
		return 0;
	}
	return -1;
}

int bc_getbigcharpos(int *big, int x, int y, int *value) {
	if (-1 < x && x < 8 && -1 < y && y < 8) {
		*value = (big[x / 4] >> (8 * (4 - x) - 1 - y)) & 0x1;
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

int bc_initBigChar(int *bigC, char symbol) {
	if (bigC == NULL) return -1;
	
	switch (value) {
		case '-': {
			bigC[0] = 0xFF000000;
			bigC[1] = 0x0;
			break;
		}
        case '+': {
        	big[0] = 0xFF181800;
            big[1] = 0x1818;
			break;
		}
        case '0': {
        	big[0] = 0x818181FF;
			big[1] = 0xFF818181;
			break;
		}
        case '1': {
        	big[0] = 0xC0D8F0E0;
        	big[1] = 0xC0C0C0C0;
			break;
		}
        case '2': {
        	big[0] = 0xFFC0C0FF;
            big[1] = 0xFF030303;
			break;
		}
        case '3': {
        	big[0] = 0xFFC0C0FF;
            big[1] = 0xFFC0C0C0;
			break;
		}
        case '4': {
        	big[0] = 0xFFC3C3C3;
        	big[1] = 0xC0C0C0C0;
			break;
		}
            big[0] = 4291019715;
            big[1] = C0C0C0C0;
            break;
        case '5':
            big[0] = 4278387711;
            big[1] = 4290822336;
            break;
        case '6':
            big[0] = 4278387711;
            big[1] = 4291019715;
            break;
        case '7':
            big[0] = 3233857791;
            big[1] = 3233857728;
            break;
        case '8':
            big[0] = 4291019775;
            big[1] = 4291019715;
            break;
        case '9':
            big[0] = 4291019775;
            big[1] = 4290822336;
            break;
        case 'A':
            big[0] = -8289793;
            big[1] = -2122219135;
            break;
        case 'B':
            big[0] = -14606017;
            big[1] = -8286847;
            break;
        case 'C':
            big[0] = 16843516;
            big[1] = -66977535;
            break;
        case 'D':
            big[0] = -1925111521;
            big[1] = 522273153;
            break;
        case 'E':
            big[0] = 1057030655;
            big[1] = -16711423;
            break;
        case 'F':
            big[0] = 1057030655;
            big[1] = 16843009;
            break;
        default:
            big[0] = 0;
            big[1] = 0;
            break;
    }
}
