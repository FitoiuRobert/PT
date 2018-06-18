/*
Write a function that takes an array of floats, a chracter buffer, and their
sizes. Print the numbers into the buffer, separated by one space, and with 6
significant digitis.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ASZ 3
#define BSZ 28



void func(float *arr, int arrsz, char *buff, int buffsz)
{
  buff[0]='\0';
  int sz=0;
  for(int i = 0; i < arrsz; ++i)
    {
      sz += strlen(buff);
      if(sz > buffsz){
	puts(buff);
	printf("Array exceeds size of character buffer!\n");
	exit(1);
      }
      char tmp[10];
      sprintf(tmp,"%.6f ",arr[i]);
      strcat(buff,tmp);
    }
  puts(buff);
}


int main(void)
{
  float arr[]={1.234567, 2.345678, 3.456789, 4.567890};
  char buff[BSZ];


  func(arr,ASZ,buff,16);
  
  exit(0);
}
