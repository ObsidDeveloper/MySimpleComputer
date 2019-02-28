#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

#include "SimpleTranslator.h"
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
