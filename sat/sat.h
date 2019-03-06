#ifndef SAT_H
#define SAT_H
/*
	This is the header file of SAT - Simple Assembler Translator.
	SAT is an integral part of extended(!) model My Simple Computer.
	The translator SAT translates the contents of the code in a low level language Simple Assembler
	from a file into a binary file.
	Basic model of My Simple Computer is named MSC (as well as extended, but abbreviated),
	search more in '../msca'. The lib is named msc.a.
	sat - is the static lib - compiled in sat.a
*/

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

/*main func of sat lib*/
int sat(char *source, char *bin_filename);

/*Translator*/
int * translate(int fd, int *size); /*work with file descriptor (fd), return code in int[*size]*/
/*SAcode - 'program'.sa in string*/
int load_SAfile(int fd, char *SAcode); /*load code*/

int returnCommand(char *str);
int satCommandEncode(int *cell);


extern int delta; /*Why it is external? I don't now.*/
/*delta support*/
int initDelta();
int changeDelta(int change_delta, int remainspace);


#define masc_bit14 0x7fff /*This should be transferred to the model MSC.*/


/*support*/
/*checkSyntax - checking syntax and getting data*/
int checkSyntax(char *str, int remainspace, int currentstage);

/*strings funcs, getting substrings, missing symbols and other*/
char * getlogos(char *str, int *remainspace); /*return new string - substring or NULL*/

int missSpaces(char *str, int *remainspace);
int missString(char *str, int *remainspace);

int countOfStrings(char *str);

int toInt(char *str); /*work normally if the str-number is integer*/


#endif
