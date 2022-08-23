
#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED
//struct decleration
struct user {
    char PAN[16], name[21];
    double balance;
};

// The functions decleration

void recieveTransactionData(float);
int isValidAccount(char*);
int isAmountAvailable(float, int);
void saveTransaction(float, int);

#endif // SERVER_H_INCLUDED

