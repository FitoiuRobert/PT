#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void insertionSort(int arr[], int n);
void disp_arr(int arr[],int n);
void gen_arr(int arr[], int n);

int main(void)
{
  int sz = 11, *arr,count_m,count_i;
  arr = malloc(sizeof(int) * sz);
  
  gen_arr(arr,sz);
  
  /*
  printf("Before Merge Sort:\n");
  disp_arr(arr,sz);
  printf("After Merge Sort:\n");
  mergeSort(arr,0,sz-1);
  
  //disp_arr(arr,sz);
  */
  
  //gen_arr(arr,sz);
  printf("Before Insertion Sort:\n");
  disp_arr(arr,sz);
  printf("After Insertion Sort:\n");
  insertionSort(arr,sz);
  printf("Unsorted array:\n");
  disp_arr(arr,sz);
  
  return 0;
}

void gen_arr(int arr[], int n)
{
  for(int i = 0; i < n ; ++i)
    arr[i] = rand() % 100;
}

void disp_arr(int arr[],int n)
{
  for(int i = 0; i < n; ++i)
    printf("%d ",arr[i]);
  printf("\n");
}

void merge(int arr[], int l, int m, int r)
{
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
  int i, j, k;
  int n1 = m - l + 1;
  int n2 =  r - m;
 
  /* create temp arrays */
  int L[n1], R[n2];
 
  /* Copy data to temp arrays L[] and R[] */
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1+ j];
 
  /* Merge the temp arrays back into arr[l..r]*/
  i = 0; // Initial index of first subarray
  j = 0; // Initial index of second subarray
  k = l; // Initial index of merged subarray
  while (i < n1 && j < n2)
    {
      if (L[i] <= R[j])
        {
	  arr[k] = L[i];
	  i++;
	  // ++count_m;
        }
      else
        {
	  arr[k] = R[j];
	  j++;
	  //++count_m;
        }
      k++;
    }
 
  /* Copy the remaining elements of L[], if there
     are any */
  while (i < n1)
    {
      arr[k] = L[i];
      i++;
      k++;
    }
 
  /* Copy the remaining elements of R[], if there
     are any */
  while (j < n2)
    {
      arr[k] = R[j];
      j++;
      k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
  if (l < r)
    {
      // Same as (l+r)/2, but avoids overflow for
      // large l and h
      int m = l+(r-l)/2;
 
      // Sort first and second halves
      mergeSort(arr, l, m);
      mergeSort(arr, m+1, r);
 
      merge(arr, l, m, r);
    }
}

void insertionSort(int arr[], int n)
{
  
  int i, key, j,tmp[n];
  memcpy(tmp,arr,sizeof(int) * n);
  /* printf("Size of tmp:%d\n",sizeof(tmp)); */
   for (i = 1; i < n; i++)
   {
       key = tmp[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && tmp[j] > key)
       {
           tmp[j+1] = tmp[j];
           j = j-1;
       }
       tmp[j+1] = key;
   }
   disp_arr(tmp,n);
}
