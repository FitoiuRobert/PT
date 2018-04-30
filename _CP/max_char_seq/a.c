/*
Write a function that, given a char array, returns the maximum  length of a 
sequence formed by characters not in a char buffer 
*/

#include <stdio.h>
#include <string.h>

int max_seq(char *,char*);

int main(void)
{
  char *arr="abcdabcd1abc12abd3abcdab",
    *buff="1234";

  printf("Max seq has length: %d\n",max_seq(arr,buff));
  //puts("It works!");
  return 0;
}

int max_seq(char *arr, char *buff)
{
  int maxSeq=0,
    currSeq=0;
  
  for(int i=0; arr[i]; ++i)
    {
      if(strchr(buff,arr[i]) != NULL) currSeq=0;
      else ++currSeq;

      if(currSeq > maxSeq) maxSeq=currSeq;
    }

  return maxSeq;
}
