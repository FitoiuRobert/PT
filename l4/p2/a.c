#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 2

struct coord{
  float x,y;
};

struct entry {
  unsigned flag_shapetype:2;
  union shape2D{
    struct triangle {
      struct coord c1,c2,c3;
    } T;
    struct circle {
      float r;
      struct coord c1,c2;
    } C;
    struct rectangle {
      struct coord c1,c2,c3,c4;
    }R;
  }
}db[MAX_ENTRIES];

void list_shape(struct entry db[]);
void add_shape(struct entry db[], int *p);

void disp_menu(){
  printf("\n0. Exit");
  printf("\n1. Add shape");
  printf("\n2. List Shapes");
  printf("\n3. Delete shape");//on index i
  printf("\n>>");
}

int main(void)
{
  int option = -1, i = -1;
  while(1)
    {
      switch(option)
	{
	case 0: return 0;
	case 1:
	  {
	    add_shape(db,&i);
	    option = -1;
	    break;
	  }
	case 2:
	  {
	    option = -1;
	    break;
	  }
	case 3:
	  {
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

void list_shape(struct entry db[]){}
void add_shape(struct entry db[], int *p)
{
  int i = *++p;
  unsigned type;
  printf("\nPlease select shape type:");
  printf("\n1. Triangle");
  printf("\n2. Circle");
  printf("\n3. Rectangle");
  printf("\n>>");
  scanf("%d",&type);
  db[i].flag_shapetype = type;
  printf("\nYour Shape type is %d",db[i].flag_shapetype);
}
