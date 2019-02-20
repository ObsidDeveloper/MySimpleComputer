all: MT

MT: sprogram.o mt.a
	gcc -o MT sprogram.o -L. mt.a

sprogram: sprogram.c
	gcc -c sprogram.c

mt.a: MyTerminal.o
	ar cr mt.a MyTerminal.o

MyTerminal.o: MyTerminal.c
	gcc -c MyTerminal.c

clear:
	rm *.exe
	rm *.o
	rm *.a