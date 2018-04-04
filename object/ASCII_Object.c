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
   initSysColor ();
   setColorYellowText ();
   printf (__MESSAGE_INIT1__);
   DATA_RESOURCE dataResource 	      = 	*(DATA_RESOURCE*)malloc(sizeof(DATA_RESOURCE));
   dataResource.equivalenceList	      =	  (EQUIVALENCE*)malloc(SIZE_ASCII * sizeof(EQUIVALENCE));
   dataResource.lenEquivalence        =   *(int*)malloc(sizeof(int));
   initEquivalences  (&dataResource);   
   chargeASCIIValues (&dataResource);
   printf (__MESSAGE_INIT2__);
   printf (__MESSAGE_INIT3__);
   hexanowRefer->dataASC_ON           = 1;
   hexanowRefer->dataResourceObject   = dataResource;
   system("PAUSE");
   setColorWhiteText();
}

static void initEquivalences (DATA_RESOURCE *dataResourceRefer) {
	//Carregando os cursores
   EQUIVALENCE* equivalenceCursor;
   EQUIVALENCE  equivalenceObj;
   unsigned int LEN_LOOP				  =	SIZE_ASCII;
   unsigned int CONTROL_LOOP			=	VALOR_INICIAL;
   equivalenceCursor 					    =	dataResourceRefer->equivalenceList;

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
    
    EQUIVALENCE  *referObj0				 =	(equivalenceCursor + 0);
	referObj0->caracter     			   =   ' ';   
    referObj0->hexaEquivalence		 = 	"00h";
	EQUIVALENCE  *referObj1				   =	(equivalenceCursor + 1);
	referObj1->caracter     			   =   ' ';    
    referObj1->hexaEquivalence		 = 	"01h";
	EQUIVALENCE  *referObj2				   =	(equivalenceCursor + 2);
	referObj2->caracter     			   =   ' ';    
    referObj2->hexaEquivalence		 = 	"02h";
    EQUIVALENCE  *referObj3				 =	(equivalenceCursor + 3);
	referObj3->caracter     			   =   ' ';    
    referObj3->hexaEquivalence		 = 	"03h";
    EQUIVALENCE  *referObj4				 =	(equivalenceCursor + 4);
	referObj4->caracter     			   =   ' ';    
    referObj4->hexaEquivalence		 = 	"04h";
    EQUIVALENCE  *referObj5				 =	(equivalenceCursor + 5);
	referObj5->caracter     			   =   ' ';    
    referObj5->hexaEquivalence		 = 	"05h";
    EQUIVALENCE  *referObj6				 =	(equivalenceCursor + 6);
	referObj6->caracter     			   =   ' ';    
    referObj6->hexaEquivalence		 = 	"06h";
    EQUIVALENCE  *referObj7				 =	(equivalenceCursor + 7);
	referObj7->caracter     			   =   ' ';    
    referObj7->hexaEquivalence		 = 	"07h";
    EQUIVALENCE  *referObj8				 =	(equivalenceCursor + 8);
	referObj8->caracter     			   =   ' ';    
    referObj8->hexaEquivalence		 = 	"08h";
    EQUIVALENCE  *referObj9				 =	(equivalenceCursor + 9);
	referObj9->caracter     			   =   ' ';    
    referObj9->hexaEquivalence		 = 	"09h";
    EQUIVALENCE  *referObj10			 =	(equivalenceCursor + 10);
	referObj10->caracter     			   =   ' ';    
    referObj10->hexaEquivalence		 = 	"0Ah";
    EQUIVALENCE  *referObj11			 =	(equivalenceCursor + 11);
	referObj11->caracter     			   =   ' ';    
    referObj11->hexaEquivalence		 = 	"0Bh";
    EQUIVALENCE  *referObj12			 =	(equivalenceCursor + 12);
	referObj12->caracter     			   =   ' ';    
    referObj12->hexaEquivalence		 = 	"0Ch";
    EQUIVALENCE  *referObj13			 =	(equivalenceCursor + 13);
	referObj13->caracter     			   =   ' ';    
    referObj13->hexaEquivalence		 = 	"0Dh";
    EQUIVALENCE  *referObj14			 =	(equivalenceCursor + 14);
	referObj14->caracter     			   =   ' ';    
    referObj14->hexaEquivalence		 = 	"0Eh";
    EQUIVALENCE  *referObj15			 =	(equivalenceCursor + 15);
	referObj15->caracter     			   =   ' ';    
    referObj15->hexaEquivalence		 = 	"0Fh";
    EQUIVALENCE  *referObj16       =  (equivalenceCursor + 16);
    referObj16->caracter             =   ' ';    
    referObj16->hexaEquivalence    =  "10h";
    EQUIVALENCE  *referObj17       =  (equivalenceCursor + 17);
    referObj17->caracter             =   ' ';    
    referObj17->hexaEquivalence    =  "11h";
    EQUIVALENCE  *referObj18       =  (equivalenceCursor + 18);
    referObj18->caracter             =   ' ';    
    referObj18->hexaEquivalence    =  "12h";
    EQUIVALENCE  *referObj19       =  (equivalenceCursor + 19);
    referObj19->caracter             =   ' ';    
    referObj19->hexaEquivalence    =  "13h";
    EQUIVALENCE  *referObj20       =  (equivalenceCursor + 20);
    referObj20->caracter             =   ' ';    
    referObj20->hexaEquivalence    =  "14h";
    EQUIVALENCE  *referObj21      =  (equivalenceCursor + 21);
    referObj21->caracter             =   ' ';    
    referObj21->hexaEquivalence    =  "15h";
    EQUIVALENCE  *referObj22       =  (equivalenceCursor + 22);
    referObj22->caracter             =   ' ';    
    referObj22->hexaEquivalence    =  "16h";
    EQUIVALENCE  *referObj23       =  (equivalenceCursor + 23);
    referObj23->caracter             =   ' ';    
    referObj23->hexaEquivalence    =  "17h";
    EQUIVALENCE  *referObj24       =  (equivalenceCursor + 24);
    referObj24->caracter             =   ' ';    
    referObj24->hexaEquivalence    =  "18h";
    EQUIVALENCE  *referObj25      =  (equivalenceCursor + 25);
    referObj25->caracter             =   ' ';    
    referObj25->hexaEquivalence    =  "19h";
    EQUIVALENCE  *referObj26       =  (equivalenceCursor + 26);
    referObj26->caracter             =   ' ';    
    referObj26->hexaEquivalence    =  "1Ah";
    EQUIVALENCE  *referObj27       =  (equivalenceCursor + 27);
    referObj27->caracter             =   ' ';    
    referObj27->hexaEquivalence    =  "1Bh";
    EQUIVALENCE  *referObj28       =  (equivalenceCursor + 28);
    referObj28->caracter             =   ' ';    
    referObj28->hexaEquivalence    =  "1Ch";
    EQUIVALENCE  *referObj29       =  (equivalenceCursor + 29);
    referObj29->caracter             =   ' ';    
    referObj29->hexaEquivalence    =  "1Dh";
    EQUIVALENCE  *referObj30       =  (equivalenceCursor + 30);
    referObj30->caracter             =   ' ';    
    referObj30->hexaEquivalence    =  "1Eh";
    EQUIVALENCE  *referObj31       =  (equivalenceCursor + 31);
    referObj31->caracter             =   ' ';    
    referObj31->hexaEquivalence    =  "1Fh";
    EQUIVALENCE  *referObj32       =  (equivalenceCursor + 32);
    referObj32->caracter             =   ' ';    
    referObj32->hexaEquivalence    =  "20h";
    EQUIVALENCE  *referObj33       =  (equivalenceCursor + 33);
    referObj33->caracter             =   '!';    
    referObj33->hexaEquivalence    =  "21h";
    EQUIVALENCE  *referObj34       =  (equivalenceCursor + 34);
    referObj34->caracter             =   '"';    
    referObj34->hexaEquivalence    =  "22h";
    EQUIVALENCE  *referObj35       =  (equivalenceCursor + 35);
    referObj35->caracter             =   '#';    
    referObj35->hexaEquivalence    =  "23h";
    EQUIVALENCE  *referObj36       =  (equivalenceCursor + 36);
    referObj36->caracter             =   '$';    
    referObj36->hexaEquivalence    =  "24h";
    EQUIVALENCE  *referObj37       =  (equivalenceCursor + 37);
    referObj37->caracter             =   '%';    
    referObj37->hexaEquivalence    =  "25h";
    EQUIVALENCE  *referObj38       =  (equivalenceCursor + 38);
    referObj38->caracter             =   '&';    
    referObj38->hexaEquivalence    =  "26h";
    EQUIVALENCE  *referObj39       =  (equivalenceCursor + 39);
    referObj39->caracter             =   '\'';    
    referObj39->hexaEquivalence    =  "27h";
    EQUIVALENCE  *referObj40       =  (equivalenceCursor + 40);
    referObj40->caracter             =   '(';    
    referObj40->hexaEquivalence    =  "28h";
    EQUIVALENCE  *referObj41       =  (equivalenceCursor + 41);
    referObj41->caracter             =   ')';    
    referObj41->hexaEquivalence    =  "29h";
    EQUIVALENCE  *referObj42       =  (equivalenceCursor + 42);
    referObj42->caracter             =   '*';    
    referObj42->hexaEquivalence    =  "2Ah";
    EQUIVALENCE  *referObj43       =  (equivalenceCursor + 43);
    referObj43->caracter             =   '+';    
    referObj43->hexaEquivalence    =  "2Bh";
    EQUIVALENCE  *referObj44       =  (equivalenceCursor + 44);
    referObj44->caracter             =   ',';    
    referObj44->hexaEquivalence    =  "2Ch";
    EQUIVALENCE  *referObj45       =  (equivalenceCursor + 45);
    referObj45->caracter             =   '-';    
    referObj45->hexaEquivalence    =  "2Dh";
    EQUIVALENCE  *referObj46       =  (equivalenceCursor + 46);
    referObj46->caracter             =   '.';    
    referObj46->hexaEquivalence    =  "2Eh";
    EQUIVALENCE  *referObj47       =  (equivalenceCursor + 47);
    referObj47->caracter             =   '/';    
    referObj47->hexaEquivalence    =  "2Fh";
    EQUIVALENCE  *referObj48       =  (equivalenceCursor + 48);
    referObj48->caracter             =   '0';    
    referObj48->hexaEquivalence    =  "30h";
    EQUIVALENCE  *referObj49       =  (equivalenceCursor + 49);
    referObj49->caracter           =   '1';    
    referObj49->hexaEquivalence    =  "31h";
    EQUIVALENCE  *referObj50       =  (equivalenceCursor + 50);
    referObj50->caracter           =   '2';    
    referObj50->hexaEquivalence    =  "32h";

	  dataResourceRefer->lenEquivalence = 50;
    equivalenceCursor					=	NULL;
    free (equivalenceCursor);
}
