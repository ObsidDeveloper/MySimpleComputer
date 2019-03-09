#include <stdio.h>

#include "../BigChars.h"
#include "../msca/MySimpleComputer.h"
#include "../mta/MyTerminal.h"
#include "../ReadKey.h"
#include "console.h"

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
		y++;
		if (i/10) x++;
	}
	return 0;
}
