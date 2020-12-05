#include "move-map.h"

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
int statusPermainan;
#endif

void move(){
    if (CurrentLocation == 0) {
        printf("Kamu berada pada base.\n");
    }
    else if (CurrentLocation == 1)
        printf("Kamu berada pada shop.\n");
    else {     
        printf("Kamu berada pada lokasi pelanggan %d.\n",CurrentLocation-1);
    }


    adrNode jalurGraph = Jalur.First;
    while (jalurGraph->NoLokasi != CurrentLocation){
        jalurGraph = jalurGraph->Next;
    }

    printf("Daftar lokasi yang dapat dicapai:\n");
    int pilihanTujuan[NbBangungan+1];

    int nomor = 1;
    adrSuccNode tujuanGraph = jalurGraph->Trail;
    
    //if (jalurGraph->Trail==NULL) printf("nul");

    while (tujuanGraph != NULL) {
        if (tujuanGraph->Succ->NoLokasi == 0){
            pilihanTujuan[nomor] = 0;
            printf("%d. Base\n",nomor);
        }
        else if (tujuanGraph->Succ->NoLokasi == 1){
            pilihanTujuan[nomor] = 1;
            printf("%d. Shop\n",nomor);
        }
        else {
            pilihanTujuan[nomor] = tujuanGraph->Succ->NoLokasi;
            printf("%d. Pelanggan %d\n",nomor, tujuanGraph->Succ->NoLokasi-1);
        }
        nomor++;
        tujuanGraph = tujuanGraph->Next;
    }

    int tujuan;
    printf("Nomor tujuan: ");
    scanf("%d", &tujuan);
    
    CurrentLocation = pilihanTujuan[tujuan];
    if (CurrentLocation == 0) {
        printf("Kamu telah mencapai base.\n");
    }
    else if (CurrentLocation == 1)
        printf("Kamu telah mencapai shop.\n");
    else {     
        printf("Kamu telah mencapai lokasi pelanggan %d.\n",CurrentLocation-1);
    }
}

void map(){
    for (int i = 0; i < mapX+2; i++){
        for (int j = 0; j < mapY+2; j++) {
            if (i==0 || i==mapX+1) {
                printf("*");
            }
            else if (j==0 || j==mapY+1){
                printf("*");
            }
            else {
                Point tmp = MakePOINT (i,j); 
                int k = 0;
                boolean tempbool = false;
                while (k < NbBangungan && !tempbool){
                    if (Absis(tmp)==Absis(LokasiBangunan[k]) && Ordinat(tmp)==Ordinat(LokasiBangunan[k])) {
                        tempbool = true;
                    }
                    k++;
                }
                k-=1;
                if (tempbool) {
                    if (k==CurrentLocation) printf("P");
                    else if (k==0) printf("B");
                    else if (k==1) printf("S");
                    else printf("%d",k-1);
                }
                else printf(" ");
            }
        }
        printf("\n");
    }
}