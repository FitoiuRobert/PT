#include <stdio.h>
#include <stdlib.h>


int main(void)
{
  FILE *fp;
  char buff[64],*arr;
  
  printf("%zu\n",sizeof(buff));
  arr = malloc(sizeof(buff));
  printf("%zu\n",sizeof(buff));
  
  return 0;
}
