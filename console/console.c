#include <stdio.h>

#include "../BigChars.h"
#include "../msca/MySimpleComputer.h"
#include "../mta/MyTerminal.h"
#include "../ReadKey.h"
#include "console.h"

int drawAll() {
	creatBlock(&display_mem, 2);
	displayMemory(&display_mem);
	
	creatBlock(&display_accum, 2);
	creatBlock(&display_instr_count, 2);
	creatBlock(&display_opers, 2);
	creatBlock(&display_keys, 2);
	creatBlock(&display_bigchar, 2);
	
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
	printNumber(x, y, accumulator, DEFAULT);
	/*TODO: create a battery register interface
	  function that returns the value of this register*/
	return 0;
}

int displayCount(struct block_info *count_block) {
	int x = count_block->x + 1;
	int y = count_block->y + 4;
	printNumber(x, y, InstrCount, DEFAULT);
	return 0;
}

int displayOpers(struct block_info *opers_block) {
	/*empty*/
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

	return 0;
}
