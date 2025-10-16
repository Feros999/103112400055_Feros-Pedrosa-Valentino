# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (Bagian Pertama)</h1>
<p align="center">Feros Pedrosa Valentino - 103112400055</p>

## Dasar Teori
Single Linked List adalah sebuah field pointer-nya hanya satu buah saja dan satu arah serta pada akhir node yang nodenya saling terhubung satu sama lain[2]. Jadi Setiap node pada linked list mempunyai field yang berisi pointer ke node berikutnya, dan juga memiliki field yang berisi data. Node terakhir akan menunjuk ke NULL yang akan digunakan sebagai kondisi berhenti pada saat pembacaan isi linked list.

### A. Linked List dengan Pointer<br/>
Linked list (biasa disebut list saja) adalah salah satu bentuk struktur data (representasi penyimpanan) berupa serangkaian elemen data yang saling berkait (berhubungan) dan bersifat fleksibel karena dapat tumbuh dan mengerut sesuai kebutuhan[1]. Data yang disimpan dalam Linked list bisa berupa data tunggal atau data majemuk. Data tunggal merupakan data yang hanya terdiri dari satu data (variabel), misalnya: nama bertipe string. Sedangkan data majemuk merupakan sekumpulan data (record) yang di dalamnya terdiri dari berbagai tipe data, misalnya: Data Mahasiswa, terdiri dari Nama bertipe string, NIM bertipe long integer, dan Alamat bertipe string.
Linked list dapat diimplementasikan menggunakan Array dan Pointer (Linked list).
Yang akan digunakan adalah pointer, karena beberapa alasan, yaitu:
1. Array bersifat statis, sedangkan pointer dinamis.
2. Pada linked list bentuk datanya saling bergandengan (berhubungan) sehingga lebih mudah memakai pointer.
3. Sifat linked list yang fleksibel lebih cocok dengan sifat pointer yang dapat diatur sesuai kebutuhan.
4. Karena array lebih susah dalam menangani linked list, sedangkan pointer lebih mudah.
5. Array lebih cocok pada kumpulan data yang jumlah elemen maksimumnya sudah diketahui dari awal.
Dalam implementasinya, pengaksesan elemen pada Linked list dengan pointer bisa menggunakan macies (->) atau tanda titik (.)

### B. Singly Linked List<br/>
Singly Linked list merupakan model ADT Linked list yang hanya memiliki satu arah pointer[1].
Komponen elemen dalam Singly linked list:
1. Elemen: segmen-segmen data yang terdapat dalam suatu list.
2. Data: informasi utama yang tersimpan dalam sebuah elemen.
3. Successor: bagian elemen yang berfungsi sebagai penghubung antar elemen.

Sifat dari Singly Linked list:
1. Hanya memerlukan satu buah pointer.
2. Node akhir menunjuk ke Nil kecuali untuk list circular.
3. Hanya dapat melakukan pembacaan maju.
4. Pencarian sequensial dilakukan jika data tidak terurut.
5. Lebih mudah ketika melakukan penyisipan atau penghapusan di tengah list.

Istilah-istilah dalam Singly Linked list :
1. first/head: pointer pada list yang menunjuk alamat elemen emen pertama list.
2. next: pointer pada elemen yang berfungsi sebagai successor (penunjuk) alamat elemen di depannya. 
3. NULL/Nil: artinya tidak memiliki nilai, atau tidak mengacu ke mana pun, atau kosong.
4. Node/simpul/elemen: merupakan tempat penyimpanan data pada suatu memori tertentu.

#### 1. Pembentukan Komponen-Komponen List
1. Pembentukan List
Sebuah proses untuk membetuk sebuah list baru. Biasanya nama fungsi yang digunakan createList(). Fungsi ini akan mengeset nilai awal list yaitu first(list) dan last(list) dengan nilai Nil.
2. Pengalokasian Memori
Proses untuk mengalokasikan memori untuk setiap elemen data yang ada dalam list. Fungsi yang biasanya digunakan adalah nama fungsi yang biasa digunakan alokasi ().
3. Dealokasi
Untuk menghapus sebuah memory address yang tersimpan atau telah dialokasikan dalam bahasa pemrograman C digunakan syntax free, sedangkan pada C++ digunakan syntax delete.
4. Pengecekan List
Fungsi untuk mengecek apakah list tersebut kosong atau tidak. Akan mengembalikan nilai true jika list kosong dan nilai false jika list tidak kosong. Fungsi yang digunakan adalah isEmpty().

