#include <stdio.h>

int main(void)
{
  unsigned int n = 0;
  char c;
  while((c = getchar()) != EOF) ++n;

  fprintf(stdout,"\nJust read %d chars from the input file.\n",n);
  
  return n;
}
