#include <string.h>// for strcmp

 typedef struct 
 {
   char name[20];
   int grade;
 }student;

//display the menu and read the choice from the keyboard
int menu()
{
  unsigned n;
  printf("0. Exit program\n");
  printf("1. Give N, number of students\n");
  printf("2. Enter the students\n");
  printf("3. Display class in alphabetic order\n");
  printf("4. Display class creating a top based on grades\n");
  printf("5. Display the first 3 students according to their grades\n");
	
  if ((scanf("%u",&n)==1)&&(n<6))
    return n;
  else
    {
      fprintf(stderr,"The given input is not correct");
      return -1;
    }
}

//display the class 
void display(student st[],int n)
{
  int i;
  for(i=0;i<n;i++)
    printf("Name: %s \n Grade: %d \n",st[i].name,st[i].grade);
}

//sort the class in alphabetic order
void sort_al(student st[], int n)
{
  student valueToInsert;
  int holePosition;
  int i;
  
  for(i = 1; i < n; i++) 
    { 
      valueToInsert = st[i];
      holePosition = i;

      while (holePosition > 0 && strcmp(st[holePosition-1].name,valueToInsert.name)>0) 
	{
	  st[holePosition] = st[holePosition-1];
	  holePosition--;
	}

      if(holePosition != i)
	st[holePosition] = valueToInsert;
    }
  display(st,n);
}

//sort the class based on the students garde
//display just the first m students (m is given number)
void sort_gr(student st[], int n , int m)
{
  student valueToInsert;
  int holePosition;
  int i;
	 
  for (i=1 ; i<n ; i++)
    {
      valueToInsert = st[i];
      holePosition = i;
		
      while (holePosition > 0 && st[i-1].grade < valueToInsert.grade)
	{
	  st[holePosition]=st[holePosition-1];
	  holePosition--;
	}
		
      if (holePosition != i)
	st[holePosition]=valueToInsert;
    }		
  display(st,m);
}
