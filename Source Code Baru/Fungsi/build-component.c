#include "build-component.h"

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

void startbuild(){
	printf("Kamu telah memulai pesanan %d untuk pelanggan %d. \n", Head(Order), InfoHead(Order).NoPelanggan);
	CreateEmptyStack(&CurrentBuild);
	statusPermainan = 2;
}

void finishbuild(){
    int count = 0;
    if (statusPermainan != 2) {
        printf("Kamu belum memulai membuat build. Silahkan mulai pembuatan build terlebih dahulu! \n");
	}
	else {
        for (int i = 0; i < 8; i++) {
            int IDKomp = InfoHead(Order).TabKodeKomponen[i];
            if (strcmp(CurrentBuild.Build[i], namaKomponen(IDKomp)) == 0) {
                count += 1;
            }
        }
        if (count == 8) {
            printf("Pesanan %d telah selesai. Silahkan antar ke pelanggan %d! \n", Head(Order), InfoHead(Order).NoPelanggan);
        }
        else {
            printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan. \n");
        }
	}
}

void addcomponent(){
	int Nomor;
	if (statusPermainan != 2) {
        printf("Kamu belum memulai membuat build. Silahkan mulai pembuatan build terlebih dahulu! \n");
	}
	else {
        printf("Komponen yang telah terpasang: \n");
        if (IsStackEmpty(CurrentBuild)) {
            printf("Tidak ada komponen yang terpasang. \n");
        }
        else {
            Stack tmpStack; CreateEmptyStack(&tmpStack);
            while (!IsStackEmpty){
                //AAAAAAAAAAAAAAAAAA
            }
        }

        printf("Komponen yang tersedia: \n");
        if (IsEmpty(Inventory)) {
            printf("Inventory kamu kosong. \n");
        }

        else {
            for (int y = 0; y < (Inventory).Neff; y++) {
                printf("%d. %s \n", y+1, Inventory.TabKomponen[y+1]);
            }

            printf("Komponen yang ingin dipasang: ");
            scanf("%d", Nomor);
            if (IsIdxEff(Inventory, Nomor)) {
                Push(&CurrentBuild, *ListKomp[Nomor]);
                printf("Komponen berhasil dipasang!");

            }
            else {
                printf("Tidak ada komponen tersebut dalam inventory kamu.");
            }
        }
    }
}

void removecomponent(){
	if (statusPermainan != 2) {
        printf("Kamu belum memulai membuat build. Silahkan mulai pembuatan build terlebih dahulu! \n");
	}
	else {
        if (IsStackEmpty(CurrentBuild)) {
            printf("Tidak ada komponen yang terpasang. \n");
        }
        else {
            Pop(&CurrentBuild, &InfoTop(CurrentBuild));
            printf("Komponen %s berhasil dicopot!", InfoTop(CurrentBuild));
        }
	}
}
