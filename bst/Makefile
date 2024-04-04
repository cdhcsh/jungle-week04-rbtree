.PHONY: clean

CFLAGS=-Wall -g

run:
	${MAKE} clean
	${MAKE} main
	./main

main: main.o bst.o

clean:
	rm -f main *.o
