.PHONY: clean

CFLAGS=-Wall -g

run: build
	./main

test:build
	./main
	valgrind ./main


build: clean main

main: main.o bst.o

clean:
	rm -f main *.o
