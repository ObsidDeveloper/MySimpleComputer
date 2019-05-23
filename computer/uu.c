#include "../msca/MySimpleComputer.h"
#include "../console/console.h"
#include "computer.h"
#include <stdio.h>

int cu() {
	int value, command, operand;
	int current_cell;
	sc_regGet(IGNORTIME, &value);
	if (value) return 1;
	FILE *f = fopen("uut.txt", "wt");
	sc_countGet(&current_cell);

	sc_memoryGet(current_cell, &value);
	if (sc_commandDecode(value, &command, &operand)) {
		sc_regSet(IGNORTIME, 1);
		sc_regSet(WRONGOP, 1);
		return -1;
	}

	if (alu(command, operand)) {
		switch (command) {
		    case READ: {
				value = readFromConsole();
			    sc_memorySet(operand, value);
				fprintf(f, "read\n");
				fflush(f);
			    break;
		    }

			case WRITE: {
				sc_memoryGet(operand, &value);
				writeFromConsole(value);
				break;
			}

			case LOAD: {
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
					return sc_countSet(operand);
				}
			    break;
		    }

			case JZ: {
				sc_accumGet(&value);
				if (value == 0) {
					if (sc_countSet(operand)) {
						return 1;
					}
				}
				break;
			}

		case HALT: {
			sc_regSet(IGNORTIME, 1);
			return -1;
		}

		default:
			return -1;
		}
	}
	sc_countInkrement();
	setDisplayNull();
	return 0;
}
