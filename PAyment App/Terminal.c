
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"Terminal.h"

int Year_1, Month_1;
float Max_amount = 8000.0;

void getTransactionDate(void) //Function To get transaction date from RTC of the system
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    Year_1 = (tm.tm_year + 1900);
    Month_1 = (tm.tm_mon + 1);
}
int gatTransactionAmount(void) //Function To get Transaction Amount
{
    float trans_amount = 0.0;
    printf("Please Enter The Transaction Amount\n");
    scanf("%f", &trans_amount);
    return trans_amount;
}
int isBelowMaxAmount(float trans) //Check if the value exceeding the predefined max account
{
    if (trans > Max_amount)
    {
        return 0;
    }
    return 1;
}
void setMaxAmount(float amount) //Function to define The max amoount
{
    Max_amount = amount;
}

int isCardExpried(int month, int year) //Function To check if The card is expired
{
    getTransactionDate();
    int y = 0;

    // printf("date and time: %d-%d",tm.tm_mon,tm.tm_year);
    if (year - Year_1 < 0)
        return 0;
    else if (year - Year_1 == 0)
        y = 1;

    if ((month - Month_1) <= 0 && y == 1) {
        return 0;
    }

    return 1;
}

