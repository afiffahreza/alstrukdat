#include "matriks.h"
#include <stdio.h>

void BuatMatriks(int Baris, int Kolom, Matriks *M){
    indeks i,j;
    (*M).Baris = Baris;
    (*M).Kolom = Kolom;
    for (i = 0; i < Baris; i++){
        for (j = 0; j < Kolom; j++){
        (*M).Mem[i][j] = 0;
      }
   }
}

indeks BarisPertama (Matriks M) {
	return BarisMin;
}

indeks KolomPertama (Matriks M) {
	return KolomMin;
}

indeks BarisTerakhir(Matriks M){
   return M.Baris - 1;
}

indeks KolomTerakhir(Matriks M){
   return M.Kolom - 1;
}

void IsiMatriks(Matriks *M){
    indeks i, j;
    for (i = 0; i < (*M).Baris; i++){
        for (j = 0; j < (*M).Kolom; j++){
            int x;
            scanf("%d", &x);

            Elmt(*M, i, j) = x;
        }
    }
}

void PrintMatriks(Matriks M){
    indeks i, j;
    for (i = 0; i <= BarisTerakhir(M); i++) {
        for (j = 0; j <= KolomTerakhir(M); j++) {
        printf(((j != KolomTerakhir(M)) ? "%d " : ((i != BarisTerakhir(M)) ? "%d\n" : "%d")), M.Mem[i][j]);
      }
   }
}
