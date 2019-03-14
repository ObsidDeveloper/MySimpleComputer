#ifndef READKEY_H
#define READKEY_H
enum Keys {
	NONE,
	F5,
	F6,
	KLOAD,
	SAVE,
	RUN,
	STEP,
	RESET,
	EXIT,
	UP,
	LEFT,
	RIGHT,
	DOWN,
	EDIT
};

#define CHECK_REG_ECH_SIG (regime < 0 || regime > 1 || echo < 0 || echo > 1 || sigint < 0 || sigint > 1)
#endif
