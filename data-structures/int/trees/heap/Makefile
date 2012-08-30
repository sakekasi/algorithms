CC=gcc
CFLAGS=-fPIC
LFLAGS=-L. -lsorting -lheap -lm

main=main.c

library=heap.o

all: main

shared: shared-library
shared-library: $(library)
	$(CC) -shared -Wl,-soname,libheap.so -o libheap.so\
	 $(library)


main: clean $(main) shared-library
	$(CC) -g $(main) -o heap $(LFLAGS)


#.o compile
$(library) : heap.h
	$(CC) $(CFLAGS) $*.c -c -o $@


#clean
.PHONY : clean
clean :
	-rm heap heap-dbg libheap.a libheap.so*\
	 $(heap) *~
