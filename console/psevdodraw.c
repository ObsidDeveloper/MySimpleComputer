#include <stdio.h>

#include "../BigChars.h"
#include "../msca/MySimpleComputer.h"
#include "../mta/MyTerminal.h"
#include "../ReadKey.h"
#include "console.h"

int creatBlock(struct block_info *block, int posreg) {
	if (NEED_ROWS < block->x || block->x < 0) return -1;
	if (NEED_COLS < block->y || block->y < 0) return -1;
	if (NEED_ROWS < (block->x + block->deltaX) || (block->x + block->deltaX) < 0) return -1;
	if (NEED_COLS < (block->y + block->deltaY) || (block->y + block->deltaY) < 0) return -1;
	
	/*creating box*/
	mt_setfgcolor(block->block_color);
	bc_box(block->x, block->y, block->deltaX, block->deltaY);
	/*end of creating without str*/
	
	int strpos = block->deltaY/posreg; /*set pos*/
	mt_gotoXY(block->x, strpos);
	
	/*print with params*/
	mt_setfgcolor(block->bg_textcolor);
	mt_setbgcolor(block->fg_textcolor);
	printf(" %s ", block->str);
	
	mt_gotoXY(block->x, block->y); /*return pos to begin, default*/
	setDefaultColorsMSC();
	return 0;
}

/*paint over the place number*/
int highlightCell(int nummer, enum Colors light) {
	int value;
	sc_memoryGet(nummer, &value); /*get value through memory interface*/
	
	int x, y;
	returnCellPos(nummer, &x, &y);
	mt_gotoXY(x, y);
	
	mt_setbgcolor(light);
	printf("+%04X", value);
	setDefaultColorsMSC();
	return 0;
}

int returnCellPos(int nummer, int *x, int *y) {
	if (N <= nummer || nummer < 0) return -1;
	
	/*(1,1) - posirion of memory[0]*/
	*x = display_memory.x + 1;
	*y = dixplay_memory.y + 1;
	
	*x += nummer/10; /*remember: 9/10 == 0*/
	*y += (nummer%10)*(5 + 1);
	return 0;
}

int printNumber(int x, int y, enum Colors bg_c) {
	mt_gotoXY(x, y);
	mt_setbgcolor(bg_c);
	printf("+%04X", value);
	mt_setbgcolor(bg_msc);
}

int setDefaultColorsMSC() {
	mt_setfgcolor(fg_msc);
	mt_setbgcolor(bg_msc);
	return 0;
}

int setHighLight(enum Colors c) {
	highlight = c;
	return 0;
}
