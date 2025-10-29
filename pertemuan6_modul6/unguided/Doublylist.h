#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan {
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address next;
    address prev;
};

// Tipe list
struct List {
    address first;
    address last;
};

// Prototypes
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

// Insert
void insertLast(List &L, address P);

// Searching
address findElm(List L, infotype x);

// Delete procedures
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

// Tampilkan isi list
void printInfo(List L);

#endif