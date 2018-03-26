typedef struct {
  float x,y;
}point_t;

typedef struct {
  point_t p1, p2, p3;
}triangle_t;

typedef struct {
  unsigned rad;
  point_t cent;
}circle_t;

typedef struct {
  point_t p1, p2, p3, p4;
}rectangle_t;

typedef union {
  triangle_t t;
  circle_t c;
  rectangle_t r;
}figure_ut;

typedef enum {
  triangle = 0,
  circle = 1,
  rectangle = 2
}type_et;

typedef struct {
  type_et type;
  figure_ut f;
}figure_t;

void disp_menu(){
  printf("\n0. Exit");
  printf("\n1. Add shape");
  printf("\n2. List Shapes");
  printf("\n3. Delete shape");//on index i
  printf("\n>>");
}

void list_shape(figure_t db[], int *n)
{
  if(*n == 0)
    printf("\nThere is no figure is the database.\n");
  else
    {
      for(int i = 0; i < *n; ++i)
	switch(db[i].type){
	case 0://triangle
	  {
	    printf("\nFigure no. %d:\n",i);
	    printf("Type: Triangle\n");
	    printf("Coordinates:\n%f %f\n%f %f\n%f %f\n",db[i].f.t.p1.x,db[i].f.t.p1.y,db[i].f.t.p2.x,db[i].f.t.p2.y,db[i].f.t.p3.x,db[i].f.t.p3.y);
	    break;
	  }
	case 1://circle
	  {
	    printf("\nFigure no. %d:\n",i);
	    printf("Type: Circle\n");
	    printf("Radius: %u\nCenter: %f %f\n",db[i].f.c.rad,db[i].f.c.cent.x,db[i].f.c.cent.y);
	    break;
	  }
	case 2://rectangle
	  {
	    printf("\nFigure no. %d:\n",i);
	    printf("Type: Rectangle\n");
	    printf("Coordinates:\n%f %f\n%f %f\n%f %f\n%f %f\n",db[i].f.r.p1.x,db[i].f.r.p1.y,db[i].f.r.p2.x,db[i].f.r.p2.y,db[i].f.r.p3.x,db[i].f.r.p3.y,db[i].f.r.p4.y,db[i].f.r.p4.y);
	    break;
	  }
	}
    }
  
}

void add_shape(figure_t db[], int *n)
{
  if(*n == MAX_ENTRIES)
    printf("\nThere is no space left in the database!\n");
  else
    {
      int add_t;
      do{
      printf("\nSelect shape type:\n");
      printf("0. Triangle\n1. Circle\n2. Rectangle\n>>");
      scanf(" %d",&add_t);
      }while(add_t < 0 || add_t > 2);
      
      switch(add_t){
	case 0://triangle
	  {
	    db[*n].type = 0;
	    printf("\nEnter triangle coordinates:");
	    printf("\nPoint 1\n>>x = ");
	    scanf("%f",&db[*n].f.t.p1.x);
	    printf(">>y = ");
	    scanf("%f",&db[*n].f.t.p1.y);
	    printf("\nPoint 2\n>>x = ");
	    scanf("%f",&db[*n].f.t.p2.x);
	    printf(">>y = ");
	    scanf("%f",&db[*n].f.t.p2.y);
	    printf("\nPoint 3\n>>x = ");
	    scanf("%f",&db[*n].f.t.p3.x);
	    printf(">>y = ");
	    scanf("%f",&db[*n].f.t.p3.y);
	    break;
	  }
	case 1://circle
	  {
	    db[*n].type = 1;
	    printf("\nEnter circle coordinates:");
	    printf("\nRadius = ");
	    scanf("%u",&db[*n].f.c.rad);;
	    printf("\nCenter \n>>x = ");
	    scanf("%f",&db[*n].f.c.cent.x);
	    printf(">>y = ");
	    scanf("%f%",&db[*n].f.c.cent.y);
	    break;
	  }
	case 2://rectangle
	  {
	    db[*n].type = 2;
	    printf("\nEnter triangle coordinates:");
	    printf("\nPoint 1\n>>x = ");
	    scanf("%f",&db[*n].f.r.p1.x);
	    printf(">>y = ");
	    scanf("%f",&db[*n].f.r.p1.y);
	    printf("\nPoint 2\n>>x = ");
	    scanf("%f",&db[*n].f.r.p2.x);
	    printf(">>y = ");
	    scanf("%f",&db[*n].f.r.p2.y);
	    printf("\nPoint 3\n>>x = ");
	    scanf("%f",&db[*n].f.r.p3.x);
	    printf(">>y = ");
	    scanf("%f",&db[*n].f.r.p3.y);
	    printf("\nPoint 4\n>>x = ");
	    scanf("%f",&db[*n].f.r.p4.x);
	    printf(">>y = ");
	    scanf("%f",&db[*n].f.r.p4.y);
	    break;
	  }
	}
      ++*n;
    
    }
}

void del_shape(figure_t db[], int *n)
{
  if(*n == 0) printf("\nThere is no shape in the database to be deleted\n");
  else
    {
      int del_n;
      do{
	printf("\nEnter the number of the shape to be deleted\n>>");
	scanf(" %d",&del_n);
      }while(del_n < 0 || del_n > *n);
      
      unsigned char validate;
      printf("\nAre you sure you want to delete shape no. %d [y/N]?",del_n);
      scanf(" %c",&validate);
      if(validate != 'y' || validate != 'Y')
	{
	  for(int i = del_n; i < (*n -1); ++i)
	    db[i] = db[i+1];
	  --*n;
	}
    }
}
