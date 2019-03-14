All: console.a

console.a: init.o console.o psevdodraw.o conmanage.o
	ar cr console.a init.o console.o psevdodraw.o conmanage.o

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
