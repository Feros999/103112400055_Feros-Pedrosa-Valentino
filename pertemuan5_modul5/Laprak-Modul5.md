# <h1 align="center">Laporan Praktikum Modul 5 - SINGLY LINKED LIST (Bagian Kedua)</h1>
<p align="center">Feros Pedrosa Valentino - 103112400055</p>

## Dasar Teori
Operasi fundamental pada struktur data tidak hanya terbatas pada penambahan atau penghapusan elemen, tetapi juga mencakup kemampuan untuk mencari (searching) dan memperbarui (updating) data yang sudah tersimpan [1]. Pada singly linked list (SLL), operasi-operasi ini memiliki karakteristik unik yang ditentukan oleh struktur linier dan satu arahnya. Proses pembaruan (update) data dalam SLL pada dasarnya adalah kombinasi dari operasi pencarian dan modifikasi. Untuk memperbarui nilai di node tertentu, pertama-tama node tersebut harus ditemukan. Setelah node target diidentifikasi melalui penelusuran, data di dalam node tersebut dapat langsung dimodifikasi [2]. Proses ini tidak mengubah struktur pointer list itu sendiri, hanya nilai internal node-nya.

Searching merupakan operasi dasar list dengan melakukan aktivitas pencarian terhadap node tertentu. Proses ini berjalan dengan mengunjungi setiap node dan berhenti setelah node yang dicari ketemu[5]. Metode pencarian paling umum dan mendasar untuk linked list adalah Linear Search (Pencarian Linier). Algoritma ini bekerja dengan cara menelusuri list secara sekuensial, dimulai dari node pertama (head). Di setiap node, data node tersebut dibandingkan dengan nilai yang dicari. Jika ditemukan kecocokan, pencarian berhasil dan biasanya mengembalikan pointer ke node tersebut atau status keberhasilan [3]. Jika penelusuran mencapai akhir list (NULL atau nullptr) tanpa menemukan data, berarti nilai yang dicari tidak ada dalam list. Dalam C++, ini biasanya diimplementasikan menggunakan loop (while) yang berlanjut selama pointer sementara tidak menunjuk ke NULL [4].

Di sisi lain, terdapat algoritma pencarian yang jauh lebih efisien yang disebut Binary Search (Pencarian Biner). Algoritma ini bekerja dengan prinsip divide and conquer, di mana ia berulang kali membagi dataset menjadi dua bagian dan hanya melanjutkan pencarian di bagian yang relevan [1]. Namun, Binary Search memiliki prasyarat mutlak: data harus dalam keadaan terurut (sorted). Selain itu, algoritma ini memerlukan kemampuan untuk mengakses elemen di posisi tengah (indeks tengah) secara instan (akses acak), yang merupakan keunggulan utama struktur data seperti array [3].

Penerapan Binary Search pada singly linked list sangat tidak efisien dan secara umum tidak praktis [1]. Linked list tidak mendukung akses acak; untuk menemukan node ke-i, kita harus menelusuri i node dari head. Menemukan node tengah dalam linked list saja sudah memerlukan penelusuran setengah list. Melakukan ini berulang kali sesuai logika Binary Search akan menghilangkan semua keuntungan efisiensinya. Karena itu, Binary Search secara fundamental tidak cocok untuk linked list dan hampir selalu lebih lambat daripada Linear Search sederhana pada struktur data ini [2, 4].


## Guided 

### 1. Guided 1

