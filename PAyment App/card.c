#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"card.h"
struct Account IN_data;

void getCardHolderName(void) //Get the Card Holder Name
{
    printf("Please Enter Your ACC Holder First Name\n");
    scanf("%s", IN_data.first_name);
    printf("Please Enter Your ACC Holder Last Name\n");
    scanf("%s", IN_data.last_name);
    strcat(IN_data.first_name, " ");
    strcat(IN_data.first_name, IN_data.last_name);
}

void getCardExpiryDate(void) //Get the Card expiry date
{
    printf("Please Enter Your ACC Expiration Month \n");
    scanf("%d", &IN_data.Exp_month);
    printf("Please Enter Your ACC Expiration Year \n");
    scanf("%d", &IN_data.Exp_year);
}
void getCardPAN(void)//Get the Card Pan Number
{
    printf("Please Enter Your ACC PAN\n");
    scanf("%s", IN_data.PAN_num);
}
