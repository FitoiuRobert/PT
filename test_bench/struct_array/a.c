#include <stdio.h>
#include <stdlib.h>


struct student
{
  char name[50];
  int grade;
} stud[50];

int main(void)
{
  //int sz=sizeof(stud);
  int nr;
  printf("\nSize: %zu\n",sizeof(stud));
  printf("Enter the number of students: ");
  scanf("%d",&nr);
  //stud = malloc(sz * nr);
  for(int i = 0; i < nr; ++i)
    {
      printf("\nStudent %d:",i+1);
      printf("\nName: ");
      scanf("%s",&stud[i].name);
      printf("Grade: ");
      scanf("%d",&stud[i].grade);
    }
  for(int i = 0; i < nr; ++i)
    printf("\nName: %s Grade %d",stud[i].name,stud[i].grade);
  printf("\nSize: %zu\n",sizeof(stud));
  return 0;
}
