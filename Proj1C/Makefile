# Megan McMillan Project 1C Makefile 4/13/14

CC=gcc
CFLAGS= -g
AR=ar
AR_FLAGS=r
INSTDIR=Proj1C
DIRS=exp trig 
OBJECTS=obj/*.o

all:include lib 
	$(CC) -o cli_compile cli/cli.c -L$(shell pwd)/lib \
		 -I$(shell pwd)/include -lm -lmath330

include:
	mkdir include; cp math330.h include

lib: make_library
	mkdir lib; cp libmath330.a lib 

make_library: obj
	$(AR) $(AR_FLAGS) libmath330.a $(OBJECTS)

obj:
	mkdir obj
	for dir in $(DIRS); do \
		cd $$dir; \
		$(CC) -c *.c -I../; \
		mv *.o ../obj; \
		cd -; \
	done

clean: 
	-rm -rf include/
	-rm -rf lib/
	-rm -rf libmath330.a
	-rm -rf obj/*.o
	-rm -rf obj/
	-rm -rf cli_compile
