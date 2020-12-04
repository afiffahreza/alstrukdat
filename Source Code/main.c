#include <stdio.h>
#include <stdlib.h>

// Library ADT
#include "Fungsi/ADT/arraydin.h"
#include "Fungsi/ADT/boolean.h"
#include "Fungsi/ADT/point.h"
#include "Fungsi/ADT/queue.h"
#include "Fungsi/ADT/stack.h"
#include "Fungsi/ADT/graph.h"
#include "Fungsi/ADT/matriks.h"
#include "Fungsi/ADT/mesinkar.h"
#include "Fungsi/ADT/mesinkata.h"

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

// FUNGSI
#include "Fungsi/load-save.h"
#include "Fungsi/move-map.h"
#include "Fungsi/build-component.h"
//#include "Fungsi/checkorder-shop-endday.h"
#include "Fungsi/status-deliver.h"

void load_konfig(){

    STARTKATAFILE();
    int panjangKata = CKata.Length;
    mapX = 0;
    for (int i=0; i < panjangKata; i++) {
        mapX = 10*mapX + (CKata.TabKata[i+1] - '0');
    }
    //printf("mapX = %d\n",mapX);

    ADVKATAFILE();
    panjangKata = CKata.Length;
    mapY = 0;
    for (int i=0; i < panjangKata; i++) {
        mapY = 10*mapY + (CKata.TabKata[i+1] - '0');
    }
    //printf("mapY = %d\n",mapY);

    ADVFILE();
    ADVKATAFILE();
    panjangKata = CKata.Length;
    NbBangungan = 0;
    for (int i=0; i < panjangKata; i++) {
        NbBangungan = 10*NbBangungan + (CKata.TabKata[i+1] - '0');
    }
    //printf("nbbang = %d\n",NbBangungan);

    for (int i=0; i<NbBangungan; i++){
        ADVFILE(); // skip enter
        ADVKATAFILE(); // skip huruf
        ADVKATAFILE();
        panjangKata = CKata.Length;
        int lokX = 0;
        for (int i=0; i < panjangKata; i++) {
            lokX = 10*lokX + (CKata.TabKata[i+1] - '0');
        }
        printf("x = %d ",lokX);
        ADVKATAFILE();
        panjangKata = CKata.Length;
        int lokY = 0;
        for (int i=0; i < panjangKata; i++) {
            lokY = 10*lokY + (CKata.TabKata[i+1] - '0');
        }
        //printf("y = %d\n",lokY);
        LokasiBangunan[i] = MakePOINT(lokX,lokY);
    }

    BuatMatriks(NbBangungan,NbBangungan,&Map);

    for (int i = 0; i < NbBangungan; i++){
        ADVFILE();
        for (int j = 0; j < NbBangungan; j++){
            ADVKATAFILE();
            int lok = (int) (CKata.TabKata[1]-'0');
            Elmt(Map, i, j) = lok;
        }
    }

    //PrintMatriks(Map);

    EOP = true;
    ADVFILE();
}

void enter_command(){

    printf("\n");
    printf("ENTER COMMAND: ");

    char listPilihanCommand[13][20] = {
        "MOVE", //0
        "STATUS",
        "CHECKORDER",
        "SHOP",
        "STARTBUILD",
        "ADDCOMPONENT", //5
        "REMOVECOMPONENT",
        "FINISHBUILD",
        "MAP",
        "DELIVER", //9
        "ENDDAY",
        "SAVE",
        "EXIT"
    };

    STARTKATA();
    char kataCommand[20];
    int panjangKata = CKata.Length;
    //printf("%d",panjangKata);

    for (int i = 0; i < panjangKata; i++){
        kataCommand[i] = CKata.TabKata[i+1];
    }

    if (isKataSama(kataCommand, listPilihanCommand[0], panjangKata)){
        move();
        enter_command();
    }
    else if (isKataSama(kataCommand, listPilihanCommand[1], panjangKata)){
        status();
        enter_command();
    }
    else if (isKataSama(kataCommand, listPilihanCommand[2], panjangKata)){
        //FUNGSI CHECKORDER
        enter_command();
    }
    else if (isKataSama(kataCommand, listPilihanCommand[3], panjangKata)){
        //FUNGSI SHOP
        enter_command();
    }
    else if (isKataSama(kataCommand, listPilihanCommand[4], panjangKata)){
        //FUNGSI STARTBUILD
        enter_command();
    }
    else if (isKataSama(kataCommand, listPilihanCommand[5], panjangKata)){
        //FUNGSI ADDCOMPONENT
        enter_command();
    }
    else if (isKataSama(kataCommand, listPilihanCommand[6], panjangKata)){
        //FUNGSI REMOVECOMPONENT
        enter_command();
    }
    else if (isKataSama(kataCommand, listPilihanCommand[7], panjangKata)){
        //FUNGSI FINISHBUILD
        enter_command();
    }
    else if (isKataSama(kataCommand, listPilihanCommand[8], panjangKata)){
        map();
        enter_command();
    }
    else if (isKataSama(kataCommand, listPilihanCommand[9], panjangKata)){
        deliver();
        enter_command();
    }
    else if (isKataSama(kataCommand, listPilihanCommand[10], panjangKata)){
        //FUNGSI ENDDAY
        enter_command();
    }
    else if (isKataSama(kataCommand, listPilihanCommand[11], panjangKata)){
        //FUNGSI SAVE
        enter_command();
    }
    else if (isKataSama(kataCommand, listPilihanCommand[12], panjangKata)){
        printf("GOOD BYE\n");
    }
    else {
        printf("Command tidak ditemukan, silahkan coba lagi!\n");
        enter_command();
    }

}

void main_menu(){

    printf("Selamat datang di Game Santo Tycoon\n");
    printf("Pilihan:\n");
    printf("1. NEW GAME\n");
    printf("2. LOAD GAME\n");
    printf("NOMOR PILIHAN: ");

    int pil; scanf("%d",&pil);

    if(pil==1){
        Uang = 1000;
        //printf("masuk pil 1\n");
        CreateEmptyGraph(&Jalur);
        adrNode nodeBangunan = AlokasiNode(0);
        Jalur.First = nodeBangunan;
        for (int i = 1; i < NbBangungan; i++){
            //printf("%d\n",i);
            nodeBangunan->Next = AlokasiNode(i);
            nodeBangunan = nodeBangunan->Next;
        }
        CurrentLocation = 0;
        //printf("sebelum mtg\n");
        MatrixToGraph(Map,&Jalur);
        //printf("selesai matriks to graph\n");
        // init
        enter_command();
    }

}

int main() {

    load_konfig();
    main_menu();

}
