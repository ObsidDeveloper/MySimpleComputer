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


int bc_printA(char *str) {
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

int bc_initBigChar(int *bigC, char value) {
	if (bigC == NULL) return -1;
	
	switch (value) {
		case '-': {
			bigC[0] = 0x000000FF;
			bigC[1] = 0x0;
			break;
		}
        case '+': {
        	bigC[0] = 0x181818FF;
            bigC[1] = 0xFF181818;
			break;
		}
        case '0': {
        	bigC[0] = 0xFF838589;
			bigC[1] = 0x915131FF;
			break;
		}
        case '1': {
        	bigC[0] = 0x01010101;
        	bigC[1] = 0x01010101;
			break;
		}
        case '2': {
        	bigC[0] = 0xff0101ff;
            bigC[1] = 0x808080ff;
			break;
		}
        case '3': {
        	bigC[0] = 0xFF0101FF;
            bigC[1] = 0xFF0101FF;
			break;
		}
        case '4': {
        	bigC[0] = 0x818181FF;
        	bigC[1] = 0x01010101;
			break;
		}
        case '5': {
        	bigC[0] = 0xff8080ff;
            bigC[1] = 0x010101ff;
			break;
		}
        case '6': {
        	bigC[0] = 0xFF8080FF;
            bigC[1] = 0x818181FF;
			break;
		}
        case '7': {
        	bigC[0] = 0xFF010204;
            bigC[1] = 0x08102040;
			break;
		}
        case '8': {
        	bigC[0] = 0xFF8181FF;
            bigC[1] = 0x818181FF;
			break;
		}
        case '9': {
        	bigC[0] = 0xFF8181FF;
            bigC[1] = 0x02040810;
			break;
		}
        case 'A': {
        	bigC[0] = 0x182442FF;
            bigC[1] = 0x4242C3C3;
			break;
		}
        case 'B': {
        	bigC[0] = 0xFC8282FF;
            bigC[1] = 0x828282FF;
			break;
		}
        case 'C': {
        	bigC[0] = 0xFF808080;
            bigC[1] = 0x808080FF;
			break;
		}
        case 'D': {
        	bigC[0] = 0xFF888482;
            bigC[1] = 0x828488FF;
			break;
		}
        case 'E': {
        	bigC[0] = 0xFF8080FF;
            bigC[1] = 0x808080FF;
			break;
		}
        case 'F': {
        	bigC[0] = 0xFF8080F8;
            bigC[1] = 0x80808080;
			break;
		}
        default:
            bigC[0] = 0;
            bigC[1] = 0;
            break;
    }
}
