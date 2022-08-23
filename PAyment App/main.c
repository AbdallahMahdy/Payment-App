/*This project is the assignment of The Payment App
designed by :Abdullah Abdelwahed Mahdy
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"card.h"
#include"server.h"
#include"Terminal.h"

extern struct Account IN_data;
extern struct user user_acc[5]; //retrive data from another folder

int main() {
    int date_verify = 0, account_verify = 0, balance_verify = 0, over_max = 0;  // Needed variables
    float transaction;
    char exit = '1';
    while (exit != 0) // The main program while loop
    {

        getCardHolderName(); //Function to identify The Name
        getCardExpiryDate(); //get The Card expiry date
        date_verify = isCardExpried(IN_data.Exp_month, IN_data.Exp_year); //Check if the card is expired
        getCardPAN(); //Get the card Pan number
        if (date_verify == 0)
        {
            printf("Sorry This card is expired!");
            goto label;
        }
        transaction = gatTransactionAmount(); //Get the transaction amount
        over_max = isBelowMaxAmount(transaction); //Check if that amount more than the pre defined MAX
        if (over_max == 0)
        {
            printf("Over Max amount\n");
            goto label;
        }
        account_verify = isValidAccount(IN_data.PAN_num); //Check if the account is valid
        if (account_verify == -1)
        {
            printf("This Account is invalid");
            goto label;
        }


        balance_verify = isAmountAvailable(transaction, account_verify); // check if there is enough money
        if (balance_verify == 0)
        {
            printf("Insufficient Amount!\n");
            goto label;
        }
        saveTransaction(transaction, account_verify); //update account with new data

        recieveTransactionData(transaction); //update the transaction log

    label:   //A point to jump to In case Any of data is not valid
        printf("To start a new process press any key\n To exit press 0 \n"); //Ask user if he needs another process
        scanf("%s", &exit);
        if (exit == '0') {
            break;
        }
        else {
            date_verify = 0;
            account_verify = 0;
            balance_verify = 0;
            transaction = 0.0;
        }

    }
}

