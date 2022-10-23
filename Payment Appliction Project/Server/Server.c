#include "Server.h"

// data base
ST_accountsDB_t accounts[255] = {
{1000,"abcdefghijklmnop1000"},{2000,"abcdefghijklmnop1001"},{3000,"abcdefghijklmnop1002"},{2000,"abcdefghijklmnop1003"},{4000,"abcdefghijklmnop1004"},
{5000,"abcdefghijklmnop1005"},{1000,"abcdefghijklmnop1006"},{2000,"abcdefghijklmnop1007"},{3000,"abcdefghijklmnop1008"},{4000,"abcdefghijklmnop1009"},{5000,"abcdefghijklmnop1010"}
,{6000,"abcdefghijklmnop1011"},{1000,"abcdefghijklmnop1012"},{2000,"abcdefghijklmnop1013"},{3000,"abcdefghijklmnop1014"},{4000,"abcdefghijklmnop1015"},{5000,"abcdefghijklmnop1016"}
,{6000,"abcdefghijklmnop1017"},{1000,"abcdefghijklmnop1018"},{2000,"abcdefghijklmnop1019"},{3000,"abcdefghijklmnop1020"},{4000,"abcdefghijklmnop1021"},{5000,"abcdefghijklmnop1022"}
,{6000,"abcdefghijklmnop1023"},{1000,"abcdefghijklmnop1024"},{2000,"abcdefghijklmnop1025"},{3000,"abcdefghijklmnop1026"},{4000,"abcdefghijklmnop1027"},{5000,"abcdefghijklmnop1028"}
,{6000,"abcdefghijklmnop1029"},{1000,"abcdefghijklmnop1030"},{2000,"abcdefghijklmnop1031"},{3000,"abcdefghijklmnop1032"},{4000,"abcdefghijklmnop1033"},{5000,"abcdefghijklmnop1034"}
,{6000,"abcdefghijklmnop1035"},{1000,"abcdefghijklmnop1036"},{2000,"abcdefghijklmnop1037"},{3000,"abcdefghijklmnop1038"},{4000,"abcdefghijklmnop1039"},{5000,"abcdefghijklmnop1040"}
,{6000,"abcdefghijklmnop1041"},{1000,"abcdefghijklmnop1042"},{2000,"abcdefghijklmnop1043"},{3000,"abcdefghijklmnop1044"},{4000,"abcdefghijklmnop1045"},{5000,"abcdefghijklmnop1046"},{6000,"abcdefghijklmnop1047"}
,{1000,"abcdefghijklmnop1048"},{2000,"abcdefghijklmnop1049"},{3000,"abcdefghijklmnop1050"},{4000,"abcdefghijklmnop1051"},{5000,"abcdefghijklmnop1052"},{6000,"abcdefghijklmnop1053"}
,{1000,"abcdefghijklmnop1054"},{2000,"abcdefghijklmnop1055"},{3000,"abcdefghijklmnop1056"},{4000,"abcdefghijklmnop1057"},{5000,"abcdefghijklmnop1058"},{6000,"abcdefghijklmnop1059"}
,{1000,"abcdefghijklmnop1060"},{2000,"abcdefghijklmnop1061"},{3000,"abcdefghijklmnop1062"},{4000,"abcdefghijklmnop1063"},{5000,"abcdefghijklmnop1064"},{6000,"abcdefghijklmnop1065"}
,{1000,"abcdefghijklmnop1066"},{2000,"abcdefghijklmnop1067"},{3000,"abcdefghijklmnop1068"},{4000,"abcdefghijklmnop1069"},{5000,"abcdefghijklmnop1070"},{6000,"abcdefghijklmnop1071"}
,{1000,"abcdefghijklmnop1072"},{2000,"abcdefghijklmnop1073"},{3000,"abcdefghijklmnop1074"},{4000,"abcdefghijklmnop1075"},{5000,"abcdefghijklmnop1076"},{6000,"abcdefghijklmnop1077"}
,{1000,"abcdefghijklmnop1078"},{2000,"abcdefghijklmnop1079"},{3000,"abcdefghijklmnop1080"},{4000,"abcdefghijklmnop1081"},{5000,"abcdefghijklmnop1082"},{6000,"abcdefghijklmnop1083"}
,{1000,"abcdefghijklmnop1084"},{2000,"abcdefghijklmnop1085"},{3000,"abcdefghijklmnop1086"},{4000,"abcdefghijklmnop1087"},{5000,"abcdefghijklmnop1088"},{6000,"abcdefghijklmnop1089"}
,{1000,"abcdefghijklmnop1090"},{2000,"abcdefghijklmnop1091"},{3000,"abcdefghijklmnop1092"},{4000,"abcdefghijklmnop1093"},{5000,"abcdefghijklmnop1094"},{6000,"abcdefghijklmnop1095"}
,{1000,"abcdefghijklmnop1096"},{2000,"abcdefghijklmnop1097"},{3000,"abcdefghijklmnop1098"},{4000,"abcdefghijklmnop1099"},{5000,"abcdefghijklmnop1100"}
,{2000,"abcdefghijklmnop1101"},{3000,"abcdefghijklmnop1102"},{2000,"abcdefghijklmnop1103"},{4000,"abcdefghijklmnop1104"},{5000,"abcdefghijklmnop1105"}
,{1000,"abcdefghijklmnop1106"},{2000,"abcdefghijklmnop1107"},{3000,"abcdefghijklmnop1108"},{4000,"abcdefghijklmnop1109"},{5000,"abcdefghijklmnop1110"},{6000,"abcdefghijklmnop1111"}
,{1000,"abcdefghijklmnop1112"},{2000,"abcdefghijklmnop1113"},{3000,"abcdefghijklmnop1114"},{4000,"abcdefghijklmnop1115"},{5000,"abcdefghijklmnop1116"},{6000,"abcdefghijklmnop1117"}
,{1000,"abcdefghijklmnop1118"},{2000,"abcdefghijklmnop1119"},{3000,"abcdefghijklmnop1120"},{4000,"abcdefghijklmnop1121"},{5000,"abcdefghijklmnop1122"},{6000,"abcdefghijklmnop1123"}
,{1000,"abcdefghijklmnop1124"},{2000,"abcdefghijklmnop1125"},{3000,"abcdefghijklmnop1126"},{4000,"abcdefghijklmnop1127"},{5000,"abcdefghijklmnop1128"},{6000,"abcdefghijklmnop1129"}
};

