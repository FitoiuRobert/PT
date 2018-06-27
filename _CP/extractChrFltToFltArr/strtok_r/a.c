/*
Given a character buffer with 6 decimal float numbers separated by spaces, 
write a function that takes as parameters the character buffer, an array of
floats and their sizes. Print the numbers into the float array.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BSZ 35
#define ASZ 3


void fun(char *buff, int buffsz, float *arr, int arrsz)
{
  char *rest = buff;
  char *token;
  for(int i = 0; i < arrsz; ++i)
    {
      token = strtok_r(rest," ",&rest);
      arr[i] = atof(token);
    }
  
}

int main(void)
{
  char buff[] = "1.234567 2.345678 3.456789 4.567890";
  float arr[ASZ];
  //printf("%d\n",strlen(buff));

  fun(buff,BSZ,arr,ASZ);
  
  for(int i = 0; i<ASZ; ++i)
    printf("%f ",arr[i]);

  puts("");
  exit(0);
}
