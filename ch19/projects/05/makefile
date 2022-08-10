queueclient: queueclient.o queueADT.o
	gcc queueclient.o queueADT.o -o queueclient
queueclient.o: queueclient.c queueADT.h
	gcc -c queueclient.c
queueADT.o: queueADT.c queueADT.h
	gcc -c queueADT.c