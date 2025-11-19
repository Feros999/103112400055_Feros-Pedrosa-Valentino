# <h1 align="center">Laporan Praktikum Modul 8 - Queue</h1>
<p align="center">Feros Pedrosa Valentino - 103112400055</p>

## Dasar Teori
Queue (dibaca kyu) merupakan struktur data linear yang dapat diumpamakan seperti sebuah antrean, contohnya adalah antrean pada loket pembelian tiket Kereta Api. Prinsip dasar dalam Queue adalah FIFO (First In First Out), di mana orang atau data yang pertama kali masuk dalam antrean akan mendapatkan pelayanan atau akses terlebih dahulu, sedangkan yang terakhir masuk akan mendapatkan layanan terakhir pula [1]. Konsep ini berbeda dengan Stack, dan dalam ilmu komputer, prinsip antrean ini diterapkan secara luas, mulai dari simulasi antrean pelanggan hingga manajemen buffer data pada sistem operasi [2].Dalam operasionalnya, terdapat dua operasi utama pada Queue, yaitu operasi penyisipan (Insert atau Enqueue) dan operasi pengambilan (Delete atau Dequeue). Sesuai dengan sifat FIFO, proses delete hanya dilakukan pada bagian Head (depan list) dan proses insert selalu dilakukan pada bagian Tail (belakang list) [1]. Hal ini memastikan bahwa urutan data tetap terjaga sesuai waktu kedatangannya. Kompleksitas waktu untuk operasi dasar ini umumnya adalah O(1), yang berarti waktu eksekusinya konstan dan tidak bergantung pada banyaknya elemen dalam antrean [3].Implementasi struktur Queue dalam bahasa C++ dapat dilakukan menggunakan dua pendekatan, yaitu menggunakan tipe data array (tabel) maupun linked list. Perbedaan yang mendasar antara representasi tabel dan pointer (linked list) adalah pada manajemen memori serta keterbatasan jumlah antreannya [1]. Implementasi menggunakan array memiliki ukuran statis yang tetap, sedangkan linked list bersifat dinamis dan dapat berkembang sesuai ketersediaan memori sistem [2].Khusus untuk implementasi menggunakan tabel (array), terdapat tantangan efisiensi saat menangani pergeseran indeks. Untuk mengatasinya, digunakan strategi di mana tabel memiliki representasi Head dan Tail yang "berputar" mengelilingi indeks tabel dari awal sampai akhir, kemudian kembali ke awal. Strategi pemakaian tabel semacam ini sering disebut sebagai "circular buffer", di mana tabel penyimpan elemen dianggap sebagai buffer yang bersambung [1].


## Guided 

### 1. Guided 1

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct queue{
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int data);

#endif
```
queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```
main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Queue setelah deQueue 2 kali ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah update ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);

    return 0;
}
```

Program di atas merupakan implementasi struktur data antrian (queue) menggunakan linked list. Pada file queue.h, didefinisikan struktur node yang menyimpan data integer (dataAngka) dan pointer ke node berikutnya (next), serta struktur queue dengan pointer head dan tail untuk menunjukkan awal dan akhir antrian. File queue.cpp berisi implementasi berbagai fungsi, seperti isEmpty untuk memeriksa apakah antrian kosong, createQueue untuk inisialisasi antrian, alokasi untuk membuat node baru, dealokasi untuk menghapus node, enQueue untuk menambahkan elemen di akhir antrian, deQueue untuk menghapus elemen dari depan antrian, updateQueue untuk mengubah data pada posisi tertentu, viewQueue untuk menampilkan isi antrian, dan searchData untuk mencari data spesifik. Fungsi-fungsi ini menggunakan pointer untuk navigasi linked list, dengan penanganan kasus khusus seperti antrian kosong atau posisi tidak valid.
Pada file main.cpp, program utama mendemonstrasikan penggunaan antrian dengan membuat objek queue, mengalokasikan lima node dengan nilai 1 hingga 5, lalu menambahkannya ke antrian menggunakan enQueue. Setelah itu, dilakukan deQueue dua kali untuk menghapus elemen pertama dan kedua, diikuti dengan updateQueue pada posisi 2 dan 1 (berhasil), serta posisi 4 (gagal karena posisi tidak valid). Terakhir, viewQueue menampilkan isi antrian yang tersisa, dan searchData mencari nilai 4 (ditemukan) serta 9 (tidak ditemukan). 

### 2. Guided 2

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);

bool isEmpty(Queue Q);

bool isFull(Queue Q);

void enQueue(Queue &Q, int x);

int deQueue(Queue &Q);

void printInfo(Queue Q);

#endif
```
queue.cpp
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```
main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

// Fungsi utama program
int main() {
    Queue Q;

    createQueue(Q);
    printInfo(Q);
    
    cout << "\n Enqueue 3 Elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    
    cout << "\n Dequeue 1 Elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);
    
    cout << "\n Enqueue 1 Elemen" << endl;
    enqueue(Q, 4);
    printInfo(Q);

    cout << "\n Dequeue 2 Elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}
```

