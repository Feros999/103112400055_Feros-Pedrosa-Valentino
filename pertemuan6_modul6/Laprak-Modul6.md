# <h1 align="center">Laporan Praktikum Modul 6 - DOUBLY LINKED LIST (BAGIAN PERTAMA) </h1>
<p align="center">Feros Pedrosa Valentino - 103112400055</p>

## Dasar Teori
Doubly Linked List merupakan salah satu struktur data linear yang terdiri dari sekumpulan node, di mana setiap node menyimpan data dan memiliki dua pointer: satu pointer yang menunjuk ke node sebelumnya (prev) dan satu lagi yang menunjuk ke node berikutnya (next). Struktur ini memungkinkan traversal dalam dua arah, yaitu dari awal ke akhir atau sebaliknya, sehingga lebih fleksibel dibandingkan dengan singly linked list yang hanya dapat ditelusuri satu arah [1]. Implementasi Doubly Linked List dilakukan menggunakan bahasa pemrograman C++, di mana setiap node didefinisikan sebagai struktur yang berisi data (misalnya, integer atau string) serta pointer prev dan next. Operasi dasar yang diimplementasikan meliputi penyisipan (insert), penghapusan (delete), pembaruan (update), penampilan (view), dan pencarian (search), yang semuanya dirancang untuk memanipulasi node dalam list secara efisien.

Operasi penyisipan dimulai dengan InsertFirst, yang menambahkan node baru di posisi awal list. Jika list kosong, node baru menjadi head dan tail; jika tidak, pointer next dari node baru diarahkan ke head lama, dan pointer prev dari head lama diarahkan ke node baru, kemudian head diperbarui [2]. InsertLast menambahkan node di akhir list, di mana jika list kosong, node baru menjadi head dan tail; sebaliknya, pointer prev dari node baru diarahkan ke tail lama, pointer next dari tail lama diarahkan ke node baru, dan tail diperbarui. InsertAfter menyisipkan node baru setelah node tertentu yang dicari berdasarkan data, dengan menyesuaikan pointer prev dan next dari node sekitarnya. Sementara itu, InsertBefore menyisipkan node baru sebelum node tertentu, dengan logika serupa namun fokus pada penyesuaian pointer prev.

Operasi penghapusan meliputi DeleteFirst, yang menghapus node di awal list dengan memperbarui head ke node berikutnya dan mengatur pointer prev dari head baru menjadi nullptr jika ada. DeleteLast menghapus node di akhir dengan memperbarui tail ke node sebelumnya dan mengatur pointer next dari tail baru menjadi nullptr. DeleteAfter menghapus node setelah node tertentu, sedangkan DeleteBefore menghapus node sebelum node tertentu, keduanya memerlukan penyesuaian pointer untuk menjaga integritas list [3]. Operasi Update memungkinkan pembaruan data pada node tertentu berdasarkan posisi atau nilai, dengan mencari node terlebih dahulu dan mengganti datanya. View digunakan untuk menampilkan seluruh isi list, baik dari awal ke akhir maupun sebaliknya, dengan melakukan traversal menggunakan pointer next atau prev. Terakhir, Searching mencari node berdasarkan data tertentu, dengan traversal dari head atau tail, dan mengembalikan posisi atau pointer node jika ditemukan. Proses pencarian update data dan view data pada dasarnya sama dengan proses pada Singly linked list. Hanya saja pada Doubly linked list lebih mudah dalam melakukan proses akses elemen, karena bisa melakukan iterasi maju dan mundur. Seperti halnya Singly linked list Doubly linked list juga mempunyai ADT yang pada dasarnya sama dengan ADT yang ada pada Singly linked list[4].


## Guided 

### 1. Guided 1

