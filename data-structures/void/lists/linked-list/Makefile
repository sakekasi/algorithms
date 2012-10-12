CC=gcc
CFLAGS=-fPIC

libname=liblinked-list
header=linked_list.h

library=create-destroy.o destructive.o ndestructive.o utils.o

library: $(library) clean
	$(CC) -shared -Wl,-soname,$(libname).so -lm -o $(libname).so $(library)

$(library): $(header)


.PHONY : clean
clean :
	-rm $(libname).so* $(objects) *~

