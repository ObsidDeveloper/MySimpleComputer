#ifndef MYSIMPLECOMPUTER_H
#define MYSIMPLECOMPUTER_H

#define N 100
#define M 10

extern int memory[N];

int sc_memoryInit();

int sc_memorySet(int address, int value);

int sc_memoryGet(int address, int * value);

int sc_memorySave(char * filename);

int sc_memoryLoad(char * filename);

int sc_memoryPrint();

#define flag0 0
#define flag1 1
#define flag2 2
#define flag3 3
#define flag4 4
#define flag5 5
#define flag6 6
#define flag7 7
#define flag8 8
#define flag9 9
#define flag10 10
#define flag11 11
#define flag12 12
#define flag13 13
#define flag14 14
#define flag15 15
#define flag16 16
#define flag17 17
#define flag18 19
#define flag20 20
#define flag21 21
#define flag22 22
#define flag23 23
#define flag24 24
#define flag25 25
#define flag26 26
#define flag27 27
#define flag28 28
#define flag29 29
#define flag30 30
#define flag31 31

extern int registr;

int sc_regInit(void);

int sc_regSet(int flag, int value);

int sc_regGet(int flag, int * value);

#define bits7 127; /*128 - 1 = 111111 in bits, - to getting first 7 bits of value*/

enum {
	/* Input/Output */
	READ   = 0x10,
	WRITE  = 0x11,
	/*Loading/overloading in accum*/
	LOAD   = 0x20,
	STORE  = 0x21,
	/*Arithmethic operations*/
	ADD    = 0x30,
	SUB    = 0x31,
	DIVIDE = 0x32,
	MUL    = 0x33,
	/*ruling*/
	JUMP   = 0x40,
	JNEG   = 0x41,
	JZ     = 0x42,
	HALT   = 0x43,
	/*User operations*/
	NOT    = 0x51,
	AND    = 0x52,
	OR     = 0x53,
	XOR    = 0x54,
	JNS    = 0x55,
	JC     = 0x56,
	JNC    = 0x57,
	JP     = 0x58,
	JNP    = 0x59,
	CHL    = 0x60,
	SHR    = 0x61,
	RCL    = 0x62,
	RCR    = 0x63,
	NEG    = 0x64,
	ADDC   = 0x65,
	SUBC   = 0x66,
	LOGLC  = 0x67,
	LOGRC  = 0x68,
	RCCL   = 0x69,
	RCCR   = 0x70,
	MOVA   = 0x71,
	MOVR   = 0x72,
	MOVCA  = 0x73,
	MOVCR  = 0x74
};

int sc_commandEncode(int command, int operand, int * value);

int sc_commandDecode(int value, int * command, int * operand);

int checkCommand(int command);
#endif
