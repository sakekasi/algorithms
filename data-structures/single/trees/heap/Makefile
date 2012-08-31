CC=gcc
CFLAGS=-fPIC
LFLAGS=-L. -lsorting -lheap -lm

main=main.c

heap=heap.o main.o
library=heap.o

all: main debug
shared: main-shared debug-shared

#library compilation files
static-library: $(library)
	ar rcs libheap.a $(library)

shared-library: $(library)
	$(CC) -shared -Wl,-soname,libheap.so -o libheap.so\
	 $(library)


#main compile (static)
debug : clean $(main) static-library
	$(CC) $(main) -g $(LFLAGS) -o heap-dbg

main : clean $(main) static-library
	$(CC) $(main) $(LFLAGS) -o heap

#main compile (shared)
debug-shared: clean $(main) shared-library
	$(CC) -g $(main) -o heap-dbg $(LFLAGS)
main-shared: clean $(main) shared-library
	$(CC) $(main) -o heap $(LFLAGS)


#.o compile
$(heap) : heap.h
	$(CC) $(CFLAGS) $*.c -c -o $@


#clean
.PHONY : clean
clean :
	-rm heap heap-dbg libheap.a libheap.so*\
	 $(heap) *~
