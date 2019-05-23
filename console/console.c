#include <stdio.h>

#include "../mbca/BigChars.h"
#include "../computer/computer.h"
#include "../msca/MySimpleComputer.h"
#include "../mta/MyTerminal.h"
#include "../rk/ReadKey.h"
#include "console.h"


void console() {
	mt_clrscr();
	fflush(stdout); 
	enum Keys key = NONE;
	sc_regSet(IGNORTACT, 0);
	mem_ptr = 0;
	/*needed to mormal work begin*/
	
	int value;
	setDisplayNull();
	FILE *f = fopen("ñht.txt", "wt");
	termInit(); /*save terminal to restore after a MSC work*/
	while(key != EXIT) {
		showAll();

		rk_readKey(&key);
		
		sc_regGet(IGNORTACT, &value);
		if (value == 0)
		{
			if (key == RIGHT) {
				if (mem_ptr < N - 1) {
					mem_ptr = mem_ptr + 1, updateMemDisplay();
				}
			}
			if (key == LEFT) if (mem_ptr > 0)  mem_ptr--, updateMemDisplay();
			if (key == UP) if (mem_ptr - 10 >= 0) mem_ptr -= 10, updateMemDisplay();
			if (key == DOWN) if (mem_ptr + 10 < N) mem_ptr += 10, updateMemDisplay();

			if (key == SAVE) sc_memorySave("memory.dat");
			if (key == KLOAD) sc_memoryLoad("memory.dat");
			if (key == F5) setAcc();
			if (key == F6) setPointer();
			
			if (key == CONS) commandBox();
		} else {
			sc_countGet(&value);
			mem_ptr = value;
			fprintf(f, "fuck %d\n", value);
			fflush(f);
			updateMemDisplay();
		}
		/*interrupts available*/
		if (key == RESET) raise(SIGUSR1);
		if (key == RUN) {
			sc_regSet(IGNORTACT, 1);
			sc_regSet(IGNORTIME, 0);
			setTimer(1, 0, 3, 0);
		}
		if (key == STEP) {
			sc_regSet(IGNORTACT, 1);
			cu();
			sc_regSet(IGNORTACT, 0);
		}
	}
	rk_myTermRestore(NULL);
	mt_gotoXY(30, 1);
	fprintf(f, "\nI be here!");
	fflush(f);
}

void reset(int signo) {
	sc_memoryInit();
	sc_regInit();
	sc_countSet(0);
	setDisplayNull();
}

int readFromConsole() {
	rk_myTermRestore(NULL);
	mt_gotoXY(24, 21);
	printf("         ");
	mt_gotoXY(24, 21);
	int value;
	scanf("%x", &value);
	rk_regime();
	return value;
}

int writeFromConsole(int value) {
	rk_myTermRestore(NULL);
	mt_gotoXY(24, 30);
	printf("         ");
	mt_gotoXY(24, 30);
	printf("%x", value);
	rk_regime();
	return 0;
}