ST_transaction_t transactions[255] = { 0 };

uint32_t transNumber=0; // global variable to count the number of transactions
uint8_t PAN_LOCATION=0;// global variable to store the location of the PAN from the data base


/*
    *This function will take card data and validate these data.
    *It checks if the PAN exists or not in the server's database.
    *If the PAN doesn't exist will return ACCOUNT_NOT_FOUND, else will return OK
*/
EN_serverError_t isValidAccount(ST_transaction_t *transData)
{
    uint8_t counter;
    uint8_t Exist_flag =0;
    for(counter=0 ; counter<255 ;counter++ )
    {
       if( (strcmp(accounts[counter].primaryAccountNumber,transData->cardHolderData.primaryAccountNumber)) ==0)
       {
           Exist_flag=1;
           break;
       }
    }
    if(Exist_flag==0)
    {
        transData->transState= DECLINED_STOLEN_CARD ;
        return ACCOUNT_NOT_FOUND;
    }
    else
    {
        PAN_LOCATION = counter;
        return OKAY;
    }
}

/*
    *This function will take terminal data and validate these data.
    *It checks if the transaction's amount is available or not.
    *If the transaction amount is greater than the balance in the database will
      return LOW_BALANCE, else will return OK
*/
EN_serverError_t isAmountAvailable(ST_transaction_t *transData)
{
    if(transData->terminalData.transAmount > accounts[PAN_LOCATION].balance )
    {
        transData->transState = DECLINED_INSUFFECIENT_FUND ;
        return LOW_BALANCE;
    }
    else
    {
        return OKAY;
    }
}

/*
    *This function will take all transaction data into the transactions database.
    *It gives a sequence number to a transaction, this number is incremented
      once a transaction is processed into the server.
    *If saves any type of transaction, APPROVED or DECLINED, with the specific reason for declining/transaction state.
    *If transaction can't be saved will return SAVING_FAILED, else will return OK
*/
EN_serverError_t saveTransaction(ST_transaction_t *transData)
{
	if (transNumber >= 255)
    {
        transData->transState= INTERNAL_SERVER_ERROR ;
        return SAVING_FAILED;
    }
	else
	{
		// minus balance and save transaction
		accounts[PAN_LOCATION].balance-=transData->terminalData.transAmount;
		transData->transactionSequenceNumber = transNumber;
		transactions[transNumber] = *transData;
		transNumber++;
		transData->transState= APPROVED ;
		return OKAY ;
	}
}

/*
    *This function will take all transaction data and validate its data.
    *It checks the account details and amount availability.
    *If the account does not exist return DECLINED_STOLEN_CARD,
      if the amount is not available will return DECLINED_INSUFFECIENT_FUND,
      if a transaction can't be saved will return INTERNAL_SERVER_ERROR and
        will not save the transaction, else returns APPROVED.
    *It will update the database with the new balance.
*/
EN_transState_t recieveTransactionData(ST_transaction_t *transData)
{
    return transData->transState ;
}

