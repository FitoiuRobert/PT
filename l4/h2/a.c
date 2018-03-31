#include <stdio.h>
#include <string.h>
#define MAX 5
#include "animlib.h"

int main(void)
{
  animal_t animal[MAX];
  char option;
  int sz = -1;
  
  while(1){
    do{disp_menu(&option);}while(option < '0' || option > '5');
    switch(option){
    case '0': return 0;
    case '1':{
      add_animal(animal,&sz);
      break;
    }
    case '2':{
      replace_animal(animal, &sz);
      break;
    }
    case '3':{
      delete_animal(animal,&sz);
      break;
    }
    case '4':{
      search_animal(animal,&sz);
      break;
    }
    case '5':{
      display_animal(animal, 0, &sz);
      break;
    }
    }
  }
}
