#ifndef CONSOLE_H
#define CONSOLE_H

#include "../mta/MyTerminal.h"

int term_rows;
int term_cols;

enum Colors bg_msc;
enum Colors fg_msc;

struct block_info {
	int x;
	int y;
	int deltaX;
	int deltaY;
	char *str; 
	enum Colors block_color;
	enum Colors bg_textcolor;
	enum Colors fg_textcolor; 
};

#endif
