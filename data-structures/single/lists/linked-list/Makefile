CC=gcc
CFLAGS=-fPIC

main=main.c

static= create-destroy.o destructive.o ndestructive.o utils.o
shared= create-destroy.lo destructive.lo ndestructive.lo utils.lo

library = create-destroy.o destructive.o ndestructive.o utils.o create-destroy.lo destructive.lo ndestructive.lo utils.lo


#library compilation files
library: $(library) clean
	libtool link $(CC) -g -c -O -o liblinked-list.la $(shared) -lm


#.o, .lo compile
$(library) : linked-list.h
	libtool compile $(CC) -g -O -c $*.c



#clean
.PHONY : clean
clean :
	-rm linked-list linked-list-dbg liblinked-list.a liblinked-list.so* liblinked-list.la\
	 $(static) *~