#### 2. Insert
1. Insert First
Merupakan metode memasukkan elemen data ke dalam list yang diletakkan pada awal list.
2. Insert Last
Merupakan metode memasukkan elemen data ke dalam list yang diletakkan pada akhir list.
3. Insert After
Merupakan metode memasukkan data ke dalam list yang diletakkan setelah node tertentu yang ditunjuk oleh user.

#### 3. View
Merupakan operasi dasar pada list yang menampilkan isi node/simpul dengan suatu penelusuran list. Mengunjungi setiap node kemudian menampilkan data yang tersimpan pada node tersebut.

### C. Delete<br/>
#### 1. Delete First
Pengambilan atau penghapusan sebuah elemen pada awal list[1].
#### 2. Delete Last
Pengambilan atau penghapusan suatu elemen dari akhir list.
#### 3. Delete After
Pengambilan atau penghapusan node setelah node tertentu.
#### 4. Delete Elemen
Operasi yang digunakan untuk menghapus dan membebaskan memori yang dipakai oleh elemen tersebut.
Fungsi yang biasanya dipakai:
1. fungsi dealokasi (P): membebaskan memori yang dipakai oleh elemen P.
2. fungsi delAll(L) : membebaskan semua memori yang dipakai elemen - elemen yang ada pada list L. Hasil akhir list L menjadi kosong.
Semua operasi-operasi dasar list biasa disebut dengan operasi primitif. Primitif-primitif dalam list ini merupakan bagian dari ADT list yang tersimpan dalam file *.h dan file *.cpp, dengan rincian file *.h untuk menyimpan prototipe primitif-primitif atau fungsi-fungsi dan menyimpan tipe data yang dipergunakan dalam primitif list tersebut.
Untuk bisa mengakses semua primitif tersebut yaitu dengan meng-include terhadap file *.h-nya.

### D. Update<br/>
Operasi dasar pada list yang digunakan untuk meng-update data yang ada di dalam list[1]. Dengan operasi update ini kita dapat meng-update data-data node yang ada di dalam list. Proses update biasanya diawali dengan proses pencarian terhadap data yang akan di-update.


## Guided 

### 1. Guided 1

list.h
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```

list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, node sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```

Di list.h, file header ini mendefinisikan struktur data, seperti struct mahasiswa untuk menyimpan nama, NIM, dan umur; struct node untuk elemen linked list yang berisi data mahasiswa dan pointer ke node berikutnya; serta struct linkedlist untuk menyimpan alamat node pertama. Selain itu, file ini menyatakan fungsi-fungsi seperti isEmpty untuk memeriksa apakah list kosong, createList untuk membuat list baru, alokasi untuk membuat node baru, dealokasi untuk menghapus node, insertFirst/insertAfter/insertLast untuk menambahkan node, dan printList untuk menampilkan isi list.
Pada list.cpp, file ini mengimplementasikan fungsi-fungsi yang dideklarasikan di list.h. Fungsi isEmpty memeriksa apakah pointer pertama list adalah NULL. createList menginisialisasi list dengan pointer pertama sebagai NULL. alokasi membuat node baru dengan data yang diberikan dan mengatur pointer next-nya ke NULL. dealokasi menghapus node dari memori. Fungsi insertFirst menambahkan node di awal list, insertAfter menambahkan node setelah node tertentu, dan insertLast menambahkan node di akhir list dengan iterasi melalui node-node yang ada. Akhirnya, printList menampilkan semua data mahasiswa dalam list jika list tidak kosong.
Di main.cpp, program utama dimulai dengan membuat linked list kosong menggunakan createList, kemudian mengalokasikan lima node untuk data mahasiswa tertentu. Node-node ini dimasukkan ke list dengan insertFirst untuk node pertama, insertLast untuk node kedua dan kelima, serta insertAfter untuk node ketiga dan keempat. Setelah itu, program mencetak isi list menggunakan printList, yang menunjukkan urutan data mahasiswa setelah operasi insert dilakukan. 

