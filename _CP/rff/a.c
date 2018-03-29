#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLC 64

int main(void)
{
  char buff[MAXLC],**lines;
  FILE *fp;
  int n=0;

  printf("Size of buff: %zu",sizeof(buff));
  
  fp = fopen("in.txt","r");

  if(fp == NULL) {perror("fopen()"); return -1;}
  else
    {
      lines = malloc(sizeof(char *));
      //printf("Size lines: %zu",sizeof(lines));
      while(fgets(buff,sizeof(buff),fp))
	{
	  printf("\nSize of lines: %zu",sizeof(lines));
	  //puts(buff);
	  //printf("%s",buff);
	  lines[n] = malloc(sizeof(buff));
	  //printf("\n\nSize lines[%d]: %zu\n\n",n,sizeof(lines));
	  //printf("\nCrash after realloc\n");
	  strcpy(lines[n],buff);
	  lines = realloc(lines,sizeof(buff)*(n+1));
	  //printf("\nCrash after strcpy\n");
	  ++n;
	}
      fprintf(stdout,"\nJust read %d buffers!\n",n);
      for(int i = 0; i < n ; ++i)
      printf("%s\n",lines[i]);
      //printf("Size of lines[1]:%zu\nSize of lines[n-1]:%zu",sizeof(lines[1]),sizeof(lines[n-1]));
    }
  fclose(fp);
  return 0;
}
