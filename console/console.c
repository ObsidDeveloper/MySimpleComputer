#include <stdio.h>

#include "../mbca/BigChars.h"
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
		}
		/*interrupts available*/
		if (key == RESET) reset();
		if (key == RUN) {
			
		}
		if (key == STEP) {
			
		}
	}
	rk_myTermRestore(NULL);
	mt_gotoXY(30, 1);
}
