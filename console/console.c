#include <stdio.h>

#include "../mbca/BigChars.h"
#include "../msca/MySimpleComputer.h"
#include "../mta/MyTerminal.h"
#include "../ReadKey.h"
#include "console.h"

int drawAll() {
	creatBlock(&display_mem, 2);
	creatBlock(&display_accum, 2);
	creatBlock(&display_instr_count, 2);
	creatBlock(&display_opers, 2);
	creatBlock(&display_keys, 2);
	creatBlock(&display_bigchar, 2);

	displayMemory(&display_mem);
	displayAccum(&display_accum);
	displayCount(&display_instr_count);
	displayOpers(&display_opers);
	displayKeys(&display_keys);
	displayBigChars(&display_bigchar);

	return 0;
}

int displayMemory(struct block_info *mem_block) {
	int i = 0;
	int x = mem_block->x + 1;
	int y = mem_block->y + 1;
	/*mt_gotoXY(x, y);*/ /*unuseful*/
	
	int value;
	while (i < N) {
		sc_memoryGet(i, &value);
		printNumber(x, y, value, DEFAULT);
		i++;
		y += 6;
		if (i/10) x++;
	}
	return 0;
}

int displayAccum(struct block_info *acc_block) {
	int x = acc_block->x + 1;
	int y = acc_block->y + 4;
	int value;
	sc_accumGet(&value);
	printNumber(x, y, value, DEFAULT);
	return 0;
}

int displayCount(struct block_info *count_block) {
	int x = count_block->x + 1;
	int y = count_block->y + 4;
	consoleUpdateInstr();
	printNumber(x, y, InstrCount, count_block->bg_textcolor);
	return 0;
}

int displayOpers(struct block_info *opers_block) {
	int value;
	sc_memoryGet(InstrCount, &value);
	
	mt_gotoXY(opers_block->x + 1, opers_block->y + 4);
	int buf;
	buf = value >> 7;
	printf("%02X :", buf);
	buf = value & bits7;
	printf("%02X", buf);
	mt_gotoXY(opers_block->x, opers_block->y);
	return 0;
}

int displayKeys(struct block_info *keys_block) {
	int x = keys_block->x + 1;
	int y = keys_block->y + 4;
	mt_gotoXY(x++, y);
	printf("l - load");

	mt_gotoXY(x++, y);
	printf("s - save");

	mt_gotoXY(x++, y);
	printf("r - run");

	mt_gotoXY(keys_block->x, y - 4);
	return 0;
}

int displayBigChars(struct block_info *bigchar_block) {
	char bigchar_buffer[6];
	int value;

	sc_memoryGet(InstrCount, &value);
	if (value = > 0) {
		sprintf(bigchar_buffer, "+%04X", value);
	}
	else {
		sprintf(bigchar_buffer, "-%04X", value);
	}

	int x = bigchar_block->x + 2;
	int y = bigchar_block->y + 4;
	int i;
	int big[2];
	for (i = 0; i < 5; i++) {
		bc_initBigChar(big, bigchar_buffer[i]);
		bc_printbigchar(big, x, y, WHITE, BLACK);
		y+= 9;
	}
	return 0;
}

int messageBox(struct message_box *box, const char *message) {
	creatMessageBox(box, message);
	if (!box->input_enabled) {
		getchar(); /*press anykey to continue*/
	}
	return 0;
}
/*fucking Google-Translate*/
