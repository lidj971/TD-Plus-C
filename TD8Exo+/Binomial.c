#include <stdlib.h>
#include <stdio.h>

int factorielle(int z);
int binomial (int n,int p);
int sigma (int n);

int main ()
{
  int n = 6, p = 3,coef = 0,result,x = 4;
  coef = binomial(n,p);
  result = sigma(x);
  printf("Coef = %d sigma = %d",coef,result);
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