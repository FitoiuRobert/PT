#include <stdio.h>
#include <stdlib.h>
#define _NOCHAR 128

int main(void)
{
  int *chfreq = calloc(_NOCHAR,sizeof(int));
  char c;
  
  while((c = fgetc(stdin)) != EOF)
    {
      //int n = c - '0';
      ++chfreq[c];
      //printf("Char %c gave %d");
    }
  printf("\n");
  for(int i = 0; i < _NOCHAR+1; ++i)
    if(chfreq[i])
      printf("Char %c appears %d times\n",i,chfreq[i]);
    
  return 0;
}
