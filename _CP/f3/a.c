#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct{
  int avg;
  char *line;
}lines_t;

typedef int(*cmp_t)(const void *, const void *);

int compare(lines_t **l, lines_t **r){

  return (*l)->avg - (*r)->avg;
}

int linecmp(const void *el1, const void *el2){
  lines_t l1=*(lines_t *)el1;
  lines_t l2=*(lines_t *)el2;
  return l1.avg-l2.avg;
}

int mean(char *arr)
{
  int tmp,i=0,n=0;
    while(*arr){
    sscanf(arr," %d",&tmp);
    //printf("%d\n",tmp);
    while(isspace(*arr)) ++arr;
    while(isdigit(*arr) || *arr == '-' || *arr == '+') ++arr;
    n+= tmp;
    ++i;
  }
    n-=tmp; --i;
    //printf("\n%d\n",n);
    return n/i;
}

int main(int argc, char *argv[])
{
  if(argc > 2){fprintf(stderr,"Too many arguments!\nUsage: ./a.out [filename]\n"); return 1;}
  
  FILE *fp = fopen(argv[1],"r");
  if(fp == NULL){perror("fopen"); return 1;}
  int _MAXLC = 512,
    _MAXL = 64;
  char *buff = malloc(sizeof(char ) * _MAXLC);
  //lines_t *lines = malloc((sizeof(char *) + sizeof(int))*_MAXL);
  lines_t *lines=malloc(sizeof(lines_t)*_MAXL);
  int n = 0;
  
  if(lines == NULL) {perror("malloc"); fclose(fp); return 1;}
  else{
    while(fgets(buff,_MAXLC,fp))
      {
	if(n >= _MAXL) {
	  lines = realloc(lines, sizeof(lines_t)*(_MAXL*=2));
	}
	int _BUFFSZ = strlen(buff);
	char *tmp = strstr(buff,"int");
	
	if(tmp != NULL){
	  //printf("\nSize of tmp %d\n", strlen(tmp));
	  //puts(tmp);
	  
	  lines[n].line = malloc(_BUFFSZ);
	  strncpy(lines[n].line,buff,_BUFFSZ-1);

	  
	  lines[n].avg = mean(tmp+3);
	  //puts(lines[n].line);
	  //printf(">>Avg: %d\n",lines[n].avg);
	  ++n;
	}
	else continue;
      }

  }
  
   qsort(lines,n,sizeof(lines_t),linecmp);
  
  for(int i = 0; i < n; ++i)
    printf("%s\n>>Avg:%d\n",lines[i].line,lines[i].avg);
  
  fclose(fp);
  return 0;
}
