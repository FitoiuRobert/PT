#include <stdio.h>
#include <stdlib.h>

struct snode{
 char name[10];
 char address[20];
 float income;
};

int main(void)
{


 printf("%zu \n",sizeof(struct snode));
 return 0;
}
