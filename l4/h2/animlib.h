typedef enum{
  bird=0,
  fish=1,
  insec=2,
  mamal=3
}type_et;

typedef struct{
  float speed,wing_l;
  char mig_hab[128];
}bird_t;

typedef struct{
  float weight,swim_depth,salt_prc;
}fish_t;

typedef struct{
  int legs,life_span;
}insect_t;

typedef struct{
  float weight,height;
  char food[64];
}mamal_t;


typedef union{
  bird_t b;
  fish_t f;
  insect_t i;
  mamal_t m;
}class_ut;

typedef struct{
  char name[64];
  class_ut c;
  type_et type;
}animal_t;

void disp_menu(char *option)
{
  printf("\n0. Exit");
  printf("\n1. Add animal");
  printf("\n2. Replace animal");
  printf("\n3. Delete animal");
  printf("\n4. Search animal");
  printf("\n5. Display animals\n>>");
  scanf(" %c",option);
}

void display_animal(animal_t animal[], int i, int *sz){
  
  if(*sz < 0){printf("The records are empty!\n"); return;}
  for(i = 0; i <= *sz; ++i)
    switch(animal[i].type){
      printf("\n");
      case 0:
	{
	  printf("\nName of bird: %s",animal[i].name);
	  printf("\nSpeed: %f",animal[i].c.b.speed);
	  printf("\nWing length: %f",animal[i].c.b.wing_l);
	  printf("\nMigration habbit: %s",animal[i].c.b.mig_hab);
	  printf("\n");
	  break;
	}
      case 1:
	{
	  printf("\nName of fish: %s",animal[i].name);
	  printf("\nWeight: %f",animal[i].c.f.weight);
	  printf("\nSwim depth: %f",animal[i].c.f.swim_depth);
	  printf("\nSalt percentage: %f",&animal[i].c.f.salt_prc);
	  printf("\n");
	  break;
	}
      case 2:
	{
	  printf("\nName of insect: %s",animal[i].name);
	  printf("\nLegs %d",animal[i].c.i.legs);
	  printf("\nLife span\n>>");
	  scanf(" %f",animal[i].c.i.life_span);
	  printf("\n");
	  break;
	}
      case 3:
	{
	  printf("\nEnter the:\nName of mamal\n>>");
	  scanf(" %s",&animal[i].name);
	  printf("\nWeight\n>>");
	  scanf(" %f",&animal[i].c.m.weight);
	  printf("\nHeight\n>>");
	  scanf(" %f",&animal[i].c.m.height);
	  printf("\nFood\n>>");
	  scanf(" %s",&animal[i].c.m.food);
	  printf("\n");
	  break;
	}
     
      }

}


void add_animal(animal_t animal[], int *sz)
{
  char o;

  if(*sz == MAX) {printf("\nThere is no place left in the records.\n"); return;}
  else{
    ++*sz;
    while(1){
      do{
	printf("\nWhich animal do you want to add?");
	printf("\n0. Bird\n1. Fish\n2. Insect\n3. Mamal\n>>");
	scanf(" %c",&o);
      }while(o < '0' || o > '3');

      switch(o){
      case '0':
	{
	  animal[*sz].type = 0;
	  printf("\nEnter the:\nName of bird\n>>");
	  scanf(" %s",&animal[*sz].name);
	  printf("Speed\n>>");
	  scanf(" %f",&animal[*sz].c.b.speed);
	  printf("Wing length\n>>");
	  scanf(" %f",&animal[*sz].c.b.wing_l);
	  printf("Migration habbit\n>>");
	  scanf(" %s",&animal[*sz].c.b.mig_hab);
	  break;
	}
      case '1':
	{
	  animal[*sz].type = 1;
	  printf("\nEnter the:\nName of fish\n>>");
	  scanf(" %s",&animal[*sz].name);
	  printf("Weight\n>>");
	  scanf(" %f",&animal[*sz].c.f.weight);
	  printf("Swim depth\n>>");
	  scanf(" %f",&animal[*sz].c.f.swim_depth);
	  printf("Salt percentage\n>>");
	  scanf(" %f",&animal[*sz].c.f.salt_prc);
	  
	  break;
	}
      case '2':
	{
	  animal[*sz].type = 2;
	  printf("\nEnter the:\nName of insect\n>>");
	  scanf(" %s",&animal[*sz].name);
	  printf("Legs\n>>");
	  scanf(" %d",&animal[*sz].c.i.legs);
	  printf("Life span\n>>");
	  scanf(" %f",&animal[*sz].c.i.life_span);
	  
	  break;
	}
      case '3':
	{
	  animal[*sz].type = 3;
	  printf("\nEnter the:\nName of mamal\n>>");
	  scanf(" %s",&animal[*sz].name);
	  printf("Weight\n>>");
	  scanf(" %f",&animal[*sz].c.m.weight);
	  printf("Height\n>>");
	  scanf(" %f",&animal[*sz].c.m.height);
	  printf("Food\n>>");
	  scanf(" %s",&animal[*sz].c.m.food);
	  break;
	}
     
      }
   
      return;
    }
  }
  
}

int search_animal(animal_t animal[],int *sz){
  char nm[64];
  int j;
  if(*sz < 0){printf("\nThere is nothing to search!\n"); return -1;}
  else
    {
      printf("\nPlease enter the name of the animal you are searching for\n>>");
      scanf(" %s",&nm);
      for(j = 0; j <= *sz; ++j)
	if(strcmp(animal[j].name,nm)){
	  printf("We could no find %s in our database.\n");
	  return -1;
	}
	else{
	  int *ptr = &j;
	  ++*ptr;
	  display_animal(animal,j,ptr);

	  return j;
	}
    }
}


void delete_animal(animal_t animal[], int *sz){

  if(*sz < 0){printf("\nThere is nothing left to delete!\n"); return;}
  else{
    int found = search_animal(animal,sz);
    if(found == -1) return;

    else{
      char o;
      printf("Do you want to delete this record?[y/N]");
      scanf(" %c",&o);
      if(o == 'y' || o == 'Y')
	if(*sz == 0) *sz = -1;
	else{
	  for(int cvar = found; cvar < (*sz-1); ++cvar)
	    animal[cvar] = animal[cvar + 1];
	  --*sz;
	}
    }
  }

}



void replace_animal(animal_t animal[],int *sz){
  if(*sz < 0){printf("\nThere is nothing to replace!\n"); return;}
  else{
    int found = search_animal(animal,sz);
    if(found == -1) return;

    else{
      char o;
      printf("Do you want to replace this record?[y/N]");
      scanf(" %c",&o);
      if(o == 'y' || o == 'Y'){
	--*sz;
	add_animal(animal,sz);
      }
    }

  }
}
