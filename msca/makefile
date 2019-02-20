all: MSC

MSC: program.o msc.a
	gcc -o MSC program.o -L. msc.a

program.o: program.c
	gcc -c program.c

msc.a: MemoryFunc.o CommandFunc.o RegistrFunc.o
	ar cr msc.a MemoryFunc.o CommandFunc.o RegistrFunc.o

MemoryFunc.o: MemoryFunc.c
	gcc -c MemoryFunc.c

CommandFunc.o: CommandFunc.c
	gcc -c CommandFunc.c
	
RegistrFunc.o: RegistrFunc.c
	gcc -c RegistrFunc.c

clear:
	rm *.o
	rm *.exe
	rm *.a