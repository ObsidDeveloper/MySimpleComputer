All: rk.a

rk.a: ReadKey.o
	ar cr rk.a ReadKey.o

ReadKey.o: ReadKey.c
	gcc -c ReadKey.c

clean:
	rm *.o
	rm *.a
