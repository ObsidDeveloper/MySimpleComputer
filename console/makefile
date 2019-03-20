All: console.a

OBJ = ../msca/MemoryFunc.o ../msca/RegistrFunc.o ../msca/CommandFunc.o ../mta/MyTerminal.o ../mbca/BigChars.o ../rk/ReadKey.o
console.a: init.o console.o psevdodraw.o conmanage.o $(OBJ)
	ar cr console.a init.o console.o psevdodraw.o conmanage.o $(OBJ)

init.o: init.c
	gcc -c init.c

console.o: console.c
	gcc -c console.c

psevdodraw.o: psevdodraw.c
	gcc -c psevdodraw.c

conmanage.o: conmanage.c
	gcc -c conmanage.c

clean:
	rm *.o
	rm console.a
