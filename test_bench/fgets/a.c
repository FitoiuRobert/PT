#include<stdio.h>
#include<stdlib.h>



int main(void)
{
  FILE *f = fopen("in.txt","r");
  char c;
  
  while(!feof)
    {
      printf("%d ",putchar(c = fgetc(f)));
      if(c == EOF) puts("--EOF--");
    }
      
  return 0;
}
