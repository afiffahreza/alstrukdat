#ifndef POINT_H
#define POINT_H

#include "boolean.h"

typedef struct { 
	float X; // absis
	float Y; // ordinat
} Point;

#define Absis(P) (P).X
#define Ordinat(P) (P).Y
        

// KONSTRUKTOR
Point MakePOINT (float X, float Y);
/* Membentuk sebuah POINT dari komponen-komponennya */

// INPUT/OUTPUT                                            
void BacaPOINT (Point * P); 
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (Point P);
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                


#endif