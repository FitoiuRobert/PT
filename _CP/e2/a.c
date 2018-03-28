#include <stdio.h>

int main(void)
{
  unsigned int n = 0;
  char c;
  FILE *fp;
  fp = fopen("in.txt","r");
  if(fp == NULL) { perror("fopen()"); return -1;}

  while((c = fgetc(fp)) != EOF) ++n;

  fclose(fp);

  fprintf(stdout,"\nJust read %d characters from input file\n",n);

  return n;
  
}
