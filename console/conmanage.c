#include <stdio.h>

#include "../ReadKey.h"
#include "../msca/MySimpleComputer.h"
#include "console.h"

int console(void) {
	enum Keys key = NONE;

	while (key != EXIT) {
		rk_readKey(&key);
		
		if (memMovement(key)) {
			switch (key) {
				case LOAD: {
					messageBox(&console_box, "Print filename (OPEN)");
					fgets(str_from_input, 128, stdin);
					formatStrBackNull(str_from_input, 128);
					consoleComLoad(str_from_input);
					drawAll();
					break;
				}
				case SAVE: {
					messageBox(&console_box, "Print filename (SAVE)");
					fgets(str_from_input, 128, stdin);
					formatStrBackNull(str_from_input, 128);
					consoleComSave(str_from_input);
					drawAll();
					break;
				}
			}
		}
	}
}

int memMovement(enum Keys key) {
	switch (key) {
	     case LEFT: {
		     if (InstrCount > 0x0) {
			     highlightCell(InstrCount, DEFAULT);
			     InstrCount--;
			     highlightCell(InstrCounter, RED);
		     }
		  return 0;
	     }
	     case RIGHT: {
			 if (InstrCount < N - 1) {
				 highlightCell(InstrCount, DEFAULT);
				 InstrCount++;
				 highlightCell(InstrCount, RED);
			 }
			 return 0;
		 }
		case UP{
			if (InstrCount / 10) {/*REMEMBER: 9/10 == 0*/
				highlightCell(InstrCount, DEFAULT);
				InstrCount -= 10;
				highlightCell(InstrCount, RED);
			}
		    return 0;
		}
		case DOWN: {
			if (InstrCount < (N - M)) {
				highlightCell(InstrCount, DEFAULT);
				InstrCount += 10;
				highlightCell(InstrCount, RED);
			}
			return 0;
		}
	}
	return -1;
}

int formatStrBackNull(char *str, int max_size) {
	int i;
	for (i = 0; i < max_size; i++) {
		if (str[i] == 10) {
			str[i] = 0;
			return 0;
		}
	}
	return -1;
}

int consoleComLoad(char *filename) {
	if (sc_memoryLoad(filename)) {
		messageBox(&alert_box, "Can not read the file");
	}
	return 0;
}

int consoleComSave(char *filename) {
	if (sc_memorySave(filename)) {
		messageBox(&alert_box, "Can not write the file");
	}
	return 0;
}
