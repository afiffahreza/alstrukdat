#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

/* Definisi Queue kosong Head = Nil; TAIL = Nil. */
/* Catatan implementasi T[0] tidak pernah dipakai */
/* Definisi akses dengan Selektor  Isilah dengan selektor yang tepat */

/* *** Predikat Pemeriksaan Kondisi Queue *** */

boolean IsQueueEmpty (Queue Q) {
/* Mengirim true jika Q kosong: ... */
	return ((Head(Q)==Nil) && (Tail(Q)==Nil));
}

boolean IsQueueFull (Queue Q) {
/* Mengirim true jika tabel ... */
	return ((Head(Q)==0) && (Tail(Q)==MaxEl(Q)-1));
}

int NBElmt(Queue Q) {
/* Mengirimkan banyaknya elemen queue. ... */
	return (Tail(Q)-Head(Q)+1);
}

/* *** Konstruktor *** */

void CreateEmptyQueue(Queue *Q, int Max) {
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, Membuat sebuah Q kosong */
	/* Kamus Lokal */
	/* Algoritma */
	(*Q).Pemesan = (infoPemesan *) malloc (Max * sizeof(infoPemesan));
	if ((*Q).Pemesan != NULL) {
		MaxEl(*Q) = Max;
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	}
	else /* alokasi gagal */ {
		MaxEl(*Q) = 0;
	}
}

void DealokasiQ(Queue *Q) {
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
	/* Kamus Lokal */
	/* Algoritma */
	MaxEl(*Q) = 0;
	free((*Q).Pemesan);
}

void Enqueue(Queue *Q, infoPemesan X) {
/* Proses: ... I.S.: ... F.S.: ... */
	/* Kamus Lokal */
	address i, j;
	/* Algoritma */
	if (IsQueueEmpty(*Q)) {
		Head(*Q) = 1;
		Tail(*Q) = 1;
	}
	else if (Tail(*Q)==MaxEl(*Q)-1) { /* Geser elemen smp Head(Q)=0 */
		i = Head(*Q); j = 0;
		do {
			*((*Q).Pemesan+j) = *((*Q).Pemesan+i);
			i++; j++;
		} while (i<=Tail(*Q));
		Tail(*Q) = NBElmt(*Q)-1; Head(*Q) = 0;
	}
	else {
		Tail(*Q)++;
	}
	InfoTail(*Q)=X;
}

void Dequeue(Queue * Q, infoPemesan* X) {
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S.,HEAD bergeser ke kanan;
Q mungkin kosong */
	/* Kamus Lokal */
	/* Algoritma */
	*X = InfoHead(*Q);
	if (Head(*Q)==Tail(*Q)) { /* Set mjd queue kosong */
		Head(*Q)=Nil;
		Tail(*Q)=Nil;
	}
	else {
		Head(*Q)++;
	}
}
