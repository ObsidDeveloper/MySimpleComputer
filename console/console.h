#ifndef CONSOLE_H
#define CONSOLE_H

#include "../mta/MyTerminal.h"
#include "../rk/ReadKey.h"

#define STD_X_MEM 1
#define STD_Y_MEM 1
#define STD_DX_MEM 12
#define STD_DY_MEM 62

#define STD_X_ACC 1
#define STD_Y_ACC 63

int command;
int operand;

int mem_ptr;

int acces_inout;
int acces_mem;
int acces_oper;
int acces_acc;
int acces_flag;
int acces_bc;
int acces_count;
int acces_menu;

int display_acces;

#define MEM 0
#define ACC 1
#define INSTR 2
#define OPER 3
#define KEYS 4
#define BC 5
#define IO 6
#define FLAGS 7

void displayInOut();
void displayMemory();
void displayAccumulator();
int displayCounter();
void displayOperation();
void displayFlags();
void displayMenu();
void displayBigCharArea();
void reset();
void showAll();
void messageBox();
void setAcc();
void setPointer();
void setPointer();
void console();
void commandBox();

int updateMemDisplay();
int displayRegGet(int flag, int * value);
int displayRegSet(int flag, int value);
int setDisplayNull();

int readFromConsole();
int writeFromConsole(int value);
#endif
