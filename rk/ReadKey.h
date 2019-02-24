#ifndef READKEY_H
#define READKEY_H

#define CHECK_REG_ECH_SIG (regime < 0 || regime > 1 || echo < 0 || echo > 1 || siginit < 0 || siginit > 1)

enum Keys {
	NONE, F5, F6, LOAD, SAVE, RUN, STEP, RESET, EXIT, UP, LEFT, 
RIGHT, DOWN, EDIT
}

#endif
