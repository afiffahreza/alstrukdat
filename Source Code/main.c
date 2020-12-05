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
int statusPermainan;
boolean MulaiBuild = false;
#endif

// FUNGSI
#include "Fungsi/load-save.c"
#include "Fungsi/move-map.c"
#include "Fungsi/build-component.c"
//#include "Fungsi/checkorder-shop-endday.c"
#include "Fungsi/status-deliver.c"

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
        startbuild();
        enter_command();
    }
    else if (isKataSama(kataCommand, listPilihanCommand[5], panjangKata)){
        //FUNGSI ADDCOMPONENT
        addcomponent();
        enter_command();
    }
    else if (isKataSama(kataCommand, listPilihanCommand[6], panjangKata)){
        //FUNGSI REMOVECOMPONENT
        removecomponent();
        enter_command();
    }
    else if (isKataSama(kataCommand, listPilihanCommand[7], panjangKata)){
        //FUNGSI FINISHBUILD
        finishbuild();
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
        printf("Terimakasih telah bermain, sampai jumpa kembali!\n");
    }
    else {
        printf("Command tidak ditemukan, silahkan coba lagi!\n");
        enter_command();
    }

}

void main_menu(){

    printf("    .   .   .                .___.    __.      ,     .___.               \n");
    printf("    |   | _ | _. _ ._ _  _     | _   (__  _.._-+-_     |  . _. _  _ ._   \n");
    printf("    |_|_|(/,|(_.(_)[ | )(/,    |(_)  .__)(_][ )|(_)    ||_|(_.(_)(_)[ )  \n");
    printf("                                                        ._|              \n");
    printf("    .__  . .             \n");
    printf("    [__)*|*|_  _.._   *  \n");
    printf("    |   |||[ )(_][ )  *  \n");
    printf("                         \n");
    printf("     ,    .  .           .__              \n");
    printf("    /|    |* | _.     ,  [ __ _.._ _  _   \n");
    printf("    .|.*  | *|(/,|_|_|   [_./(_][ | )(/,  \n");
    printf("                                          \n");
    printf("     _,   .           .  .__             \n");
    printf("    '_)   |    _  _. _|  [ __ _.._ _  _  \n");
    printf("    /_.*  |___(_)(_](_]  [_./(_][ | )(/, \n");
    printf("                                         \n \n");
    printf("NOMOR PILIHAN: ");

    int pil; scanf("%d",&pil);

    if (pil==1){

        Uang = 1000;

        // INIT INVENTORY

        CreateEmptyGraph(&Jalur);
        adrNode nodeBangunan = AlokasiNode(0);
        Jalur.First = nodeBangunan;
        for (int i = 1; i < NbBangungan; i++){
            nodeBangunan->Next = AlokasiNode(i);
            nodeBangunan = nodeBangunan->Next;
        }
        CurrentLocation = 0;
        MatrixToGraph(Map,&Jalur);

        infoPemesan dataOrder[7] = {
            {1,1,{1,4,7,10,13,16,19,22},1500},
            {2,2,{2,4,7,10,13,16,19,22},1400},
            {3,3,{0,4,7,10,13,16,19,22},1400},
            {4,4,{2,5,7,10,13,16,19,22},1500},
            {5,5,{1,4,8,10,13,16,19,22},1500},
            {6,6,{1,4,7,10,13,16,19,22},1300},
            {7,7,{0,4,7,10,13,16,19,22},1500}
        };

        CreateEmptyQueue(&Order,30);
        for (int l=0; l<7; l++){
            Enqueue(&Order, dataOrder[l]);
        }

        printf("     __.   .            ,   .__                    \n");
        printf("    (__  _ | _.._ _  _.-+-  [__) _ ._.._ _  _.*._  \n");
        printf("    .__)(/,|(_][ | )(_] |   [__)(/,[  [ | )(_]|[ ) \n");
        printf("                                                   \n");

        enter_command();
    }
    else if (pil==2){
        //load
    }
    else {
        printf("Data belum ada, mengulang game. \n \n");
        main_menu();
    }

}

int main() {

    load_konfig();
    main_menu();

}
