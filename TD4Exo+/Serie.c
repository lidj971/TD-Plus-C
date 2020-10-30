#include <stdlib.h>
#include <stdio.h>
int main()
{
   int tailleS = 0,i = 0,valeur = 0,resultat = 0;
   printf("Combien d'entiers composent la s%crie ?\n",130);
   scanf("%d",&tailleS);
   for(i = 0; i < tailleS;i++)
   {
     printf("Entrer element %d de la s%crie\n",i + 1,130);
     scanf("%d",&valeur);
     resultat += valeur;
   }
   printf("La somme des valeurs de la s%crie est : %d",130,resultat);

   
   return EXIT_SUCCESS;
}