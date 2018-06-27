#include <stdio.h>
#include <stdlib.h>



void initMaze(char **maze, int x, int y, FILE *fp)
{
  maze = realloc(maze,x);
  for(int i=0; i < x; ++i)
    {
      maze[i]=malloc(y);
      for(int j=0; j<y; ++j)
	maze[i][j]=fgetc(fp);
      fgetc(fp);
      printf("%s\n",maze[i]);
    }
  
}


int main(void)
{
  FILE *fp = fopen("maze.txt","r");
  if(fp == NULL){perror("maze.txt"); return -1;}
  char **maze=malloc(1);
  int x=5,y=5;

  initMaze(maze,x,y,fp);
  


  return 0;
}
