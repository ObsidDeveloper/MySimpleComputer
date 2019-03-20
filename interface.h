#ifndef INTERFACE_MSC
#define INTERFACE_MSC


#define STD_X_MEM 1
#define STD_Y_MEM 1
#define STD_DX_MEM 12
#define STD_DY_MEM 62

#define STD_X_ACC 1
#define STD_Y_ACC 63


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
int setInstrCounter();
void setPointer();
void console();
int setAccesNull();

int updateMemDisplay();
int displayRegGet(int flag, int * value);
int displayRegSet(int flag, int value);
#endif
