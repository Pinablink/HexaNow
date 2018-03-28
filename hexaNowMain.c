#include <stdio.h>
#include <stdlib.h>
#include "lib/hexaNow.h"

#define FINISH 0

int main (void) {
	HEXANOW *hexaNow = newObj();
	hexaNow->init();
	return FINISH;
}
