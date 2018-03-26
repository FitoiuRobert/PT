#include <stdio.h>
#include "starlib.h"


int main(void)
{
  star_t star[1];
  int option;

  while(1){
    do{disp_menu(&option);}while(option < 0 || option > 2);

    switch(option) {
    case 0: return 0;
    case 1:
      {
        read_star(star);
	break;
      }
    case 2:
      {
        disp_star(star);
	break;
      }
    }
  }
  
}
