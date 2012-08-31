output=sorting
header=sorting.h

CC=gcc
CFLAGS=-fPIC

main = main.c

library=bubble-sort.o selection-sort.o insertion-sort.o merge-sort.o quick-sort.o quicker-sort.o swap.o heapsort.o


all: shared

#library compilation files
shared: shared-library
shared-library: $(library)
	$(CC) -shared -Wl,-soname,libsorting.so -o libsorting.so $(library)

#main compile (shared)
main: clean shared-library
	$(CC) -g $(main) -o $(output) -L. -lheap -lm -lsorting


$(objects) : $(header)

#heapsort.o : sorting.h
#	$(CC) $(CFLAGS) -c $*.c -o $@ -L. -lheap -lm

.PHONY : clean
clean :
	-rm $(output) $(debug) $(libname).a $(libname).so* $(objects) *~
