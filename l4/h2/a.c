#include <stdio.h>
#include <string.h>
#define MAX 5
#include "animlib.h"

int main(void)
{
  animal_t anim[MAX];
  int option = -1;
  while(1){
    do{disp_menu(&option);}while(option < 0 || option > 4);
    switch(option){
    case 0: return 0;
    case 1:{

      break;
    }
    case 2:{

      break;
    }
    case 3:{

      break;
    }
    case 4:{

      break;
    }
    case 5:{

      break;
    }
    }
  }
}
