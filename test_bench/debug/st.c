#include <stdio.h>
#include <stdlib.h>
#include "myfunctions.h"
#define MAX 30

int main(void)
{
  int choice,n,i;
  student st[MAX];
  do
    {
      choice=menu();
      switch (choice)
	{
	case 0 :
	  {
	    return 0;
	    break;
	  }
	case 1 :
	  {
	    printf("Give the number of students:");
	    if(scanf("%d",&n)!=1)
	      {
		fprintf(stderr,"The given input is not correct");
		return 0;
	      }
	    break;
	  }
	case 2 :
	  {
	    for(i=0;i<n;i++)
	      {
		printf("Name:");
		scanf("%s",st[i].name);
		printf("Grade:");
		scanf("%d",&st[i].grade);
	      }
	    break;
	  }
	case 3 :
	  {
	    sort_al(st,n);
	    break;
	  }
	case 4 :
	  {
	    sort_gr(st,n,n);
	    break;
	  }
	case 5 :
	  {
	    sort_gr(st,n,3);
	    break;
	  }
	}
    }
  while (choice!=0);
  return 0;
}
