.PHONY: clean

CFLAGS=-Wall -g

run:
	${MAKE} clean
	${MAKE} driver
	./driver

driver: driver.o rbtree.o

clean:
	rm -f driver *.o
