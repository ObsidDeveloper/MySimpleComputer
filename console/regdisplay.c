#include <stdio.h>

#include "../rk/ReadKey.h"
#include "../msca/MySimpleComputer.h"
#include "console.h"

int setDisplayNull() {
	display_acces = display_acces & 0;
	return 0;
}

int displayRegSet(int flag, int value) {
	if (-1 < flag && flag < 32) {
		if (value == 0) display_acces = display_acces & (~(1 << flag));
			else if (value == 1) display_acces = display_acces | (1 << flag);
				else return -1;
		return 0;
	}
	sc_regSet(WRONGFLAG, 1);
	return WRONGFLAG;
}

int displayRegGet(int flag, int * value) {
	if (-1 < flag && flag < 32) {
		*value =  (display_acces >> flag) & 0x1;
		return 0;
	}
	sc_regSet(WRONGFLAG, 1);
	return WRONGFLAG;
}

int updateMemDisplay() {
	displayRegSet(MEM, 0);
	displayRegSet(ACC, 0);
	displayRegSet(OPER, 0);
	displayRegSet(BC, 0);
	return 0;
}
