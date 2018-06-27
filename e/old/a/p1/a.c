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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "menu.h"


int main(void)
{

  init();
  showMenu();
  
  printf("\n");
  return 0;
}