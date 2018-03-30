#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLC 64

int main(void)
{
  char buff[MAXLC],**lines;
  FILE *fp;
  int n=0;
  
  fp = fopen("in.txt","r");

  if(fp == NULL) {perror("fopen()"); return -1;}
  else
    {
      lines = malloc(sizeof(buff));
      while(fgets(buff,sizeof(buff),fp))
	{
	  lines[n] = malloc(sizeof(buff));
	  strcpy(lines[n],buff);
	  ++n;
	}
      fprintf(stdout,"\nJust read %d buffers!\n",n);
      for(int i = 0; i < n ; ++i)
      printf("%s\n",lines[i]);
    }
  fclose(fp);
  return 0;
}
