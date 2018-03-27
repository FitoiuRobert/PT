#include <stdio.h>
#define N 3
char board[N][N];

void init_board(void);
void print_board(void);
void print_menu(void);
void play(void);



int main(void)
{
  init_board();
  print_board();
  print_menu();
  play();

  return 0;
}

void init_board(void){
  printf("\n--INIT BOARD--\n");
  int i,j;
  for(i = 0; i < N; ++i)
    for(j = 0; j < N; ++j)
      board[i][j] = ' ';
}

void print_board(void){
  int i,j;
  printf("\n--PRINT BOARD--\n");
  for(i = 0; i < N; ++i){
    for(j = 0; j < N; ++j)
      {
	if(i < N-1) printf("_%c_",board[i][j]);
	else printf(" %c ",board[i][j]);
	if(j < N-1) printf("|");
      }
    printf("\n");
  }
}

void print_menu(void){
  printf("\n--PRINT MENU--\n");
}

void play(void){
  printf("\n--PLAYING--\n");
}
