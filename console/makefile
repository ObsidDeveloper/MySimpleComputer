All: console.a

LIB = ../msca/MemoryFunc.o ../msca/RegistrFunc.o ../msca/CommandFunc.o ../mta/MyTerminal.o ../mbca/BigChars.o ../rk/ReadKey.o

console.a: messagebox.o console.o psevdodraw.o regdisplay.o 
	ar cr console.a messagebox.o console.o psevdodraw.o regdisplay.o

messagebox.o: messagebox.c
	gcc -c messagebox.c

console.o: console.c
	gcc -c console.c

psevdodraw.o: psevdodraw.c
	gcc -c psevdodraw.c

regdisplay.o: regdisplay.c
	gcc -c regdisplay.c

clean:
	rm *.o
	rm console.a
