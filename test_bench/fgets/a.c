#include<stdio.h>
#include<string.h>

int main(void)
{
  FILE *f = fopen("in.txt","r");
  char c;

  while(!feof(f))
    {
      printf("%d ",putchar(c = fgetc(f)));
      if(c == EOF) puts("--EOF--");
    }

  return 0;
}

