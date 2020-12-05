#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

/* Definisi stack S kosong : S.TOP = Nil */
/* S.TOP = jumlah element stack */
/* S.T[S.TOP-1] = element paling atas */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S){
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
    S->TOP = -999;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsStackEmpty(Stack S){
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
    return (S.TOP == -999);
}
boolean IsStackFull(Stack S){
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */
    return (S.TOP == 8);
}

/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, int X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
    if (IsStackEmpty((*S))) {
        S->TOP = 1;
        S->Build[S->TOP-1] = X;
    }
    else {
        S->TOP ++;
        S->Build[S->TOP-1] = X;
    }
}
void Pop(Stack *S, int *X){
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    if (S->TOP == 1){
        (*X) = S->Build[S->TOP-1];
        S->TOP = -999;
    }
    else {
        (*X) = S->Build[S->TOP-1];
        S->TOP -= 1;
    }
}
