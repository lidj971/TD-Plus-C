#include <stdlib.h>
#include <stdio.h>
#define  COUVERT 1
#define ENSOLEILLE 2
#define PLUVIEUX 3
int main()
{
   int temps = PLUVIEUX;
   if(temps == COUVERT)
   {
	  printf("Couvert");
   }
   else if(temps == ENSOLEILLE)
   {
	  printf("Ensoleill%c",130);
   }
   else
   {
      printf("Pluvieux");
   }
   return EXIT_SUCCESS;
}