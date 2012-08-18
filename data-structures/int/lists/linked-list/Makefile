CC=gcc
CFLAGS=-fPIC
LFLAGS=-L. -llinked-list

main=main.c
linked-list=linked-list-accessors.o linked-list-construct-delete.o \
			linked-list-node-ops.o main.o

library=linked-list-accessors.o linked-list-construct-delete.o \
			linked-list-node-ops.o	

all: main debug
shared: main-shared debug-shared

#library compilation files
static-library: $(library)
	ar rcs liblinked-list.a $(library)

shared-library: $(library)
	$(CC) -shared -Wl,-soname,liblinked-list.so -o liblinked-list.so\
	 $(library)


#main compile (static)
debug : clean $(main) static-library
	$(CC) $(main) -g $(LFLAGS) -o linked-list-dbg

main : clean $(main) static-library
	$(CC) $(main) $(LFLAGS) -o linked-list

#main compile (shared)
debug-shared: clean $(main) shared-library
	$(CC) -g $(main) -o linked-list-dbg $(LFLAGS)
main-shared: clean $(main) shared-library
	$(CC) $(main) -o linked-list $(LFLAGS)


#.o compile
$(linked-list) : linked-list.h
	$(CC) $(CFLAGS) $*.c -c -o $@


#clean
.PHONY : clean
clean :
	-rm linked-list linked-list-dbg liblinked-list.a liblinked-list.so*\
	 $(linked-list) *~
