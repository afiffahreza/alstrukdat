#include "status-deliver.h"

// Library ADT
#include "ADT/arraydin.h"
#include "ADT/boolean.h"
#include "ADT/point.h"
#include "ADT/queue.h"
#include "ADT/stack.h"
#include "ADT/graph.h"
#include "ADT/matriks.h"
#include "ADT/mesinkar.h"
#include "ADT/mesinkata.h"
#include "ADT/komponen.h"

// Variable Global
#ifndef GLOBALVAR
#define GLOBALVAR
int Uang;
ArrayDinInventory Inventory;
int CurrentLocation;
int NbBangungan;
int mapX, mapY;
Point LokasiBangunan[30];
Matriks Map;
Graph Jalur;
Queue Order;
Stack CurrentBuild;
int statusPermainan;
#endif

void status(){
    printf("Uang tersisa: $%d\n", Uang);

    printf("Build yang sedang dikerjakan: pesanan %d untuk pelanggan %d.\n", Order.Pemesan[Head(Order)].NoPesanan, Order.Pemesan[Head(Order)].NoPelanggan);
    
    if (CurrentLocation == 0) {
        printf("Lokasi: pemain sedang berada pada base.\n");
    }
    else if (CurrentLocation == 1)
        printf("Lokasi: pemain sedang berada pada shop.\n");
    else {     
        printf("Lokasi: pemain sedang berada pada lokasi pelanggan %d.\n",CurrentLocation-1);
    }
    
    if (Inventory.Neff == 0){
        printf("Inventory anda kosong.\n", Inventory.TabKomponen);
    }
    else {
        printf("Inventory anda:\n");
        for(int m = 0; m < Inventory.Neff; m++){
            char* nama_komponen = namaKomponen(Inventory.TabKomponen[m]);
            printf("%d. %s (%d)\n", m+1, nama_komponen, Inventory.Kuantitas[m]);
        }
    }
    //printf("Inventory anda: %d", Inventory.TabKomponen);
}

void deliver(){
    if (statusPermainan==3) {
        if(CurrentLocation == Order.Pemesan[Head(Order)].NoPelanggan+1){
            printf("Pesanan #%d berhasil diantarkan kepada pelanggan %d!\n",Order.Pemesan[Head(Order)].NoPesanan,Order.Pemesan[Head(Order)].NoPelanggan);
            Uang = Uang + Order.Pemesan->Invoice;
            infoPemesan tmpDel;
            Dequeue(&Order,&tmpDel);
            statusPermainan = 1;
        }
        else {
            printf("Lokasi tempat pengantaran salah.");
        }
    }
    else {
        printf("Anda sedang tidak memiliki build yang sudah selesai dibuat.\n");
    }
}