#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *c10t13(char s[],char sc[])
{
  unsigned sum = 38;
  //printf("%d\n", strlen(sct13));

  for(int i = 3; i < 12; ++i)
    {
      sc[i] = s[i-3];
      if(i&1) sum += (sc[i] - '0') * 3;
      else sum += sc[i] - '0';
      //printf("Pos %d  Nr %d   Sum %d\n",i,sc[i]-'0',sum);
    }
  printf("Sum = %d\n",sum);
  sum = 10 - (sum % 10);
  sc[12] = sum + '0';
  return sc;
}

char *c13t10(char s[], char sc[])
{
  unsigned sum = 0;
  for(int i = 0; i < 9; ++i)
    {
      sc[i] = s[i+3];
      sum += (i+1)*(sc[i] - '0');
      //printf("Pos %d  Nr %d   Sum %d\n",i,sc[i]-'0',sum);
    }
  sum %= 11;
  if(sum == 10) sc[9] = 'X';
  else sc[9] = sum + '0';
  
  return sc;
}


int main(void)
{
  char s13[] = "9781435704572", s10[] = "0521396549", sct13[14] = "978", sct10[11]="";
  printf("%s\n",c13t10(s13, sct10));

  return 0;
}
