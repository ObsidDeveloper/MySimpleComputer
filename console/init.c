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
	
	
	if (rows < NEED_ROWS || cols < NEED_COLS) {
		printf("Sorry, your terminal is smaller than necessary.\n");
		return -1;
	}
	initMemoryDisplay();
	initAccumDisplay();
	initCountDisplay();
	initOpersDisplay();
	initKeysDisplay();
	
	return 0;
}

int initMemoryDisplay() {
	display_mem.x = 0;
	display_mem.y = 0;
	display_mem.deltaY = 56;
	display_mem.deltaX = 12;
	display_mem.bg_textcolor = BLUE;
	display_mem.fg_textcolor = GREEN;
	
	strcpy(display_mem.str, "Memory");
	return 0;
}

int initAccumDisplay() {
	display_accum.x = 0;
	display_accum.y = 56 + 1;
	display_accum.deltaX = 4;
	display_accum.deltaY = 16;
	display_accum.bg_textcolor = BLUE;
	display_accum.fg_textcolor = GREEN;
	
	strcpy(display_accum.str, "Accumulator");
	return 0;
}

int initCountDisplay() {
	display_instr_count.x = 6;
	display_instr_count.y = 56 + 1;
	display_instr_count.deltaX = 4;
	display_instr_count.deltaY = 16;
	display_instr_count.bg_textcolor = BLUE;
	display_instr_count.fg_textcolor = GREEN;
	
	strcpy(display_accum.str, "Instruction C.");
	return 0;
}

int initOpersDisplay() {
	display_opers.x = 11;
	display_opers.y = 56 + 1;
	display_opers.deltaX = 4;
	display_opers.deltaY = 16;
	display_opers.bg_textcolor = BLUE;
	display_opers.fg_textcolor = GREEN;
	
	strcpy(display_accum.str, "Operation");
	return 0;
}

int initKeysDisplay() {
	display_keys.x = 19;
	display_keys.y = 56 + 1;
	display_keys.deltaX = 16;
	display_keys.deltaY = 16;
	display_keys.bg_textcolor = BLUE;
	display_keys.fg_textcolor = GREEN;
	
	strcpy(display_accum.str, "Operation");
	return 0;
}