Program di atas merupakan implementasi struktur data antrian (queue) menggunakan array circular, dengan kapasitas maksimal 5 elemen. Pada file queue.h, didefinisikan struktur Queue yang terdiri dari array info untuk menyimpan data integer, indeks head dan tail untuk menunjukkan posisi awal dan akhir antrian, serta count untuk menghitung jumlah elemen. File queue.cpp berisi implementasi fungsi-fungsi utama, seperti createQueue untuk inisialisasi antrian dengan mengatur head, tail, dan count ke 0, isEmpty dan isFull untuk memeriksa kondisi antrian berdasarkan count, enqueue untuk menambahkan elemen di posisi tail dengan pergeseran circular menggunakan modulo MAX_QUEUE, serta dequeue untuk menghapus dan mengembalikan elemen dari head dengan pergeseran serupa. Fungsi printInfo menampilkan isi antrian dengan iterasi circular dari head sebanyak count elemen.
Pada file main.cpp, program utama mendemonstrasikan operasi antrian dengan membuat objek Queue, menginisialisasinya, dan menampilkan isi awal (kosong). Kemudian, dilakukan enqueue tiga elemen (5, 2, 7), diikuti dequeue satu elemen (keluar 5), enqueue satu elemen lagi (4), dan dequeue dua elemen (keluar 2 dan 7), dengan output yang menunjukkan perubahan isi antrian setelah setiap operasi.


## Unguided 

### 1. Soal Unguided 1
Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”:
Type infotype: integer
Type Queue: <
info : array [5] of infotype {index array dalam C++
dimulai dari 0}
head, tail : integer
>
procedure CreateQueue (input/output Q: Queue)
function isEmptyQueue (Q: Queue) → boolean
function isFullQueue (Q: Queue) → boolean
procedure enqueue (input/output Q: Queue, input x: infotype)
function dequeue (input/output Q: Queue) → infotype
procedure printInfo (input Q: Queue)

Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).
int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);

    cout<< "----------------------" << endl;
    cout<< " H- T \t | Queue info" << endl;
    cout<< "----------------------" << endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
queue.cpp
```C++
#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == 4);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1;
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        x = Q.info[Q.head];
        if (Q.head == Q.tail) {
            // Queue menjadi kosong
            Q.head = -1;
            Q.tail = -1;
        } else {
            // Geser semua elemen ke kiri (head tetap di 0)
            for (int i = Q.head; i < Q.tail; i++) {
                Q.info[i] = Q.info[i + 1];
            }
            Q.tail--;
        }
    }
    return x;
}

void printInfo(Queue Q) {
    cout << " " << Q.head << " - " << Q.tail << " \t | ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i];
            if (i < Q.tail) {
                cout << " ";
            }
        }
    }
    cout << endl;
}
```
main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue Info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan8_modul8/output-unguided1-modul8.png)

Implementasi Queue dalam program ini menggunakan struktur data array dengan ukuran tetap 5 elemen, diwakili oleh struct Queue yang memiliki array info[5], serta indeks head dan tail untuk menandai posisi awal dan akhir antrean. Fungsi createQueue menginisialisasi head dan tail ke -1 untuk menandai queue kosong, sedangkan isEmptyQueue memeriksa kondisi tersebut dan isFullQueue mengecek apakah tail telah mencapai indeks maksimal 4. Operasi enqueue menambahkan elemen baru di posisi tail, menangani kasus queue kosong dengan mengatur head dan tail ke 0, serta mencegah penambahan jika penuh. Sebaliknya, dequeue menghapus elemen dari head, mengembalikan nilainya, dan jika queue tidak kosong, menggeser semua elemen ke kiri untuk menjaga urutan, kemudian mengurangi tail; jika hanya satu elemen, queue direset ke kosong. Fungsi printInfo menampilkan nilai head dan tail serta isi array dari head hingga tail, atau "empty queue" jika kosong. Dalam main.cpp, program mendemonstrasikan operasi ini dengan membuat queue, menambahkan elemen (5, 2, 7), menghapus beberapa, dan mencetak status setelah setiap operasi untuk menunjukkan perilaku FIFO.

### 2. Soal Unguided 2
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
queue.cpp
```C++
#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = 0;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == Q.tail);
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % 5 == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        Q.info[Q.tail] = x;
        Q.tail = (Q.tail + 1) % 5;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1;
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        x = Q.info[Q.head];
        Q.head = (Q.head + 1) % 5;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << " " << Q.head << " - " << Q.tail << " \t | ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        int i = Q.head;
        while (true) {
            cout << Q.info[i];
            if (i == Q.tail - 1 || (Q.tail == 0 && i == 4)) break; // Adjust for circular
            cout << " ";
            i = (i + 1) % 5;
        }
    }
    cout << endl;
}
```
main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue Info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan8_modul8/output-unguided2-modul8.png)

