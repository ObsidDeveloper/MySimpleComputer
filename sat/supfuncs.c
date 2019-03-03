#include <string.h>
#include <stdlib.h>
#include "sat.h"

int checkSyntax(char *str, int remainspace, int currentstage) {
	if (str == NULL) return -1;
	char *buffer = getlogos(str, &remainspace);
	if (!buffer) return -1;

	if (toInt(buffer) == currentstage) {
		missSpaces(str);
		currentline.nummer = currentstage;
		buffer = getlogos(str, &remainspace);
		int value = returnCommand(buffer);
		missSpaces(str);
		buffer = getlogos(str, &remainspace);
		int oper = toInt(buffer);
		if (value == -1 || N - 1 < oper || oper < 0 ) return value;
		currentline.command 
	}
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
		str++;
	}
	logos[i] = 0;
	*remainspace -= i;
	return logos;
}

int missSpaces(char *str, int *remainspace) {
	if (str == NULL) return -1;

	int i = 0;
	while (str[i] == ' ') {
		str++;
	}
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
