#include "mesinkar.h"
#include <stdio.h>

char CC;        /* bisa diakses dimana saja */
boolean EOP;    /* bisa diakses dimana saja */

static FILE * konfig_file;
static int retval;

void STARTFILE() {
	konfig_file = fopen("FILE_KONFIG.txt","r");
	ADVFILE();
}

void START() {
	ADV();
}

void ADVFILE() {
	retval = fscanf(konfig_file,"%c",&CC);
	EOP = (CC == MARK);
	if (EOP) {
		//char enter = fgetc(konfig_file);
    	fclose(konfig_file);
 	}
}

void ADV() {
	scanf("%c",&CC);
	EOP = (CC == MARK);
	if (EOP) {
		
 	}
}