### 2. Guided 2

list.h
```C++
// list.h

//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```

list.cpp
```C++
// list.cpp

#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {

    List.first = Nil;
}

//pembuatan node baru
address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```

main.cpp
```C++
// main.cpp

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Di list.h, file header ini mendefinisikan struct mahasiswa, node (berisi data dan pointer next), serta linkedlist (dengan pointer first), beserta fungsi dasar seperti isEmpty, createList, alokasi, dealokasi, printList, insertFirst/insertAfter/insertLast, dan fungsi baru: delFirst/delLast/delAfter untuk menghapus node, nbList untuk menghitung jumlah node, serta deleteList untuk menghapus seluruh list, semuanya dilindungi header guard.
Pada list.cpp, implementasi fungsi dasar tetap sama: isEmpty memeriksa pointer first, createList menginisialisasi list kosong, alokasi membuat node baru, dealokasi menghapus node, insertFirst menambahkan di awal, insertAfter setelah node tertentu, dan insertLast di akhir dengan iterasi. Fungsi baru meliputi delFirst yang menghapus node pertama dan memperbarui first, delLast yang mencari node terakhir untuk dihapus (dengan penanganan kasus list tunggal), delAfter yang menghapus node setelah nodePrev jika valid, nbList yang menghitung node dengan loop while, serta deleteList yang menghapus semua node secara berurutan hingga list kosong dan mencetak konfirmasi.
Di main.cpp, program utama membuat list kosong, mengalokasikan lima node mahasiswa, dan menambahkan ke list menggunakan insertFirst, insertLast, dan insertAfter untuk membentuk urutan tertentu. Kemudian, mencetak isi list dan jumlah node dengan nbList. Selanjutnya, melakukan delFirst (hapus node pertama), delLast (hapus node terakhir), dan delAfter (hapus nodeD setelah nodeC), diikuti pencetakan ulang isi dan jumlah node. Terakhir, deleteList menghapus seluruh list, diikuti pencetakan terakhir yang menunjukkan list kosong.


## Unguided 

### 1. Soal Unguided 1
Buatlah ADT Singly Linked list sebagai berikut di dalam file "Singlylist.h" Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file "Singlylist.cpp" Kemudian buat program utama didalam file "main.cpp" dengan implementasi sebagai berikut:

Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

struct List {
    Node* first;
};

void createList(List& L);
Node* alokasi(int x);
void insertFirst(List& L, Node* P);
void insertAfter(Node* Prec, Node* P);
void insertLast(List& L, Node* P);
void printList(const List& L);

void deleteFirst(List& L);
void deleteLast(List& L);
void deleteAfter(Node* Prec);
int nbList(const List& L);
void deleteList(List& L);

#endif
```

Singlylist.cpp
```C++
#include "Singlylist.h"

void createList(List& L) { L.first = nullptr; }

Node* alokasi(int x) {
    Node* P = new Node;
    P->info = x;
    P->next = nullptr;
    return P;
}

void insertFirst(List& L, Node* P) {
    P->next = L.first;
    L.first = P;
}

void insertAfter(Node* Prec, Node* P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(List& L, Node* P) {
    if (L.first == nullptr)
        L.first = P;
    else {
        Node* Q = L.first;
        while (Q->next != nullptr)
            Q = Q->next;
        Q->next = P;
    }
}

void printList(const List& L) {
    Node* P = L.first;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List& L) {
    if (L.first != nullptr) {
        Node* P = L.first;
        L.first = P->next;
        delete P;
    }
}

void deleteLast(List& L) {
    if (L.first != nullptr) {
        if (L.first->next == nullptr) {
            delete L.first;
            L.first = nullptr;
        } else {
            Node* P = L.first;
            while (P->next->next != nullptr)
                P = P->next;
            delete P->next;
            P->next = nullptr;
        }
    }
}

void deleteAfter(Node* Prec) {
    if (Prec != nullptr && Prec->next != nullptr) {
        Node* P = Prec->next;
        Prec->next = P->next;
        delete P;
    }
}

int nbList(const List& L) {
    int count = 0;
    Node* P = L.first;
    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List& L) {
    Node* P = L.first;
    while (P != nullptr) {
        Node* temp = P;
        P = P->next;
        delete temp;
    }
    L.first = nullptr;
}
```

