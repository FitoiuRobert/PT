#include <stdio.h>


int main(void)
{
  FILE *fp;
  int i=0,nr;
  
  fp = fopen("test.pnm","rb+");

  if(fp == NULL){perror("fopen()"); return -1;}

  while(!feof(fp))
    {
      if(i>2)
	{
	  fscanf(fp," %d",&nr);
	  printf("\n%d",nr);
	}
      ++i;
    }
  printf("%d",i);
  return 0;
}
