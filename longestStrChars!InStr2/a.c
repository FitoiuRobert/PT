#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void f(char s1[], char s2[],char *buff)
{
  buff = malloc(sizeof(char*));
  
  int len = strlen(s2), max = 0,gMax = 0;
  for(int i = 0; s1[i]; ++i)
    {
      int flag = 1;
      for(int j = 0; s2[j]; ++j)
	if(s1[i] == s2[j]) flag = 0;
      if(flag)
	{
	  ++max;
	  if(gMax <= max)
	    {
	      gMax = max;
	      buff = realloc(buff,sizeof(char)*gMax);
	      int count = 0;
	      for(int k = gMax-1; k >= 0; --k)
		buff[count++] = s1[i-k];
	    }
	}
      else
	{
	  max = 0;
	}
      
    }
  puts(buff);
  free(buff);
}

int main(void)
{
  char s1[] = "2abccabcbbca1cFUCK THIS SHIT", s2[] = "1c", *buff;
  //buff = malloc(sizeof(char) * strlen(s1));

  printf("String 1: %s\nString 2: %s\nString f: ",s1,s2);
  f(s1,s2,buff);
  return 0;
}
