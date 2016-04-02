#include <PNMreader.h>
#include <PNMwriter.h>
#include <filters.h>
#include <logging.h>

int main(int argc, char *argv[]) {
	PNMreader reader("gnu.pnm");
	
    PNMwriter writer;
	writer.Write("gnu_out.pnm");
/*
    PNMreader reader("deschutes.pnm");
	
    PNMwriter writer;
	writer.Write("deschutes_out.pnm");
    
    PNMreader reader("hank.pnm");
	
    PNMwriter writer;
	writer.Write("hank_out.pnm");
    
    PNMreader reader("puddles.pnm");
	
    PNMwriter writer;
	writer.Write("puddles_out.pnm");
    
    PNMreader reader("question_marks.pnm");
	
    PNMwriter writer;
	writer.Write("question_marks_out.pnm");

    PNMreader reader("tux.pnm");
	
    PNMwriter writer;
	writer.Write("tux_out.pnm");
 */
    
}
