#include <stdio.h>
#include <ctype.h>


int main(void)
{
  char *arr = "1234 56 78";


  while(arr)
    {
      int n=0;
      while(isdigit(*arr))
	{
	  n = n*10 + (*arr - '0');
	  ++arr;
	}
      
      printf("%d ",n);
    }
  return 0;
}
