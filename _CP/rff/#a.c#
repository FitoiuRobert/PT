#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if(argc > 2){fprintf(stderr,"Too many arguments!\nUsage: ./a.out [filename]\n"); return 1;}
  
  FILE *fp = fopen(argv[1],"r");
  if(fp == NULL){perror("fopen"); return 1;}
  int _MAXLC = 512,
    _MAXL = 64;
  char buff[_MAXLC],
    **lines = malloc(sizeof(char *)*_MAXL);
  int n = 0;
  
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

  }
  
  
  printf("It runs!\n");
  fclose(fp);
  return 0;
}
