#ifndef BIGCHARS_H
#define BIGCHARS_H

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
#endif
