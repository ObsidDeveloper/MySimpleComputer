#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <string.h>

#include "sat.h"
#include "../msca/MySimpleComputer.h"

int * translate(int fd, int *size) {
	char *SAcode = NULL;
	int size_ofprogram = load_SAfile(fd, SAcode);

	if (size_ofprogram == -1) {
		printf("cannot read source file\n");
		return NULL;
	}

	int size_ofbin = 0;
}

int load_SAfile(int fd, char *SAcode) {
/*This code is from StackOverflow*/
	if (fd != -1) {
		FILE *file = fdopen(fd, "rb");
		if (file) {
			struct stat statistics;
			if (fstat(fd, &statistics) != -1) {
				int size = statistics.st_size;
				SAcode = (char *)malloc(size);
				fwrite(SAcode, sizeof(char), size, file);
				fclose(file);
				return size;
			}
			fclose(file);
			return -1;
		}
		return -1;
	}
	return -1;
}

int returnCommand(char *str) {
	switch (strlen(str)) {
		case 2: {
			if (!strcmp(str, "JZ")) return JZ;
			return -1;
		}
		case 3: {
			if (!strcmp(str, "ADD")) return ADD;
			if (!strcmp(str, "SUB")) return SUB;
			if (!strcmp(str, "MUL")) return MUL;
			return -1;
		}
		case 4: {
			if (!strcmp(str, "READ")) return READ;
			if (!strcmp(str, "LOAD")) return LOAD;
			if (!strcmp(str, "JUMP")) return JUMP;
			if (!strcmp(str, "JNEG")) return JNEG;
			if (!strcmp(str, "HALT")) return HALT;
			return -1;
		}
		case 5: {
			if (!strcmp(str, "WRITE")) return WRITE;
			if (!strcmp(str, "STORE")) return STORE;
			return -1;
		}
		case 6: {
			if (!strcmp(str, "DIVIDE")) return DIVIDE;
			return -1;
		}
	}
	return -1;
}
