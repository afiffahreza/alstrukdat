#include "mesinkata.h"

boolean EndKata;    /* bisa diakses dimana saja */
Kata CKata;         /* bisa diakses dimana saja */

void IgnoreBlankFILE()
{
   while ((CC == BLANK) && (CC != MARK))
   {
       ADVFILE();
   }
}

void IgnoreBlank()
{
   while ((CC == BLANK || CC == ENTER) && (CC != MARK))
   {
       ADV();
   }
}

void STARTKATAFILE()
{
    EndKata = false;
    STARTFILE();
    IgnoreBlankFILE();
    ADVKATAFILE();
}

void STARTKATA()
{
    EndKata = false;
    START();
    IgnoreBlank();
    ADVKATA();
}

void ADVKATAFILE()
{
    IgnoreBlankFILE();
    if (CC == MARK){
        EndKata = true;
    }
    else{
        SalinKataFILE();
    }
}

void ADVKATA()
{
    IgnoreBlank();
    if (CC == MARK){
        EndKata = true;
    }
    else{
        SalinKata();
    }
}

void SalinKataFILE()
{
    int i = 1;
    do {

        CKata.TabKata[i] = CC;

        ADVFILE();
        i++;

    }while ( (CC != ENTER) && (CC != MARK) && (CC != BLANK) && (i < NMax));

    CKata.Length = i-1;
}

void SalinKata()
{
    int i = 1;
    do {

        CKata.TabKata[i] = CC;

        ADV();
        i++;

    }while ( (CC != ENTER) && (CC != MARK) && (CC != BLANK) && (i < NMax));

    CKata.Length = i-1;
}

boolean isKataSama(char *kata1, char *kata2, int len){
    boolean kataSama = true;
    int ik = 0;
    while(ik < len && kataSama){
        if (kata1[ik]!=kata2[ik]){
            kataSama = false;
        }
        ik++;
    }
    return kataSama;
}
