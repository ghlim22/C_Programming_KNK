inventory2: inventory2.o readline.o
	gcc inventory2.o readline.o -o inventory2
inventory2.o: inventory2.c readline.h
	gcc -c inventory2.c
readline.o: readline.c readline.h
	gcc -c readline.c