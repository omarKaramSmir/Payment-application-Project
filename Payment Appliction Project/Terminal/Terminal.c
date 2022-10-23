#include "Terminal.h"

/*

    *This function will ask for the transaction data and store it in terminal data.
    *Transaction date is 10 characters string in the format DD/MM/YYYY, e.g 25/06/2022.
    *If the transaction date is NULL, less than 10 characters or wrong format will return
     WRONG_DATE error, else return OK.

*Optional:
 The function will read the current date from your computer and store it into terminal data
  with the mentioned size and format.
*/
EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
    printf("Enter the Transaction date,please \n");
    gets(termData->transactionDate);

    uint8_t Lengh = strlen(termData->transactionDate) ;
    uint8_t alpha_flag =0;

    if(Lengh!=10 || termData->transactionDate[2]!='/'|| termData->transactionDate[5]!='/' )
    {
       printf("\nWRONG_DATE\nTransaction date should be is 10 characters in the format DD/MM/YYYY\n");
       return WRONG_DATE;
    }
    else
    {
        for(uint8_t counter=0 ; counter<Lengh ;counter++ )
        {
           if(  (isdigit(termData->transactionDate[counter]))  )
           {
              alpha_flag++;
           }
        }
        if(alpha_flag == 8)
        {
           printf("\nOK\n");
           return OKK;
        }
        else
        {
           printf("\WRONG DATE\nTransaction date should be is 10 characters in the format DD/MM/YYYY\n");
           return WRONG_DATE;
        }
    }
}

/*
    *This function compares the card expiry date with the transaction date.
    *If the card expiration date is before the transaction date will return EXPIRED_CARD, else return OK.
*/
EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
   if ((cardData->cardExpirationDate[3] == termData->transactionDate[8]))
   {
       if ((cardData->cardExpirationDate[4] == termData->transactionDate[9]))
       {
            if ((cardData->cardExpirationDate[1] == termData->transactionDate[4]))
            {
                if ((cardData->cardExpirationDate[0] == termData->transactionDate[3]))
                {
                     return OKK;
                }
                else if ((cardData->cardExpirationDate[0] > termData->transactionDate[3]))
                {
                    return OKK;
                }
                else if ((cardData->cardExpirationDate[0] < termData->transactionDate[3]))
                {
                    return EXPIRED_CARD;
                }
            }
            else if ((cardData->cardExpirationDate[1] > termData->transactionDate[4]))
            {
                return OKK;
            }
            else if ((cardData->cardExpirationDate[1] < termData->transactionDate[4]))
            {
                return EXPIRED_CARD;
            }
       }
       else if ((cardData->cardExpirationDate[4] > termData->transactionDate[9]))
       {
           return OKK;
       }
       else if ((cardData->cardExpirationDate[4] < termData->transactionDate[9]))
       {
           return EXPIRED_CARD;
       }
   }
   else if ((cardData->cardExpirationDate[3] > termData->transactionDate[8]))
   {
       return OKK;
   }
   else if ((cardData->cardExpirationDate[3] < termData->transactionDate[8]))
   {
       return EXPIRED_CARD;
   }
}


/*
    *This function asks for the transaction amount and saves it into terminal data.
    *If the transaction amount is less than or equal to 0 will return INVALID_AMOUNT, else return OK.
*/
EN_terminalError_t  getTransactionAmount (ST_terminalData_t *termData)
{
    printf("Enter the Transaction amount,please \n");
    scanf("%f",&termData->transAmount);
    if(termData->transAmount <= 0)
    {
       printf("\nINVALID AMOUNT\n please Enter number more than zero\n");
       return INVALID_AMOUNT;
    }
    else
    {
        printf("\nOK\n");
        return OKK;
    }
}

/*
    *This function compares the transaction amount with the terminal max amount.
    *If the transaction amount is larger than the terminal max amount will return
      EXCEED_MAX_AMOUNT, else return OK.
*/
EN_terminalError_t  isBelowMaxAmount (ST_terminalData_t *termData)
{
    if(termData->transAmount > termData->maxTransAmount )
    {
       return EXCEED_MAX_AMOUNT;
    }
    else
    {
        return OKK;
    }
}

/*
    *This function sets the maximum allowed amount into terminal data.
    *Transaction max amount is a float number.
    *If transaction max amount less than or equal to 0 will return
      INVALID_MAX_AMOUNT error, else return OK.
*/
EN_terminalError_t setMaxAmount(ST_terminalData_t *termData)
{
    printf("Enter the Transaction max amount,please \n");
    scanf("%f",&termData->maxTransAmount);
    if(termData->maxTransAmount <= 0)
    {
       printf("\INVALID MAX AMOUNT\n please Enter number more than zero\n");
       return INVALID_MAX_AMOUNT;
    }
    else
    {
        printf("\nOK\n");
        return OKK;
    }
}
