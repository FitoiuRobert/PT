#include <stdio.h>

int main(void)
{
  int *p;
  p = NULL;
  *p = 10;
  printf("%d\n",*p);
  
  return 0;
}