SRC=main3H.C image.C sink.C source.C PNMreader.C PNMwriter.C filters.C filter.C logging.C
OBJ=$(SRC:.C=.o)

prog: $(OBJ)
	g++ $(OBJ) -o proj3G

.C.o: $<
	g++  -g -I. -c $<

clean:
	rm *.o proj3H 3H_output.pnm logger.txt proj3G_checksum
