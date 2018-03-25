#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  char *dest = malloc(12*sizeof(char)), src[] = "Destination String!";

  strcpy(dest,src);
  puts(dest);
  
  return 0;
}
