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
