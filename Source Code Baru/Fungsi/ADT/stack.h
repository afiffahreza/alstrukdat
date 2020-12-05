#ifndef __STACK_H__
#define __STACK_H__

#include "komponen.h"
#include "boolean.h"

typedef int address;

typedef struct
{
    int Build[8];
    address TOP;
} Stack;

#define Top(S) (S).TOP
#define InfoTop(S) (S).Build[(S).TOP-1]

/* Definisi stack S kosong : S.TOP = Nil */
/* S.TOP = jumlah element stack */
/* S.Build[S.TOP-1] = element paling atas */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsStackEmpty(Stack S);
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
boolean IsStackFull(Stack S);
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */
boolean IsStackSame(Stack S1, Stack S2);
/* Mengirim true jika stack S1 dan S2 sama */

/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, int X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
void Pop(Stack *S, int *X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif
