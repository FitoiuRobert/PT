#include <stdio.h>
#define N 20

unsigned int memo[N];
unsigned int c1,c2;

unsigned int fib1(unsigned int n)
{
  ++c1;
  if(n == 0) return 0;
  if(n == 1) return 1;
  if(memo[n] != 0) return memo[n];
  memo[n] = fib1(n-1) + fib1(n-2);
  return memo[n];
}

unsigned long int fib2(unsigned long int n)
{
  ++c2;
  if(n == 0) return 0;
  if(n == 1) return 1;
  return  fib2(n-1) + fib2(n-2);
}

int main(void)
{
  
  memo[0]=0;
  memo[1]=1;
  
  printf("Fib1(%d)= %u\n", N, fib1(N));
  printf("Counter1 = %u\n",c1);
  printf("Fib2(%d)= %u\n", N,fib2(N));
  printf("Counter2 = %u\n",c2);
  return 0;
}


