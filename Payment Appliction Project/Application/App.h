#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

/***********************************************\INCLUDES\*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "../Card/Card.h"
#include "../Terminal/Terminal.h"
#include "../Server/Server.h"

/************************************************\TYPEDEFS\****************************************/
typedef enum EN_MODE
{
SET_TERMINAL_SETTINGS=1,NEW_TRANSACTION,EXIT
}EN_MODE;

/************************************************\PROTOTYPES\***************************************/
void appStart(void);


#endif // APP_H_INCLUDED
