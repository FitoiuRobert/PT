#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int** arr_alloc (size_t x, size_t y)
{
  int** pp = malloc(sizeof(*pp) * x);
  printf("%d and %d\n",sizeof(*pp),sizeof(**pp));
  assert(pp != NULL);
  for(size_t i=0; i<x; i++)
  {
    pp[i] = malloc(sizeof(**pp) * y);
    assert(pp[i] != NULL);
  }

  return pp;
}

int** arr_fill (int** pp, size_t x, size_t y)
{
  for(size_t i=0; i<x; i++)
  {
    for(size_t j=0; j<y; j++)
    {
      pp[i][j] = (int)j + 1;
    }
  }

  return pp;
}

void arr_print (int** pp, size_t x, size_t y)
{
  for(size_t i=0; i<x; i++)
  {
    for(size_t j=0; j<y; j++)
    {
      printf("%d ", pp[i][j]);
    }
    printf("\n");
  }
}

void arr_free (int** pp, size_t x, size_t y)
{
  (void) y;

  for(size_t i=0; i<x; i++)
  {
    free(pp[i]);
    pp[i] = NULL;
  }
  free(pp);
  pp = NULL;
}


int main (void)
{
  size_t x = 2;
  size_t y = 3;
  int** pp;

  pp = arr_alloc(x, y);
  pp = arr_fill(pp, x, y);
  arr_print(pp, x, y);
  arr_free(pp, x, y);

  return 0;
}
