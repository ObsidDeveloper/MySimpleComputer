#include "../msca/MySimpleComputer.h"
#include "computer.h"

int cu() {
	int value, command, operand;
	int current_cell;
	sc_countGet(&current_cell);

	sc_memoryGet(current_cell, &value);
	if (sc_commandDecode(value, &command, &operand)) {
		setTimer(0, 0, 0, 0);
		sc_regSet(IGNORTACT, 1);
		return -1;
	}

	if (alu(command, operand)) {
		switch (command) {
		    case READ: {
				value = readFromConsole();
			    sc_memorySet(operand, value);
			    break;
		    }

			case WRITE: {
				sc_memoryGet(operand, &value);
				writeFromConsole(value);
				break;
			}

			case LOAD: {
				sc_accumGet(&value);
				sc_memoryGet(operand, &value);
				sc_accumSet(value);
				break;
			}

			case STORE: {
				sc_accumGet(&value);
				sc_memorySet(operand, value);
				break;
			}

			case JUMP: {
				if (!sc_countSet(operand)) {
					return 0;
				}
				break;
			}

			case JNEG: {
				sc_accumGet(&value);
				if (value < 0) {
					if (!sc_countSet(operand)) {
						return 0;
					}
				}
			    break;
		    }

			case JZ: {
				sc_accumGet(&value);
				if (value == 0) {
					if (!sc_countSet(operand)) {
						return 0;
					}
				}
				break;
			}

		case HALT: {
			setTimer(0, 0, 0, 0);
			sc_regSet(IGNORTACT, 1);
			break;
		}

		default:
			return -1;
		}
	}
	sc_countInkrement();
	return 0;
}
