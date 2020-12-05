#ifndef __KOMPONEN_H__
#define __KOMPONEN_H__

typedef struct {
    int KodeKomponen;
    int Harga;
    int Kategori;
} Komponen;

typedef struct {
    Komponen *A;
    int Neff;
    int Capacity;
} ListKomponen;

char* namaKomponen(int ID);

/*
#define Neff(T) (T).Neff
#define Capacity(T) (T).Capacity
#define KodeKomponen(T) (T).KodeKomponen
#define KodeKomponen(T, i) (T).KodeKomponen[(i)]
#define Harga(T) (T).Harga
#define Harga(T, i) (T).Harga[(i)]
#define Kategori(T) (T).Kategori
#define Kategori(T, i) (T).Kategori[(i)]
*/
//#define ListKomp(T,i) (T).A[i]

/* 
KATEGORI
Motherboard = 1
CPU = 2
Memory = 3
CPU Cooler = 4
Case = 5
GPU = 6
Storage = 7
PSU = 8
*/


#endif