#include <stdio.h>
#include <ctype.h>

int main()
{
  int l,r,m;
  char a;
  printf("Pick a number between 1 and 100.\n");
 Q: printf("Did you pick it? [Y/N]");
  a=getchar();
  ungetc(' ',stdin);
  if (tolower(a)=='y')
    {
      l=1; r=100; 
      do
	{
	  m=(l+r)/2;
	  printf("Is the number lower than %d ?",m);
	  a=getchar();
	  ungetc(' ',stdin);
	  if (tolower(a)=='y')
	    r=m-1;
	  else
	    {
	      if (tolower(a)=='n')
		l=m+1;
	    }
	}while (l<=r);
      printf("Your number is : %d\n",r);
    }
  else
    {
      printf("PICK A NUMBER FML!!!\n");
      goto Q;
    }
  return 0;
}