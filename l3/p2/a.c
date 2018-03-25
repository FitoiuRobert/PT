#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct student{
  char name[50];
  int grade;
};

void disp_stud(struct student stud[], int nr)
{
  for(int i = 0; i < nr; ++i)
    printf("\nName: %s Grade: %d",stud[i].name,stud[i].grade);
  printf("\n");
}

void sort_name(struct student stud[], int nr)
{
  struct student tmp;
  
  for (int i = 0; i < nr-1; ++i)
    {
      for (int j = i+1; j < nr; ++j)
	{
	  if (strcmp(stud[i].name,stud[j].name) > 0)
	    {
	      tmp = stud[i];
	      stud[i] = stud[j];
	      stud[j] = tmp;	  
	    }
	}

    }

}

void sort_grade(struct student stud[], int nr)
{
  struct student tmp;
  
  for (int i = 0; i < nr-1; ++i)
    {
      for (int j = i+1; j < nr; ++j)
	{
	  if (stud[i].grade < stud[j].grade)
	    {
	      tmp = stud[i];
	      stud[i] = stud[j];
	      stud[j] = tmp;	  
	    }
	}

    }

}

int main(void)
{
  int nr = 4;
  int option = -1;
  struct student stud[] = {{"Calistar Jamar",6},{"Brak Mira",10},{"Azel Dan",8},{"Arashi Kera",9}};

  while(1){
    switch(option)
      {
      case 0: return 0;
      case 1:
	{
	  printf("\nEnter the number of students: ");
	  scanf("%d",&nr);
	  option = -1;
	  break;
	}
      case 2:
	{
	  if(nr)  
	    {
	      for(int i = 0; i < nr; ++i)
		{
		  printf("\nStudent %d:",i+1);
		  printf("\nName: ");
		  scanf("%s",&stud[i].name);
		  printf("Grade: ");
		  scanf("%d",&stud[i].grade);
		}
	    
	    }
	    
	  else printf("\n!!! Please enter the number of students first!!!\n");
	  
	  option = -1;
	  break;
	}
      case 3:
	{
	  if(stud[nr-1].name[0])
	    {
	      sort_name(stud,nr);
	      disp_stud(stud,nr);
	    }
	  else printf("\n!!! Please enter the students first!!!\n");
	  option = -1;
	  break;
	}
      case 4:
	{
	  if(stud[nr-1].name[0])
	    {
	      sort_grade(stud,nr);
	      disp_stud(stud,nr);
	    }
	  option = -1;
	  break;
	}
      case 5:
	{
	  if(stud[nr-1].name[0])
	    {
	      sort_grade(stud,nr);
	      disp_stud(stud,3);
	    }
	  else printf("\n!!! Please enter the students first!!!\n");

	  option = -1;
	  break;
	}
      default:
	{
	  printf("\nSelect an option:\n");
	  printf("0. Exit program\n");
	  printf("1. Give N, number of students\n");
	  printf("2. Enter the students\n");
	  printf("3. Display class in alphabetic order\n");
	  printf("4. Display class creating a top based on grade\n");
	  printf("5. Display the first 3 students according to their grade\n>>");
	  scanf("%d",&option);
	}
      }
    
  }
  
}
