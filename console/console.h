#ifndef CONSOLE_H
#define CONSOLE_H

#include "../mta/MyTerminal.h"

#define NEED_COLS 85
#define NEED_ROWS 25


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

struct block_info display_mem; /*memory field*/
struct block_info display_accum; /*field for accumulator value*/
struct block_info display_opers;
struct block_info display_instr_count; /*nummer of cell in memory*/
struct block_info display_keys; /*help-list of keys for user*/
struct block_info display_bigchar; /*display for printing cell value as a bigchar*/

#endif
