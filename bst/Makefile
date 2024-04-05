.PHONY: clean

CFLAGS=-Wall -g

run: build
	./main

test:build
	./main
	valgrind ./main


build:
	${MAKE} clean
	${MAKE} main

main: main.o bst.o

clean:
	rm -f main *.o