Implementasi Queue dalam program ini menggunakan pendekatan circular buffer dengan array berukuran tetap 5 elemen, diwakili oleh struct Queue yang memiliki array info[5] serta indeks head dan tail yang berputar menggunakan operasi modulo 5 untuk menghindari pergeseran elemen. Fungsi createQueue menginisialisasi head dan tail ke 0, menandai queue kosong, sedangkan isEmptyQueue memeriksa apakah head sama dengan tail, dan isFullQueue mengecek kondisi (tail + 1) % 5 == head untuk mencegah overflow. Operasi enqueue menambahkan elemen baru di posisi tail, kemudian menggeser tail dengan (tail + 1) % 5 jika tidak penuh, sementara dequeue mengambil elemen dari head, menggeser head dengan (head + 1) % 5 jika tidak kosong, dan mengembalikan nilai elemen atau -1 jika kosong. Fungsi printInfo menampilkan nilai head dan tail serta isi array secara circular dari head hingga sebelum tail, menangani kasus kosong dengan "empty queue". Dalam main.cpp, program mendemonstrasikan operasi ini dengan membuat queue, menambahkan elemen (5, 2, 7), menghapus beberapa, dan mencetak status setelah setiap langkah untuk mengilustrasikan prinsip FIFO.

### 3. Soal Unguided 3
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

const int MAX = 5;

struct Queue {
infotype info[MAX];
int head;
int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.head == 0 && Q.tail == MAX - 1) || (Q.tail + 1 == Q.head));
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX;
    }

    return x;
}

void printInfo(Queue Q) {
    cout << " " << Q.head << " - " << Q.tail << " \t | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        int i = Q.head;
        while (true) {
            cout << Q.info[i];
            if (i == Q.tail) break;
            cout << " ";
            i = (i + 1) % MAX;
        }
    }
    cout << endl;
}
```
main.cpp
```C++
// ==== main.cpp ====
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue Info" << endl;
    cout << "----------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);  printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan8_modul8/output-unguided3-modul8.png)

Implementasi Queue dalam program ini menggunakan pendekatan circular buffer dengan array berukuran tetap 5 elemen, diwakili oleh struct Queue yang memiliki array info[MAX], indeks head, dan tail yang berputar menggunakan operasi modulo MAX untuk efisiensi ruang. Fungsi createQueue menginisialisasi head dan tail ke -1 untuk menandai queue kosong, sedangkan isEmptyQueue memeriksa kondisi head == -1, dan isFullQueue mengecek dua kondisi: ketika head di 0 dan tail di MAX-1, atau ketika tail + 1 sama dengan head untuk mencegah overlap. Operasi enqueue menambahkan elemen baru di posisi tail, menangani kasus kosong dengan mengatur head dan tail ke 0, kemudian menggeser tail dengan (tail + 1) % MAX jika tidak penuh, sementara dequeue mengambil elemen dari head, mengembalikannya, dan jika queue menjadi kosong (head == tail), mereset indeks ke -1, atau menggeser head dengan (head + 1) % MAX. Fungsi printInfo menampilkan nilai head dan tail serta isi array secara circular dari head hingga tail, menangani kasus kosong dengan "empty queue". Dalam main.cpp, program mendemonstrasikan operasi ini dengan membuat queue, menambahkan elemen (5, 2, 7), menghapus beberapa, dan mencetak status setelah setiap langkah untuk menunjukkan prinsip FIFO.

## Kesimpulan
Queue merupakan struktur data linear yang mengikuti prinsip FIFO (First In First Out), di mana elemen yang pertama masuk akan keluar terlebih dahulu, berbeda dengan Stack, dan diterapkan dalam berbagai aplikasi seperti simulasi antrean atau manajemen buffer data. Operasi utamanya adalah Enqueue untuk penyisipan di bagian Tail dan Dequeue untuk pengambilan di bagian Head, dengan kompleksitas waktu O(1). Implementasi dapat menggunakan array yang bersifat statis atau linked list yang dinamis, di mana array menghadapi tantangan efisiensi indeks yang diatasi melalui strategi circular buffer untuk memungkinkan rotasi indeks secara berputar.

## Referensi
[1] Modul 8 - Praktikum Struktur Data
<br>[2] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). Cambridge: MIT Press.
<br>[3] GeeksforGeeks. (2024). Queue Data Structure. Diakses dari https://www.geeksforgeeks.org/queue-data-structure/
