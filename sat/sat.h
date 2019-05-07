#ifndef SAT
#define SAT

#define SAT_STD_NUMMER_STR_SIZE 8
#define SAT_STD_COMMAND_STR_SIZE 8
#define SAT_STD_OPERAND_STR_SIZE 8

#include <stdio.h>
FILE *fff;

int sat(char *sourcecode_filename, char *code_filename);
int translate(char *s_filename, char *o_filename);

int toInt(char *str);
char* goToNextString(char *source);
char* missSpaces(char *source);
int readStringToDict(char **dict, int nummer, char **source_ptr);

int removeDict(char ***dict, int rows, int cells);
char*** initDict(char ***dict, int rows, int cells);
int countOfString(char *source);
char* loadSource(char *filename, int *lenght);

int encodeCell(int command, int operand, int *cell);
int satEncoder(char **dict_record, int nummer, int *cell);
int checkCommandSAT(char *command);
#endif // !SAT
