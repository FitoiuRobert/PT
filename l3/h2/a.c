#include <stdio.h>
#include <stdlib.h>

unsigned pow2(unsigned n);
void gen_arr(unsigned arr[], unsigned n);
void disp_arr(unsigned arr[], unsigned n);
unsigned lin_search(unsigned arr[], unsigned n, unsigned key,unsigned *steps);
void inserton_sort(unsigned arr[], unsigned n);


int main(void)
{
  
  unsigned n,N,key, arr[],step;
  printf("Enter N\n>>");
  scanf("%d",&N);
  n = pow2(N);
  arr = malloc(sizeof(unsigned)*n);

  gen_arr(arr,n);
  disp_arr(arr,n);

  printf("Please enter the elementyo are looking for\n>>");
  scanf("%d",&key);

  unsigned found = lin_search(arr,n,key);
  if(found) printf("Element %u was found at postion %u.\n",key,found);
  else printf("Element %u could not be found.\n",key);

  
  
  return 0;
}

unsigned pow2(unsigned n){return n == 1 ? 2 : 2*pow2(n-1);}

void gen_arr(unsigned arr[], unsigned n)
{
  for(unsigned i = 0; i < n; ++i)
    arr[i] = rand() % 100;
}

void disp_arr(unsigned arr[],unsigned n)
{
  printf("The generated array is:\n");
  for(unsigned i = 0; i < n; ++i)
    printf("%d ",arr[i]);
  printf("\n");
}

unsigned lin_search(unsigned arr[], unsigned n, unsigned key,unsigned *steps)
{
  unsigned i;
  for(i = 0; i < n; ++i)
    if(arr[i] == key) return i;
  return 0;
}

void inserton_sort(unsigned array[], unsigned n)
{
  
  unsigned i,key,j;
  for(i = 1; i < n; ++i)
    {
      key = arr[i];
      j = i - 1;

      while(j >= 0 && arr[j] > key)
	{
	  arr[j+1] = arr[j];
	  --j;
	}
      arr[j+1] = key;
    }
}
