#include<stdio.h>
#include<string.h>
 
unsigned valid(char s[13])
{
  unsigned len = strlen(s) - 1,sum = 0;
 
  for(unsigned i = 0; i < len; ++i)
    if(i&1) sum += (s[i] - '0') * 3;
    else sum += s[i] - '0';
  return (10 - (sum % 10)) == (s[len] - '0') ? 1 : 0;
}
 
int main(void)
{
  char s[13];
 
  scanf("%13s",&s);
 
  if(valid(s)) printf("Valid\n");
  else printf("Invalid\n");
  //printf("\n%d\n",strlen(s));
 
  return 0;
}
