#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
<<<<<<< HEAD
  if(argc > 2){fprintf(stderr,"Too many arguments!\nUsage: ./a.out [filename]\n"); return 1;}
  
  FILE *fp = fopen(argv[1],"r");
  if(fp == NULL){perror("fopen"); return 1;}
  int _MAXLC = 512,
    _MAXL = 64;
  char buff[_MAXLC],
    **lines = malloc(sizeof(char *)*_MAXL);
  int n = 0;
=======
  char buff[MAXLC],**lines;
  FILE *fp;
  int n=0;
>>>>>>> 0d6a1c2712a8d7264527352010f94866ecb9948c
  
  if(lines == NULL) {perror("malloc"); fclose(fp); return 1;}
  else{
    while(fgets(buff,sizeof(buff),fp))
      {
	if(n >= _MAXL) {lines = realloc(lines,sizeof(char *)*(_MAXL*=2));}
	int _BUFFSZ = strlen(buff);
	lines[n] = malloc(_BUFFSZ);
	strncpy(lines[n],buff,_BUFFSZ-1);
	puts(lines[n]);
	++n;
	
	
      }

<<<<<<< HEAD
  }
  
  
  printf("It runs!\n");
=======
  if(fp == NULL) {perror("fopen()"); return -1;}
  else
    {
      lines = malloc(sizeof(buff));
      while(fgets(buff,sizeof(buff),fp))
	{
	  lines[n] = malloc(sizeof(buff));
	  strcpy(lines[n],buff);
	  ++n;
	}
      fprintf(stdout,"\nJust read %d buffers!\n",n);
      for(int i = 0; i < n ; ++i)
      printf("%s\n",lines[i]);
    }
>>>>>>> 0d6a1c2712a8d7264527352010f94866ecb9948c
  fclose(fp);
  return 0;
}
