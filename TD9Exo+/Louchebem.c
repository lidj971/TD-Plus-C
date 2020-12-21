#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
   int i = 0,j = 1;
   char x;
   char mots[8000];
   while(1)
   {
      printf("Entrez un mot\n");
      scanf("%s",mots);
      i = strlen(mots);
      mots[i] = mots[0];
      mots[0] = 'l';
      mots[i + 1] = 'e';
      mots[i + 2] = 'm';
      printf("%s\n",mots);
   }
   return EXIT_SUCCESS;
}                                         