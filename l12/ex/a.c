#include <stdio.h>
#include <stdlib.h>

struct node *head, *tail,*crt;

struct node{
  int info;
  struct node *next;
  struct node *prev;
};

  struct node * add_to_head(int info){
    crt = (struct node *)malloc(sizeof (struct node));
    if(crt == NULL) {perror("malloc"); exit(EXIT_FAILURE);}
    crt -> next = head;
    crt -> prev = tail;
    crt -> info = info;
    head = crt;
    return crt;
}
  
int main(void)
{
  for(int i = 0; i < 10; ++i)
    add_to_head(i);

  crt = head;
  while(crt != NULL){
    printf("%d\n",crt->info);
    crt = crt -> next;
  }

  
  free(crt);
  return 0;
}
