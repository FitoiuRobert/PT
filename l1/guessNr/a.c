#include <stdio.h>
int search(int st,int dr)
{   
    int c;
    char r[2];
    if(st>dr)
            return -1;
    else
        {
            c =(st+dr)/2;
            printf("Is your number %d?\n",c);
            scanf("%s",r);
            if (r[0]=='y')
                return c;
            printf("Is your number greater than %d?\n",c);
            scanf("%s",r); 
            if (r[0]=='y')
                 return search(c+1,dr);
            else
               return search(st,c-1);
        }
}

int main(void)
{
    int c,st=1,dr=100;
    printf("Think about a number from 1 to 100 and I will guess it.\nReady?");
    c=search(st,dr);
    if (c==-1)
     printf("Error, number not found!");
    else
    printf("Your number is %d",c);   
    return 0;
}
