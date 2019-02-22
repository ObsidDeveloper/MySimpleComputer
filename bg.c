#include "mbca/BigChars.h"
#include "msca/MySimpleComputer.h"
#include "mta/MyTerminal.h"

int main() {
	sc_memoryInit();
	bc_printA("m");
	/*mt_gotoXY(15, 15);*/
	bc_box(10, 10, 6, 6);
	return 0;
}
