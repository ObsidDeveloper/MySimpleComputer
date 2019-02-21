#include "MySimpleComputer.h"
int checkCommand(int command) {
	if (
		command == READ   ||
		command == WRITE  ||
		command == LOAD   ||
		command == STORE  ||
		command == ADD    ||
		command == SUB    ||
		command == DIVIDE ||
		command == MUL    ||
		command == JUMP   ||
		command == JNEG   ||
		command == JZ     ||
		command == HALT   ||
		command == NOT    ||
		command == AND    ||
		command == OR     ||
		command == XOR    ||
		command == JNS    ||
		command == JC     ||
		command == JNC    ||
		command == JP     ||
		command == JNP    ||
		command == CHL    ||
		command == SHR    ||
		command == RCL    ||
		command == RCR    ||
		command == NEG    ||
		command == ADDC   ||
		command == SUBC   ||
		command == LOGLC  ||
		command == LOGRC  ||
		command == RCCL   ||
		command == RCCR   ||
		command == MOVA   ||
		command == MOVR   ||
		command == MOVCA  ||
		command == MOVCR
	) {
		return 0;
	}
		else return -1;
}

int sc_commandEncode(int command, int operand, int * value) {
	if (!checkCommand(command)) {
		sc_regSet(ERRORCOM, 0);
		*value = (*value) & 0;
		*value = (*value) | command;
		*value = (*value) << 7;
		*value = (*value) | operand;
		return 0;
	}
	sc_regSet(ERRORCOM, 1);
	return ERRORCOM;
}

int sc_commandDecode(int value, int * command, int * operand) {
	int buf;
	buf = value & bits7;
	value = value >> 7;
	value = value & bits7;
	if (!checkCommand(value)) {
		sc_regSet(ERRORCOM, 0);
		*command = value;
		*operand = buf;
		return 0;
	}
	sc_regSet(ERRORCOM, 1);
	return ERRORCOM;
}
