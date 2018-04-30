#include <stdio.h>



int main(int argc, char **argv)
{
  FILE *fin = fopen(argv[1],"r"),
    *fout = fopen (argv[2],"w");
  char c;

  if(fin == NULL){printf("%s\n",argv[1]); perror("fopen "); return 0;}
  if(fout == NULL){printf("%s\n",argv[2]); perror("fopen "); return 0;}

  while((c = fgetc(fin)) != EOF)
    {
      if(c == '\n') fputc('\r',fout);
      fputc(c,fout);
    }
 
  //printf("Hello world\n");
  return 0;
}

char *s ="out_";
strcat(s,argv[i]);
fopen(s,"w");
