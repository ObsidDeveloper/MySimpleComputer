#include "console/console.h"
#include "msca/MySimpleComputer.h"

int main() {
	sc_memoryInit();
	sc_regInit();
	initialization();
	
	console();
	return 0;
}
