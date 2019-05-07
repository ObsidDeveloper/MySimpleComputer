#include <stdio.h>
#include <stdlib.h>
#include "../msca/MySimpleComputer.h"
#include "sat.h"

char ***dictionary;

int sat(char *sourcecode_filename, char *code_filename) {
	fff = fopen("satf.txt", "wt");
	if (sourcecode_filename == NULL) return -1;
	FILE *s_code_file = fopen(sourcecode_filename, "rb");
	if (s_code_file) {
		fprintf(fff, "source: yes");
		fflush(fff);
		fclose(s_code_file);
		dictionary = initDict(dictionary, N, 3);
		fprintf(fff, "dict is inited");
		fflush(fff);
		if (!translate(sourcecode_filename, code_filename)) {
			fprintf(fff, "sat: yes");
			fflush(fff);
			return 0;
		} else {
			removeDict(dictionary, N, 3);
		}
	}

}

int translate(char *s_filename, char *o_filename) {
	int count_strings;
	int lenght;
	char *source = loadSource(s_filename, &lenght);
	fprintf(fff, "\n%s\n", source);
	fflush(fff);
	if (source) {
		count_strings = countOfString(source);
		fprintf(fff, "\ncount of strings: %d", count_strings);
		fflush(fff);
		int program[N];
		int i;
		for (i = 0; i < count_strings; i++) {
			char **gh = *(dictionary + i);
			fprintf(fff, "it %d\n", i);
			fflush(fff);
			readStringToDict(dictionary[i], i, &source);
			fprintf(fff, "\niter of reading %d", i);
			fflush(fff);
			if (satEncoder(dictionary[i], i, &(program[i])) == -1) {
				free(source);
				return -1;
			}
		}
		for (; i < N; i++) {
			program[i] = 0;
		}
		FILE *o_file = fopen(o_filename, "wb");
		fwrite(program, sizeof(int), N, o_file);
		fflush(o_file);
		fclose(o_file);
		return 0;
	} else {
		return -1;
	}
}

int satEncoder(char **dict_record, int nummer, int *cell) {
	if (nummer != toInt(dict_record[0])) return -1;
	int command = checkCommandSAT(dict_record[1]);
	if (command < 0) {
		return -1;
	} else {
		return encodeCell(command, toInt(dict_record[2]), cell);
	}
}