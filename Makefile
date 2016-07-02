#compiler
CC=gcc
#linker
LD=gcc
#include file directory
CFLAGS= -std=c99 -I.

#linker rule
testSort: main.o insertionSort.o sort1.o sort2.o
#	gcc -o testSort main.o insertionSort.o
	$(LD) -o testSort main.o insertionSort.o sort1.o sort2.o
	
#compiler rules
main.o: main.c
#gcc -c -I. main.c
	$(CC) -c $(CFLAGS) main.c	
	 
insertionSort.o:
sort1.o: 
sort2.o: 

#clean up procedure		
clean:
	rm *.o

