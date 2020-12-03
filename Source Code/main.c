#include <stdio.h>
#include <stdlib.h>

// Library ADT
#include "ADT/arraydin.h"
#include "ADT/boolean.h"
#include "ADT/point.h"
#include "ADT/queue.h"
#include "ADT/stack.h"
/*
#include "ADT/graph.h"
#include "ADT/matriks.h"
*/

// Variable Global
int Uang;
ArrayDinInventory Inventory;
Point CurrentLocation;
Point BaseLocation;
Point ShopLocation;
Queue Order;
Stack CurrentBuild;


int main(){

    // LOAD FILE KONFIGURASI
    // mesin kata, disimpen ke konfig

    // LOAD FILE KOMPONEN
    
    // MINTA COMMAND

       
       
}

void load(){
    
}

void move(){

}

void status(){
    printf("Uang tersisa: $%d\n", Uang);
    printf("Build yang sedang dikerjakan: pesanan %d untuk pelanggan %d.\n", Head(Order), Order.Pemesan->NoPelanggan );
    printf("Lokasi: pemain sedang berada pada %d\n", CurrentLocation);
    printf("Inventory anda: %d", Inventory.TabKomponen);
}

void checkorder(){

}

void startbuild(){
	
}

void finishbuild(){
	
}

void addcomponent(){
    
}

void removecomponent(){
   
}


void shop(){

}

void deliver(){
    Point P = Order.Pemesan[Head(Order)].Lokasi;
    if(CurrentLocation == P){
        Head(Order) = Head(Order)+1;
        Uang = Uang + Order.Pemesan->Invoice;
    }
}

void end_day(){
    
}

void save(){
    
}

void map(){

}

void exit (){
    
}
