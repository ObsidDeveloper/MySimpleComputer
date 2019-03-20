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

project: 
	make MSC
	make MT
	make MBC
	make RK
	make program
	
program: main.o interface.o msca/msc.a mta/mt.a mbca/mbc.a rk/rk.a console/console.a
	gcc -o binar main.o interface.o -L. msca/msc.a mta/mt.a mbca/mbc.a rk/rk.a console/console.a

interface.o: interface.c
	gcc interface.c -c

main.o: main.c
	gcc main.c -c
	
console: 
	cd console/ && make console.a

MSC: 
	cd msca/ && make msc.a
	
MT: 
	cd mta/ && make mt.a
	
MBC: 
	cd mbca/ && make mbc.a
	
RK: 
	cd rk/ && make rk.a
	
SAT: 
	cd sat/ && make sat.a

rk/rk.a: ReadKey.o
	ar cr rk/rk.a ReadKey.o
	
ReadKey.o: rk/ReadKey.c
	gcc -c rk/ReadKey.c

pro: interface.o
	cd msca/ && make msc.a
	cd mta/ && make mt.a
	cd mbca/ && make mbc.a
	cd rk/ && make rk.a
	cd console/ && make console.a
	gcc -o model interface.o -L. console/console.a msca/msc.a mta/mt.a rk/rk.a

clean: 
	rm *.o
	rm mta/mt.a
	rm mbca/mbc.a
	rm msca/msc.a