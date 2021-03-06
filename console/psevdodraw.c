#include <stdio.h>
#include <string.h>

#include "../mbca/BigChars.h"
#include "../msca/MySimpleComputer.h"
#include "../mta/MyTerminal.h"
#include "../rk/ReadKey.h"
#include "console.h"

void showAll() {
	int value;
	sc_regGet(IGNORTACT, &value);
	if (value) sc_countGet(&mem_ptr);
	displayInOut();
	displayMemory();
	displayAccumulator();
	displayCounter();
	displayOperation();
	displayFlags();
	displayMenu();
	displayBigCharArea();
	mt_setfgcolor(DEFAULT);
	mt_setbgcolor(DEFAULT);
	fflush(stdout);
	/*mt_gotoXY(1, 1);*/
}

void displayInOut() {
	int value;
	displayRegGet(IO, &value);
	if (value) return;
	
	mt_setfgcolor(BLUE);
	mt_setbgcolor(DEFAULT);
	bc_box(23, 1, 3, 42);
	bc_box(23, 43, 3, 42);

	mt_setfgcolor(DEFAULT);
	mt_setbgcolor(BLUE);
	mt_gotoXY(23, 19);
	printf(" Input ");
	mt_gotoXY(23, 61);
	printf(" Output ");
	mt_setbgcolor(DEFAULT);

	mt_gotoXY(24, 21);
	printf("          ");
	mt_gotoXY(24, 50);
	printf("         ");
	displayRegSet(IO, 1);
}

void displayMemory() {
	int value;
	displayRegGet(MEM, &value);
	int k = 2;
	FILE *ffff = fopen("disMem.txt", "wt");
	fprintf(ffff, "%d", mem_ptr);
	fflush(ffff);
	mt_setfgcolor(BLUE);
	mt_setbgcolor(DEFAULT);
	bc_box(STD_X_MEM, STD_Y_MEM, STD_DX_MEM, STD_DY_MEM);
	mt_setfgcolor(DEFAULT);
	mt_setbgcolor(BLUE);
	mt_gotoXY(1, 28);
	printf("Memory");
	mt_gotoXY(2, 2);

	int i;
	for (i = 0; i < N; i++) {
		mt_setbgcolor(DEFAULT);
		if (mem_ptr == i) mt_setbgcolor(RED);
		sc_memoryGet(i, &value);
		if ((value >> 14)) {
			value = value & 0x3fff;
			printf("-%04X ", value);
		}
		else {
			printf("+%04X ", value);
		}
		if ((i + 1) % 10 == 0) {
			k++;
			mt_gotoXY(k, 2);
		}
	}
	mt_gotoXY(30, 1);
	displayRegSet(MEM, 1);
}

void displayAccumulator() {
	int value;
	displayRegGet(ACC, &value);
	if (value) return;
	mt_setfgcolor(BLUE);
	mt_setbgcolor(DEFAULT);
	bc_box(1, 63, 3, 22);
	mt_setfgcolor(DEFAULT);
	mt_setbgcolor(BLUE);
	mt_gotoXY(1, 67);
	printf(" accumulator ");
	mt_setbgcolor(DEFAULT);
	mt_gotoXY(2, 71);
	sc_accumGet(&value);
	value = (value & 0x3fff);
	if ((value >> 14))
	{
		printf("-%04X", value);
	}
	else
	{
		printf("+%04X", value);
	}
	displayRegSet(ACC, 1);
}

int displayCounter() {
	int value;
	displayRegGet(INSTR, &value);
	if (value) return 0;
	mt_setfgcolor(BLUE);
	mt_setbgcolor(DEFAULT);
	bc_box(4, 63, 3, 22);
	mt_setfgcolor(DEFAULT);
	mt_setbgcolor(BLUE);
	mt_gotoXY(4, 64);
	printf(" instructionCounter ");
	mt_setbgcolor(DEFAULT);
	mt_gotoXY(5, 71);
	printf("+%04X", mem_ptr);
	acces_count = 1;
	displayRegSet(INSTR, 1);
	return 0;
}

void displayOperation() {
	int value;
	displayRegGet(OPER, &value);
	if (value) return;
	mt_setfgcolor(BLUE);
	mt_setbgcolor(DEFAULT);
	bc_box(7, 63, 3, 22);
	mt_setfgcolor(DEFAULT);
	mt_setbgcolor(BLUE);
	mt_gotoXY(7, 68);
	printf(" Operation ");

	sc_memoryGet(mem_ptr, &value);
	command = value >> 7;
	operand = value & bits7;
	mt_setbgcolor(DEFAULT);
	mt_gotoXY(8, 70);
	printf("%02X : %02X", command, operand);
	
	displayRegSet(OPER, 1);
}

void displayFlags() {
	int value;
	displayRegGet(FLAGS, &value);
	if (value) return;
	mt_setfgcolor(BLUE);
	mt_setbgcolor(DEFAULT);
	bc_box(10, 63, 3, 22);
	mt_setfgcolor(DEFAULT);
	mt_setbgcolor(BLUE);
	mt_gotoXY(10, 70);
	printf(" Flags ");

	mt_setbgcolor(DEFAULT);

	mt_gotoXY(11, 68);
	printf("           ");
	sc_regGet(WRONGADD, &value);
	if (value == 1) {
		mt_gotoXY(11, 69);
		printf("A");
	}

	sc_regGet(WRONGFLAG, &value);
	if (value == 1) {
		mt_gotoXY(11, 71);
		printf("F");
	}

	sc_regGet(ERRORFILE, &value);
	if (value == 1) {
		mt_gotoXY(11, 73);
		printf("D");
	}

	sc_regGet(IGNORTACT, &value);
	if (value == 1) {
		mt_gotoXY(11, 75);
		printf("T");
	}

	sc_regGet(ERRORCOM, &value);
	if (value == 1) {
		mt_gotoXY(11, 77);
		printf("C");
	}
	displayRegSet(FLAGS, 1);
}

void displayMenu() {
	if (acces_menu) return;
	mt_setfgcolor(BLUE);
	mt_setbgcolor(DEFAULT);
	bc_box(13, 47, 10, 38);
	mt_gotoXY(13, 48);
	mt_setfgcolor(DEFAULT);
	mt_setbgcolor(BLUE);
	printf(" Keys: ");
	mt_setbgcolor(DEFAULT);
	mt_gotoXY(14, 48);
	printf("L  - load");
	mt_gotoXY(15, 48);
	printf("S  - save");
	mt_gotoXY(16, 48);
	printf("R  - run");
	mt_gotoXY(17, 48);
	printf("T  - step");
	mt_gotoXY(18, 48);
	printf("I  - reset");
	mt_gotoXY(19, 48);
	printf("F5 - accumulator");
	mt_gotoXY(20, 48);
	printf("F6 - instructionCounter");
	mt_gotoXY(21, 48);
	printf("Press \"Q\" to exit.");
	acces_menu = 1;
}

void displayBigCharArea() {
	int value;
	displayRegGet(BC, &value);
	if (value) return;
	mt_setfgcolor(BLUE);
	mt_setbgcolor(DEFAULT);
	bc_box(13, 1, 10, 46);

	int big[2] = {0, 0};
    char ss[8];

	sc_memoryGet(mem_ptr, &value);
	if ((value >> 14)) {
		value = value & 0x3fff;
		sprintf(ss, "-%04X", value);
	}
	else {
		sprintf(ss, "+%04X", value);
	}
	
	for (int i = 0; i < 5; i++){
		bc_initBigChar(big, ss[i]);
		bc_printbigchar(big, 14, 2 + i * 9, DEFAULT, DEFAULT);
	}
	
}
