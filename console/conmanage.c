#include <stdio.h>

#include "../ReadKey.h"
#include "console.h"

int console(void) {
	enum Keys key = NONE;

	while (key != EXIT) {
		rk_readKey(&key);

		switch (key) {
		case LEFT: {

			}
		}
	}
}

int memMovement(enum Keys key) {
	/*TODO::WRITE DEFINES OF MSC COLORS - ALL!!!!*/
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