#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

void CreateEmptyGraph(Graph *G){
    (*G).First = NULL;
}

adrNode AlokasiNode (int NP){
    adrNode P = (adrNode) malloc (sizeof(GraphNode));
    if (P!=NULL){
        P->NoLokasi = NP;
        P->Trail = NULL;
        P->Next = NULL;
    }
    else return NULL;
}
void DealokasiNode (adrNode P){
    free(P);
}

adrSuccNode AlokasiSuccNode (adrNode Pn){
    adrSuccNode P = (adrSuccNode) malloc (sizeof(GraphSuccNode));
    if (P!=NULL){
        P->Succ = Pn;
        P->Next = NULL;
    }
    else return NULL;
}
void DealokasiSuccNode (adrSuccNode Pn){
    free(Pn);
}

void insertNode(Graph *G, int X, adrNode *Pn){
    (*Pn) = AlokasiNode(X);
    if (*Pn!=NULL){
        adrNode P = G->First, Prev = NULL;
        while (P!=NULL){
            Prev = P;
            P = P->Next;
        }
        if (Prev==NULL){
            G->First = (*Pn);
        }
        else {
            Prev->Next = (*Pn);
        }
    }
}
void insertEdge(Graph *G, int prec, int succ){

    adrNode P = G->First, precNode = NULL, succNode = NULL;
    boolean found1 = false, found2 = false;
    while (!(found1&&found2) && P!=NULL){
        if (P->NoLokasi == prec){
            precNode = P;
            found1 = true;
        }
        else if (P->NoLokasi == succ){
            succNode = P;
            found1 = true;
        }
        P = P->Next;
    }
    

    adrSuccNode Prec = precNode->Trail, trailNode = AlokasiSuccNode(succNode);
    if (Prec==NULL){
        precNode->Trail = trailNode;
    }
    else {
        while (Prec->Next!=NULL){
            Prec = Prec->Next;
        }
        Prec->Next = trailNode;        
    }

    /*
    adrNode P, firstNode = NULL, secondNode = NULL;
    adrSuccNode firstSuccNode, secondSuccNode;

    P = G->First;
    while (P!=NULL){
        if (P->NoLokasi == prec){
            firstNode = P;
        }
        if (P->NoLokasi == succ){
            secondNode = P;
        }
        P = P->Next;
    }

    boolean firstFound = false, secondFound = false;
    firstSuccNode = firstNode->Trail;
    while (firstSuccNode!=NULL && firstFound == false){
        if (firstSuccNode->Succ->NoLokasi == succ) firstFound = true;
        firstSuccNode = firstSuccNode->Next;
    }
    
    secondSuccNode = secondNode->Trail;
    while (secondSuccNode!=NULL && secondFound == false){
        if (secondSuccNode->Succ->NoLokasi == prec) secondFound = true;
        secondSuccNode = secondSuccNode->Next;
    }

    adrSuccNode first = AlokasiSuccNode(firstNode), second = AlokasiSuccNode(secondNode);
    if (firstFound == false && secondFound == false && first != NULL && second != NULL){
        firstSuccNode = second;
        firstSuccNode->Next = NULL;
        secondSuccNode = first;
        secondSuccNode->Next = NULL;
    }
    */
}

void MatrixToGraph (Matriks M, Graph *G){
    for (int i = 0; i < M.Baris; i++){
        for (int j = 0; j < M.Kolom; j++){
            if (Elmt(M, i, j) == 1) {
                //printf("wih masuk\n");
                insertEdge(G,i,j);
            }
        }
    }
}