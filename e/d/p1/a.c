/*
Using function pointers write a program which prints the value table for the
following functions:
a) 2x^2-1
b) tan(x)
*/

#include <stdio.h>
#include <math.h>



double fun_a(double x)
{
  return 2*(x*x)-1;
}

double fun_b(double x)
{
  return tan(x);
}

int main(void)
{
  double (*fa)(double) = &fun_a;
  double (*fb)(double) = &fun_b;

  printf("Function a:\n");
  for(double i=0; i <= 1; i=i+0.1)
    {
      printf("%f : %f\n",i,(*fa)(i));
    }

  printf("Function b:\n");
  for(double i=0; i <= 1; i=i+0.1)
    {
      printf("%f : %f\n",i,(*fa)(i));
    }
  
  //printf("It runs\n");
  return 0;
}
