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

/*struct for saving data about a display*/
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

#define STD_MEM_SIZE_X 22
#define STD_MEM_SIZE_Y 62

#define STD_IND_SIZE_X 5
#define STD_IND_SIZE_Y 16

#define STD_BIGCH_SIZE_X 10
#define STD_BIGCH_SIZE_Y 42

#define STD_KEYS_SIZE_X 10
#define STD_KEYS_SIZE_Y 36

int initMemoryDisplay();
int initAccumDisplay();
int initCountDisplay();
int initOpersDisplay();
int initKeysDisplay();
int initBigCharDisplay();

struct message_box {
	struct block_info mes_block;
	const char *message;
	int input_enabled;
	int inputline_lenght;
	Colors inputline_bgcolor;
	Colors inputline_fgcolor;
};

#define STD_MESBOX_SIZE_X 7
#define STD_MESBOX_SIZE_Y 56

struct message_box console_box;

int initConsoleBox();

int message_display_status; /*unnecessary variable?*/

/*psevdodraw*/
#define NOWHERE_POSREG 0
#define CENTER_POSREG 2
#define BEGIN_POSREG 10

int creatBlock(struct block_info *block, int posreg);
int creatMessageBox(struct message_box *box, const char *message);

int printNumber(int x, int y, int value, enum Colors bg_c);

/*psevdodraw/'color funcs'*/
int initHighLight(enum Colors c);
int highlightCell(int nummer, enum Colors light);
int setHighLight(enum Colors c);

int setDefaultColorsMSC();

/*InstCount - is a variable to display the current memory location.*/
int InstrCount;

#endif
