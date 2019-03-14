#include <stdio.h>
#include <string.h>

#include "../mbca/BigChars.h"
#include "../msca/MySimpleComputer.h"
#include "../mta/MyTerminal.h"
#include "../ReadKey.h"
#include "console.h"

int initialization() {
	int rows, cols;
	mt_getscreensize(&rows, &cols);
	
	
	if (rows < NEED_ROWS || cols < NEED_COLS) {
		printf(
			"Sorry, your terminal is smaller than necessary.\n Set %dx%d", 
			NEED_ROWS, NEED_COLS
			);
		return -1;
	}
	initMemoryDisplay();
	initAccumDisplay();
	initCountDisplay();
	initOpersDisplay();
	initKeysDisplay();
	initBigCharDisplay();
	initConsoleBox();
	
	initColors();
	
	InstrCount = 0;
	return 0;
}

int initMemoryDisplay() {
	display_mem.x = 0;
	display_mem.y = 0;
	display_mem.deltaY = STD_MEM_SIZE_Y;
	display_mem.deltaX = STD_MEM_SIZE_X;
	display_mem.bg_textcolor = bg_msc;
	display_mem.fg_textcolor = fg_msc;
	
	strcpy(display_mem.str, "Memory");
	return 0;
}

int initAccumDisplay() {
	display_accum.x = 0;
	display_accum.y = STD_MEM_SIZE_Y + 1;
	display_accum.deltaX = STD_IND_SIZE_X;
	display_accum.deltaY = STD_IND_SIZE_Y;
	display_accum.bg_textcolor = bg_msc;
	display_accum.fg_textcolor = fg_msc;
	
	strcpy(display_accum.str, "Accumulator");
	return 0;
}

int initCountDisplay() {
	display_instr_count.x = STD_IND_SIZE_X + 1;
	display_instr_count.y = STD_MEM_SIZE_Y + 1;
	display_instr_count.deltaX = STD_IND_SIZE_X;
	display_instr_count.deltaY = STD_IND_SIZE_Y;
	display_instr_count.bg_textcolor = bg_msc;
	display_instr_count.fg_textcolor = fg_msc;
	
	strcpy(display_accum.str, "Instruction C.");
	return 0;
}

int initOpersDisplay() {
	display_opers.x = 2 * STD_IND_SIZE_X + 1;
	display_opers.y = STD_MEM_SIZE_Y + 1;
	display_opers.deltaX = STD_IND_SIZE_X;
	display_opers.deltaY = STD_IND_SIZE_Y;
	display_opers.bg_textcolor = bg_msc;
	display_opers.fg_textcolor = fg_msc;
	
	strcpy(display_accum.str, "Operation");
	return 0;
}

int initKeysDisplay() {
	display_keys.x = 3 * STD_IND_SIZE_X + 1;
	display_keys.y = STD_MEM_SIZE_Y + 1;
	display_keys.deltaX = STD_KEYS_SIZE_X;
	display_keys.deltaY = STD_KEYS_SIZE_Y;
	display_keys.bg_textcolor = bg_msc;
	display_keys.fg_textcolor = fg_msc;
	
	strcpy(display_accum.str, "Operation");
	return 0;
}

int initBigCharDisplay() {
	display_bigchar.x = STD_MEM_SIZE_X + 1;
	display_bigchar.y = 0;
	display_bigchar.deltaX = STD_BIGCH_SIZE_X;
	display_bigchar.deltaY = STD_BIGCH_SIZE_Y;
	display_bigchar.bg_textcolor = bg_msc;
	display_bigchar.fg_textcolor = fg_msc;
	
	strcpy(display_bigchar.str, "Zoom");
	return 0;
}

int initConsoleBox() {
	console_box.mes_block.x = 3;
	console_box.mes_block.y = 3;
	console_box.mes_block.deltaX = STD_MESBOX_SIZE_X;
	console_box.mes_block.deltaY = STD_MESBOX_SIZE_Y;
	console_box.mes_block.block_color = WHITE;
}

int initAlertBox() {
	alert_box.inputline_lenght = 0;
	alert_box.input_enabled = 0;
	alert_box.mes_block.x = 7;
	alert_box.mes_block.y = 10;
	alert_box.mes_block.deltaX = 5;
	alert_box.mes_block.deltaY = 40;
	alert_box.mes_block.block_color = WHITE;
}

int initColors() {
	bg_msc = DEFAULT;
	fg_MSC = BLUE;
	highlight = RED;
	return 0;
}
