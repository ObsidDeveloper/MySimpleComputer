#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "SimpleAssembler.h"

int sat(char *source, char *bin_filename) {
	if (source == NULL) {
		printf("sat error: \n");
		return -1;
	}
	int descriptor;
	if ((descriptor = open(source, O_RDONLY) == -1) {
		printf("sat error: %s - no such file\n", source);
		return -1;
	}
	int size_ofprogram;
	int *bin = translate(descriptor, &size_ofprogram);

	if (bin == NULL) {
		printf("translator return value -1\n");
		return -1;
	}

	FILE *binfile = fopen(bin_filename, "wb");
	if (binfile) {
		fwrite(bin, sizeof(int), size_ofprogram, binfile);
	} else {
		printf("Cannot writing binary file\n");
		fclose(binfile);
		return -1;
	}
	fclose(binfile);
	liberation(bin);
	return 0;
}
