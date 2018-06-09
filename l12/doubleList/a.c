#include <stdio.h>
#include <stdlib.h>



struct node  {
	int data;
	struct node *prev;
	struct node *next;
};

struct node *head, *tail;

//Create new node and return pointer to it
struct createNode(int n){
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new -> data = n;
  new -> prev = NULL;
  new -> next = NULL;
  return new;
}

//Insert node at head of the list
void insertAtHead(int n){
  struct node *new = createNode(n);
  if(head == NULL){head=new; return;}
  head -> prev = new;
  new -> next = head;
  head = new;
}

//Insert node at tail of the list
void insertAtTail(int n){
  struct node *tmp = head;
  struct node *new = createNode(n);
  if(head == NULL){head = new; return;}
  while(tmp -> next != NULL) tmp = tmp -> next; //Go to the last node
  tmp -> next = new;
  new -> prev = tmp;
}

void print(){
  struct node *tmp = head;
  if(tmp == NULL) return;
  
  
}

//  while(tmp -> next != NULL) tmp = tmp -> next;

int main(void)
{


  return 0;
}
