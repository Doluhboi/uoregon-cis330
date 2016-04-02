prog: main3B.o functions.o image.o
	g++ -o proj3B main3B.o functions.o image.o

main3B.o: main3B.C functions.h image.h
	g++ -c -I. main3B.C

functions.o: functions.C functions.h image.h
	g++ -c -I. functions.C

image.o: image.C image.h
	g++ -c -I. image.C

clean:
	-rm -rf proj3B
	-rm -rf *.o
	-rm -rf 3B_output.pnm
