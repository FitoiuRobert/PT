typedef enum{
  insect,
  bird,
  mamal,
  fish
}type_et;

typedef struct{
  int legs,life_span;
}insect_t;

typedef struct{
  float speed,wing_l;
  char mig_hab[128];
}bird_t;

typedef struct{
  float weight,height;
  char food[64];
}mamal_t;

typedef struct{
  float weight,swim_depth,salt_prc;
}fish_t;

typedef union{
  insect_t i;
  bird_t b;
  mamal_t m;
  fish_t f;
}class_ut;

typedef struct{
  char name[64];
  class_ut class;
  type_et type;
}animal_t;

void disp_menu(int *option)
{
  printf("\n0. Exit");
  printf("\n1. Add animal");
  printf("\n2. Replace animal");
  printf("\n3. Delete animal");
  printf("\n4. Search animal");
  printf("\n5. Display animals\n>>");
  scanf("%d",option);
}
