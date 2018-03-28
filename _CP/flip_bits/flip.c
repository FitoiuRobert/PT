#include <stdio.h>


int main(void)
{

  char c;
  int sz = sizeof(unsigned char)*8;
  FILE *fin,*fout;

  fin = fopen("in.txt","r");
  fout = fopen("out.txt","w");

  if(fin == NULL || fout == NULL) {perror("fopen()"); return -1;}
  else {
    while((c = getc(fin)) != EOF)
      {
	c = ~c;
	fprintf(fout,"%c",c);
      }
    fprintf(stdout,"Finished to flip bits\n");
  }

  fclose(fin);
  fclose(fout);
  return 0;
}
