#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../lib/hexaNow.h"
#include "../lib/message.h"

#define  LIST_VIEW 			1
#define  INPUT     			2 
#define  EXIT      			3

static void implInit ();
static void finishResource ();
static void cleanMEM (void *refer);
static void clearScreen ();

static HEXANOW  hexaNow;
static int      *inputOption;
static int      *inputOptionIData;
static int      *inputOptionIIData;
static int      quantCaracter;
static FILE     *fileDataTransf;

HEXANOW* newObj (void) {
	quantCaracter		 		=	*(int*)malloc(sizeof(int));
	hexaNow 			 		= 	*(HEXANOW*)malloc(sizeof(HEXANOW));
	hexaNow.dataASC_ON			=	*(int*)malloc(sizeof(int));
	hexaNow.MENU 		 		=	__MENU__;
	hexaNow.MENU_INPUT	 		=	__MENUINPUT__;
	hexaNow.WORD_CONVERT 		=  (char*)calloc(1,sizeof(char));
	hexaNow.dataConvertExist	=   0;
	hexaNow.init    	 		=   &implInit;
	
	clearScreen();

	return &hexaNow; 
} 

static void inputDataHex (char *dataInput) {
	fileDataTransf = fopen ("DATA_TRANSF.dat", "w");

    if (fileDataTransf == NULL) {
    	//Deverá ser implementado a lógica para quando ocorrer o erro
    	printf("\nErro na execucao\n\n");
    } else {
    	//Incluir no arquivo de transferencia
    	if (fwrite(dataInput,1,31,fileDataTransf) != -1) {
    		printf("\nEscrita ok\n");
    	}  else {
    		printf ("\nProblema na escrita\n");
    	}

    	fclose (fileDataTransf);
    }

}

static void finishResource () {
	inputOption = NULL;
	free(inputOption);	
}

static void cleanMEM (void *refer) {
	refer = NULL;
	free(refer);
}

static void clearScreen () {
	system("cls");
}
// FUNÇÕES PARA ENTRADA DE CARACTERES
//Tela de apresentação para entrada de caracteres
static void inputConfigScreen4 () {
	unsigned int STATUS					=	1;
	int*		 internalOpt			=	(int*)malloc(sizeof(int));

	while (STATUS == 1) {
		clearScreen();
		printf ("%s\nEntre com uma opcao: ",__INPUT_OPT_CHARS__);
		scanf("%d",internalOpt);
		fflush(stdin);

		if (*internalOpt > 0 && *internalOpt < 4) {
			//PROCEDIMENTO
			if (*internalOpt == 1) {
				// ADICIONAR PROCEDIMENTO
			} else if (*internalOpt == 2) {
				// ADICIONAR PROCEDIMENTO
			} else if (*internalOpt == 3) {
				STATUS 		= 0;
				internalOpt = NULL;
				free (internalOpt);
				clearScreen();
			}

		} else {
			printf ("Opcao informada nao existente.\n");
			system("PAUSE");
		}

	}
}

static void inputConfigScreen3 () {
	char          charReader;
	char*         charCtrInput;
	unsigned int  STATUS 		 	    =  1;
	unsigned int  indexQuantCaracter 	=  0;
	cleanMEM (hexaNow.WORD_CONVERT);
	charCtrInput 						= hexaNow.WORD_CONVERT 	=  (char*)calloc(quantCaracter,sizeof(char));

	while (STATUS == 1) {
		clearScreen();
		indexQuantCaracter = quantCaracter;
		printf ("\n\nInforme os caracteres: ");
		
		while (indexQuantCaracter > 0) {
			charReader = getch();
			printf("%c",charReader);
			*(charCtrInput++) = charReader;
			indexQuantCaracter--;
		}

		hexaNow.dataConvertExist = 1;
		clearScreen();
		fflush(stdin);
		printf("\nCaracteres informados com sucesso!\n");
		printf("%s\n",hexaNow.WORD_CONVERT);
		charCtrInput = NULL;
		free(charCtrInput);
		STATUS = 0;
		system("PAUSE");
	}

}

static void inputConfigScreen2 () {
	int STATUS 			= 	1;
	inputOptionIIData	=	(int*)malloc(sizeof(int));
	clearScreen();
	while (STATUS == 1) {
		quantCaracter	=	0;
		clearScreen();
		printf ("\nInforme a quantidade de caracteres para o processamento. Informando 0 ou qualquer caracter nao numerico voce retorna para tela anterior.\n");
		printf ("Quantidade de Caracter: ");
		scanf("%d",&quantCaracter);
		fflush(stdin);

		if (quantCaracter == 0) {
			STATUS = 0;
			clearScreen();
		} else if (quantCaracter > 0 && quantCaracter < 33) {
			printf ("\n\nFoi reservado um espaco para %d caracter(es) na memoria.\n",quantCaracter);
			system("PAUSE");
			inputConfigScreen3 ();

			if (hexaNow.dataConvertExist == 1) {
				//CHAMA A TELA DE INCLUSAO DE NOME
				inputConfigScreen4 ();
			}

			STATUS = 0;
		} else {
			printf ("\n\nValor informado nao obedece os quesitos de parametrizacao\n");
			system("PAUSE");
		}

	}	
}

