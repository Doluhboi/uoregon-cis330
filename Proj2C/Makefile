proj2C: shapes.o driver_2C.o
	gcc -o proj2C driver_2C.o shapes.o

driver_2C.o: prototypes.h driver_2C.c
	gcc -I. -c driver_2C.c

shapes.o: prototypes.h shapes.c
	gcc -I. -c shapes.c
clean: 
	-rm -rf *.o
	-rm -rf proj2C
