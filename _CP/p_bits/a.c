#include <stdio.h>


int main(void)
{

  unsigned char c = 'a';
  int sz = sizeof(c)*8;

  printf("Character: %c\n",c);
  printf("Unisgned int value: %u\n",c);
  printf("Binary representation: ");
  for(int i = 0; i < sz; ++i)
      if(c<<i & 0x80) putchar('1');
      else putchar('0');
  printf("\n",c);
  return 0;
}
