output=int-test
header=int-test.h

CC=gcc
CFLAGS=-fPIC -ldl

main = int-test.c

all: main

main: clean $(main)
	$(CC) $(CFLAGS) -g $(main) -o $(output)

.PHONY : clean
clean :
	-rm $(output) $(debug) *~
