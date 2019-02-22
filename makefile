All: bg

bg: bg.o mbca/mbc.a msca/msc.a mta/mt.a
	gcc -o bg bg.o -L. mbca/mbc.a msca/msc.a mta/mt.a

mbca/mbc.a: BigChars.o
	ar cr mbca/mbc.a BigChars.o

msca/msc.a: MemoryFunc.o CommandFunc.o RegistrFunc.o
	ar cr msca/msc.a MemoryFunc.o CommandFunc.o RegistrFunc.o

MemoryFunc.o: msca/MemoryFunc.c
	gcc -c msca/MemoryFunc.c

CommandFunc.o: msca/CommandFunc.c
	gcc -c msca/CommandFunc.c
	
RegistrFunc.o: msca/RegistrFunc.c
	gcc -c msca/RegistrFunc.c
	
mta/mt.a: MyTerminal.o
	ar cr mta/mt.a MyTerminal.o

MyTerminal.o: mta/MyTerminal.c
	gcc -c mta/MyTerminal.c

BigChars.o: BigChars.c
	gcc -c BigChars.c

bg.o: bg.c
	gcc -c bg.c

clean: 
	rm *.o
	rm *.exe
	rm mta/mt.a
	rm mbca/mbc.a
	rm msca/msc.a
	