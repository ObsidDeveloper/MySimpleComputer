#include <stdio.h>
#include "MySimpleComputer.h"

int memory[N];

int sc_memoryInit() {
	int index = 0;
	for (; index < N; memory[index] = 0, index++);
	return 0;
}

int sc_memorySet(int address, int value) {
	if (address > -1 && address < N) {
		memory[address] = value;
		if (memory[address] == value) return 0;
	}
	return -1;
}

int sc_memoryGet(int address, int * value) {
	if (address > -1 && address < N) {
		*value = memory[address];
		return 0;
	} else return -1;
}

int sc_memorySave(char * filename) {
	FILE *file = fopen(filename, "wb");
	if (file) {
		fwrite(memory, sizeof(int), N, file);
		fclose(file);
		return 0;
	} else fclose(file);
	return -1;
}

int sc_memoryLoad(char * filename) {
	FILE *file = fopen(filename, "rb");
	if (file) {
		fread(memory, sizeof(int), N, file);
		fclose(file);
		return 0;
	} fclose(file);
	return -1;
}

int sc_memoryPrint() {
	printf("\n\n    ");
	int i, j, buf;
	for (i = 0; i < M; i++) printf("%4d", i);
	for (i = 0; i < N; i++) {
		if (!(i%10)) printf("\n%4d%4d", i/10, memory[i]);
			else printf("%4d", memory[i]);
	}
	return 0;
}
