#ifndef BIGCHARS_H
#define BIGCHARS_H

#include "mta/MyTerminal.h"

#define EN_ACS "\E(0"
#define DS_ACS "\E(B"

#define ACS_CKBOARD "a"

#define horline "q"
#define vertline "x"
#define upleftcorner "l"
#define uprightcorner "k"
#define downleftcorner "m"
#define downrightcorner "j"


int bc_printA (char *str);
int bc_box(int leftX, int leftY, int deltaX, int deltaY);
int bc_printbigchar (int symbol[2], int x, int y, enum Colors bgcolor, enum Colors fgcolor);
int bc_setbigcharpos(int *big, int x, int y, int value);
int bc_getbigcharpos(int *big, int x, int y, int *value);

#endif
