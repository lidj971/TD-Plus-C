#include <stdlib.h>

int main ()
{
  int x = 1, y = 2 ,z = 3, temp;
  temp = x;
  x = z;
  z = y;
  y = temp;

  return EXIT_SUCCESS;
}