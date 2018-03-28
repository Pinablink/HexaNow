#include <stdio.h>
#include <stdlib.h>
#include "../lib/hexaNow.h"
#include "../lib/message.h"
#define  SIZE_ASCII 		255
#define  VALOR_INICIAL 		0
#define  QT_POS_REPRE_HEXA 	4

void runInitResource (HEXANOW *hexanowRefer);
static void initEquivalences  (DATA_RESOURCE *dataResourceRefer);
static void chargeASCIIValues (DATA_RESOURCE *dataResourceRefer);

void runInitResource (HEXANOW *hexanowRefer) {

   printf (__MESSAGE_INIT1__);
   DATA_RESOURCE dataResource 	= 	*(DATA_RESOURCE*)malloc(sizeof(DATA_RESOURCE));
   dataResource.equivalenceList	=	(EQUIVALENCE*)malloc(SIZE_ASCII * sizeof(EQUIVALENCE));
   initEquivalences  (&dataResource);   
   chargeASCIIValues (&dataResource);
   printf (__MESSAGE_INIT2__);
   printf (__MESSAGE_INIT3__);
   system("PAUSE");
}

static void initEquivalences (DATA_RESOURCE *dataResourceRefer) {
	//Carregando os cursores
   EQUIVALENCE* equivalenceCursor;
   EQUIVALENCE  equivalenceObj;
   unsigned int LEN_LOOP				=	SIZE_ASCII;
   unsigned int CONTROL_LOOP			=	VALOR_INICIAL;
   equivalenceCursor 					=	dataResourceRefer->equivalenceList;

   for (; CONTROL_LOOP < LEN_LOOP; CONTROL_LOOP++) {
   		equivalenceObj						= *(EQUIVALENCE*)malloc(sizeof(equivalenceObj));
   		equivalenceObj.caracter 			= *(char*)malloc(sizeof(char));
   		equivalenceObj.hexaEquivalence		=  (char*)calloc(QT_POS_REPRE_HEXA, sizeof(char));
   		*(equivalenceCursor + CONTROL_LOOP)	=	equivalenceObj;	
   }

   equivalenceCursor = NULL;
   free (equivalenceCursor);
}

static void chargeASCIIValues (DATA_RESOURCE *dataResourceRefer) {

	EQUIVALENCE* equivalenceCursor		=	dataResourceRefer->equivalenceList;
    
    EQUIVALENCE  *referObj0				=	(equivalenceCursor + 0);
	referObj0->caracter     			=   ' ';   
    referObj0->hexaEquivalence			= 	"0x00";
	EQUIVALENCE  *referObj1				=	(equivalenceCursor + 1);
	referObj1->caracter     			=   ' ';    
    referObj1->hexaEquivalence			= 	"0x01";
	EQUIVALENCE  *referObj2				=	(equivalenceCursor + 2);
	referObj2->caracter     			=   ' ';    
    referObj2->hexaEquivalence			= 	"0x02";
    EQUIVALENCE  *referObj3				=	(equivalenceCursor + 3);
	referObj3->caracter     			=   ' ';    
    referObj3->hexaEquivalence			= 	"0x03";
    EQUIVALENCE  *referObj4				=	(equivalenceCursor + 4);
	referObj4->caracter     			=   ' ';    
    referObj4->hexaEquivalence			= 	"0x04";
    EQUIVALENCE  *referObj5				=	(equivalenceCursor + 5);
	referObj5->caracter     			=   ' ';    
    referObj5->hexaEquivalence			= 	"0x05";
    EQUIVALENCE  *referObj6				=	(equivalenceCursor + 6);
	referObj6->caracter     			=   ' ';    
    referObj6->hexaEquivalence			= 	"0x06";
    EQUIVALENCE  *referObj7				=	(equivalenceCursor + 7);
	referObj7->caracter     			=   ' ';    
    referObj7->hexaEquivalence			= 	"0x07";
    EQUIVALENCE  *referObj8				=	(equivalenceCursor + 8);
	referObj8->caracter     			=   ' ';    
    referObj8->hexaEquivalence			= 	"0x08";
    EQUIVALENCE  *referObj9				=	(equivalenceCursor + 9);
	referObj9->caracter     			=   ' ';    
    referObj9->hexaEquivalence			= 	"0x09";
    EQUIVALENCE  *referObj10			=	(equivalenceCursor + 10);
	referObj10->caracter     			=   ' ';    
    referObj10->hexaEquivalence			= 	"0x0A";
    EQUIVALENCE  *referObj11			=	(equivalenceCursor + 11);
	referObj11->caracter     			=   ' ';    
    referObj11->hexaEquivalence			= 	"0x0B";
    EQUIVALENCE  *referObj12			=	(equivalenceCursor + 12);
	referObj12->caracter     			=   ' ';    
    referObj12->hexaEquivalence			= 	"0x0C";
    EQUIVALENCE  *referObj13			=	(equivalenceCursor + 13);
	referObj13->caracter     			=   ' ';    
    referObj13->hexaEquivalence			= 	"0x0D";
    EQUIVALENCE  *referObj14			=	(equivalenceCursor + 14);
	referObj14->caracter     			=   ' ';    
    referObj14->hexaEquivalence			= 	"0x0E";
    EQUIVALENCE  *referObj15			=	(equivalenceCursor + 15);
	referObj15->caracter     			=   ' ';    
    referObj15->hexaEquivalence			= 	"0x0F";
	
    equivalenceCursor					=	NULL;
    free (equivalenceCursor);
}
