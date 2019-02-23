#include "BigChars.h"
#include "msca/MySimpleComputer.h"
#include "mta/MyTerminal.h"

int main() {
	sc_memoryInit();
	/*bc_printA("m");
	mt_gotoXY(15, 15);
	bc_box(10, 10, 6, 6);*/
	int s[2];
	s[0] = 0xff8181ff;
	s[1] = 0xff8181ff;
	bc_printbigchar(s, 10, 10, WHITE, RED);
	return 0;
}