listMakanan.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```

listMakanan.cpp
```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List) == true) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (nodeNext) tidak valid!" << endl;
        }
    }
}
```

main.cpp
```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```

Program ini merupakan implementasi Doubly Linked List dalam bahasa C++ untuk mengelola data makanan, dengan struktur node yang menyimpan informasi nama, jenis, harga, dan rating, serta pointer prev dan next untuk navigasi dua arah. File header listMakanan.h mendefinisikan struktur data seperti makanan untuk data, node untuk elemen list, dan linkedlist dengan pointer first dan last, serta prototipe fungsi untuk operasi dasar. Di listMakanan.cpp, fungsi isEmpty memeriksa apakah list kosong, createList menginisialisasi list, alokasi membuat node baru dengan data yang diberikan, dan dealokasi menghapus node. Operasi insert seperti insertFirst dan insertLast menambahkan node di awal atau akhir dengan menyesuaikan pointer, sementara insertAfter dan insertBefore menyisipkan node relatif terhadap node tertentu, dengan penanganan khusus jika node target adalah first atau last. Fungsi printList menampilkan semua data dari first ke last. Operasi update seperti updateFirst, updateLast, updateAfter, dan updateBefore memungkinkan pengubahan data pada posisi spesifik melalui input pengguna, dengan validasi untuk mencegah error pada list kosong atau node tidak valid. Di main.cpp, program membuat list kosong, mengalokasikan lima node makanan, dan melakukan insert secara berurutan (first, last, after, before, last) untuk membentuk urutan D-A-C-E-B, kemudian mencetak list, melakukan update pada first, last, before C, dan after C, serta mencetak hasil akhir.

### 2. Guided 2

Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan { //struktur untuk menyimpan info kendaraan
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info; // info kendaraan
    address next;
    address prev;
};

// Tipe list
struct List {
    address first; //pointer ke elemen pertama
    address last;  //pointer ke elemen terakhir
};

// Prototypes
void CreateList(List &L); //ngebuat list kosong
address alokasi(infotype x); //alokasi elemen baru/nambah elemen baru
void dealokasi(address &P); //dealokasi elemen/hapus elemen

// Insert Last
void insertLast(List &L, address P);

// Searching
address findElm(List L, string nopol);

// Delete
void deleteByNopol(List &L, string nopol);

// Tampilkan isi list
void printInfo(List L);

#endif
```

Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { //blm ada elemen
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) { //fs alokasi elemen baru
    address P = new ElmList; //alokasi memori untuk elemen baru
    P->info = x; //mengisi bagian info dengan data x
    P->next = Nil; //ini jadi nill karena gak terhubung ke list manapun
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P; //menghapus elemen yang ditunjuk oleh P dan mengembalikan memori ke sistem
}

void insertLast(List &L, address P) {
    if (L.first == Nil) { // List kosong
        L.first = P; // elemen pertama dan terakhir sama dengan P
        L.last = P;
    } else { // List ada isi
        P->prev = L.last; // prev P menunjuk ke elemen terakhir saat ini
        (L.last)->next = P; // next elemen terakhir saat ini menunjuk ke P
        L.last = P; // update last menjadi P
    }
}

// Searching
address findElm(List L, string nopol) {
    address P = L.first; // mulai dari elemen pertama
    while (P != Nil) {
        //Bandingkan nopol yang dicari dengan nopol di elemen saat ini
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next; // Lanjut ke elemen berikutnya kalau g cocok
    }
    return Nil; // Tidak ketemu
}

