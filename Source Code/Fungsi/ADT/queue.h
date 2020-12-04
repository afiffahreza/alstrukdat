#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "boolean.h"
#include "komponen.h"
#include "point.h"

#define Nil 0

// SELEKTOR
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).Pemesan[(Q).HEAD]
#define InfoTail(Q) (Q).Pemesan[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl

// DEFINISI ELEMEN DAN ADDRESS
typedef struct {
	int NoPelanggan;
	Point Lokasi;
	Komponen TabKomponen[8]; /* tabel penyimpan komponen */
	int Invoice; /*pembayaran setelah orderan selesai diantar*/
} infoPemesan;
typedef int address; /* indeks tabel */

// DEFINISI QUEUE
typedef struct {
	infoPemesan *Pemesan; /* tabel penyimpan elemen */
	address HEAD; /*alamat penghapusan*/
	address TAIL; /*alamat penambahan*/
	int MaxEl;
} Queue;


//PREDIKAT
boolean IsQueueEmpty (Queue Q);
boolean IsQueueFull (Queue Q);
int NBElmt (Queue Q);

// KONSTRUKTOR
void CreateEmptyQueue (Queue *Q,int Max);
void Dealokasi (Queue *Q);

// TAMBAH KURANG ELEMEN
void Enqueue (Queue *Q ,infoPemesan X);
void Dequeue (Queue *Q,infoPemesan *X);
void dummy(infoPemesan *info,int x,Point v,const Komponen Tab[],int I);

#endif
