output=sorting
debug=sorting-dbg
libname=libsorting
header=sorting.h

CC=gcc
CFLAGS=-fPIC
LFLAGS=-L. -l$(libname)

main = main.c

objects=bubble-sort.o selection-sort.o insertion-sort.o merge-sort.o\
	quick-sort.o quicker-sort.o swap.o main.o heapsort.o
library=bubble-sort.o selection-sort.o insertion-sort.o merge-sort.o\
	quick-sort.o quicker-sort.o swap.o heapsort.o

heaploc=~/Programming/algorithms/data-structures/trees/heap/



all: main debug
shared: main-shared debug-shared

#library compilation files
static-library: $(library)
	ar rcs $(libname).a $(library)

shared-library: $(library)
	$(CC) -shared -Wl,-soname,$(libname).so -L. -lheap -lm -o \
	 $(libname).so $(library)

#main compile (static)
debug : clean $(main) static-library
	$(CC) $(main) -g $(LFLAGS) -o $(debug)

main : clean $(main) static-library
	$(CC) $(main) $(LFLAGS) -o $(output)


#main compile (shared)
debug-shared: clean $(main) shared-library
	$(CC) -g $(main) -o $(debug) $(LFLAGS)
main-shared: clean $(main) shared-library
	$(CC) $(main) -o $(output) $(LFLAGS)

$(objects) : $(header)

#heapsort.o : sorting.h
#	$(CC) -c $*.c -L$(heaploc) -lheap 

heapsort.o : sorting.h
	$(CC) $(CFLAGS) -c $*.c -o $@ -L. -lheap -lm

.PHONY : clean
clean :
	-rm $(output) $(debug) $(libname).a $(libname).so*\
	 $(objects) *~
