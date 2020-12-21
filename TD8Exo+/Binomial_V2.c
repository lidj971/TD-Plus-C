#include <stdlib.h>
#include <stdio.h>

int factorielle(int z);
int binomial (int n,int p);
int sigma (int n);

int main ()
{
  int n = 0, p = 0,Coef = 0,result,x;
  printf("Entrez n\n");
  scanf("%d",&n);
  printf("Entrez p\n");
  scanf("%d",&p);
  Coef = binomial(n,p);
  printf("Coeficciant binomial = %d\n",Coef);
  printf("Entrez un entier\n");
  scanf("%d",&x);
  result = sigma(x);
  printf("sigma = %d",result);
  return EXIT_SUCCESS;
}

int binomial(int n,int p)
{
  int temp = 0,result;
  temp = factorielle(n - p);
  n = factorielle(n);
  p = factorielle(p);
  result = n/(p * temp);
  return result;
}

int factorielle(int z)
{
    int i,result = 1;
    for (i = 1;i<= z;i++)
    {
       result *= i;
    }
    return result;
}

int sigma(int n)
{
    int i = 0, j = 0,result = 0,temp = 0; 
    for (i = 0;i <= n - 1;i++)
    {
        temp = 0;
        for(j = 0;j <= i - 1;j++)
        {
           
           temp += i + j;
        }
        result += i*temp;
    }
    return result;
}