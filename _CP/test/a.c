#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(void)
{
  int len=strlen("Hello");
  char *s1=malloc(len),
    *s2=" world!";
  len += strlen(s2);
  s1=strcpy(s1,"Hello");
  
  s1 = realloc(s1,len+1);
  puts(strcat(s1,s2));
  
  printf("sz:%d\tlen:%d\n",sizeof(s1),strlen(s1));
  return 0;
}
