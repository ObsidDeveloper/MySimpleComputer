#include "../msca/MySimpleComputer.h"
#include "computer.h"

int alu(int command, int operand) {
	int value;
	switch (command) {
		case ADD: {
			sc_memoryGet(operand, &value);
			accumulator += value;
			break;
		}
		case SUB: {
			sc_memoryGet(operand, &value);
			accumulator -= value;
			break;
		}
		case DIVIDE: {
			sc_memoryGet(operand, &value);
      		accumulator /= value;
			break;
		}
		case MUL: {
			sc_memoryGet(operand, &value);
      		accumulator *= value;
			break;
		}
		default: {
			return -1;
		}
	}
	instruction_counter++;
	return 0;
}