static void inputConfigScreen1 () {
	int STATUS = 1;
	inputOptionIData = (int*)malloc(sizeof(int));

	while (STATUS == 1) {
		clearScreen();
		printf ("%s%s",hexaNow.MENU_INPUT,"Entre com a opcao: ");
		scanf ("%d",inputOptionIData);
		fflush(stdin);

		if (*inputOptionIData > 0 && *inputOptionIData < 3) {

			if (*inputOptionIData == 1) { //Entrar com quantidade de Caracteres
				inputConfigScreen2 ();
				*inputOptionIData = 0;
			} else if (*inputOptionIData == 2) {
				STATUS = 0;
				clearScreen();
				inputOptionIData = NULL;
				free(inputOptionIData);				
			}

		} else {
			printf ("Opcao informada nao existente.\n");
			system("PAUSE");
		}
	}
}

static void setCaracterWord (unsigned int pos) {
	if (pos <= 9) {
		printf("     - Caracter : ");
	} else if (pos <= 99) {
		printf("    - Caracter : ");
	} else if (pos >= 100) {
		printf("   - Caracter : ");
	}
}

static void viewList() {
	char  		  valueChar;
	char*  		  strHexa;
	char          space         =   *(char*)malloc(sizeof(char));
	unsigned int  indexCursor 	=  	 0;
	DATA_RESOURCE dtResource 	=	hexaNow.dataResourceObject;
	EQUIVALENCE*  CURSOR 		=	dtResource.equivalenceList;	
	unsigned int  lenList	 	= 	dtResource.lenEquivalence;
	clearScreen();
	space						=	0x20;

	setColorWhiteText();
	printf ("--- ");
	setColorYellowText ();
	printf ("Numero decimal");
	setColorWhiteText();
	printf (" | ");
	setColorGreenText ();
	printf ("Caracter");
	setColorWhiteText();
	printf ("  | ");
	setColorRedText();
	printf ("Valor Hexadecimal");
	setColorWhiteText();
	printf (" |---");

	for (;indexCursor < (lenList + 1); indexCursor++) {
		valueChar 		 = (*(CURSOR + indexCursor)).caracter;
		strHexa 		 = (*(CURSOR + indexCursor)).hexaEquivalence;
		
		if (indexCursor <= 32) {
			setColorYellowText();
			printf("\n%c%d", space, indexCursor);
			setColorWhiteText();
			setCaracterWord(indexCursor);
			setColorGreenText();
			printf("Sem exibicao Grafica ");
			setColorWhiteText();
			printf("- Valor : ");
			setColorRedText();
			printf("%s", strHexa);
		} else {
			setColorYellowText();
			printf("\n%c%d", space, indexCursor);
			setColorWhiteText();
			setCaracterWord(indexCursor);
			setColorGreenText();
			printf("%c",valueChar);
			//printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",space, space, space, space, space, space, space, space, space ,space, valueChar, space, space, space, space, space, space, space, space);
			setColorWhiteText();
			printf("                    - Valor : ");
			setColorRedText();
			printf("%s", strHexa);
		}
		 	
	}

	printf ("\n");
	setColorWhiteText();
	CURSOR 				 = NULL;
	free(CURSOR);
	system ("PAUSE");
}

// FIM DA AREA DE ENTRADA DE CARACTERES
static void implInit () {
	int STATUS  = 1;
	inputOption = (int*)malloc(sizeof(int));
	
	runInitResource (&hexaNow);	

	while (STATUS == 1) {
		clearScreen();
		printf ("%s\n%s",hexaNow.MENU,"Entre com a opcao: ");
		scanf ("%d",inputOption);
		fflush(stdin);

		if (*inputOption > 0 && *inputOption < 4) {
			
			if (*inputOption == LIST_VIEW) {
				*inputOption = 0;	
				viewList();	
			} else if (*inputOption == INPUT) {
				*inputOption = 0;
				inputConfigScreen1();
			} else if (*inputOption == EXIT) {
				STATUS = 0;
				clearScreen();
				finishResource();
				printf ("HexaNow finalizado.\n");
			}

		} else {
			printf ("Opcao informada nao existente.\n");
			system("PAUSE");
		}

	}
	
	//Exemplo disponibilizar conteudo
	//char* inputValue = "NAME DB 20h,20h,27h,30h,54h,20h";
	//inputDataHex (inputValue);
	//system("clipboard_hexanow.bat");
	//printf("\nConteudo gerado na area de transferencia");

}
