#include "BigChars.h"
#include "msca/MySimpleComputer.h"
#include "mta/MyTerminal.h"

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
	sc_memoryInit();
	/*bc_printA("m");
	mt_gotoXY(15, 15);
	bc_box(10, 10, 6, 6);*/
	int s[2];
	s[0] = 0xff8181ff;
	s[1] = 0xff8181ff;
	bc_printbigchar(s, 10, 10, WHITE, RED);
	int buf = open("met.txt", O_WRONLY);
	BC_SIZE = 2;
	int result = bc_bigcharwrite(buf, s, 1);
	printf("result of writing: %d\n", result);
	close(buf);
	buf = open("met.txt", O_RDONLY);
	int c;
	result = bc_bigcharread(buf, s, 1, &c);
	bc_printbigchar(s, 10, 10, GREEN, BLUE);
	printf("result: %d\n c: %d\ndescryptor: %d", result, c, buf);
	close(buf);
	return 0;
}
