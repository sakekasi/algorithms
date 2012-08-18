output=int-test
debug=int-test-dbg
header=int-test.h

CC=gcc
CFLAGS=-fPIC -ldl

main = int-test.c

all: main debug

main: clean $(main)
	$(CC) $(CFLAGS) $(main) -o $(output)

debug: clean $(main)
	$(CC) $(CFLAGS) -g $(main) -o $(debug)

.PHONY : clean
clean :
	-rm $(output) $(debug) *~
