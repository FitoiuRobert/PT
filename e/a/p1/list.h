/*
  A list with persons is given from the keyboard row by row (name, first name, sex, address, phone)
  up until the EOF character (CTRL-D).  Use a linked list to handle the information by the following
  functions:
  1. Insert person
  2. Search (by name)
  3. Delete person
  4. Modify
  5. Show list sorted by name
  The functions will be presented as a menu.
*/


struct node {  
  char name[32],
    fName[32],
    sex,
    adr[128],
    phone[14];
  
  struct node *next;
};

struct node *head;

void printList(void)
{

  struct node *crt = head;
  if(head == NULL) {printf("\n List is empty!\n"); return;}
  
  while(crt != NULL)
    {
      printf("\nName: %s",crt->name);
      printf("\nFirst Name: %s",crt->fName);
      printf("\nSex: %c",crt->sex);
      printf("\nAddress: %s",crt->adr);
      printf("\nPhone: %s",crt->phone);
      crt = crt->next;
    }
  //scanf("%*[^\n]%*c");
}

void insert(void)
{
  struct node *new = malloc(sizeof(struct node));
  
  printf("Name:");
  scanf(" %[^\n]%*c",new->name);
  printf("First Name:");
  scanf(" %[^\n]%*c",new->fName);
  printf("Sex:");
  scanf(" %c%*[^\n]%*c",&new->sex);
  printf("Address:");
  scanf(" %[^\n]%*c",new->adr);
  printf("Phone:");
  scanf(" %[^\n]%*c",new->phone);
  //printf("\nChars read in phn input: %d--\n",a);

  if(head == NULL)
    {
      head = new;
      head->next = NULL;
    }else{
    new->next = head;
    head = new;
  }
}

void init(void)
{
  head = NULL;
  /* char c;
  
  do{
    insert();
    scanf("%[^\n]");
    printf("\nPress any key to keep keep inserting data or EOF to show menu:\n");
    scanf("%c",&c);
    printf("--%c %d--\n",c,c);
  }while(c != 0);
  */
}

int search(char name[32], char fName[32])
{
  struct node *crt = head;
  
  while(crt != NULL){
    if(!strcmp(crt->name,name) && !strcmp(crt->fName,fName))
      {
	printf("\nPerson %s %s was found!\n",name,fName);
	return 1;
      }
    crt = crt -> next;
  }
  printf("Person %s %s could not be found!!!",name,fName);
  return 0;
}
