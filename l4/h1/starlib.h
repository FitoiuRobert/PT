typedef struct {
  int age;
  char color[13];
}main_seq_t;
typedef struct {
  int rad1,rad2;
}binary_t;

typedef struct {
  int lum_l,lum_h,light;
}var_light_t;

typedef enum {
  main_seq = 0,
  binary = 1,
  var_light = 2
}type_et;

typedef union {
  main_seq_t m_s;
  binary_t b;
  var_light_t v_l;
}class_ut;

typedef struct {
  char name[50];
  type_et type;
  class_ut class;
}star_t;

void disp_menu(int *option)
{
  printf("\n0. Exit");
  printf("\n1. Add star");
  printf("\n2. List stars\n>>");
  scanf("%d",option);
}

void read_star(star_t star[])
{
  int type;
  do {
    printf("\nSelect the type of star:");
    printf("\n0. Main Sequence Star\n1. Binary Star\n2. Variable Light star\n>>");
    scanf(" %d",&type);
  }while(type < 0 || type >2);
  switch(type)
    {
    case 0:
      {
        star->type = 0;
	printf("\nEnter data for the Main Sequence Star:");
	printf("\nName\n>>");
	scanf("%s",&star->name);
	printf("Age\n>>");
	scanf("%d",&star->class.m_s.age);
	printf("Color\n>>");
	scanf("%s",&star->class.m_s.color);
	break;
      }
    case 1:
      {
	star->type = 1;
	printf("\nEnter data for the Binary Star:");
	printf("\nName\n>>");
	scanf("%s",&star->name);
	printf("\nRadius 1\n>>");
	scanf("%d",&star->class.b.rad1);
	printf("\nRadius 2\n>>");
	scanf("%d",&star->class.b.rad2);
	break;
      }
    case 2:
      {
       	star->type = 2;
	printf("\nEnter data for the Variable Light star:");
	printf("\nName\n>>");
	scanf("%s",&star->name);
	printf("\nLowest luminosty\n>>");
	scanf("%d",&star->class.v_l.lum_l);
        printf("\nHighest luminosty\n>>");
	scanf("%d",&star->class.v_l.lum_h);
	printf("\nPeriodicity in earth days\n>>");
	scanf("%d",&star->class.v_l.light);
	break; 
      }
    }
  
}

void disp_star(star_t star[])
{
  int type;
  switch(star->type){
  case 0:
    {
      printf("\nName: %s",star->name);
      printf("\nAge: %d",star->class.m_s.age);
      printf("\nColor: %s\n",star->class.m_s.color);
      break;
    }
  case 1:
    {
      printf("\nName: %s",star->name);
      printf("\nRadius 1: %d",star->class.b.rad1);
      printf("\nRadius 2: %d",star->class.b.rad2);
      break;
    }
  case 2:
    {
      printf("\nName: %s",star->name);
      printf("\nLowest luminosty: %d",star->class.v_l.lum_l);
      printf("\nHighest luminosty: %d",star->class.v_l.lum_h);
      printf("\nPeriodicity in earth days: %d",star->class.v_l.light);
      break; 
    }
  }
}