// Delete
void deleteByNopol(List &L, string nopol) {
    // Cari elemen dengan nopol yang sesuai
    address P = findElm(L, nopol);
    if (P == Nil) { // Tidak ditemukan
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else { // Ditemukan
        if (P == L.first && P == L.last) { // Kasus 1: Hanya 1 elemen di list
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) { // Kasus 2: Hapus elemen pertama tapi bukan satu-satunya
            L.first = P->next; // update first ke elemen berikutnya
            (L.first)->prev = Nil; // update prev elemen pertama barumenjadi nil
        } else if (P == L.last) { // Kasus 3: Hapus elemen terakhir
            L.last = P->prev; // update last ke elemen sebelumnya
            (L.last)->next = Nil; P->prev = Nil; // update next elemen terakhir baru menjadi nil
        } else { // Kasus 4: Hapus elemen di tengah
            address Prec = P->prev; // elemen sebelum P
            address Succ = P->next; // elemen setelah P
            Prec->next = Succ; Succ->prev = Prec; // hubungkan Prec ke Succ
            P->next = Nil; P->prev = Nil; // putuskan hubungan P dari list
        }
        dealokasi(P); // dealokasi elemen P
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) { //menampilkan isi list
    address P = L.first; //mulai dari elemen pertama
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```

main.cpp
```C++
#include "Doublylist.h"

using namespace std;

int main() { // penggunaan fungsi-fungsi dalam Doublylist
    List L; // deklarasi list
    CreateList(L); // buat list kosong
    address P; // deklarasi pointer elemen list
    infotype data; // deklarasi variabel info kendaraan

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    cout << "DATA LIST AWAL" << endl;
    printInfo(L);


    string cariNopol = "D001";
    cout << "MENCARI NOPOL " << cariNopol << " -" << endl;
    address found = findElm(L, cariNopol); //Manggil fungsi pencarian di Doublylist.cpp
    if (found != Nil) { // Ketemu
        cout << "Ditemukan: " << found->info.nopol << ", Warna: " << found->info.warna << endl << endl;
    } else {
        cout << cariNopol << " tidak ditemukan." << endl << endl;
    }

    string hapusNopol = "D003";
    cout << "MENGHAPUS NOPOL " << hapusNopol << " -" << endl;
    deleteByNopol(L, hapusNopol); //Manggil fungsi delete di Doublylist.cpp
    cout << endl;

    cout << "DATA LIST SETELAH HAPUS" << endl;
    printInfo(L);

    // Contoh delete elemen pertama
    cout << "MENGHAPUS ELEMEN PERTAMA " << endl;
    deleteByNopol(L, L.first->info.nopol); //Menghapus elemen pertama
    cout << endl;
    printInfo(L);


    return 0;
}
```

Program ini merupakan implementasi Doubly Linked List dalam bahasa C++ untuk mengelola data kendaraan, dengan struktur node yang menyimpan informasi nomor polisi (nopol), warna, dan tahun pembuatan, serta pointer next dan prev untuk navigasi dua arah. File header Doublylist.h mendefinisikan tipe data kendaraan sebagai infotype, struktur ElmList untuk node, dan List dengan pointer first dan last, bersama prototipe fungsi seperti CreateList untuk inisialisasi list kosong, alokasi untuk membuat node baru, dealokasi untuk menghapus node, insertLast untuk penyisipan di akhir, findElm untuk pencarian berdasarkan nopol, deleteByNopol untuk penghapusan berdasarkan nopol, dan printInfo untuk menampilkan isi list. Di Doublylist.cpp, fungsi insertLast menangani penyisipan dengan menyesuaikan pointer prev dan next, findElm melakukan traversal dari first untuk mencari nopol yang cocok, deleteByNopol menangani empat kasus penghapusan (list kosong, elemen tunggal, first, last, atau tengah) dengan memperbarui pointer dan dealokasi, serta printInfo menampilkan data dari first ke last. Program utama di main.cpp membuat list kosong, mengalokasikan dan menyisipkan tiga data kendaraan (D001, D003, D004), menampilkan list awal, mencari nopol D001, menghapus D003, menampilkan list setelah hapus, lalu menghapus elemen pertama (D001) dan menampilkan hasil akhir, mendemonstrasikan operasi insert, search, delete, dan view pada Doubly Linked List.


## Unguided 

### 1. Soal Unguided 1
Buatlah ADT Doubly Linked list sebagai berikut didalam file “Doublylist.h”:
Type infotype: kendaraan <
 nopol :string
 warna :string
 thnBuat:integer
 >
 Type address :pointer to ElmList
 Type ElmList <
 info:infotype
 next:address
 prev:address
 >
 Type List <
 First :address
 Last:address
 >
 procedure CreateList( input/output L: List)
 function alokasi( x : infotype ) → address
 procedure dealokasi( input/output P : address )
 procedure printInfo( input L :List )
 procedure insertLast( input/output L :List, input P : address)
Buatlah implementasi ADT Doubly Linked list pada file “Doublylist.cpp” dan coba hasil implementasi ADT pada file “main.cpp”.

Doublylist.h
```C++
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
```
Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        (L.last)->next = P;
        L.last = P;
    }
}

// Searching - mencari berdasarkan nopol
address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// Delete First - menghapus elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.first;
        L.first = P->next;
        (L.first)->prev = Nil;
        P->next = Nil;
    }
}

// Delete Last - menghapus elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.last;
        L.last = P->prev;
        (L.last)->next = Nil;
        P->prev = Nil;
    }
}

// Delete After - menghapus elemen setelah Prec
void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != Nil) {
            (P->next)->prev = Prec;
        }
        P->next = Nil;
        P->prev = Nil;
    } else {
        P = Nil;
    }
}

void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```
main.cpp
```C++
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    address P;
    infotype data;
    int n;
    
    // ========================================
    // SOAL 1: Input data secara dinamis dari pengguna
    // ========================================
    cout << "Masukkan jumlah kendaraan: ";
    cin >> n;
    cin.ignore(); // membersihkan buffer
    
    for (int i = 0; i < n; i++) {
        cout << "\nKendaraan ke-" << (i + 1) << endl;
        cout << "No polisi: ";
        getline(cin, data.nopol);
        cout << "Warna    : ";
        getline(cin, data.warna);
        cout << "Tahun    : ";
        cin >> data.thnBuat;
        cin.ignore(); // membersihkan buffer
        
        P = alokasi(data);
        insertLast(L, P);
    }
    
    // Tampilkan data awal
    cout << "\n====================================\n";
    cout << "DATA LIST AWAL" << endl;
    cout << "====================================\n";
    printInfo(L);
    
    // ========================================
    // SOAL 2: Mencari elemen berdasarkan input nomor polisi dari pengguna
    // ========================================
    cout << "====================================\n";
    cout << "MENCARI DATA KENDARAAN" << endl;
    cout << "====================================\n";
    string cariNopol;
    cout << "Masukkan nomor polisi yang dicari: ";
    getline(cin, cariNopol);
    
    infotype cari;
    cari.nopol = cariNopol;
    address found = findElm(L, cari);
    
    if (found != Nil) {
        cout << "\nDitemukan:" << endl;
        cout << "no polisi: " << found->info.nopol << endl;
        cout << "warna    : " << found->info.warna << endl;
        cout << "tahun    : " << found->info.thnBuat << endl;
    } else {
        cout << "\nData dengan nomor polisi " << cariNopol << " tidak ditemukan.\n";
    }
    
    // ========================================
    // SOAL 3: Hapus elemen berdasarkan input nomor polisi dari pengguna
    // ========================================
    cout << "\n====================================\n";
    cout << "MENGHAPUS DATA KENDARAAN" << endl;
    cout << "====================================\n";
    string hapusNopol;
    cout << "Masukkan nomor polisi yang akan dihapus: ";
    getline(cin, hapusNopol);
    
    // Cari elemen yang akan dihapus
    infotype hapus;
    hapus.nopol = hapusNopol;
    address toDelete = findElm(L, hapus);
    
    if (toDelete != Nil) {
        // Tentukan posisi elemen yang akan dihapus
        if (toDelete == L.first) {
            // Gunakan deleteFirst
            address temp;
            deleteFirst(L, temp);
            dealokasi(temp);
            cout << "\nData dengan nomor polisi " << hapusNopol << " berhasil dihapus (deleteFirst).\n";
        } else if (toDelete == L.last) {
            // Gunakan deleteLast
            address temp;
            deleteLast(L, temp);
            dealokasi(temp);
            cout << "\nData dengan nomor polisi " << hapusNopol << " berhasil dihapus (deleteLast).\n";
        } else {
            // Gunakan deleteAfter
            address Prec = toDelete->prev;
            address temp;
            deleteAfter(Prec, temp);
            dealokasi(temp);
            cout << "\nData dengan nomor polisi " << hapusNopol << " berhasil dihapus (deleteAfter).\n";
        }
    } else {
        cout << "\nData dengan nomor polisi " << hapusNopol << " tidak ditemukan.\n";
    }
    
    // Tampilkan data setelah penghapusan
    cout << "\n====================================\n";
    cout << "DATA LIST SETELAH PENGHAPUSAN" << endl;
    cout << "====================================\n";
    printInfo(L);
    
    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan6_modul6/output-unguided1-modul6.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan6_modul6/output-semuaunguided-modul6.png)

File Doublylist.h merupakan header file dalam bahasa C++ untuk mengimplementasikan doubly linked list yang digunakan untuk menyimpan data kendaraan. Di dalamnya, terdapat definisi tipe data infotype yang berupa struct kendaraan, yang mencakup atribut nomor polisi (nopol) sebagai string, warna kendaraan sebagai string, dan tahun pembuatan (thnBuat) sebagai integer. Selanjutnya, didefinisikan tipe address sebagai pointer ke struct ElmList, yang merupakan node dalam list dengan elemen info berupa infotype, serta pointer next dan prev untuk menghubungkan node secara dua arah. Struct List didefinisikan dengan pointer first dan last untuk menunjukkan awal dan akhir list. File ini juga menyertakan prototipe fungsi-fungsi dasar seperti CreateList untuk inisialisasi list kosong, alokasi untuk membuat node baru, dan dealokasi untuk menghapus node. Prototipe insertLast digunakan untuk menambahkan elemen di akhir list, findElm untuk mencari elemen berdasarkan nomor polisi, serta fungsi delete seperti deleteFirst, deleteLast, dan deleteAfter untuk menghapus elemen dari berbagai posisi. Terakhir, prototipe printInfo disediakan untuk menampilkan isi list. Header ini menggunakan include untuk iostream dan string, serta define Nil sebagai NULL, sehingga memungkinkan penggunaan list ini dalam program utama dengan cara yang terstruktur dan modular.
File Doublylist.cpp berisi implementasi konkret dari prototipe fungsi yang dideklarasikan di Doublylist.h, sehingga menyediakan logika operasional untuk doubly linked list kendaraan. Fungsi CreateList menginisialisasi list dengan mengatur first dan last menjadi NULL, menandai list sebagai kosong. Alokasi membuat node baru dengan mengalokasikan memori menggunakan new, mengisi info dengan data kendaraan yang diberikan, dan mengatur next serta prev ke NULL. Dealokasi menghapus node dari memori dengan delete dan mengatur pointer ke NULL untuk mencegah dangling pointer. InsertLast menambahkan elemen di akhir list: jika list kosong, elemen tersebut menjadi first dan last; jika tidak, elemen baru dihubungkan ke last sebelumnya dan last diperbarui. FindElm melakukan pencarian linear dari first hingga akhir list, membandingkan nomor polisi untuk menemukan elemen yang cocok, dan mengembalikan address jika ditemukan atau NULL jika tidak. Fungsi delete seperti deleteFirst menghapus elemen pertama dengan menyesuaikan first dan prev dari elemen berikutnya, deleteLast menghapus elemen terakhir dengan menyesuaikan last dan next dari elemen sebelumnya, sedangkan deleteAfter menghapus elemen setelah node yang diberikan (Prec) dengan menyesuaikan pointer next dan prev di sekitarnya. Akhirnya, printInfo menampilkan isi list dengan iterasi dari first ke last, mencetak nomor polisi, warna, dan tahun pembuatan setiap kendaraan, atau pesan "List Kosong" jika list tidak memiliki elemen.
File main.cpp adalah program utama yang mendemonstrasikan penggunaan doubly linked list kendaraan melalui interaksi dengan pengguna. Pada bagian soal 1, program meminta input jumlah kendaraan dari pengguna, kemudian dalam loop sebanyak n kali, membaca data kendaraan secara dinamis termasuk nomor polisi, warna, dan tahun pembuatan menggunakan getline dan cin, dengan cin.ignore untuk membersihkan buffer input agar tidak terjadi kesalahan pembacaan. Setiap data kendaraan dialokasikan menjadi node baru melalui fungsi alokasi dan ditambahkan ke akhir list menggunakan insertLast, sehingga list terbentuk secara bertahap. Setelah input selesai, program menampilkan data awal list menggunakan printInfo. 

### 2. Soal Unguided 2
Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru. fungsi findElm( L : List, x : infotype ) : address

Doublylist.h
```C++
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
```
Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        (L.last)->next = P;
        L.last = P;
    }
}

// Searching - mencari berdasarkan nopol
address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// Delete First - menghapus elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.first;
        L.first = P->next;
        (L.first)->prev = Nil;
        P->next = Nil;
    }
}

// Delete Last - menghapus elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.last;
        L.last = P->prev;
        (L.last)->next = Nil;
        P->prev = Nil;
    }
}

// Delete After - menghapus elemen setelah Prec
void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != Nil) {
            (P->next)->prev = Prec;
        }
        P->next = Nil;
        P->prev = Nil;
    } else {
        P = Nil;
    }
}

void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```
main.cpp
```C++
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    address P;
    infotype data;
    int n;
    
    // ========================================
    // SOAL 1: Input data secara dinamis dari pengguna
    // ========================================
    cout << "Masukkan jumlah kendaraan: ";
    cin >> n;
    cin.ignore(); // membersihkan buffer
    
    for (int i = 0; i < n; i++) {
        cout << "\nKendaraan ke-" << (i + 1) << endl;
        cout << "No polisi: ";
        getline(cin, data.nopol);
        cout << "Warna    : ";
        getline(cin, data.warna);
        cout << "Tahun    : ";
        cin >> data.thnBuat;
        cin.ignore(); // membersihkan buffer
        
        P = alokasi(data);
        insertLast(L, P);
    }
    
    // Tampilkan data awal
    cout << "\n====================================\n";
    cout << "DATA LIST AWAL" << endl;
    cout << "====================================\n";
    printInfo(L);
    
    // ========================================
    // SOAL 2: Mencari elemen berdasarkan input nomor polisi dari pengguna
    // ========================================
    cout << "====================================\n";
    cout << "MENCARI DATA KENDARAAN" << endl;
    cout << "====================================\n";
    string cariNopol;
    cout << "Masukkan nomor polisi yang dicari: ";
    getline(cin, cariNopol);
    
    infotype cari;
    cari.nopol = cariNopol;
    address found = findElm(L, cari);
    
    if (found != Nil) {
        cout << "\nDitemukan:" << endl;
        cout << "no polisi: " << found->info.nopol << endl;
        cout << "warna    : " << found->info.warna << endl;
        cout << "tahun    : " << found->info.thnBuat << endl;
    } else {
        cout << "\nData dengan nomor polisi " << cariNopol << " tidak ditemukan.\n";
    }
    
    // ========================================
    // SOAL 3: Hapus elemen berdasarkan input nomor polisi dari pengguna
    // ========================================
    cout << "\n====================================\n";
    cout << "MENGHAPUS DATA KENDARAAN" << endl;
    cout << "====================================\n";
    string hapusNopol;
    cout << "Masukkan nomor polisi yang akan dihapus: ";
    getline(cin, hapusNopol);
    
    // Cari elemen yang akan dihapus
    infotype hapus;
    hapus.nopol = hapusNopol;
    address toDelete = findElm(L, hapus);
    
    if (toDelete != Nil) {
        // Tentukan posisi elemen yang akan dihapus
        if (toDelete == L.first) {
            // Gunakan deleteFirst
            address temp;
            deleteFirst(L, temp);
            dealokasi(temp);
            cout << "\nData dengan nomor polisi " << hapusNopol << " berhasil dihapus (deleteFirst).\n";
        } else if (toDelete == L.last) {
            // Gunakan deleteLast
            address temp;
            deleteLast(L, temp);
            dealokasi(temp);
            cout << "\nData dengan nomor polisi " << hapusNopol << " berhasil dihapus (deleteLast).\n";
        } else {
            // Gunakan deleteAfter
            address Prec = toDelete->prev;
            address temp;
            deleteAfter(Prec, temp);
            dealokasi(temp);
            cout << "\nData dengan nomor polisi " << hapusNopol << " berhasil dihapus (deleteAfter).\n";
        }
    } else {
        cout << "\nData dengan nomor polisi " << hapusNopol << " tidak ditemukan.\n";
    }
    
    // Tampilkan data setelah penghapusan
    cout << "\n====================================\n";
    cout << "DATA LIST SETELAH PENGHAPUSAN" << endl;
    cout << "====================================\n";
    printInfo(L);
    
    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan6_modul6/output-unguided2-modul6.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan6_modul6/output-semuaunguided-modul6.png)

File Doublylist.h merupakan header file dalam bahasa C++ untuk mengimplementasikan doubly linked list yang digunakan untuk menyimpan data kendaraan. Di dalamnya, terdapat definisi tipe data infotype yang berupa struct kendaraan, yang mencakup atribut nomor polisi (nopol) sebagai string, warna kendaraan sebagai string, dan tahun pembuatan (thnBuat) sebagai integer. Selanjutnya, didefinisikan tipe address sebagai pointer ke struct ElmList, yang merupakan node dalam list dengan elemen info berupa infotype, serta pointer next dan prev untuk menghubungkan node secara dua arah. Struct List didefinisikan dengan pointer first dan last untuk menunjukkan awal dan akhir list. File ini juga menyertakan prototipe fungsi-fungsi dasar seperti CreateList untuk inisialisasi list kosong, alokasi untuk membuat node baru, dan dealokasi untuk menghapus node. Prototipe insertLast digunakan untuk menambahkan elemen di akhir list, findElm untuk mencari elemen berdasarkan nomor polisi, serta fungsi delete seperti deleteFirst, deleteLast, dan deleteAfter untuk menghapus elemen dari berbagai posisi. Terakhir, prototipe printInfo disediakan untuk menampilkan isi list. Header ini menggunakan include untuk iostream dan string, serta define Nil sebagai NULL, sehingga memungkinkan penggunaan list ini dalam program utama dengan cara yang terstruktur dan modular.
File Doublylist.cpp berisi implementasi konkret dari prototipe fungsi yang dideklarasikan di Doublylist.h, sehingga menyediakan logika operasional untuk doubly linked list kendaraan. Fungsi CreateList menginisialisasi list dengan mengatur first dan last menjadi NULL, menandai list sebagai kosong. Alokasi membuat node baru dengan mengalokasikan memori menggunakan new, mengisi info dengan data kendaraan yang diberikan, dan mengatur next serta prev ke NULL. Dealokasi menghapus node dari memori dengan delete dan mengatur pointer ke NULL untuk mencegah dangling pointer. InsertLast menambahkan elemen di akhir list: jika list kosong, elemen tersebut menjadi first dan last; jika tidak, elemen baru dihubungkan ke last sebelumnya dan last diperbarui. FindElm melakukan pencarian linear dari first hingga akhir list, membandingkan nomor polisi untuk menemukan elemen yang cocok, dan mengembalikan address jika ditemukan atau NULL jika tidak. Fungsi delete seperti deleteFirst menghapus elemen pertama dengan menyesuaikan first dan prev dari elemen berikutnya, deleteLast menghapus elemen terakhir dengan menyesuaikan last dan next dari elemen sebelumnya, sedangkan deleteAfter menghapus elemen setelah node yang diberikan (Prec) dengan menyesuaikan pointer next dan prev di sekitarnya. Akhirnya, printInfo menampilkan isi list dengan iterasi dari first ke last, mencetak nomor polisi, warna, dan tahun pembuatan setiap kendaraan, atau pesan "List Kosong" jika list tidak memiliki elemen.
File main.cpp adalah program utama yang mendemonstrasikan penggunaan doubly linked list kendaraan melalui interaksi dengan pengguna. Pada bagian soal 2, program meminta input nomor polisi yang ingin dicari, kemudian menggunakan findElm untuk mencari elemen dalam list berdasarkan nomor polisi tersebut; jika ditemukan, program menampilkan detail kendaraan seperti nomor polisi, warna, dan tahun, sedangkan jika tidak ditemukan, program memberikan pesan bahwa data tidak ada. 

### 3. Soal Unguided 3
 Hapus elemen dengan nomor polisi D003 dengan procedure delete.
- procedure deleteFirst( input/output L : List, P : address )
- procedure deleteLast( input/output L : List, P : address )
- procedure deleteAfter( input Prec : address, input/output P : address )

Doublylist.h
```C++
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
```
Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        (L.last)->next = P;
        L.last = P;
    }
}

// Searching - mencari berdasarkan nopol
address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// Delete First - menghapus elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.first;
        L.first = P->next;
        (L.first)->prev = Nil;
        P->next = Nil;
    }
}

// Delete Last - menghapus elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.last;
        L.last = P->prev;
        (L.last)->next = Nil;
        P->prev = Nil;
    }
}

// Delete After - menghapus elemen setelah Prec
void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != Nil) {
            (P->next)->prev = Prec;
        }
        P->next = Nil;
        P->prev = Nil;
    } else {
        P = Nil;
    }
}

void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```
main.cpp
```C++
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    address P;
    infotype data;
    int n;
    
    // ========================================
    // SOAL 1: Input data secara dinamis dari pengguna
    // ========================================
    cout << "Masukkan jumlah kendaraan: ";
    cin >> n;
    cin.ignore(); // membersihkan buffer
    
    for (int i = 0; i < n; i++) {
        cout << "\nKendaraan ke-" << (i + 1) << endl;
        cout << "No polisi: ";
        getline(cin, data.nopol);
        cout << "Warna    : ";
        getline(cin, data.warna);
        cout << "Tahun    : ";
        cin >> data.thnBuat;
        cin.ignore(); // membersihkan buffer
        
        P = alokasi(data);
        insertLast(L, P);
    }
    
    // Tampilkan data awal
    cout << "\n====================================\n";
    cout << "DATA LIST AWAL" << endl;
    cout << "====================================\n";
    printInfo(L);
    
    // ========================================
    // SOAL 2: Mencari elemen berdasarkan input nomor polisi dari pengguna
    // ========================================
    cout << "====================================\n";
    cout << "MENCARI DATA KENDARAAN" << endl;
    cout << "====================================\n";
    string cariNopol;
    cout << "Masukkan nomor polisi yang dicari: ";
    getline(cin, cariNopol);
    
    infotype cari;
    cari.nopol = cariNopol;
    address found = findElm(L, cari);
    
    if (found != Nil) {
        cout << "\nDitemukan:" << endl;
        cout << "no polisi: " << found->info.nopol << endl;
        cout << "warna    : " << found->info.warna << endl;
        cout << "tahun    : " << found->info.thnBuat << endl;
    } else {
        cout << "\nData dengan nomor polisi " << cariNopol << " tidak ditemukan.\n";
    }
    
    // ========================================
    // SOAL 3: Hapus elemen berdasarkan input nomor polisi dari pengguna
    // ========================================
    cout << "\n====================================\n";
    cout << "MENGHAPUS DATA KENDARAAN" << endl;
    cout << "====================================\n";
    string hapusNopol;
    cout << "Masukkan nomor polisi yang akan dihapus: ";
    getline(cin, hapusNopol);
    
    // Cari elemen yang akan dihapus
    infotype hapus;
    hapus.nopol = hapusNopol;
    address toDelete = findElm(L, hapus);
    
    if (toDelete != Nil) {
        // Tentukan posisi elemen yang akan dihapus
        if (toDelete == L.first) {
            // Gunakan deleteFirst
            address temp;
            deleteFirst(L, temp);
            dealokasi(temp);
            cout << "\nData dengan nomor polisi " << hapusNopol << " berhasil dihapus (deleteFirst).\n";
        } else if (toDelete == L.last) {
            // Gunakan deleteLast
            address temp;
            deleteLast(L, temp);
            dealokasi(temp);
            cout << "\nData dengan nomor polisi " << hapusNopol << " berhasil dihapus (deleteLast).\n";
        } else {
            // Gunakan deleteAfter
            address Prec = toDelete->prev;
            address temp;
            deleteAfter(Prec, temp);
            dealokasi(temp);
            cout << "\nData dengan nomor polisi " << hapusNopol << " berhasil dihapus (deleteAfter).\n";
        }
    } else {
        cout << "\nData dengan nomor polisi " << hapusNopol << " tidak ditemukan.\n";
    }
    
    // Tampilkan data setelah penghapusan
    cout << "\n====================================\n";
    cout << "DATA LIST SETELAH PENGHAPUSAN" << endl;
    cout << "====================================\n";
    printInfo(L);
    
    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan6_modul6/output-unguided3-modul6.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan6_modul6/output-semuaunguided-modul6.png)

File Doublylist.h merupakan header file dalam bahasa C++ untuk mengimplementasikan doubly linked list yang digunakan untuk menyimpan data kendaraan. Di dalamnya, terdapat definisi tipe data infotype yang berupa struct kendaraan, yang mencakup atribut nomor polisi (nopol) sebagai string, warna kendaraan sebagai string, dan tahun pembuatan (thnBuat) sebagai integer. Selanjutnya, didefinisikan tipe address sebagai pointer ke struct ElmList, yang merupakan node dalam list dengan elemen info berupa infotype, serta pointer next dan prev untuk menghubungkan node secara dua arah. Struct List didefinisikan dengan pointer first dan last untuk menunjukkan awal dan akhir list. File ini juga menyertakan prototipe fungsi-fungsi dasar seperti CreateList untuk inisialisasi list kosong, alokasi untuk membuat node baru, dan dealokasi untuk menghapus node. Prototipe insertLast digunakan untuk menambahkan elemen di akhir list, findElm untuk mencari elemen berdasarkan nomor polisi, serta fungsi delete seperti deleteFirst, deleteLast, dan deleteAfter untuk menghapus elemen dari berbagai posisi. Terakhir, prototipe printInfo disediakan untuk menampilkan isi list. Header ini menggunakan include untuk iostream dan string, serta define Nil sebagai NULL, sehingga memungkinkan penggunaan list ini dalam program utama dengan cara yang terstruktur dan modular.
File Doublylist.cpp berisi implementasi konkret dari prototipe fungsi yang dideklarasikan di Doublylist.h, sehingga menyediakan logika operasional untuk doubly linked list kendaraan. Fungsi CreateList menginisialisasi list dengan mengatur first dan last menjadi NULL, menandai list sebagai kosong. Alokasi membuat node baru dengan mengalokasikan memori menggunakan new, mengisi info dengan data kendaraan yang diberikan, dan mengatur next serta prev ke NULL. Dealokasi menghapus node dari memori dengan delete dan mengatur pointer ke NULL untuk mencegah dangling pointer. InsertLast menambahkan elemen di akhir list: jika list kosong, elemen tersebut menjadi first dan last; jika tidak, elemen baru dihubungkan ke last sebelumnya dan last diperbarui. FindElm melakukan pencarian linear dari first hingga akhir list, membandingkan nomor polisi untuk menemukan elemen yang cocok, dan mengembalikan address jika ditemukan atau NULL jika tidak. Fungsi delete seperti deleteFirst menghapus elemen pertama dengan menyesuaikan first dan prev dari elemen berikutnya, deleteLast menghapus elemen terakhir dengan menyesuaikan last dan next dari elemen sebelumnya, sedangkan deleteAfter menghapus elemen setelah node yang diberikan (Prec) dengan menyesuaikan pointer next dan prev di sekitarnya. Akhirnya, printInfo menampilkan isi list dengan iterasi dari first ke last, mencetak nomor polisi, warna, dan tahun pembuatan setiap kendaraan, atau pesan "List Kosong" jika list tidak memiliki elemen.
File main.cpp adalah program utama yang mendemonstrasikan penggunaan doubly linked list kendaraan melalui interaksi dengan pengguna.Pada bagian soal 3, program meminta input nomor polisi yang akan dihapus, lalu mencari elemen tersebut menggunakan findElm; jika ditemukan, program menentukan posisi elemen—jika di awal list, gunakan deleteFirst; jika di akhir, gunakan deleteLast; jika di tengah, gunakan deleteAfter dengan predecessor sebagai prev dari elemen tersebut—kemudian dealokasikan node yang dihapus dan tampilkan pesan sukses, setelah itu menampilkan list setelah penghapusan menggunakan printInfo. 

## Kesimpulan
Doubly Linked List merupakan struktur data linear yang efektif untuk aplikasi yang memerlukan manipulasi data dinamis dengan kemampuan traversal dua arah, menjadikannya lebih fleksibel dibandingkan Singly Linked List. Melalui implementasi di bahasa pemrograman C++, operasi seperti InsertFirst, InsertLast, InsertAfter, InsertBefore, DeleteFirst, DeleteLast, DeleteAfter, DeleteBefore, Update, View, dan Searching dapat dilakukan secara efisien, dengan kompleksitas waktu yang bervariasi tergantung pada posisi operasi. Struktur ini memanfaatkan pointer prev dan next pada setiap node untuk menjaga integritas list, memungkinkan akses maju dan mundur yang memudahkan proses pencarian, pembaruan, dan penampilan data. Secara keseluruhan, Doubly Linked List mendukung Abstract Data Type (ADT) yang serupa dengan Singly Linked List namun dengan keunggulan tambahan dalam navigasi, sehingga cocok untuk skenario seperti manajemen antrian atau struktur data yang sering dimodifikasi.

## Referensi
[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.
<br>[2] Weiss, M. A. (2011). Data Structures and Algorithm Analysis in C++ (4th ed.). Pearson.
<br>[3] Goodrich, M. T., Tamassia, R., & Mount, D. M. (2011). Data Structures and Algorithms in C++ (2nd ed.). Wiley.
<br>[4] Modul 6 - Praktikum Struktur Data
