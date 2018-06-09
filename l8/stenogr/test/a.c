#include <stdio.h>
#include <stdlib.h>



int main(int argc, char **argv)
{
  if(argc > 2)
    {
      fprintf(stderr,"Usage %s <textfile>\n",argv[0]);
      exit(EXIT_FAILURE);
    }
  
  FILE *fin = fopen(argv[1],"r+");
  if(!fin)
    {
      fprintf(stderr,"Could not open the file %s!\n",argv[1]);
      exit(EXIT_FAILURE);
    }
  
  char c;

  
  while((c=fgetc(fin)) != EOF)
    {
      if(c == '\n')
	{

	  fseek(fin,-2, SEEK_CUR);
	  fputc('!',fin);
	  fseek(fin,0, SEEK_CUR);
	}
    }
  
  
  fclose(fin);
  printf("\n");
  return 0;
}
