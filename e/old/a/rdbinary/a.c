#include <stdio.h>
#include <stdlib.h>



int main(void)
{
  FILE *f;
  int x;
  f = fopen("test.bin","wb");
  if(f == NULL){perror("\nCound not open file!\n"); return 1;}

  for(int i = 0; i < 10; ++i)
    {
      x = i;
      fwrite(&x,sizeof(int),1,f);
    }

  fclose(f);

  f = fopen("test.bin","rb");
  if(f == NULL){perror("\nCound not open file!\n"); return 1;}
  for(int i = 0; i < 10; ++i)
    {
      fread(&x,sizeof(int),1,f);
      printf("--%d--",x);
    }

  printf("\n");
  return 0;
}
