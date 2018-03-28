#include <stdio.h>


int main(void)
{

  char c;
  int sz = sizeof(unsigned char)*8;
  FILE *fp;

  fp = fopen("in.txt","rb");

  if(fp == NULL) {perror("fopen()"); return -1;}
  else {
    while((c = getc(fp)) != EOF)
      {
	fprintf(stdout,"%c",c);

	
	c = (unsigned int)c;
	c = ~c;
	printf("\nCharacter: %c",c);
	printf("\nUnisgned int value: %u",c);
	printf("\nBinary representation: ");
	for(int i = 0; i < sz; ++i)
	  if(c<<i & 0x80) putchar('1');
	  else putchar('0');
	fprintf(stdout,"\n");
	
      }
    fprintf(stdout,"\n");
  }

  fclose(fp);
  return 0;
}
