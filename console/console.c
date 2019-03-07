#include <stdio.h>

#include "../BigChars.h"
#include "../msca/MySimpleComputer.h"
#include "../mta/MyTerminal.h"
#include "../ReadKey.h"

int creatBlock(struct block_info *block, int posreg) {
	if (term_rows < block->x || block->x < 0) return -1;
	if (term_cols < block->y || block->y < 0) return -1;
	if (term_rows < (block->x + block->deltaX) || (block->x + block->deltaX) < 0) return -1;
	if (term_cols < (block->y + block->deltaY) || (block->y + block->deltaY) < 0) return -1;
	
	mt_setfgcolor(block->block_color);
	bc_box(block->x, block->y, block->deltaX, block->deltaY);
	
	int strpos = block->y/posreg;
	mt_gotoXY(block->x, strpos);
	
	mt_setfgcolor(block->bg_textcolor);
	mt_setbgcolor(block->fg_textcolor);
	printf(" %s ", block->str);
	mt_gotoXY(block->x, block->y);
	setDefaultColors();
	return 0;
}

int setDefaultColors() {
	mt_setfgcolor(fg_msc);
	mt_setbgcolor(bg_msc);
	return 0;
}
