#include <iostream>
using namespace std;

// DEKLARASI STRUKTUR
struct Elemen {
    float info;
    Elemen* next;
};

struct List {
    Elemen* First;
    Elemen* Last;
};

// 1b. Prosedur membuat list kosong
void createList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

// 1c. Prosedur membuat elemen baru
void createElm(float X, Elemen* &elm) {
    elm = new Elemen;
    elm->info = X;
    elm->next = NULL;
}

// 1d. Prosedur insert ascending
void insertAscending(List &L, float X) {
    Elemen* elm;
    createElm(X, elm);
    
    // List kosong
    if (L.First == NULL) {
        L.First = elm;
        L.Last = elm;
        cout << "Data " << X << " berhasil ditambahkan (list kosong)" << endl;
    }
    // Insert di awal
    else if (X < L.First->info) {
        elm->next = L.First;
        L.First = elm;
        cout << "Data " << X << " berhasil ditambahkan di awal" << endl;
    }
    // Insert di akhir
    else if (X >= L.Last->info) {
        L.Last->next = elm;
        L.Last = elm;
        cout << "Data " << X << " berhasil ditambahkan di akhir" << endl;
    }
    // Insert di tengah
    else {
        Elemen* prec = L.First;
        while (prec->next->info < X) {
            prec = prec->next;
        }
        elm->next = prec->next;
        prec->next = elm;
        cout << "Data " << X << " berhasil ditambahkan di tengah" << endl;
    }
}

// Fungsi utilitas untuk menampilkan list
void printList(List L) {
    if (L.First == NULL) {
        cout << "List kosong" << endl;
        return;
    }
    
    cout << "Isi list: ";
    Elemen* P = L.First;
    while (P != NULL) {
        cout << P->info;
        if (P->next != NULL) cout << " -> ";
        P = P->next;
    }
    cout << endl;
}

// PROGRAM UTAMA SOAL 1
int main() {
    List L;
    createList(L);
    
    cout << "========================================" << endl;
    cout << "SOAL 1: INSERT ASCENDING" << endl;
    cout << "========================================" << endl;
    
    int pilihan;
    float nilai;
    
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Tambah data (Insert Ascending)" << endl;
        cout << "2. Tampilkan list" << endl;
        cout << "3. Buat list contoh (10.5, 12.0, 20.9, 25.1)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertAscending(L, nilai);
                printList(L);
                break;
            case 2:
                printList(L);
                break;
            case 3:
                createList(L); // Reset list
                insertAscending(L, 10.5);
                insertAscending(L, 25.1);
                insertAscending(L, 12.0);
                insertAscending(L, 20.9);
                cout << "\nList contoh berhasil dibuat!" << endl;
                printList(L);
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while(pilihan != 0);
    
    return 0;
}