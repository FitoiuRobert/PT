#include <stdio.h>
#include <ctype.h>
#define N 3
char board[N][N];

void init_board(void);
void print_board(void);
void print_menu(int *);
void play(void);



int main(void)
{
  int option;
  
  print_menu(&option);

  return 0;
}

void init_board(void){
  printf("\n--INIT BOARD--\n");
  int i,j,o,r,c;
  for(i = 0; i < N; ++i)
    for(j = 0; j < N; ++j)
      (board[i][j]) = ' ';
  
  while(1)
    {
      do
	{
	  printf("\n0. Exit");
	  printf("\n1. Add entry\n>>");
	  scanf(" %d",&o);
	}while(o < 0 || o > 1);
      switch(o)
	{
	case 0: return;
	case 1:
	  {
      
	    do{
	      printf("\nEnter row [1..3]\n>>");
	      scanf(" %d",&r);
	    }while(isdigit(r) && (r < 1 || r > 3));
	    do{
	      printf("\nEnter col [1..3]\n>>");
	      scanf(" %d",&c);
	    }while(isdigit(c) && (c < 1 || c > 3));

	    do{
	      printf("\nEnter value[x/O)]\n>>");
	      scanf(" %c",&board[r-1][c-1]);
	    }while(tolower(board[r-1][c-1])!='x' && tolower(board[r-1][c-1])!='o');
	  }
	}
    }
  
}

void print_board(void){
  int i,j;
  printf("\n--PRINT BOARD--\n");
  for(i = 0; i < N; ++i){
    for(j = 0; j < N; ++j)
      {
	if(i < N-1) printf("_%c_",toupper(board[i][j]));
	else printf(" %c ",toupper(board[i][j]));
	if(j < N-1) printf("|");
      }
    printf("\n");
  }
}

void print_menu(int *option){
  printf("\n--PRINT MENU--\n");
  while(1){
    do{
      printf("\n0. Exit");
      printf("\n1. Init Board");
      printf("\n2. Print Board");
      printf("\n3. Play\n>>");
      scanf(" %d",option);
    }while(*option < 0 || *option >3);
    switch(*option){
    case 0:return;
    case 1:{
      init_board();
      break;
    }
    case 2:{
      print_board();
      break;
    }
    case 3:{
      play();
      break;
    }
    }

  }
  
}

void play(void){
  printf("\n--PLAYING--\n");
}
