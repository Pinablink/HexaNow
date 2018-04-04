#ifndef _HEXANOW
#define _HEXANOW

typedef void(*LIST_EQUIVALENCE)(void);
typedef void(*SHOW_MENU)(void);

typedef struct{
   char   caracter;
   char*  hexaEquivalence;
}EQUIVALENCE;

typedef struct{
	unsigned int lenEquivalence;
	EQUIVALENCE *equivalenceList; 
}DATA_RESOURCE;

typedef struct {
	unsigned int    dataASC_ON;
	char* 			MENU;
	char* 			MENU_INPUT;
	char* 			WORD_CONVERT;
	DATA_RESOURCE   dataResourceObject;
	unsigned int 	dataConvertExist;
	SHOW_MENU 		init;	
}HEXANOW;

#endif