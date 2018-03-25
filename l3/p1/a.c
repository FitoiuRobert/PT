#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

void sort(int arr[])
{
  for(int i = 0; i < N; ++i)
    for(int j = i+1; j < N; ++j)
      if(arr[i] > arr[j])
	{
	  int tmp = arr[i];
	  arr[i] = arr[j];
	  arr[j] = tmp;
	}
}

void disp_arr(int arr[]){for(int i=0;arr[i];++i) printf("%d ",arr[i]);printf("\n");}


int main(int argc, char **argv)
{
  int num[N];
  srand(time(NULL));

  for(int i = 0; i < N; ++i)
    {
      num[i] = rand()%100;
    }
  disp_arr(num);
  
  sort(num);
  disp_arr(num);
  
  
  return 0;
}
