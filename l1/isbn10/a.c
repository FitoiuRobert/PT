#include<stdio.h>
#include<string.h>
 
unsigned valid(char s[10])
{
  unsigned sum = 0,len = strlen(s)-1;
 
  //printf("len is %d\n",len);
 
  for(unsigned i = 1; i <= len; ++i)
    sum += i * (s[i-1] - '0');
 
  if((sum % 11) == 10) sum = 'X' - '0';
  else sum %= 11;
  return sum == (s[len] - '0') ? 1 : 0;
}

int main(void)
{
  char s[10];
 
  scanf("%10s",&s);
 
  if(valid(s)) printf("Valid\n");
  else printf("Invalid\n");
 
  //printf("It works!\n");
  return 0;
}
