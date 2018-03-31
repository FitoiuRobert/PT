#include <stdio.h>
#include <stdlib.h>

unsigned pow2(unsigned n);
void gen_arr(unsigned arr[], unsigned n);
void disp_arr(unsigned arr[], unsigned n);
int lin_search(unsigned arr[], unsigned n, unsigned key);
void ins_sort(unsigned arr[], unsigned n);
int bin_search(unsigned arr[], unsigned n,unsigned key,int *step);

int main(void)
{
  
  unsigned n,key, *arr;
  int step=0;
  printf("Enter N\n>>");
  scanf("%u",&n);
  n = pow2(n);
  arr = malloc(sizeof(unsigned)*n);

  gen_arr(arr,n);
  disp_arr(arr,n);;

  printf("Please enter the element you are looking for\n>>");
  scanf("%d",&key);

  int found = lin_search(arr,n,key);
  if(found >= 0) {
    printf("Lineary search:\n");
    printf("Element %u was found at postion %d.\n",key,found);
    printf("No of steps: %u\n",found+1);
  }
  else printf("Element %u could not be found.\n",key);

  ins_sort(arr,n);
  disp_arr(arr,n); 
  found = bin_search(arr,n,key,&step); 
  if(found >= 0){ 
    printf("Binary search:\n");
    printf("Element %u was found at postion %d.\n",key,found); 
    printf("No of steps: %d\n",step); 
  } 
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

int lin_search(unsigned arr[], unsigned n, unsigned key)
{
  unsigned i;
  for(i = 0; i < n; ++i)
    if(arr[i] == key) return i;
  return -1;
}

void ins_sort(unsigned arr[], unsigned n)
{
  
  int i,key,j;
  for(i = 1; i < n; ++i)
    {
      key = arr[i];
      j = i-1;

      while(j >= 0 && arr[j] > key)
	{
	  arr[j+1] = arr[j];
	  j = j - 1;
	}
      arr[j+1] = key;
    }
}

int bin_search(unsigned arr[], unsigned n,unsigned key, int *step)
{
  unsigned l=0,r=n-1;
  int mid;
  while(l <= r)
    {
      ++*step;
      mid = (l+r)/2;
      if(arr[mid] == key) return mid;
      if(arr[mid] < key) l = mid + 1;
      if(arr[mid] > key) r = mid - 1;
    }
  return -1;
}
