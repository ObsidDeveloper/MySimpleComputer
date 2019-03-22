#include <stdio.h>
#include <string.h>

#include "../mbca/BigChars.h"
#include "../msca/MySimpleComputer.h"
#include "../mta/MyTerminal.h"
#include "../rk/ReadKey.h"
#include "console.h"

void messageBox() {
	rk_myTermRestore(NULL); /*return std. term settings*/
	
    mt_setbgcolor(WHITE);
    mt_setfgcolor(GREEN);
    
    int i, j;
    for (i = 1; i < 60; i++) {
    	for (j = 5; j < 10; j++) {
        	mt_gotoXY(j, i);
			bc_printA(" ");
    	}
    }
    mt_setbgcolor(BLACK);
    for (i = 20; i < 50; i++) {
    	mt_gotoXY(7, i);
    	bc_printA(" ");
    }
    mt_setbgcolor(WHITE);
    bc_box(5, 1, 5, 60);
    setDisplayNull();
}

void setPointer() {
    messageBox();
    mt_gotoXY(6, 21);
    mt_setfgcolor(RED);
    printf("Enter the pointer:");
    mt_gotoXY(7, 21);
    mt_setbgcolor(BLACK);
    mt_setfgcolor(DEFAULT);
    int ptr;
	fscanf(stdin, "%x", &ptr);
	if (-1 < ptr && ptr < N) mem_ptr = ptr;
		else sc_regSet(WRONGADD, 1);
    mt_setbgcolor(DEFAULT);
    setAccesNull();
}

void setAcc() {
	FILE *f = fopen("ght.txt", "at");
	putc('Y', f);
	fclose(f);
    messageBox();
    int value;
    mt_gotoXY(6, 21);
    mt_setfgcolor(RED);
    printf("Enter the value:");
    mt_gotoXY(7, 21);
    mt_setbgcolor(BLACK);
    mt_setfgcolor(DEFAULT);
	fscanf(stdin, "%x", &value);
	if (value > 0) value = value & 0x3fff;
		else {
			value--;
			value = ~value;
			value = value | (0x1 << 14);
		}
	accumulator = value;
    sc_memorySet(mem_ptr, value);
    mt_setbgcolor(DEFAULT);
    setAccesNull();
}
