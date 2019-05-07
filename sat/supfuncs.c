#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../msca/MySimpleComputer.h"
#include "sat.h"

char* loadSource(char *filename, int *lenght) {
	FILE *file = fopen(filename, "rb");
	if (!file) return NULL;

	fseek(file, 0, 2);
	*lenght = ftell(file);
	fseek(file, 0, 0);

	char *source = (char *)malloc((*lenght)*sizeof(char) + 1);
	fread(source, sizeof(char), *lenght, file);
	source[*lenght] = 0;
	return source;
}

int countOfString(char *source) {
	int count = 1;
	while (*source != 0) {
		if (*source == '\n') count++;
		source++;
	}
	if (*(source - 1) == '\n') count--;
	return count;
}

char*** initDict(char ***dict, int rows, int cells) {
	if (!(rows || cells)) return 1;
	dict = (char ***)malloc(rows * sizeof(char **));
	fprintf(fff, "char *** & %d\n", rows);
	fflush(fff);
	while (rows > 0) {
		rows--;
		dict[rows] = (char **)malloc(cells * sizeof(char *));
		fprintf(fff, "iter %d - yes", rows);
		fflush(fff);
	}
	return dict;
}

int removeDict(char ***dict, int rows, int cells) {
	if (dict) {
		while (rows) {
			rows--;
			int i;
			for (i = 0; i < cells; i++) {
				free(dict[rows][i]);
			}
			free(dict[rows]);
		}
		free(dict);
		return 0;
	}
	return -1;
}

int readStringToDict(char **dict, int nummer, char **source_ptr) {
	fprintf(fff, "inter %d", nummer);
	fflush(fff);
	dict[0] = (char *)malloc(SAT_STD_NUMMER_STR_SIZE + 1);
	dict[1] = (char *)malloc(SAT_STD_COMMAND_STR_SIZE + 1);
	dict[2] = (char *)malloc(SAT_STD_OPERAND_STR_SIZE + 1);

	char *source = *(source_ptr);
	fprintf(fff, "init %d - yes, \n %s \n", nummer, source);
	fflush(fff);
	int i;
	while (source[i] != ' ' && i < SAT_STD_NUMMER_STR_SIZE) {
		dict[0][i] = source[i];
		i++;
	}
	dict[0][i] = 0;
	source += i;
	
	source = missSpaces(source);

	i = 0;
	while (source[i] != ' ' && i < SAT_STD_COMMAND_STR_SIZE) {
		dict[1][i] = source[i];
		i++;
	}
	dict[1][i] = 0;
	source += i;

	source = missSpaces(source);

	i = 0;
	while (source[i] != ' ' && source[i] != '\n' && i < SAT_STD_OPERAND_STR_SIZE) {
		dict[2][i] = source[i];
		i++;
	}
	dict[2][i] = 0;
	source += i;

	fprintf(fff, "\nreaded: %s\n%s%s\n", dict[0], dict[1], dict[2]);
	fflush(fff);
	source = goToNextString(source);
	*(source_ptr) = source;
	return 0;
}

char* missSpaces(char *source) {
	while (*source == ' ') {
		source++;
	}
	return source;
}

char* goToNextString(char *source) {
	while (*source != '\n') {
		source++;
	}
	source++;
	return source;
}

int toInt(char *str) {
	int number = 0;
	int neg = 0;
	if (*str == '-') neg = 1, str++; 
	while (*str != 0) {
		number *= 10;
		number += (*str) % '0';
		str++;
	}
	if (neg) number *= -1;
	return number;
}

int checkCommandSAT(char *command) {
	if (!strncmp(command, "READ", 4)) return READ;
	if (!strncmp(command, "WRITE", 5)) return WRITE;
	if (!strncmp(command, "LOAD", 4)) return LOAD;
	if (!strncmp(command, "STORE", 5)) return STORE;
	if (!strncmp(command, "ADD", 3)) return ADD;
	if (!strncmp(command, "SUB", 3)) return SUB;
	if (!strncmp(command, "DIVIDE", 6)) return DIVIDE;
	if (!strncmp(command, "MUL", 3)) return MUL;
	if (!strncmp(command, "JUMP", 4)) return JUMP;
	if (!strncmp(command, "JZ", 2)) return JZ;
	if (!strncmp(command, "JNEG", 4)) return JNEG;
	if (!strncmp(command, "HALT", 4)) return HALT;
	if (!strncmp(command, "SUBC", 4)) return SUBC;
	if (!strncmp(command, "=", 1)) return 0;
	return -1;
}

int encodeCell(int command, int operand, int *cell) {
	*cell = 0;
	if (command) {
		operand = operand & bits7;
	} else {
		operand = operand & 0x7fff;
	}
	*cell += command;
	*cell = *cell << 7;
	*cell += operand;
	return 0;
}