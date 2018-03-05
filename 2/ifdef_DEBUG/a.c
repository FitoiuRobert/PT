#include<stdio.h>
#include<stdlib.h>

#ifdef DEBUG
#define DEBUG_TEST 1
#else
#define DEBUG_TEST 0
#endif

void main(void)
{
  
  if(DEBUG_TEST) fprintf(stdout, "[%s][%d] doing something\n", __FILE__, __LINE__);

}
