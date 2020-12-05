#include "boolean.h"
#include <stdio.h>
#ifndef matriks_h
#define matriks_h

#define BarisMin 1
#define BarisMax 50
#define KolomMin 1
#define KolomMax 50

#define Baris(M) (M).Baris
#define Kolom(M) (M).Kolom
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

typedef int indeks;
typedef int eltype;
typedef struct {
    eltype Mem[BarisMax+1][KolomMax+1];
    int Baris;
    int Kolom;
} Matriks;

void BuatMatriks(int Baris, int Kolom, Matriks *M);

indeks BarisPertama (Matriks M);

indeks KolomPertama (Matriks M);

indeks BarisTerakhir(Matriks M);

indeks KolomTerakhir(Matriks M);

void IsiMatriks(Matriks *M);

void PrintMatriks(Matriks M);

#endif
