#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
  FILE *fp;
  char c,*arr;
  int n=0;
  
  fp = fopen("in.txt","r");

  if(fp == NULL) {perror("fopen()"); return -1;}
  else{
    arr = malloc(sizeof(c));
    while((c = getc(fp)) != EOF)
      {
	arr = realloc(arr,(n+1)*sizeof(c));
	arr[n] = c;
	++n;
      }
    for(int i = 0; i < n; ++i)
      printf(" %c",arr[i]);
    printf("\n");
  }


    
  fclose(fp);
  return 0;
}
