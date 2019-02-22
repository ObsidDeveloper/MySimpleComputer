#include "BigChars.h"
#include "msca/MySimpleComputer.h"
#include "mta/MyTerminal.h"

int main() {
	sc_memoryInit();
	bc_printA("hello");
	mt_gotoXY(15, 15);
	return 0;
}
