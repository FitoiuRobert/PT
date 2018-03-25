#include <stdio.h>
//#include <math.h>

void func(unsigned n);

int main(void)
{
  //int a = sqrt(21);
  unsigned n = 3;

  func(n);
  
  return 0;
}

void func(unsigned n)
{
  unsigned j = 3;
  for(unsigned i = 0; i < n; ++i)
    for(; ;j+=2) if(j < 10) {printf("%u ",j); break;}
  printf("\n");
}
