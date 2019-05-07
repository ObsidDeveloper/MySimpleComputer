#include "MySimpleComputer.h"

int instruction_counter;
int accumulator;
int registr;

int sc_regInit(void) {
	registr = registr & 0;
	accumulator = accumulator & 0;
	instruction_counter = instruction_counter & 0;
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

int sc_accumGet(int *value) {
	*value = accumulator;
	return 0;
}

int sc_accumSet(int value) {
	accumulator = value;
	return 0;
}

int sc_countGet(int *value) {
	*value = instruction_counter;
	return 0;
}

int sc_countSet(int value) {
	instruction_counter = value;
	return 0;
}

int sc_countInkrement() {
	if (instruction_counter == N - 1) return -1;
	instruction_counter++;
	return 0;
}