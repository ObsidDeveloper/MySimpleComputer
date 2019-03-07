#include <stdio.h>
#include <string.h>

#include "../BigChars.h"
#include "../msca/MySimpleComputer.h"
#include "../mta/MyTerminal.h"
#include "../ReadKey.h"
#include "console.h"

int initialization() {
	int rows, cols;
	mt_getscreensize(&rows, &cols);
	
	term_cols = 3 + 10*6 + 3 + 4 + 16;
	term_rows = 40;
	
	if (rows < term_rows || cols < term_cols) {
		printf("Sorry, your terminal is smaller than necessary.\n");
		return -1;
	}
}

int initMemoryDisplay() {
	display_mem.x = 1;
	display_mem.y = 1;
	display_mem.deltaX = 2 + 10*6;
	display_mem.deltaY = 4 + 10*2;
	display_mem.bg_textcolor = BLUE;
	display_mem.fg_textcolor = GREEN;
}
