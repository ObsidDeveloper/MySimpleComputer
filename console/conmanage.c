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
	switch (key) {
	case LEFT: {
		if (InstrCount % 10) {
			highlightCell(InstrCount, DEFAULT);
			InstrCount--;
			highlightCell(InstrCounter, RED);
		}
	}
	}
	return 0;
}