#include "load-save.h"

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

void load(){

}

void save(){
    if (statusPermainan==2){
        printf("Anda sedang mengerjakan build, selesaikan build terlebih dahulu.\n");
    }
    else if (statusPermainan==3){
        printf("Anda sedang membawa build yang telah selesai dibuat, deliver terlebih dahulu.\n");
    }
    else {
        FILE *SAVE;
        printf("Lokasi save file: ");
        // input lokasi file
        // save = w apalah itu
        // uang
        // currentloc
        // inven
        // order kalo sempet
    }
}