// This program is from: Abdul
// The author believes it has <2> memory errors

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* callee allocates memory and returns pointer */
char *function1()
{
  char *buf = (char *)malloc(40);
  strcpy(buf, "Allocated in function1");
  return buf;
}

/* caller allocates memory and passes a pointer to it */
void function2(char *buf)
{
  strcpy(buf, "Modified in function2");
}

int main()
{
  char *buf1 = function1();

  char *buf2 = (char *)malloc(40);

  strcpy(buf2, "Allocated on the heap");

  char buf3[] = "Allocated on the stack";

  printf("\nbuf1: %s\n", buf1);

  printf("\nbuf2: %s\n", buf2);
  
  function2(buf2);

  printf("\nbuf2: %s\n", buf2);

  printf("\nbuf3: %s\n", buf3);

  function2(buf3);

  printf("\nbuf3: %s\n", buf3);

  printf("\n");
}
