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

void startbuild(){
	printf("Kamu telah memulai pesanan %d untuk pelanggan %d. \n", Head(Order), InfoHead(Order).NoPelanggan);
	CreateEmptyStack(&CurrentBuild);
	MulaiBuild = true;
}

void finishbuild(){
    int panjangKata = CKata.Length;
    int count = 0;
    if (!MulaiBuild) {
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
	if (!MulaiBuild) {
        printf("Kamu belum memulai membuat build. Silahkan mulai pembuatan build terlebih dahulu! \n");
	}
	else {
        printf("Komponen yang telah terpasang: \n");
        if (IsStackEmpty(CurrentBuild)) {
            printf("Tidak ada komponen yang terpasang. \n");
        }
        else {
            for (int x = 0; x < Top(CurrentBuild) ; x++) {
                printf("%d. %s \n", x+1, InfoTop(CurrentBuild));
                if (IsStackFull(CurrentBuild)) {
                    printf("Build ini sudah penuh. Silahkan menyelesaikan build atau melepas komponen jika ada yang salah! \n");
                    break;
                }
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
                Push(&CurrentBuild, Inventory.TabKomponen[(Nomor)]);
                printf("Komponen berhasil dipasang!");

            }
            else {
                printf("Tidak ada komponen tersebut dalam inventory kamu.");
            }
        }
    }
}

void removecomponent(){
	if (!MulaiBuild) {
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
