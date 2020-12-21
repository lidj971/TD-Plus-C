#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct date_s
{
    int day;
    int month;
    int year;
};

struct date_s userInput_bm();
struct date_s userInputBoucle_bm(struct date_s x_bm);
struct date_s addDay_bm(struct date_s x_bm);

int CheckDate(int month,int year);
int CheckBissextile(int y);


int main()
{
    struct date_s Input_bm,nextDay_bm;
    Input_bm = userInput_bm();
    Input_bm = userInputBoucle_bm(Input_bm);
    printf("%d/%d/%d",Input_bm.day,-Input_bm.month,-Input_bm.year);
    nextDay_bm = addDay_bm(Input_bm);
    printf("\n%d/%d/%d",nextDay_bm.day,-nextDay_bm.month,-nextDay_bm.year);
    return EXIT_SUCCESS;
}


struct date_s userInput_bm()
{
    struct date_s userDate_bm;
    printf("Saisir la date (format jj-mm-aaaa): ");
    scanf("%d%d%d",&userDate_bm.day,&userDate_bm.month,&userDate_bm.year);
    return userDate_bm;
}


struct date_s userInputBoucle_bm(struct date_s x_bm)
{
    int nbDays;
    nbDays = CheckDate(x_bm.month,x_bm.year);
    while(x_bm.day > nbDays || x_bm.month < -12)
    {
        x_bm = userInput_bm();
        nbDays = CheckDate(x_bm.month,x_bm.year);
    }
    return x_bm;
}


struct date_s addDay_bm(struct date_s x_bm)
{
    int nbDays = 0;
    nbDays = CheckDate(x_bm.month,x_bm.year);
    if(x_bm.day == nbDays)
    {
        x_bm.day = 1;
        if(x_bm.month == -12)
        {
            x_bm.month = -1;
            x_bm.year--;
        }else
        {
            x_bm.month--;
        }
    }else
    {
        x_bm.day++;
    }
    return x_bm; 
}


int CheckDate(int month,int year)
{
    int mois31[7] = {-1,-3,-5,-7,-8,-10,-12};
    int i = 0,nbDays,bissex = 0;
    bissex = CheckBissextile(year);
    for(i = 0;i <= 7; i++)
    {
        if(mois31[i] == month)
        {
            nbDays = 31;
            break;
        }else if(month == -2)
        {
            if(bissex == TRUE)
            {
                nbDays = 29;
            }
            else
            {
                nbDays = 28;
            }
            
        }
        else
        {
            nbDays = 30;
        } 
    }
    return nbDays;
}


int CheckBissextile(int y)
{
    if(y%4 == 0)
    {
        if(y%100 == 0)
        {
           if(y%400 == 0)
           {
               return TRUE;
           }else
           {
               
               return FALSE;
           }
           
        }
        else
        {
            
            return TRUE;
        }  
    }
    else
    {
        
        return FALSE;
    }
    
}

