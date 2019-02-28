#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

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
	int *bin = translate
	return 0;
}
