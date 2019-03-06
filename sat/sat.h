#ifndef SAT_H
#define SAT_H

/*
This is a structure template.
Struct save nummer of memory cell - nummer
and data of MSC-command
*/
struct codeline_info {
	int command;
	int operand;
	int nummer;
};
/*Used structure to saving data to translation*/
struct codeline_info currentline;

#define masc_bit14 0x7fff
/*support*/
int checkSyntax(char *str, int remainspace, int currentstage);
char * getlogos(char *str, int *remainspace);
int missSpaces(char *str, int *remainspace);

#endif
