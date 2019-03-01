#ifndef SAT_H
#define SAT_H

struct codeline_info {
	int command;
	int operand;
	int nummer;
};

/*support*/
int checkSyntax(char *str, int remainspace, int currentstage);
char * getlogos(char *str, int *remainspace);
int missSpaces(char *str, int *remainspace);

#endif