main.cpp
```C++
#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    insertFirst(L, alokasi(9));

    insertAfter(L.first, alokasi(12));

    insertAfter(L.first->next, alokasi(8));

    insertAfter(L.first->next->next, alokasi(0));

    insertLast(L, alokasi(2));

    printList(L);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan4_modul4/output-unguided1-modul4.png)

Di Singlylist.h, struktur Node berisi data integer 'info' dan pointer 'next' ke node berikutnya, sedangkan struktur List menyimpan pointer 'first' yang menunjuk ke node pertama. Fungsi-fungsi seperti createList() menginisialisasi list kosong, alokasi() membuat node baru, insertFirst() menambahkan node di awal, insertAfter() menambahkan node setelah node tertentu, insertLast() menambahkan node di akhir, printList() mencetak semua elemen, deleteFirst() menghapus node pertama, deleteLast() menghapus node terakhir, deleteAfter() menghapus node setelah node tertentu, nbList() menghitung jumlah node, dan deleteList() menghapus seluruh list beserta memori yang dialokasikan.
Singlylist.cpp menyediakan implementasi dari fungsi-fungsi di atas. Misalnya, insertFirst() menghubungkan node baru ke awal list dengan mengatur pointer 'next' dari node baru ke node pertama yang lama, kemudian memperbarui 'first' dari list. Fungsi lain seperti deleteFirst() memindahkan pointer 'first' ke node berikutnya dan menghapus node lama untuk menghindari kebocoran memori.
Di main.cpp, program utama membuat list baru menggunakan createList(), kemudian menambahkan node dengan nilai 9 di awal, 12 setelah node pertama, 8 setelah node kedua, 0 setelah node ketiga, dan 2 di akhir. Akhirnya, printList() digunakan untuk menampilkan isi list, yang menghasilkan output: "9 12 8 0 2".


### 2. Soal Unguided 2
Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

struct List {
    Node* first;
};

// Prototype ADT
void createList(List& L);
Node* alokasi(int x);
void insertFirst(List& L, Node* P);
void insertAfter(Node* Prec, Node* P);
void insertLast(List& L, Node* P);
void printList(const List& L);

void deleteFirst(List& L);
void deleteLast(List& L);
void deleteAfter(Node* Prec);
int nbList(const List& L);
void deleteList(List& L);

#endif
```

Singlylist.cpp
```C++
#include "Singlylist.h"

void createList(List& L) { L.first = nullptr; }

Node* alokasi(int x) {
    Node* P = new Node;
    P->info = x;
    P->next = nullptr;
    return P;
}

void insertFirst(List& L, Node* P) {
    P->next = L.first;
    L.first = P;
}

void insertAfter(Node* Prec, Node* P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(List& L, Node* P) {
    if (L.first == nullptr)
        L.first = P;
    else {
        Node* Q = L.first;
        while (Q->next != nullptr)
            Q = Q->next;
        Q->next = P;
    }
}

void printList(const List& L) {
    Node* P = L.first;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List& L) {
    if (L.first != nullptr) {
        Node* P = L.first;
        L.first = P->next;
        delete P;
    }
}

void deleteLast(List& L) {
    if (L.first != nullptr) {
        if (L.first->next == nullptr) {
            delete L.first;
            L.first = nullptr;
        } else {
            Node* P = L.first;
            while (P->next->next != nullptr)
                P = P->next;
            delete P->next;
            P->next = nullptr;
        }
    }
}

void deleteAfter(Node* Prec) {
    if (Prec != nullptr && Prec->next != nullptr) {
        Node* P = Prec->next;
        Prec->next = P->next;
        delete P;
    }
}

int nbList(const List& L) {
    int count = 0;
    Node* P = L.first;
    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List& L) {
    Node* P = L.first;
    while (P != nullptr) {
        Node* temp = P;
        P = P->next;
        delete temp;
    }
    L.first = nullptr;
}
```

