#include <stdio.h>
#include <stdlib.h>

#include "arraydin.h"

// KONSTRUKTOR
void MakeEmpty(ArrayDinInventory *T, int maxel){
    T->Neff = 0;
    T->MaxEl = maxel;
    T->TabKomponen = (int *) malloc(maxel * sizeof(int));
    T->Kuantitas = (int *) malloc(maxel * sizeof(int));
}
void Dealokasi(ArrayDinInventory *T){
    T->Neff = 0;
    T->MaxEl = 0;
    free((T->TabKomponen));
}

// SELEKTOR
int NbElmt(ArrayDinInventory T){
    return T.Neff;
}
int MaxElement(ArrayDinInventory T){
    return T.MaxEl;
}
int GetFirstIdx(ArrayDinInventory T){
    return 0;
}
int GetLastIdx(ArrayDinInventory T){
    return T.Neff-1;
}
int SearchElmt(ArrayDinInventory T, Komponen K){
    int i = 0;
    boolean found = false;
    while(!found && i<= GetLastIdx(T)){
        if (T.TabKomponen[i] == K.KodeKomponen){
            found = true;
        }
        i++;
    }
    i = i-1;
    if (found){
        return i;
    }
    else{
        return (-999);
    }
}

// PREDIKAT
boolean IsIdxValid(ArrayDinInventory T, int i){
    return (i >= 0 && i < T.MaxEl);
}
boolean IsIdxEff(ArrayDinInventory T, int i){
    return (i >= 0 && i < T.Neff);
}
boolean IsEmpty(ArrayDinInventory T){
    return (T.Neff == 0);
}
boolean IsFull(ArrayDinInventory T){
    return (T.Neff == T.MaxEl);
}

// UBAH UKURAN ARRAY
void GrowTab(ArrayDinInventory *T, int num){
    ArrayDinInventory baru;
    MakeEmpty(&baru, ((T->MaxEl)+num));
    baru.Neff = T->Neff;
    for(int i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
        baru.TabKomponen[i] = (*T).TabKomponen[i];
    }
    Dealokasi(T);
    *T = baru;
}
void ShrinkTab(ArrayDinInventory *T, int num){
    ArrayDinInventory baru;
    int shrinked = (T->MaxEl)-num;
    MakeEmpty(&baru, shrinked);
    baru.Neff = (T->Neff < shrinked ? T->Neff : shrinked);
    for(int i = GetFirstIdx(baru); i <= GetLastIdx(baru); i++){
        baru.TabKomponen[i] = (*T).TabKomponen[i];
    }
    Dealokasi(T);
    *T = baru;
}


// TAMBAH KURANG ELEMEN
void addKomponen (ArrayDinInventory *T, int KodeKomponen, int kuantitas){
    boolean found = false;
    int o = 0;
    while(!found && o<= GetLastIdx(*T)){
        if (T->TabKomponen[o] == KodeKomponen){
            found = true;
        }
        o++;
    }
    o-=1;
    if (found){
        T->Kuantitas[o] = T->Kuantitas[o] + kuantitas;
    }
    else{
        o = GetLastIdx(*T) + 1;
        T->TabKomponen[o] = KodeKomponen;
        T->Kuantitas[o] = kuantitas;
        T->Neff+=1;        
    }
}    

void removeKomponen (ArrayDinInventory *T, int *KodeKomponen){
    boolean found = false;
    int i = 0;
    while(!found && i<= GetLastIdx(*T)){
        if (T->TabKomponen[i] == *KodeKomponen){
            found = true;
        }
        i++;
    }
    if (found){
        if(*T->Kuantitas >= 2){
            T->Kuantitas = T->Kuantitas - 1;
        }
        else {
            T->Kuantitas = NULL;
            Dealokasi(T); 
            while (i < GetLastIdx(*T)){
                (*T).TabKomponen[i] = (*T).TabKomponen[i-1];
            }
        }
    }  
}