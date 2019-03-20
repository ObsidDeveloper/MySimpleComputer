#include "interface.h"
#include "msca/MySimpleComputer.h"
#include <signal.h>


int main() {

	sc_regInit();
	sc_memoryInit();
	console();

	return 0;
}
