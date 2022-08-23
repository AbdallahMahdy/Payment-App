
#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
//struct decleration
struct Account {
    char PAN_num[16], first_name[10], last_name[10];
    int Exp_month, Exp_year;
    float balance;
};


// The functions decleration
void getCardHolderName(void);
void getCardExpiryDate(void);
void getCardPAN(void);

#endif // CARD_H_INCLUDED

