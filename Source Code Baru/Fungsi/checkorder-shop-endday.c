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
char IDKomponen[24][35];
Komponen ListKomp[24][3];
infoPemesan dataOrder[7] = {
            {1,1,{1,4,7,10,13,16,19,22},1500},
            {2,2,{2,4,7,10,13,16,19,22},1400},
            {3,3,{0,4,7,10,13,16,19,22},1400},
            {4,4,{2,5,7,10,13,16,19,22},1500},
            {5,5,{1,4,8,10,13,16,19,22},1500},
            {6,6,{1,4,7,10,13,16,19,22},1300},
            {7,7,{0,4,7,10,13,16,19,22},1500}
        };

#endif

//MakeEmpty(&Inventory,99); //awal bgt inventory bikin ksong dulu

void checkorder(){
    printf("Nomor Order: %d\n",InfoHead(Order).NoPesanan);
    printf("Pemesan: Pelanggan %d\n",InfoHead(Order).NoPelanggan);
    printf("Invoice: %d\n",InfoHead(Order).Invoice);
    for (int i = 0; i<8 ; i++) {
        int ID=InfoHead(Order).TabKodeKomponen[i];
        printf("%d. %s \n",i+1,namaKomponen(ID));
    }
}

void shop(){
    if (CurrentLocation == 1){
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
            if (i==belikomp-1){
                total = ((ListKomp[i]->Harga)*(kuantitas));
                ada=true;
                if (total>Uang){
                    printf("Uang tidak cukup!\n");
                } else{
                    Uang=Uang-total;
                    //printf("debug");
                    addKomponen(&Inventory,i,kuantitas);
                    printf("Komponen berhasil dibeli!\n");
                }
            }
        }
        if(ada==false){
            printf("Tidak ada komponen, silahkan ulangi!\n");
        }
    }
    else {
        printf("Anda sedang tidak berada di shop.\n");
    }
}

void end_day(){
    if (statusPermainan==2){
        printf("Anda sedang mengerjakan build, selesaikan build terlebih dahulu.\n");
    }
    else if (statusPermainan==3){
        printf("Anda sedang membawa build yang telah selesai dibuat, deliver terlebih dahulu.\n");
    }
    else{
        CreateEmptyQueue(&Order,30);
        for (int l=0; l<7; l++){
            Enqueue(&Order, dataOrder[l]);
        }
        printf("Hari telah berganti, antrian order telah direset.\n");
    }
}