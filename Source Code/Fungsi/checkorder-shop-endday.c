#include "checkorder-shop-endday.h"

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

//MakeEmpty(&Inventory,99); //awal bgt inventory bikin ksong dulu

void checkorder(){
    printf("Nomor Order: %d\n",InfoHead(Order).NoPesanan);
    printf("Pemesan: Pelanggan %d\n",InfoHead(Order).NoPelanggan);
    printf("Invoice: %d\n",InfoHead(Order).Invoice);
    for (int i = 1; i<=8 ; i++) {
        int ID=InfoHead(Order).TabKodeKomponen[i];
        printf("%d. %s \n",i,namaKomponen(ID));
    }
}

void shop(){
    int belikomp,kuantitas,total;
    boolean ada=false;
    printf("Komponen yang tersedia:\n");
    for (int i=0;i<24;i++){
        printf("%d. %s - ""$""%d\n",(i+1),IDKomponen[i],ListKomp[i]->Harga);
    }
    printf("Komponen yang ingin dibeli: ");
    scanf("%d",(&belikomp));
    printf("Masukkan jumlah yang ingin dibeli: ");
    scanf("%d",(&kuantitas));
    for (int i=0;i<24;i++){
        if (i==belikomp){
            total = ((ListKomp[i-1]->Harga)*(kuantitas));
            ada=true;
            if (total>Uang){
                printf("Uang tidak cukup!");
            } else{
                Uang=Uang-total;
                addKomponen(&Inventory,&(i-1),kuantitas);
                printf("Komponen berhasil dibeli!");
            }
        }
    }
    if(ada==false){
        printf("Tidak ada komponen, silahkan ulangi!");
    }
}

void end_day(){
    MakeEmpty(&Inventory,99);
    while (!IsQueueFull(Order));
        Enqueue(&Order,dataOrder);
    //masukin orderan baru sampe queue stack full lg
}