#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0


typedef enum Day
{
   SUNDAY,
   MONDAY,
   TUESDAY, 
   WEDNESDAY, 
   THURSDAY, 
   FRIDAY, 
   SATURDAY 
}Day;

typedef struct date_s
{
    int day;
    int month;
    int year;
}date_s;

date_s userInput_bm();
date_s userInputBoucle_bm(date_s x_bm);
date_s addDay_bm(date_s x_bm);

int CheckBissextile(int y);
int CheckDate(int month,int year);

int NameDay(date_s x_bm);
void PrintDay(date_s x_bm);


int main()
{
    int userControls = 1;
    date_s Input_bm;
    while(userControls == 1)
    {
        Input_bm = userInput_bm();
        Input_bm = userInputBoucle_bm(Input_bm);
        printf("%d/%d/%d",Input_bm.day,-Input_bm.month,-Input_bm.year);
        PrintDay(Input_bm);
        Input_bm = addDay_bm(Input_bm);
        printf("\n%d/%d/%d",Input_bm.day,-Input_bm.month,-Input_bm.year);
        PrintDay(Input_bm);
        printf("\nCONTINUE? 1\nQUIT 0\n");
        scanf("%d",&userControls);
    }
    return EXIT_SUCCESS;
}

struct date_s userInput_bm()
{
    date_s userDate_bm;
    printf("Saisir la date (format jj-mm-aaaa): ");
    scanf("%d%d%d",&userDate_bm.day,&userDate_bm.month,&userDate_bm.year);
    return userDate_bm;
}

struct date_s userInputBoucle_bm(date_s x_bm)
{

    int month;
    month = CheckDate(x_bm.month,x_bm.year);
    while(x_bm.day > month || x_bm.month < -12)
    {
        printf("invalid date\n");
        x_bm = userInput_bm();
        month = CheckDate(x_bm.month,x_bm.year);
    }
    return x_bm;
}

int CheckDate(int month,int year)
{
    int mois31[7] = {-1,-3,-5,-7,-8,-10,-12};
    int i = 0,quelMois,bissex = 0;
    bissex = CheckBissextile(year);
    for(i = 0;i <= 7; i++)
    {
        if(mois31[i] == month)
        {
            quelMois = 31;
            break;
        }else if(month == -2)
        {
            if(bissex == TRUE)
            {
                quelMois = 29;
            }
            else
            {
                quelMois = 28;
            }

        }
        else
        {
            quelMois = 30;
        }
    }
    return quelMois;
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

date_s addDay_bm(date_s x_bm)
{
    int combienJours = 0;
    combienJours = CheckDate(x_bm.month,x_bm.year);
    if(x_bm.day == combienJours)
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

int NameDay(date_s x_bm)
{
    int c = 0,y = 0,m = 0,d = 0;
    c = (14 - -x_bm.month)/12;
    y = -x_bm.year - c;
    m = -x_bm.month + 12*c - 2;
    d = (x_bm.day + y + y/4 - y/100 + y/400 + (31*m)/12)%7;
    return d;
}

void PrintDay(date_s x_bm)
{
    Day dayName;
    dayName = NameDay(x_bm);
    switch(dayName)
    {
        case SUNDAY:
        printf(" its a sunday");
        break;
        case MONDAY: 
        printf(" its a monday");
        break;
        case TUESDAY:
        printf(" its a tuesday");
        break;
        case WEDNESDAY:
        printf(" its a wednesday");
        break;
        case THURSDAY:
        printf(" its a thursday");
        break;
        case FRIDAY:
        printf(" its a friday");
        break;
        case SATURDAY:
        printf(" its a saturday");
        break;
    }
}

