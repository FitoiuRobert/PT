#include "libstr.h"

void main(void)
{
  char s1[12],s2[]="Hello darkness my old friend";

  printf("%d\n",mystrcmp("abb","ab"));
  mystrncpy(s1, s2, 11);
  puts(s1);
  mystrcpy(s1,"Text replacement, beach!");
  puts(s1);

}
