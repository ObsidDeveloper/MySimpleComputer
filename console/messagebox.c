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
