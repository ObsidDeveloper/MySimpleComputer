#include <stdio.h>

#include "msca/MySimpleComputer.h"
#include "mta/MyTerminal.h"
#include "BigChars.h"

int bc_printA (char *str) {
	printf(EN_ACS);
	printf(str);
	printf(DS_ACS);
	return 0;
}
