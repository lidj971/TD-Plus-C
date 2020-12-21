#include <stdlib.h>
#include <stdio.h>
int main()
{
   int i = 0,resultat = 1;
   int tableau[4] = {43,5,6,13};
   
   for(i = 0; i < 4;i++)
   {
      resultat *= tableau[i];
   }
   printf("Produit des %cl%cments = %d",130,130,resultat);
   
   return EXIT_SUCCESS ;
}