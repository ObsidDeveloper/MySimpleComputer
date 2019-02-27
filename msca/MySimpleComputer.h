#ifndef MYSIMPLECOMPUTER_H
#define MYSIMPLECOMPUTER_H

#define N 100
#define M 10


int memory[N];

int sc_memoryInit();

int sc_memorySet(int address, int value);

int sc_memoryGet(int address, int * value);

int sc_memorySave(char * filename);

int sc_memoryLoad(char * filename);

int sc_memoryPrint();

#define WRONGADD 1
#define WRONGFLAG 2
#define ERRORFILE 3
#define ERRORCOM 4
#define WRONGOP 5

int registr;

int sc_regInit(void);

int sc_regSet(int flag, int value);

int sc_regGet(int flag, int * value);

#define bits7 0x7f /* 0111 1111 in bits, - to getting (&) first 7 bits of value*/
#define bits8 0xff

enum coms {
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
