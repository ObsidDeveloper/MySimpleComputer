#include <string.h>
#include <stdlib.h>
#include "sat.h"

int delta;

int initDelta() {
	delta = 0;
	return 0;
}

int changeDelta(int change_delta, int remainspace) {
	if (change_delta <= remainspace) {
		delta += change_delta;
		return 0;
	}
	return -1;
}

int checkSyntax(char *str, int *remainspace, int currentstage) {
	if (str == NULL) return -1;
	initDelta();
	char *buffer = getlogos(str, remainspace);
	
	if (!buffer) return -1;

	if (toInt(buffer) == currentstage) {
		missSpaces(str);
		currentline.nummer = currentstage;
		buffer = getlogos(str, remainspace);

		int value = returnCommand(buffer);
		missSpaces(str);

		buffer = getlogos(str, remainspace);
		int oper = toInt(buffer);

		if (value == -1) return value;

		currentline.command = value;
		currentline.operand = oper;
		if (missString(str, &remainspace)) return 1;
		return 0;
	}
	return -1;
}

char * getlogos(char *str, int *remainspace) {
	char * logos = (char *)malloc(8);
	int i = 0;
	while (i < 8 && str[i] != ' ' && str[i] != 10) {
		if (i == *remainspace) {
			free(logos);
			return NULL;
		}
		logos[i] = *str;
		i++;
	}
	logos[i] = 0;
	*remainspace -= i;
	changeDelta(i, *remainspace);
	return logos;
}

int missSpaces(char *str, int *remainspace) {
	if (str == NULL) return -1;

	int i = 0;
	while (*str == ' ') {
		str++;
		i++;
	}
	changeDelta(i, *remainspace);
	return 0;
}


int toInt(char *str) {
	int i;
	int n = 0;
	for (i = 0; i < strlen(str); i++) {
		n *= 10;
		n += str[i] % 46;
	}
	return n;
}

/*This function counts the number of lines separated by a carriage return.*/
int countOfStrings(char *str) {
	if (str == NULL) return -1;
	int count = 1; /*If execution came here, then at least one string is.*/
	while (*str) {
		if (*str == "\n") count++;
	}
	return count;
}

int missString(char *str, int *remainspace) {
	int i = 0;
	while (*str != "\n") {
		str++;
		if (i == *remainspace) return -1;
		i++;
	}
	str++;
	*remainspace -= i;
	changeDelta(i, *remainspace);
	return 0;
}
