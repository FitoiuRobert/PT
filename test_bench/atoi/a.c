#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
  char *arr = "10 -10 9";
  int n=0,i=0,tmp;
  while(*arr){
    sscanf(arr," %d",&tmp);
    printf("%d\n",tmp);
    while(isspace(*arr)) ++arr;
    while(isdigit(*arr) || *arr == '-' || *arr == '+') ++arr;
    n+= tmp;
    ++i;

    
  }
  printf("%d\n",n/i);
  puts(arr);
  
}