
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"card.h"
#include"server.h"

extern struct Account IN_data;
struct user user_acc[5] = { {"12345624569874","Ahmed Mohamed",5973.5},
                          {"65987562345689","ALi khaled",987562.5},
                          {"89756478654362","Ibrahim Awad",132565.5},
                          {"45687498524654","Ismaiel mohsen",75895.5},
                          {"78956524687982","Taha abdelwareth",456875.3} }; // User accounts database

void recieveTransactionData(float transaction) { //saving Ongoing Transactions
    FILE* fptr;
    fptr = fopen("Transactions.txt", "a");
    if (fptr == NULL) {
        printf("ERROR!");
    }
    fprintf(fptr, "Pan Number %s  Name is %s Transaction Amount is %f \n", IN_data.PAN_num, IN_data.first_name, transaction);
}



int isValidAccount(char* pan) //Check if The account is Valid
{
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(pan, user_acc[i].PAN) == 0)
            return i;
    }
    return -1;
}
int isAmountAvailable(float transaction, int user) { //Check if there is an enough balance
    if (user_acc[user].balance - transaction >= 0) {
        return 1;
    }

    return 0;
}
void saveTransaction(float transaction, int user) //Confirm The Transaction data
{
    user_acc[user].balance = (user_acc[user].balance - transaction);
    printf("\n user balance is: %f\n", (user_acc[user].balance));
}

