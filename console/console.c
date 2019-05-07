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
	
	termInit(); /*save terminal to restore after a MSC work*/
	while(key != EXIT) {
		showAll();

		rk_readKey(&key);
		
		sc_regGet(IGNORTACT, &value);
		if (value == 0)
		{
			if (key == RIGHT) if (mem_ptr < N - 1) mem_ptr++, updateMemDisplay();
			if (key == LEFT) if (mem_ptr > 0)  mem_ptr--, updateMemDisplay();
			if (key == UP) if (mem_ptr - 10 >= 0) mem_ptr -= 10, updateMemDisplay();
			if (key == DOWN) if (mem_ptr + 10 < N) mem_ptr += 10, updateMemDisplay();

			if (key == SAVE) sc_memorySave("memory.dat");
			if (key == KLOAD) sc_memoryLoad("memory.dat");
			if (key == F5) setAcc();
			if (key == F6) setPointer();
			
			if (key == CONS) commandBox();
		}
		/*interrupts available*/
		if (key == RESET) reset();
		if (key == RUN) {
			sc_regSet(IGNORTACT, 1);
			setTimer(1, 0, 2, 0);
		}
		if (key == STEP) {
			setTimer(0, 0, 0, 0);
			sc_regSet(IGNORTACT, 0);
			raise(SIGALRM);
		}
	}
	rk_myTermRestore(NULL);
	mt_gotoXY(30, 1);
}

void reset() {
	sc_memoryInit();
	sc_regInit();
	sc_countSet(0);
	setDisplayNull();
}

int readFromConsole() {
	rk_myTermRestore(NULL);
	mt_gotoXY(24, 21);
	int value;
	scanf("%x", &value);
	return value;
}

int writeFromConsole(int value) {
	rk_myTermRestore(NULL);
	mt_gotoXY(24, 30);
	printf("%x", value);
	return 0;
}
