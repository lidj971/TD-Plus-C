#include <stdlib.h>
#include <stdio.h>
int main()
{
   int i = 0,valeur = 0,resultat = 1;
   printf("Entrez un entier naturel\n");
   scanf("%d",&valeur);
   for(i = 1; i < valeur;i++)
   {
     resultat *= i + 1;
   }
   printf("La factorielle de %d est : %d",valeur,resultat);
   
   return EXIT_SUCCESS ;
}