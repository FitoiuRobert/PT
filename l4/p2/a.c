#include <stdio.h>
#include <stdlib.h>
#define MAX_ENTRIES 5
#include "figlib.h"


int main(void)
{
  figure_t db[MAX_ENTRIES];
  int option = -1, i = -1, n = 0;
  while(1)
    {
      switch(option)
	{
	case 0: return 0;
	case 1: //add_shape
	  {
	    add_shape(db, &n);
	    option = -1;
	    break;
	  }
	case 2://list_shape
	  {
	    list_shape(db, &n);
	    option = -1;
	    break;
	  }
	case 3://delete_shape
	  {
	    del_shape(db, &n);
	    option = -1;
	    break;
	  }
	default:
	  {
	    disp_menu();
	    scanf("%d",&option);
	  }
	}
    }
  
  return 0;
}