main.cpp
```C++
#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    insertFirst(L, alokasi(9));
    insertAfter(L.first, alokasi(12));
    insertAfter(L.first->next, alokasi(8));
    insertAfter(L.first->next->next, alokasi(0));
    insertLast(L, alokasi(2));

    deleteFirst(L);           // hapus node 9
    deleteLast(L);            // hapus node 2
    deleteAfter(L.first);     // hapus node 8 (setelah 12)

    printList(L);

    cout << endl;
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan4_modul4/output-unguided2-modul4.png)


Di Singlylist.h, struktur Node berisi data integer 'info' dan pointer 'next', sementara struktur List menyimpan pointer 'first' ke node pertama. Fungsi-fungsi seperti createList() menginisialisasi list kosong, alokasi() membuat node baru, insertFirst()/insertAfter()/insertLast() menambahkan node, printList() mencetak elemen, deleteFirst()/deleteLast()/deleteAfter() menghapus node tertentu, nbList() menghitung jumlah node, dan deleteList() menghapus seluruh list.
Singlylist.cpp menyediakan implementasi fungsi-fungsi tersebut, misalnya insertFirst() menambahkan node di awal dengan memperbarui pointer, sedangkan deleteFirst() menghapus node pertama dan membebaskan memori, serta fungsi lain seperti deleteLast() yang menelusuri list untuk menghapus node terakhir dan deleteAfter() yang menghapus node setelah node yang ditentukan.
Di main.cpp, program membuat list baru dan menambahkan node: 9 (pertama), 12 (setelah 9), 8 (setelah 12), 0 (setelah 8), dan 2 (akhir). Kemudian, deleteFirst() menghapus 9 (list menjadi 12 → 8 → 0 → 2), deleteLast() menghapus 2 (list menjadi 12 → 8 → 0), dan deleteAfter(L.first) menghapus 8 (setelah 12, sehingga list menjadi 12 → 0). Program kemudian mencetak list (12 0), jumlah node (2), menghapus seluruh list menggunakan deleteList(), dan mencetak pesan konfirmasi serta jumlah node yang sekarang 0, menunjukkan operasi manipulasi dan penghapusan berhasil.

## Kesimpulan
Linked list, khususnya singly linked list, merupakan struktur data dinamis yang fleksibel dan efisien untuk menyimpan serta mengelola elemen-elemen data yang saling terhubung melalui pointer, sehingga lebih unggul dibandingkan array dalam konteks pertumbuhan dan penyisipan/penghapusan elemen. Singly linked list hanya menggunakan satu arah pointer untuk menghubungkan elemen (data) dengan successor-nya, dimulai dari pointer first/head hingga akhir yang menunjuk ke NULL, dengan operasi dasar seperti pembentukan list (melalui fungsi createList, alokasi memori, dealokasi, dan pengecekan isEmpty), penyisipan (insert first, last, atau after), penghapusan (delete first, last, after, atau elemen lengkap), tampilan isi list (view), serta pembaruan data (update setelah pencarian). Keunggulan ini membuat singly linked list ideal untuk program yang memerlukan fleksibilitas, meskipun operasi pencarian cenderung sekuensial, dan implementasinya biasanya dirancang sebagai Abstract Data Type (ADT) dalam file .h untuk prototipe fungsi dan .cpp untuk implementasi, memastikan modularitas dan kemudahan penggunaan dalam pemrograman.

## Referensi
[1] Modul 4 - Praktikum Struktur Data
<br>[2] Mengenal Single Linked List dalam Struktur Data. (n.d.). Retrieved from https://daismabali.com/artikel_detail/54/1/Mengenal-Single-Linked-List-dalam-Struktur-Data.html