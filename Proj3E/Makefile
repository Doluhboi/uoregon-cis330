SRC=main3E.C image.C sink.C source.C filters.C PNMreaderCPP.C PNMwriterCPP.C 

OBJ=$(SRC:.C=.o)

prog: $(OBJ)
	g++ $(OBJ) -g -o proj3E 

.C.o: $<
	g++ -I. -c $<

clean:
	rm *.o proj3E 3E_output.pnm
