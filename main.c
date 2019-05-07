#include "interface.h"
#include "computer/computer.h"
#include "msca/MySimpleComputer.h"
#include <signal.h>


int main() {

	siginit();
	sc_regInit();
	sc_memoryInit();
	console();

	return 0;
}
