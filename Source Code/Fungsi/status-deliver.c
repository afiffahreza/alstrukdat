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
    // inventory dibikin for
    //printf("Inventory anda: %d", Inventory.TabKomponen);
}

void deliver(){
    if(CurrentLocation == Order.Pemesan[Head(Order)].NoPelanggan+1){
        Uang = Uang + Order.Pemesan->Invoice;
        infoPemesan tmpDel;
        Dequeue(&Order,&tmpDel);
    }
}