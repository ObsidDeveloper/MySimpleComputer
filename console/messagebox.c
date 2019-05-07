#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../mbca/BigChars.h"
#include "../msca/MySimpleComputer.h"
#include "../mta/MyTerminal.h"
#include "../rk/ReadKey.h"
#include "console.h"
#include "../sat/sat.h"

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
	fscanf(stdin, "%d", &ptr);
	if (-1 < ptr && ptr < N) mem_ptr = ptr;
		else sc_regSet(WRONGADD, 1);
    mt_setbgcolor(DEFAULT);
	setDisplayNull();
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
	sc_accumSet(value);
    //sc_memorySet(mem_ptr, value);
    mt_setbgcolor(DEFAULT);
    setDisplayNull();
}

void commandBox() {
	messageBox();
	mt_gotoXY(6, 21);
	mt_setfgcolor(RED);
	printf("Print command:");
	mt_gotoXY(7, 21);
	char *command;
	command = (char *)malloc(128);
	/*gets(command);*/
	fgets(command, 127, stdin);
	int i;
	int pr = 0;
	char com[8];
	for (i = 0; i < 128; i++) {
		if ((command[i]) == 10) {
			command[i] = 0;
			break;
		}
		if ((command[i]) == 32) pr = 1;
		if (i < 7 && !pr) {
			com[i] = command[i];
		}
	}
	char param1[32];
	char param2[32];

	FILE *f = fopen("fff.txt", "wt");
	fprintf(f, "%s\n", com);
	char *p1, *p2;
	for (i = 0; command[i] && (command[i]) != 32; i++);
	if (command[i]) {
		fprintf(f, "hello\n");
		int j;
		i++;
		for (j = 0; command[i] && (command[i]) != 32; i++, j++) {
			param1[j] = command[i];
		}
		fprintf(f, "%d\n", j);
		param1[j] = 0;
		p1 = param1;
		fprintf(f, "%s\n", p1);
		if (command[i]) {
			i++;
			for (j = 0; command[i] && (command[i]) != 32; i++, j++) {
				param2[j] = command[i];
			}
			param2[j] = 0;
			p2 = param2;
			fprintf(f, "%s\n", p2);
		} else {
			p2 = NULL;
		}
	} else {
		p1 = p2 = NULL;
	}
	fflush(f);
	fclose(f);
	if (!strncmp(com, "sat", 3)) {
		sat(p1, p2);
	}
	if (!strncmp(com, "load", 4)) {
		sc_memoryLoad(p1);
	}
	setDisplayNull();
}
