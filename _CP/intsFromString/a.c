#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(void)
{
  char *arr="123ab-123+45z";

  while(*arr)
    {
      if(isdigit(*arr)|| *arr=='-' || *arr=='+')
	{
	  printf("%ld ",strtol(arr,&arr,10));
	  puts(arr);
	}
      else ++arr;
    }

  
  puts("");
  return 0;
}

