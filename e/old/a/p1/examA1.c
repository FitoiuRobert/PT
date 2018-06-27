/*
A list with persons is given from the keyboard row by row (name, first name, sex, address, phone) up until the EOF character (CTRL-D).  Use a linked list to handle the information by the following func-tions:

1. Insert person
2. Search (by name)
3. Delete person
4. Modify
5. Show list sorted by name

The functions will be presented as a menu.		
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct person
{
  char name[30];
  char fst_name[30];
  int sex;
  char adress[100];
  char phone[11];
  struct person  *nxt;
}prs_t;

void print_lst (prs_t *current)
{
  while(current != NULL)
    {
      printf("\n\n person: \n\n");
      printf("name: %s\n",current -> name);
      printf("first name: %s\n",current -> fst_name);
      switch(current -> sex)
	{
	case 1: printf("sex: men\n"); break;
	case 2: printf("sex: women\n"); break;
	case 3: printf("sex: transsexual\n");break;
	default: printf("sex: Please dont be offended your sex is not in the list\n");break;
	}
      printf("adress: %s\n",current -> adress);
      printf("phone number: %s\n",current -> phone);
      current = current -> nxt;
    }
}

prs_t *add_to_tail(prs_t *root)
{
  prs_t *new_prs = malloc (sizeof(prs_t));
  printf("\nlast name: ");
  scanf("%s",new_prs -> name);
  printf("\nfirst name: ");
  scanf("%s",new_prs -> fst_name);
  printf("\nsex: [1 = men; 2 = women; 3 = transsexual] ");
  scanf("%d",&new_prs -> sex);
  printf("\nadress: ");
  scanf("%s",new_prs -> adress);
  printf("\nphone number: [10 digits]");
  scanf("%s",new_prs -> phone);
  printf("\n");

  if(root == NULL)
    {
      new_prs -> nxt = root;
      root = new_prs;
      return root;
    }

  prs_t *current = root;
  while(current -> nxt != NULL)
    current = current -> nxt;    // now current points to the last existing node

  new_prs -> nxt = current -> nxt; // linking
  current -> nxt = new_prs;

  return root;
}

void search(prs_t *root)
{
  char wanted[30];
  printf("\nLast name of the person wanted: ");
  scanf("%s",wanted);

  prs_t *current = root;
  while(strcmp(current -> name, wanted))  //searching the person
    {
      if(current == NULL)
	{
	  printf("\ncouldn't find the person, check for typo's");
	  return;
	}
      current = current -> nxt;
    }

  printf("\n\n We found! The person is: \n\n");
  printf("name: %s\n",current -> name);
  printf("first name: %s\n",current -> fst_name);
  switch(current -> sex)
    {
    case 1: printf("sex: men\n"); break;
    case 2: printf("sex: women\n"); break;
    case 3: printf("sex: transsexual\n");break;
    default: printf("sex: Please dont be offended your sex is not in the list\n");break;
    }
  printf("adress: %s\n",current -> adress);
  printf("phone number: %s\n",current -> phone);
}

prs_t *delete(prs_t *root)
{
  char wanted[30];
  printf("\nLast name of the person to delete: ");
  scanf("%s",wanted);

  prs_t *current = root,*last_adress;
  while(strcmp(current -> name, wanted) && current != NULL)  // searching the list
    {
      last_adress = current;
      current = current -> nxt;
    }

  if(current == root) // if it is the first one in the list
    {
      if(current -> nxt == NULL) // if it is the only element
	{
	  root = NULL;
	  free(current);
	  printf("\nperson deleted succesfully!\n");
	  return root;
	}
      root = current -> nxt;
      free(current);
      printf("\nperson deleted succesfully!\n");
      return root;
    }

  if(current -> nxt == NULL) // if it is the last one in the list
    {
      last_adress -> nxt = NULL;
      free(current);
      printf("\nperson deleted succesfully!\n");
      return root;
    }

  // now it may be only in the middle of the list

  last_adress -> nxt = current -> nxt;
  free(current);

  if(current == NULL)
    printf("\ncouldn't find the person, check for typo's");
  else
    printf("\nperson deleted succesfully!\n");

  return root;
}

void modify(prs_t *root)
{
  char wanted[30];
  printf("\nLast name of the person to modify: ");
  scanf("%s",wanted);

  prs_t *current = root,*last_adress;
  while(strcmp(current -> name, wanted) && current != NULL)  // searching the list
      current = current -> nxt;

  if(current == NULL)
    {
      printf("\ncouldn't find the person, check for typo's");
      return;
    }
  
  printf("\nlast name: ");
  scanf("%s",current -> name);
  printf("\nfirst name: ");
  scanf("%s",current -> fst_name);
  printf("\nsex: [1 = men; 2 = women; 3 = transsexual] ");
  scanf("%d",&current -> sex);
  printf("\nadress: ");
  scanf("%s",current -> adress);
  printf("\nphone number: [10 digits]");
  scanf("%s",current -> phone);
  printf("\n");
}

prs_t *add_ord(prs_t *root, prs_t *info)
{
  prs_t *new_prs = malloc(sizeof(prs_t));
  strcpy(new_prs -> name, info -> name);
  strcpy(new_prs -> fst_name, info -> fst_name);
  new_prs -> sex = info -> sex;
  strcpy(new_prs -> adress, info -> adress);
  strcpy(new_prs -> phone, info -> phone);

  free(info);

  if(root == NULL)
    {
      new_prs -> nxt = root;
      root = new_prs;
      return root;
    }

  if(strcmp(new_prs -> name, root -> name) < 0)
    {
      new_prs -> nxt = root;
      root = new_prs;
      return root;
    }

  prs_t *current = root;
  while(current -> nxt != NULL)
    {
      if(strcmp(new_prs -> name, current -> nxt -> name) < 0)
	{
	  new_prs -> nxt = current -> nxt;
	  current -> nxt = new_prs;
	  return root;
	}
      current= current -> nxt;
    }

  new_prs -> nxt = current -> nxt;
  current -> nxt = new_prs;
  return root;
}

prs_t *crt_sorted_lst(prs_t *lst)
{
  if(lst == NULL)
    {
      printf("the list is empty! Please add first!");
      return lst;
    }
  prs_t *srt_lst = NULL;
  
  prs_t *current = lst;
  while(current != NULL)
    {
      srt_lst = add_ord(srt_lst, current);
      current = current -> nxt;
    }
  
  return srt_lst;
}

void menu(void)
{
  int indx;
  prs_t *prs = NULL;
  do
    {
      printf("menu is: \n\n");
      printf("0.Exit program\n");
      printf("1.Insert person\n");
      printf("2.Search (by name)\n");
      printf("3.Delete person\n");
      printf("4.Modify\n");
      printf("5.Show list sorted by name\n");
      printf("6.Print list\n");

      printf("what is your choice?\n");
      scanf("%d",&indx);
      
      switch(indx)
	{
	case 0: goto exit;
	case 1: prs = add_to_tail(prs); break;
	case 2: search(prs); break;
	case 3: prs = delete(prs); break;
	case 4: modify(prs); break;
	case 5: prs = crt_sorted_lst(prs); break;
	case 6: print_lst(prs); break;
	default: printf("invalid input");break;
	}
    }
  while(1);
  exit: return;
}

int main(void)
{
  menu();
  return 0;
}
