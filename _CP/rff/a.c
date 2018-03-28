#include <stdio.h>
 main(void)
{
  char c;
  FILE *fp;
  int n=0;

  fp = fopen("inn.txt","r");

  if(fp == NULL) {perror("fopen()"); return -1;}
  else
    {
      while((c = getc(fp)) != EOF)
	{
	  fprintf(stdout,"%c",c);
	  ++n;
	}
      fprintf(stdout,"\nJust read %d characters!\n",n);
    }
  fclose(fp);
  return 0;
}
