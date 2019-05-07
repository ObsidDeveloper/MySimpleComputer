#ifndef COMP
#define COMP
int cu();
int alu(int command, int operand);

void signHandler(int signo);
void siginit();
void setTimer(long it_sec, long it_usec, long val_sec, long val_usec);
#endif