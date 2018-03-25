#include <stdio.h>

void guess_nr(void)
{
  int l=1,r=100;
  char c;
  
  while((r-l) > 1)
    {
      
      printf("\nIs your number lower then %d? [y/N]",(l+r)/2);
      scanf(" %c",&c);
      //c = getchar();
      //printf("-- c = %c --",c);
      if(c == 'y' || c == 'Y') r = (l+r)/2;
      else l = (l+r)/2;
      //if(l == r) break;
      
      printf("\nIs your number greater then %d[y/N]",(l+r)/2);
      scanf(" %c",&c);
      //c = getchar();
      //printf("-- c = %c --",c);
      if(c == 'y' || c == 'Y')  l = (l+r)/2;
      else r = (l+r)/2;
      //if(l == r) break;
  
    }

  if(l != r)
    {
      printf("\nIs your number greater then %d[y/N]",l);
      scanf(" %c",&c);
    }

  printf("\nYour number is %d\n",(c == 'y' || c == 'Y') ? r : l);
}

int main(void)
{

  guess_nr();
  return 0;
}
