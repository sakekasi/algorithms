CC=gcc
CFLAGS=-fPIC -O -g

library = create-destroy.o modif.o utils.o props.o signal.o

all:main

%.o : %.c hash-table.h 
	$(CC) -c -o $@ $< $(CFLAGS)

shared: shared-library
shared-library: $(library)
	$(CC) -shared -Wl,-soname,libhash-table.so -o libhash-table.so  $(library)

main: main.c shared-library
	$(CC) $@.c -g -o hash-table -L. -lhash-table -lm

.PHONY: clean
clean:
	-rm $(library) hash-table libhash-table* *~
