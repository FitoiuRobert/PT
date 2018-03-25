#include <stdio.h>

int mystrcmp(const char *cl, const char *cr)
{
  unsigned char c1, c2;

  while (1) {
    c1 = *cl++;
    c2 = *cr++;
    if (c1 != c2)
      return c1 < c2 ? -1 : 1;
    if (!c1)
      break;
  }
  return 0;
}

char *mystrcpy(char *dest, const char *src)
{
  char *tmp = dest;

  while((*dest++ = *src++) != '\0');

  return tmp;
}

char *mystrncpy(char *dest, const char *src, unsigned n)
{
  unsigned i;

  for (i = 0; i < n && src[i] != '\0'; i++)
    dest[i] = src[i];
  for ( ; i < n; i++)
    dest[i] = '\0';

  return dest;
}
