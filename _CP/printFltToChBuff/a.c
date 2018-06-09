/*
Write a function that takes an array of floats, a chracter buffer, and their
sizes. Print the numbers into the buffer, separated by one space, and with 6
significant digitis.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void prtToBuff(float *, int, char *, int);

int main(void)
{
  float arr[]={3.12, 3.1234, 3.12345, 3.123456};
  char buff[16];
  int arrSz=4,
    buffSz=64;

  prtToBuff(arr, arrSz, buff, buffSz);
  
  
  exit(EXIT_SUCCESS);
}

void prtToBuff(float *arr, int arrSz, char *buff, int buffSz)
{
  int sz=0;
  buff[0]='\0';
  for(int i = 0; i < arrSz; ++i)
    {
      char tmp[40];
      
      sprintf(tmp,"%.6f ",arr[i]);
      sz += strlen(tmp);
      if(sz>buffSz){
	puts(buff);
	fprintf(stderr,"Size of the buffer is too small, some numbers were not printed!\n");
	exit(EXIT_FAILURE);}
      
      strcat(buff,tmp);
      
    }

  puts(buff);
}
