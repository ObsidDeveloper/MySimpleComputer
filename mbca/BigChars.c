#include <stdio.h>

#include "MySimpleComputer.h"
#include "MyTerminal.h"
#include "BigChars.h"

int bc_printA (char *str) {
	printf(EN_ACS);
	printf(str);
	printf(DS_ACS);
	return 0;
}
