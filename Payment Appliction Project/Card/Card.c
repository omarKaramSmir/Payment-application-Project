#include"Card.h"

/*
    -This function will ask for the card holder's name and store it into card data.
    -Card holder name is 24 characters string max and 20 min.
    -If the card holder name is NULL, less than 20 characters or more than 24
    will return WRONG_NAME error, else return OK.
*/
EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
    printf("Enter the card holder name\n");
    fflush(stdin);
    gets(cardData->cardHolderName);
    uint8_t Lengh = strlen(cardData->cardHolderName) ;
    if(Lengh>24 || Lengh<20)
    {
       printf("\nWRONG_NAME\nthe card holder name should be more than 20 characters & less than 24\n");
       return WRONG_NAME;
    }
    else
    {
       printf("\nOK\n");
       return OK;
    }
}


/*
    -This function will ask for the card expiry date and store it in card data.
    -Card expiry date is 5 characters string in the format "MM/YY", e.g "05/25".
    -If the card expiry date is NULL, less or more than 5 characters, or has the wrong format
     will return WRONG_EXP_DATE error, else return OK.
*/
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
    printf("Enter the  card expiry date\n");
    gets(cardData->cardExpirationDate);
    uint8_t Lengh = strlen(cardData->cardExpirationDate) ;
    if(Lengh!=5 || cardData->cardExpirationDate[2]!='/' || (cardData->cardExpirationDate[0]-'0')<0 ||(cardData->cardExpirationDate[0]-'0')>9 || (cardData->cardExpirationDate[1]-'0')<0 ||(cardData->cardExpirationDate[1]-'0')>9 || (cardData->cardExpirationDate[3]-'0')<0 ||(cardData->cardExpirationDate[3]-'0')>9 || (cardData->cardExpirationDate[4]-'0')<0 ||(cardData->cardExpirationDate[4]-'0')>9  )
    {
       printf("\nWRONG_EXP_DATE\nthe card date should be 5 numbers with this format xx/yy\n ");
       return WRONG_EXP_DATE;
    }
    else
    {
       printf("\nOK\n");
       return OK;
    }
}


/*
    -This function will ask for the card's Primary Account Number and store it in card data.
    -PAN is 20 characters alphanumeric only string 19 character max, and 16 character min.
    -If the PAN is NULL, less than 16 or more than 19 characters, will return WRONG_PAN error, else return OK.
*/
EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
   uint8_t check_PAN = 0;
   uint8_t check_Digits = 0;
   uint8_t index;
   printf("Please Enter The Card PAN: \n");
   fflush(stdin);
   gets(cardData->primaryAccountNumber);
   check_PAN = strlen(cardData->primaryAccountNumber);
   if ( check_PAN != 20 )
   {
      printf("WRONG_PAN 1\n");
      return WRONG_PAN;
   }

   for (index = 0; index < 20; index++)
   {
      if ( isdigit(cardData->primaryAccountNumber[index]) )
         check_Digits++;
   }

   if ( check_Digits <=4 && check_Digits >=1)
   {
        printf("ok\n");
        return OK;
   }
   else
   {
      printf("WRONG_PAN\n");
      return WRONG_PAN;
   }

}
