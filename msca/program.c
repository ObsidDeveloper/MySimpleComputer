#include "MySimpleComputer.h"
#include <stdio.h>

int main() {
	sc_memoryInit();
	sc_memorySet(34, 23);
	int v;
	sc_memoryGet(34, &v);
	printf("\nmust be 23 - %d", v);
	sc_memorySave("data.bin");
	FILE *f = fopen("data.bin", "rb");
	fseek(f, 0, 2);
	printf("\nmust be 400 or 800 - %d", ftell(f));
	fclose(f);
	
	sc_regInit();
	printf("\n flag 67 - error, flag 67 in reality: %d", sc_regGet(67, &v));
	sc_regSet(3, 1);
	sc_regGet(3, &v);
	printf("\non flag 3 init 1 - %d", v);
	sc_regSet(4, 0);
	sc_regGet(4, &v);
	printf("\non flag 4 init 0 - %d", v);
	
	printf("\ncommand 0x1 - not found - %d", sc_commandEncode(0x1, 0x3, &v));
	sc_commandEncode(0x10, 0x34, &v);
	printf("\ncommand 0x10, operand - 0x34, - %d", v);
	int c, o;
	c = o = 0;
	sc_commandDecode(v, &c, &o);
	printf("\n oper = %d, comm = %d", o, c);
	printf("\nexpected: c - 16, o - 52");
	return 0;
}
