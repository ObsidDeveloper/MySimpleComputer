#include <stdio.h>
#include <string.h>

#include "../mbca/BigChars.h"
#include "../msca/MySimpleComputer.h"
#include "../mta/MyTerminal.h"
#include "../rk/ReadKey.h"
#include "console.h"

int creatBlock(struct block_info *block, int posreg) {
	FILE *g = fopen("f.txt", "wt");
	fprintf(g, "vrode");
	/*creating box*/
	mt_setfgcolor(block->block_color);
	bc_box(block->x, block->y, block->deltaX, block->deltaY);
	/*end of creating without str*/
	
	if (posreg) {/*if zero do not print header*/
		int strpos = block->deltaY / posreg; /*set pos*/
		mt_gotoXY(block->x, strpos);

		/*print with params*/
		mt_setfgcolor(block->bg_textcolor);
		mt_setbgcolor(block->fg_textcolor);
		printf(" %s ", block->str);
	}
	
	mt_gotoXY(block->x, block->y); /*return pos to begin, default*/
	setDefaultColorsMSC();
	return 0;
	/*The performance is mentally verified 13.03.19 #1*/
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
	/*The performance is mentally verified 13.03.19 #1*/
}

int returnCellPos(int nummer, int *x, int *y) {
	if (0 < nummer && nummer < N) {
		/*(1,1) - posirion of memory[0]*/
		*x = display_mem.x + 1;
		*y = display_mem.y + 1;
		
		*x += nummer/10; /*remember: 9/10 == 0*/
		*y += (nummer%10)*(5 + 1);
		return 0;
	}
	return -1;
	/*The performance is mentally verified 13.03.19 #1*/
}

int printNumber(int x, int y, int value, enum Colors bg_c) {
	mt_gotoXY(x, y);
	mt_setbgcolor(bg_c);
	if (value >= 0) {
		printf("+%04X", value);
	} else {
		printf("+%04X", value);
	}
	mt_setbgcolor(bg_msc);
	/*The performance is mentally verified 13.03.19 #1*/
}

int setDefaultColorsMSC() {
	mt_setfgcolor(fg_msc);
	mt_setbgcolor(bg_msc);
	return 0;
	/*The performance is mentally verified 13.03.19 #1*/
}

int saveColors(enum Colors bg, enum Colors fg, int instruction) {
	bg_res = bg;
	fg_res = fg;
	if (instruction) {
		mt_setbgcolor(bg);
		mt_setfgcolor(fg);
	}
	return 0;
}

int returnSavedColors(enum Colors *bg, enum Colors *fg) {
	if (bg == NULL || fg == NULL) return -1;
	*bg = bg_res;
	*fg = fg_res;
	return 0;
}

int setHighLight(enum Colors c) {
	highlight = c;
	return 0;
	/*The performance is mentally verified 13.03.19 #1*/
}

int creatMessageBox(struct message_box *box, const char *message) {
	/*TODO: this func is too big(realy?), minimize, break into smaller funcs*/
	creatBlock(&(box->mes_block), 0);
	
	int x = box->mes_block.x + 1;
	int y = box->mes_block.y + 1;
	int dl_x = x + box->mes_block.deltaX - 1;
	int dl_y = y + box->mes_block.deltaY - 1;
	
	mt_setbgcolor(box->mes_block.block_color);
	drawField(x, y, dl_x, dl_y);
	
	box->message = message;
	y = box->mes_block.y + (box->mes_block.deltaY - strlen(message))/2;
	
	mt_gotoXY(x, y);
	mt_setbgcolor(box->mes_block.bg_textcolor);
	mt_setfgcolor(box->mes_block.fg_textcolor);
	
	printf("%s", message); /*Hm, why is that? It can be 'printf(message)'. Think about it.*/
	/*remember: message is constant char-string*/
	if (box->input_enabled) {
		x += 2;
		mt_gotoXY(x, y);
		mt_setbgcolor(box->inputline_bgcolor);
		mt_setfgcolor(box->inputline_fgcolor);
		int i;
		for (i = 0; i < box->inputline_lenght; i++) {
			printf(" ");
		}
		mt_gotoXY(x, y);
	}
	else {
		x += 2;
		mt_gotoXY(x, y);
		printf("OK");
	}
	return 0;
}

int drawField(int x, int y, int deltaX, int deltaY) {
	int drawer_i, drawer_j;
	for (drawer_i = x; drawer_i < deltaX; drawer_i++) {
		mt_gotoXY(drawer_i, y);
		for (drawer_j = y; drawer_j < deltaY; drawer_j++) {
			printf(" ");
		}
	}
	return 0;
	/*The performance is mentally verified 13.03.19 #1*/
}

int drawInputLine(int x, int y, struct message_box *box) {
	mt_gotoXY(x, y);
	mt_setbgcolor(box->inputline_bgcolor);
	mt_setfgcolor(box->inputline_fgcolor);
	int i;
	for (i = 0; i < box->inputline_lenght; i++) {
		printf(" ");
	}
	mt_gotoXY(x, y);
	setDefaultColorsMSC();
}
