#include <stdio.h>
#include <stdlib.h>
#include <math.h>
  
void gen_primes(unsigned arr[], unsigned n);
void disp_arr(unsigned arr[], unsigned n);
int prime(unsigned nr);

int main(void)
{
  unsigned n, *arr;
  
  printf("Please enter the number of first N numbers to be generated: ");
  scanf("%d",&n);
  arr = malloc(sizeof(unsigned) * n);

  gen_primes(arr,n);
  disp_arr(arr,n);
  
  return 0;
}

void disp_arr(unsigned arr[], unsigned n)
{
  for(unsigned i = 0; i < n; ++i) printf("%u ",arr[i]);
  printf("\n");
}

int prime(unsigned nr){
  unsigned limit = sqrt(nr);
  for(unsigned k = limit; k > 2; --k)
    if(nr % k == 0) return 0;
  return 1;
}

void gen_primes(unsigned arr[], unsigned n)
{
  arr[0]=2;arr[1]=3;
  for(unsigned i = 2; i < n; ++i)
    {
      
      for(unsigned j = arr[i-1]+2; ; j +=2)
	if(prime(j)) {arr[i] = j; break;}
	
    }    
}
