#include <string.h>

int checkSyntax(char *str, int remainspace, int currentstage) {
	if (str == NULL) return -1;
}

char * getlogos(char *str, int remainspace) {
	char * logos = (char *)malloc(8);
	int i = 0;
	while (i < 8 && str[i] != ' ' && str[i] != 10) {
		if (i == remainspace) {
			free(logos);
			return NULL;
		}
		logos[i] = *str;
		str++;
	}
	return logos;
}
