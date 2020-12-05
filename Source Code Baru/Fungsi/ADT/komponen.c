#include <stdio.h>
#include <stdlib.h>
#include "komponen.h"

// array of string untuk menyimpan nama komponen
// indeks pada array menunjukkan ID komponen
char IDKomponen[24][35] = {
    // MOTHERBOARD IDX 1-3
    "Asrock B450M PRO",
    "Asus ROG STRIX B450F",
    "MSI B550A PRO",
    // CPU IDX 4-6
    "AMD Ryzen 9 3900X",
    "Intel Core i7-9800X",
    "AMD Ryzen Threadripper 1950X",
    // MEMORY IDX 7-9
    "LED Corsair Vengeance",
    "G Skill Trident Z RGB",
    "Adata Spectrix D80",
    // CPU COOLER IDX 10-12
    "Noctua NH-D15 ",
    "Corsair H115i RGB Platinum",
    "Cooler Master Hyper 212 EVO",
    // CASE IDX 13-15
    "Armageddon Nimitz TR5000",
    "Cube Gaming Cabazon",
    "Cougar Turret RGB",
    // GPU IDX 16-18
    "Asus RoG Strix GeForce RTX 2070",
    "MSI Gaming GeForce GTX 1070 Ti",
    "Gigabyte Radeon RX 550 D5",
    // STORAGE IDX 19-21
    "Samsung 970 Evo Plus",
    "Crucial P1",
    "WD Black 3D",
    // PSU IDX 22-24
    "EVGA SuperNOVA 1600 T2",
    "Corsair AX1600i",
    "Seasonic Prime Platinum 1200PD",
};
//[24][3]=S
Komponen ListKomp[24][3]={
    // {KODE, HARGA, KATEGORI}
    {1,250,1},
    {2,100,1},
    {3,150,1},
    {4,200,2},
    {5,125,2},
    {6,100,2},
    {7,175,3},
    {8,100,3},
    {9,150,3},
    {10,75,4},
    {11,50,4},
    {12,100,4},
    {13,125,5},
    {14,175,5},
    {15,100,5},
    {16,125,6},
    {17,175,6},
    {18,150,6},
    {19,25,7},
    {20,50,7},
    {21,75,7},
    {22,125,8},
    {23,100,8},
    {24,150,8}
};

char* namaKomponen(int ID){
    char* nama = IDKomponen[ID];
    return nama;
}