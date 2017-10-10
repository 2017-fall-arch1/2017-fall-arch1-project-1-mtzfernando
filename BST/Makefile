all: main

CFLAGS=-g -O3


main: bst.o main.o
	cc -o $@ $^

bst.o: bst.c bst.h
	cc -c $(CFLAGS) bst.c

main.o: main.c bst.h
	cc -c $(CFLAGS) main.c

clean:
	rm -f *.o main


