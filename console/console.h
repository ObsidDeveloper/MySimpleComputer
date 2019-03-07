#ifndef CONSOLE_H
#define CONSOLE_H

#include "../mta/MyTerminal.h"

int term_rows;
int term_cols;

enum Colors bg_msc;
enum Colors fg_msc;

enum Colors highlight;

struct block_info {
	int x;
	int y;
	int deltaX;
	int deltaY;
	char str[16]; 
	Colors block_color;
	Colors bg_textcolor;
	Colors fg_textcolor; 
};

struct block_info display_mem;
struct block_info display_accum;
struct block_info display_opers;
struct block_info display_instr_count;
struct block_info display_keys;

#endif
