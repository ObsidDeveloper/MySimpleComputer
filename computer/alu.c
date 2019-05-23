#include "../msca/MySimpleComputer.h"
#include "computer.h"

int alu(int command, int operand) {
	int value;
	int accumulator;
	switch (command) {
		case ADD: {
			sc_memoryGet(operand, &value);
			sc_accumGet(&accumulator);
			accumulator += value;
			sc_accumSet(accumulator);
			break;
		}
		case SUB: {
			sc_memoryGet(operand, &value);
			sc_accumGet(&accumulator);
			accumulator -= value;
			sc_accumSet(accumulator);
			break;
		}
		case DIVIDE: {
			sc_memoryGet(operand, &value);
			sc_accumGet(&accumulator);
      		accumulator /= value;
			sc_accumSet(accumulator);
			break;
		}
		case MUL: {
			sc_memoryGet(operand, &value);
			sc_accumGet(&accumulator);
      		accumulator *= value;
			sc_accumSet(accumulator);
			break;
		}
		default: {
			return -1;
		}
	}
	return 0;
}