listBuah.h
```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil nullptr

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; //memberikan nama alias databuah untuk struct buah

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node{
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List,address nodeBaru);
void insertAfter(linkedlist &list, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

#endif
```
listBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

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

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
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
    if (Prev != Nil) {
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
        cout << "Node pertama berhasil terhapus!" << endl;
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
        cout << "Node terakhir berhasil terhapus!" << endl;
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
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
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
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
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
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```
main.cpp
```C++
#include "listBuah.h"

#include <iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    //A - C - D - B - E

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program ini mengimplementasikan singly linked list dalam bahasa C++ untuk mengelola data buah, yang terdiri dari nama (string), jumlah (int), dan harga (float), dengan menggunakan tiga file yaitu header (listBuah.h), implementasi (listBuah.cpp), dan program utama (main.cpp). Di header, struct buah mendefinisikan data buah, struct node menyimpan data tersebut beserta pointer next, dan struct linkedlist memiliki pointer first sebagai awal list; typedef digunakan untuk alias seperti dataBuah dan address, serta dideklarasikan prototipe fungsi untuk operasi dasar seperti pengecekan kosong (isEmpty), pembuatan list kosong (createList), alokasi dan dealokasi node, insert (first, after, last), delete (first, last, after), print list, hitung jumlah node (nbList), hapus seluruh list (deleteList), serta update data node (first, last, after). Implementasi di listBuah.cpp menyediakan fungsi-fungsi tersebut dengan manajemen memori menggunakan new dan delete, di mana insert menambahkan node di posisi tertentu dengan menyesuaikan pointer next, delete menghapus node sambil membebaskan memori dan menampilkan pesan, print menelusuri list untuk menampilkan data, nbList menghitung node, dan update meminta input baru untuk mengubah data node spesifik. Di main.cpp, program membuat linked list kosong, mengalokasikan lima node buah (Jeruk, Apel, Pir, Semangka, Durian), menyisipkannya dalam urutan yang menghasilkan list A-C-D-B-E (dengan insertFirst, insertLast, dan insertAfter), mencetak isi list dan jumlah node, kemudian melakukan update pada node pertama, terakhir, dan setelah node D, sebelum mencetak list lagi untuk menunjukkan perubahan.

### 2. Guided 2
Linear Search

```C++
#include<iostream>
using namespace std;

//Definisi node
struct Node { //memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk pencarian linear
Node* linearSearch(Node* head, int key) {
    Node* current = head; //mulai dari node pertama
    while (current != nullptr) { //selama masih ada node
        if (current->data == key) return current;
        current = current->next; //pindah ke node berikutnya
    }
    return nullptr; //tidak ditemukan
}

//prosedur untuk menambahkan node
void append(Node*& head, int value){
    Node* newNode = new Node{value, nullptr};
    if(!head)head=newNode; //jika head null
    else{
        Node* temp = head; //mulai dari head
        while(temp->next)temp=temp->next; //pindah ke node berikutnya sampai ketemu node terakhir
        temp->next=newNode; //node terakhir dihubungkan ke node baru
    }
}

int main(){
    Node* head = nullptr; //inisialisasi head list kosong

    //menambah node
    append(head, 10); append(head, 20); append(head, 30);

    Node* result = linearSearch(head, 20); //result ini pointer untuk mencari data 20
    cout << (result? "Found" : "Not Found") << endl;

    return 0;
}
```
Program diatas mengimplementasikan struktur data linked list dengan menggunakan struct Node yang terdiri dari data integer dan pointer ke node berikutnya. Fungsi linearSearch melakukan pencarian linear dengan memulai dari head (node pertama) dan menelusuri setiap node hingga menemukan nilai yang cocok dengan key, mengembalikan pointer ke node tersebut atau nullptr jika tidak ditemukan. Prosedur append menambahkan node baru di akhir linked list dengan membuat node baru dan menghubungkannya ke node terakhir jika list tidak kosong, atau menjadikannya head jika list masih kosong. Di fungsi main, linked list diinisialisasi kosong, kemudian ditambahkan tiga node dengan nilai 10, 20, dan 30 menggunakan append. Terakhir, linearSearch dipanggil untuk mencari nilai 20, dan hasilnya dicetak sebagai "Found" jika ditemukan atau "Not Found" jika tidak, menunjukkan operasi pencarian berhasil menemukan data di posisi kedua.

### 3. Guided 3
Binary Search

```C++
#include<iostream>
using namespace std;

//Definisi node
struct Node { //memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//prosedur untuk menambahkan node
void append(Node*& head, int value){
    Node* newNode = new Node{value, nullptr};
    if(!head)head=newNode; //jika head null
    else{
        Node* temp = head; //mulai dari head
        while(temp->next)temp=temp->next; //pindah ke node berikutnya sampai ketemu node terakhir
        temp->next=newNode; //node terakhir dihubungkan ke node baru
    }
}

Node* binarySearch(Node* head, int key) { //Node* ini pointer (kembalian) //head ini pointer ke node pertama //key ini data yang dicari
    int size = 0; //var size diisi 0
    for (Node* current = head; current; current = current->next) size++; //current adalah pointer yang digunakan untuk menyusuri linked list
    Node *start = head; 
    Node* end = nullptr; //end adalah pointer yang menunjuk ke node terakhir
    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;
        for (int i = 0; i < mid; i++) midNode = midNode->next; //midNode ini pointer yang menunjuk ke node tengah

        if (midNode->data == key) return midNode;

        if (midNode->data < key){
            start = midNode->next;
        }
        else { //jika data midNode lebih besar dari key, kita cari di bagian kiri
            end = midNode;
        }
        size -= mid; //kita mengurangi size dengan mid
    }
    return nullptr; //jika key tidak ditemukan
}

int main(){
    Node* head = nullptr; //inisialisasi linked list kosong

    append(head, 10); append(head, 20); append(head, 30); append(head, 40); append(head, 50);

    //mencari data 40 menggunakan binarySearch
    Node* result = binarySearch(head, 40);
    cout << (result? "Found" : "Not Found") << endl; //menampilkan hasil pencarian

    return 0;
}
```
Program ini mengimplementasikan struktur data linked list sederhana dalam C++ dengan operasi penambahan node dan pencarian biner. Struktur Node mendefinisikan setiap elemen linked list yang terdiri dari data integer dan pointer ke node berikutnya. Fungsi append menambahkan node baru di akhir linked list dengan membuat node baru, lalu menghubungkannya ke node terakhir jika linked list tidak kosong, atau menjadikannya head jika kosong. Fungsi binarySearch melakukan pencarian biner pada linked list yang diasumsikan terurut, meskipun linked list tidak mendukung akses acak secara efisien; ia menghitung ukuran linked list terlebih dahulu, lalu menggunakan pointer untuk menemukan node tengah, membandingkan dengan kunci pencarian, dan menyempitkan pencarian ke bagian kiri atau kanan hingga ditemukan atau tidak. Dalam fungsi main, linked list diinisialisasi kosong, kemudian ditambahkan nilai 10, 20, 30, 40, dan 50 secara berurutan, lalu dilakukan pencarian untuk nilai 40 yang akan mencetak "Found" jika ditemukan atau "Not Found" jika tidak, dengan hasil akhir adalah "Found" karena 40 ada dalam list.


## Unguided 

### 1. Soal Unguided 1
Implementasikan program C++ yang menggunakan algoritma Binary 
Search pada Linked List untuk mencari elemen tertentu. Program 
harus mampu: 
1. Membuat linked list dengan menambahkan node di akhir 
2. Mengimplementasikan binary search pada linked list 
3. Menampilkan detail proses pencarian dan hasil akhir

Petunjuk Tugas 1: 
• Gunakan struktur Node dengan data integer dan pointer next 
• Implementasikan fungsi append() untuk menambah node 
• Implementasikan fungsi binarySearch() yang mengembalikan pointer ke node yang ditemukan 
• Data dalam linked list harus terurut (ascending) untuk binary search bekerja dengan benar 
• Tampilkan langkah-langkah pencarian dan posisi tengah setiap iterasi 
• Program utama harus membuat linked list dengan minimal 5 elemen dan melakukan pencarian 


```C++
#include<iostream>
using namespace std;

//Definisi node
struct Node {
    int data;
    Node* next;
};

//Prosedur untuk menambahkan node di akhir
void append(Node*& head, int value){
    Node* newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

//Fungsi untuk menampilkan linked list
void displayList(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data;
        if(temp->next) cout << " -> ";
        else cout << " -> NULL";
        temp = temp->next;
    }
    cout << endl;
}

//Fungsi Binary Search dengan output detail
Node* binarySearch(Node* head, int key) {
    int size = 0;
    for (Node* current = head; current; current = current->next) size++;
    
    Node* start = head;
    Node* end = nullptr;
    int iterasi = 1;
    int remainingSize = size;
    
    cout << "\nProses Pencarian:" << endl;
    
    while (remainingSize > 0) {
        int mid = remainingSize / 2;
        Node* midNode = start;
        
        for (int i = 0; i < mid; i++) {
            midNode = midNode->next;
        }
        
        cout << "Iterasi " << iterasi << ": Mid = " << midNode->data << " (indeks tengah)";
        
        if (midNode->data == key) {
            cout << " - DITEMUKAN!" << endl;
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << midNode << endl;
            cout << "Data node: " << midNode->data << endl;
            if(midNode->next){
                cout << "Node berikutnya: " << midNode->next->data << endl;
            } else {
                cout << "Node berikutnya: NULL" << endl;
            }
            return midNode;
        }
        
        if (midNode->data < key){
            cout << " -> Cari di bagian kanan" << endl;
            start = midNode->next;
            remainingSize = remainingSize - mid - 1;
        }
        else {
            cout << " -> Cari di bagian kiri" << endl;
            end = midNode;
            remainingSize = mid;
        }
        
        iterasi++;
    }
    
    if(remainingSize == 0){
        cout << "Tidak ada elemen tersisa" << endl;
    }
    
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    return nullptr;
}

int main(){
    Node* head = nullptr;
    
    cout << "BINARY SEARCH PADA LINKED LIST" << endl;
    
    //Membuat linked list
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);
    
    cout << "Linked List yang dibuat: ";
    displayList(head);
    
    //Pencarian pertama: mencari nilai 40
    cout << "Mencari nilai: 40" << endl;
    Node* result1 = binarySearch(head, 40);
    
    //Pencarian kedua: mencari nilai 25
    cout << "Mencari nilai: 25" << endl;
    Node* result2 = binarySearch(head, 25);
    
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan5_modul5/output-unguided1-modul5.png)

Program ini adalah implementasi binary search pada linked list dalam bahasa C++. Struktur Node didefinisikan dengan data integer dan pointer next. Fungsi append menambahkan node baru di akhir linked list, sementara displayList menampilkan seluruh isi linked list dalam format "data -> data -> ... -> NULL". Fungsi binarySearch melakukan pencarian biner dengan menghitung ukuran linked list terlebih dahulu, lalu secara iteratif membagi rentang pencarian menjadi kiri atau kanan berdasarkan perbandingan nilai tengah dengan kunci yang dicari, sambil menampilkan detail proses setiap iterasi, termasuk nilai tengah, arah pencarian, dan hasil akhir (ditemukan atau tidak). Di fungsi main, program membuat linked list dengan nilai 10, 20, 30, 40, 50, dan 60, menampilkannya, lalu melakukan pencarian untuk nilai 40 (yang ditemukan) dan 25 (yang tidak ditemukan), dengan output yang menunjukkan alamat node, data, dan node berikutnya jika ada.


### 2. Soal Unguided 2
Implementasikan program C++ yang menggunakan algoritma Linear 
Search pada Linked List untuk mencari elemen tertentu. Program 
harus mampu: 
1. Membuat linked list dengan menambahkan node di akhir 
2. Mengimplementasikan linear search pada linked list 
3. Menampilkan detail proses pencarian dan hasil akhir

Petunjuk Tugas 2: 
• Gunakan struktur Node dengan data integer dan pointer next 
• Implementasikan fungsi append() untuk menambah node 
• Implementasikan fungsi linearSearch() yang mengembalikan pointer ke node yang ditemukan 
• Data dalam linked list tidak perlu terurut untuk linear search 
• Tampilkan setiap langkah pencarian dan node yang sedang diperiksa 
• Program utama harus membuat linked list dengan minimal 3 elemen dan melakukan pencarian

```C++
#include<iostream>
using namespace std;

//Definisi node
struct Node {
    int data;
    Node* next;
};

//Prosedur untuk menambahkan node di akhir
void append(Node*& head, int value){
    Node* newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

//Fungsi untuk menampilkan linked list
void displayList(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data;
        if(temp->next) cout << " -> ";
        else cout << " -> NULL";
        temp = temp->next;
    }
    cout << endl;
}

//Fungsi Linear Search dengan output detail
Node* linearSearch(Node* head, int key) {
    Node* current = head; //mulai dari node pertama
    int nodeNumber = 1; //nomor node yang diperiksa
    
    cout << "\nProses Pencarian:" << endl;
    
    //Iterasi melalui setiap node dalam linked list
    while (current != nullptr) {
        cout << "Memeriksa node " << nodeNumber << ": " << current->data;
        
        //Cek apakah data pada node saat ini sama dengan key
        if (current->data == key) {
            cout << " (SAMA) - DITEMUKAN!" << endl;
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << current << endl;
            cout << "Data node: " << current->data << endl;
            
            //Tampilkan node berikutnya jika ada
            if(current->next){
                cout << "Node berikutnya: " << current->next->data << endl;
            } else {
                cout << "Node berikutnya: NULL" << endl;
            }
            return current;
        } else {
            cout << " (tidak sama)" << endl;
        }
        
        //Pindah ke node berikutnya
        current = current->next;
        nodeNumber++;
    }
    
    //Jika sudah mencapai akhir list dan tidak ditemukan
    cout << "Tidak ada node lagi yang tersisa" << endl;
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    return nullptr;
}

int main(){
    Node* head = nullptr;
    
    cout << "LINEAR SEARCH PADA LINKED LIST" << endl;
    
    //Membuat linked list
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    
    cout << "Linked List yang dibuat: ";
    displayList(head);
    
    //Pencarian pertama: mencari nilai 30
    cout << "Mencari nilai: 30" << endl;
    Node* result1 = linearSearch(head, 30);
    
    //Pencarian kedua: mencari nilai 25
    cout << "Mencari nilai: 25" << endl;
    Node* result2 = linearSearch(head, 25);
    
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan5_modul5/output-unguided2-modul5.png)

Program ini adalah implementasi linear search pada linked list dalam bahasa C++. Struktur Node terdiri dari data integer dan pointer next. Fungsi append menambahkan node baru di akhir linked list, sedangkan displayList menampilkan isi linked list dalam format "data -> data -> ... -> NULL". Fungsi linearSearch melakukan pencarian linier dengan memulai dari node pertama, memeriksa setiap node secara berurutan, dan menampilkan detail proses seperti nomor node yang diperiksa, nilai data, serta apakah cocok dengan kunci pencarian. Jika ditemukan, fungsi mengembalikan pointer ke node tersebut beserta informasi alamat, data, dan node berikutnya; jika tidak, mengembalikan nullptr. Di fungsi main, program membuat linked list dengan nilai 10, 20, 30, 40, dan 50, menampilkannya, lalu melakukan pencarian untuk nilai 30 (yang ditemukan) dan 25 (yang tidak ditemukan), dengan output yang menunjukkan langkah-langkah pemeriksaan setiap node. 


## Kesimpulan
Operasi fundamental pada singly linked list (SLL) meliputi penambahan, penghapusan, pencarian (searching), dan pembaruan (updating) data, di mana updating merupakan kombinasi dari pencarian dan modifikasi nilai internal node tanpa mengubah struktur pointer. Pencarian pada SLL umumnya menggunakan Linear Search, yang menelusuri list secara sekuensial dari head, membandingkan data di setiap node dengan nilai yang dicari, dan berhenti jika ditemukan atau mencapai akhir list (NULL). Meskipun Binary Search lebih efisien untuk struktur data terurut dengan akses acak seperti array, algoritma ini tidak praktis untuk SLL karena kurangnya kemampuan akses acak, sehingga memerlukan penelusuran berulang yang menghilangkan keunggulannya dan membuatnya lebih lambat daripada Linear Search sederhana. 

## Referensi
[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.
<br>[2] Sahni, S. (2005). Data Structures, Algorithms, and Applications in C++ (2nd ed.). Silicon Press.
<br>[3] Malik, D. S. (2018). C++ Programming: From Problem Analysis to Program Design (8th ed.). Cengage Learning.
<br>[4] Lafore, R. (2002). Object-Oriented Programming in C++ (4th ed.). Sams Publishing.
<br>[5] Modul 5 - Praktikum Struktur Data
