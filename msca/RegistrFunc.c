#include "MySimpleComputer.h"


int sc_regInit(void) {
	registr = registr & 0;
	accumulator = accumulator & 0;
	return 0;
}

int sc_regSet(int flag, int value) {
	if (-1 < flag && flag < 32) {
		if (value == 0) registr = registr & (~(1 << flag));
			else if (value == 1) registr = registr | (1 << flag);
				else return -1;
		return 0;
	}
	sc_regSet(WRONGFLAG, 1);
	return WRONGFLAG;
}

int sc_regGet(int flag, int * value) {
	if (-1 < flag && flag < 32) {
		*value =  (registr >> flag) & 0x1;
		return 0;
	}
	sc_regSet(WRONGFLAG, 1);
	return WRONGFLAG;
}
