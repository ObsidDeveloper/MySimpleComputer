#include "MySimpleComputer.h"
int registr;


int sc_regInit(void) {
	registr = registr & 0;
	return 0;
}

int sc_regSet(int flag, int value) {
	if (-1 < flag && flag < 32) {
		if (value == 0) registr = registr & (~(1 << flag));
			else if (value == 1) registr = registr | (1 << flag);
				else return 0;
		return 1;
	}
	return 0;
}

int sc_regGet(int flag, int * value) {
	if (-1 < flag && flag < 32) {
		*value =  (registr >> flag) & 0x1;
		return 1;
	} else return 0;
}
