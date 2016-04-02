// This program is from: Sarah Yablok
// The author believes it has 4 memory errors

#include <string.h>
#include <stdlib.h>
#include <stdio.h> 

class Book {
		int pgCount;
		char ** pages;
		public:
			Book();
			Book(int c);
			int getPgCount();
			char * getPage(int i);
			void setPage(int i, const char * p);
			~Book();
};

Book::Book() {
	pgCount = 0;
	pages = NULL;
}

Book::Book(int c) {
	pgCount = c;
	pages = new char * [pgCount];
}

int Book::getPgCount() {
	return pgCount;
}

char * Book::getPage(int i) {
	return pages[i];
}

void Book::setPage(int i, const char * p) {
	strcpy(pages[i], p);
}

Book::~Book() {
	for (int i = 0; i < pgCount; i++) {
		free(pages[i]);
	}
	delete [] pages;
}


int main() {
	Book b;
	Book k(2);
	char ** cpy = (char**) malloc(sizeof(char *) * k.getPgCount());
	
	k.setPage(0, "hello");
	k.setPage(1, "world");
	
	for (int i = 0; i < k.getPgCount(); i++) {
		strcpy (cpy[i], "");
	}
	
	
	for(int i = 0; i < k.getPgCount(); i++) {
		char * str = k.getPage(i);
		char * str2 = b.getPage(i);
		strcpy (cpy[i], str2);
  		strcat (cpy[i], str);
	}
	
}
