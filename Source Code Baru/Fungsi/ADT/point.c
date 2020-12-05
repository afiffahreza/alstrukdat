#include <stdio.h>

#include "boolean.h"
#include "point.h"

#define Absis(P) (P).X
#define Ordinat(P) (P).Y
        
Point MakePOINT (float X, float Y){
    Point P;
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}
                                              
void BacaPOINT (Point * P){
    float X,Y;
    scanf("%f %f",&X,&Y);
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void TulisPOINT (Point P){
    printf("(%f,%f)",Absis(P),Ordinat(P));
}       