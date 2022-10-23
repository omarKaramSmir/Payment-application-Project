#include "App.h"
extern ST_accountsDB_t accounts[255];
/*
    this function will run according to the following flowchart
*/
void appStart(void)
{
/**************************INITIALIZATIONS**********************************************/
    EN_MODE MODE = -1 ;
    ST_terminalData_t terminal_IN_PROCESS ;
    ST_cardData_t card_IN_PROCESS ;
    ST_transaction_t Transaction_IN_PROCESS ;
/**************************WHILE(1)*****************************************************/
    while(1)
    {
       printf("/***************************************************************************************/\n");
       printf("choose from these modes :\n\t1- SET TERMINAL SETTINGS\n\t2- NEW TRANSACTION\n\t3- EXIT\n");
       scanf("%d",&MODE);
       switch(MODE)
       {
       case SET_TERMINAL_SETTINGS :
           printf("/********************************/\n");
           while ( (setMaxAmount(&terminal_IN_PROCESS)));
           break;
/*****************************************************************************************/
       case NEW_TRANSACTION :
           // get all card data
           printf("/********************************/\n");
           while (  ( getCardHolderName(&card_IN_PROCESS) ) );
           printf("/********************************/\n");
           while (  ( getCardExpiryDate(&card_IN_PROCESS) ) );
           printf("/********************************/\n");
           while (  ( getCardPAN(&card_IN_PROCESS) ) );

/*****************************************************************************************/
           //get the transaction date & check if the card expired or not
           printf("/********************************/\n");
           while (  (getTransactionDate(&terminal_IN_PROCESS)) );
           if( (isCardExpired(&card_IN_PROCESS,&terminal_IN_PROCESS))==EXPIRED_CARD )
           {
               printf("this card is expired , the process will end \n");
               break;
           }
           else
              printf("this card is not expired , the process in progress\n");


           //get the transaction amount & check if it is below max amount or not
           printf("/********************************/\n");
           while (  (getTransactionAmount(&terminal_IN_PROCESS)) );
           if( (isBelowMaxAmount(&terminal_IN_PROCESS))==EXCEED_MAX_AMOUNT )
           {
               printf("EXCEED MAX AMOUNT, the process will end \n");
               break;
           }
           else
              printf("not EXCEED MAX AMOUNT , the process in progress\n");

/*****************************************************************************************/
           /*checks if the PAN exists or not in the server's database */
           printf("/********************************/\n");
           Transaction_IN_PROCESS.cardHolderData = card_IN_PROCESS;
           isValidAccount(&Transaction_IN_PROCESS);
           if( (recieveTransactionData(&Transaction_IN_PROCESS))== DECLINED_STOLEN_CARD)
           {
               printf("\PAN does not exist in the server's database , the process will end \n");
               break;
           }
           else
              printf("\PAN exist in the server's database , the process in progress\n");

            Transaction_IN_PROCESS.terminalData = terminal_IN_PROCESS;
           /*checks if the transaction's amount is available or not */
           printf("/********************************/\n");
           isAmountAvailable(&Transaction_IN_PROCESS);
           if( (recieveTransactionData(&Transaction_IN_PROCESS))== DECLINED_INSUFFECIENT_FUND)
           {
               printf("transaction's amount is not available, the process will end \n");
               break;
           }
           else
              printf("transaction's amount is available, the process in progress\n");

           /*saving the data in the server */
           printf("/********************************/\n");
           saveTransaction(&Transaction_IN_PROCESS);
           if( (recieveTransactionData(&Transaction_IN_PROCESS))== INTERNAL_SERVER_ERROR)
           {
               printf("there is an error in the server, the process will end \n");
               break;
           }
           else
              printf("the process is Approved\n");

/*****************************************************************************************/
           break ;

       case EXIT :
          printf("the process end, program will exit");
          return 0 ;
          break;
       }
    }
}
