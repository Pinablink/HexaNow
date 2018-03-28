#ifndef _HEXANOW
#define _HEXANOW

typedef void(*LIST_EQUIVALENCE)(void);
typedef void(*SHOW_MENU)(void);

typedef struct{
   char   caracter;
   char*  hexaEquivalence;
}EQUIVALENCE;

typedef struct{
	EQUIVALENCE *equivalenceList; 
}DATA_RESOURCE;

typedef struct {
	char* 			MENU;
	char* 			MENU_INPUT;
	char* 			WORD_CONVERT;
	DATA_RESOURCE   dataResourceObject;
	unsigned int 	dataConvertExist;
	SHOW_MENU 		init;	
}HEXANOW;

#endif