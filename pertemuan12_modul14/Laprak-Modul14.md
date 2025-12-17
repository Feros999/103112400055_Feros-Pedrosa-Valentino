# <h1 align="center">Laporan Praktikum Modul 14 - GRAPH</h1>
<p align="center">Feros Pedrosa Valentino - 103112400055</p>

## Dasar Teori
Graph merupakan himpunan tidak kosong dari node (vertec) dan garis penghubung (edge)[1]. Secara lebih formal, struktur ini didefinisikan sebagai pasangan G = (V, E), di mana V adalah himpunan simpul (vertices) dan E adalah himpunan sisi (edges) yang menghubungkan pasangan simpul tersebut[2]. Contoh sederhana yang dapat menggambarkan konsep graph adalah hubungan lokasi antara tempat Kost dan Common Lab; di mana kedua tempat tersebut merepresentasikan node (vertec), sedangkan jalan yang menghubungkan keduanya merupakan garis penghubung (edge)[1]. Dalam penerapannya yang lebih luas, graph digunakan untuk memodelkan hubungan antar objek yang kompleks, seperti analisis jaringan sosial, pemetaan rute terpendek, hingga topologi jaringan komputer[3].Berdasarkan arah hubungannya, graph dapat dibedakan menjadi dua jenis utama. Pertama adalah Graph Berarah (Directed Graph), yaitu graph di mana setiap node memiliki edge yang mempunyai arah spesifik ke node lain yang dituju[1]. Kedua adalah Graph Tidak Berarah (Undirected Graph), di mana edge menghubungkan antar node tanpa memiliki arah tertentu, sehingga hubungan berlaku dua arah secara otomatis[1]. Selain arah, ketetanggaan juga menjadi konsep penting; suatu node dikatakan bertetangga dengan node lain jika keduanya dihubungkan langsung oleh sebuah edge[1].Untuk merepresentasikan graph dalam pemrograman, terdapat dua metode umum yaitu menggunakan Adjacency Matrix (Array 2 Dimensi) dan Multi Linked List. Representasi matriks menggunakan array n x n untuk memetakan hubungan, sementara Multi Linked List lebih dinamis dan sering digunakan untuk efisiensi memori pada graph yang kompleks[1]. Dalam proses pengolahan data graph, metode penelusuran (traversal) menjadi elemen krusial, yang terdiri dari Breadth First Search (BFS) dan Depth First Search (DFS). BFS melakukan pencarian melebar dengan mengunjungi node tetangga pada level yang sama terlebih dahulu (menggunakan konsep Queue), sedangkan DFS melakukan pencarian mendalam pada satu cabang sebelum kembali (backtracking) ke cabang lain (menggunakan konsep Stack)[4].


## Guided 

### 1. Guided 1

graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

// Prototypes
void createGraph(Graph &G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif
```
graph_edge.cpp
```C++
#include "graph.h"

adrNode findNode(Graph G, infoGraph X){
    adrNode P = G.first;
    while(P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void connectNode (Graph &G, infoGraph start, infoGraph end){
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge;
        pStart->firstEdge = newEdge;
    }
}
```
graph_init.cpp
```C++
#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocateNode (infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void insertNode (Graph &G, infoGraph X) {
    adrNode P = allocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
```
graph_print.cpp
```C++
#include "graph.h"

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}   
```
main.cpp
```C++
#include "graph.h"
#include <iostream>

using namespace std;

int main(){
    Graph G;
    createGraph(G);

    // Menambahkan Node
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    // Menghubungkan Node
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}
```
Program tersebut merupakan implementasi struktur data Graph Berarah (Directed Graph) menggunakan representasi Multi Linked List (Adjacency List). Struktur utamanya didefinisikan dalam graph.h, di mana setiap ElmNode (simpul) memiliki pointer ke node berikutnya dalam daftar utama serta pointer ke ElmEdge (sisi) pertama yang dimilikinya. Manajemen memori dan pembuatan node ditangani oleh graph_init.cpp, sedangkan logika penghubungan antar node berada di graph_edge.cpp; fungsi connectNode bekerja dengan mencari alamat node asal dan tujuan, lalu menambahkan edge baru di awal list (insert first) milik node asal. File main.cpp mendemonstrasikan pembentukan graph dengan menyisipkan node 'A' hingga 'D', menghubungkannya (seperti A ke B), dan menampilkan seluruh koneksi tersebut ke layar menggunakan fungsi traversal yang ada di graph_print.cpp.


## Unguided 

### 1. Soal Unguided 1
Buatlah ADT Graph tidak berarah file “graph.h”:
Type infoGraph: char
Type adrNode : pointer to ElmNode
Type adrEdge : pointer to ElmNode
Type ElmNode <
info : infoGraph
visited : integer
firstEdge : adrEdge
Next : adrNode
>
Type ElmEdge <
Node : adrNode
Next : adrEdge
>
Type Graph <
first : adrNode
>
procedure CreateGraph (input/output G : Graph)
procedure InsertNode (input/output G : Graph,
input X : infotype)
procedure ConnectNode (input/output N1, N2 : adrNode)
procedure PrintInfoGraph (input G : Graph)

Buatlah implementasi ADT Graph pada file “graph.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”.

graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

// Definisi Tipe Data
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

adrNode FindNode(Graph G, infoGraph X);

#endif
```
graph.cpp
```C++
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    // Alokasi Node Baru
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode temp = G.first;
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = P;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        // Karena Graph Tidak Berarah, buat edge dua arah.
        
        // 1. Buat Edge dari N1 ke N2
        adrEdge E1 = new ElmEdge;
        E1->Node = N2;
        E1->Next = N1->firstEdge; // Insert First pada list edge N1
        N1->firstEdge = E1;

        // 2. Buat Edge dari N2 ke N1
        adrEdge E2 = new ElmEdge;
        E2->Node = N1;
        E2->Next = N2->firstEdge; // Insert First pada list edge N2
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung dengan: ";
        adrEdge E = P->firstEdge;
        if (E == NULL) {
            cout << "(tidak ada)";
        }
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->Next;
    }
    return NULL;
}
```
main.cpp
```C++
#include <iostream>
#include "graph.h"
#include "graph.cpp"

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    cout << "=== Menambahkan Node A-H ===" << endl;
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode G_node = FindNode(G, 'G'); // Nama variabel G_node agar tidak bentrok dengan Graph G
    adrNode H = FindNode(G, 'H');

    cout << "=== Menghubungkan Edge sesuai Ilustrasi ===" << endl;
    ConnectNode(A, B);
    ConnectNode(A, C);

    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, G_node);

    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(G_node, H);

    cout << endl << "=== Tampilan Adjacency List Graph ===" << endl;
    PrintInfoGraph(G);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan12_modul14/output-unguided1-modul14.png)

Program ini mengimplementasikan struktur data Graf Tidak Berarah (Undirected Graph) menggunakan representasi Adjacency List (Senarai Ketetanggaan). Pada file graph.h, didefinisikan tiga struktur utama yaitu ElmNode, ElmEdge, dan Graph. Struktur ElmNode merepresentasikan sebuah simpul (vertex) yang menyimpan informasi karakter (info), status kunjungan (visited), pointer ke edge pertama (firstEdge), dan pointer ke node berikutnya (Next). Struktur ElmEdge merepresentasikan hubungan (garis) antar simpul yang menyimpan pointer ke node tujuan dan pointer ke edge selanjutnya. Terakhir, struktur Graph bertindak sebagai pembungkus utama yang menyimpan pointer first yang menunjuk ke node pertama dalam graf.
Pada file graph.cpp, fungsi CreateGraph digunakan untuk menginisialisasi graf kosong dengan mengatur pointer first menjadi NULL. Prosedur InsertNode bertugas menambahkan simpul baru ke dalam graf. Prosedur ini mengalokasikan memori untuk node baru, mengisi datanya, dan menyisipkannya ke dalam list node. Logika penyisipan yang digunakan adalah Insert Last (menyisipkan di akhir), di mana program akan menelusuri list node hingga menemukan elemen terakhir (Next == NULL) baru kemudian menyambungkan node baru tersebut. Hal ini menjaga urutan node sesuai dengan urutan pemanggilannya di fungsi main (A, B, C, dst).
Prosedur ConnectNode memegang peranan vital dalam menghubungkan dua simpul. Karena ini adalah graf tidak berarah, koneksi bersifat dua arah (simetris). Ketika menghubungkan node N1 dan N2, prosedur ini akan membuat dua objek ElmEdge baru yaitu satu edge ditambahkan ke daftar edge milik N1 (menunjuk ke N2) dan satu lagi ditambahkan ke daftar edge milik N2 (menunjuk ke N1). Metode penyisipan edge menggunakan logika Insert First, yang berarti edge baru selalu diletakkan di awal daftar ketetanggaan node tersebut agar prosesnya lebih cepat. Terdapat fungsi bantuan FindNode yang berfungsi untuk mencari alamat memori (pointer) dari sebuah node berdasarkan karakter info-nya (misalnya mencari node 'A'). Fungsi ini melakukan pencarian linear dari node pertama hingga node ditemukan. Selain itu, prosedur PrintInfoGraph digunakan untuk menampilkan struktur graf ke layar. Prosedur ini bekerja dengan menggunakan nested loop (perulangan bersarang) yaitu loop luar menelusuri setiap node dalam graf, sedangkan loop dalam menelusuri seluruh edge yang dimiliki oleh node tersebut untuk mencetak daftar tetangganya.
Pada file main.cpp, seluruh komponen disatukan untuk membentuk topologi graf tertentu. Program dimulai dengan membuat graf kosong, lalu memasukkan 8 node (A hingga H). Setelah node dibuat, program menggunakan FindNode untuk mendapatkan pointer dari setiap node tersebut agar bisa dihubungkan. Selanjutnya, fungsi ConnectNode dipanggil berulang kali untuk membentuk struktur graf sesuai ilustrasi (A terhubung ke B dan C, B ke D dan E, dan seterusnya hingga semua bermuara ke H). Terakhir, PrintInfoGraph dipanggil untuk mencetak hasil adjacency list yang telah terbentuk.

### 2. Soal Unguided 2
Buatlah prosedur untuk menampilkanhasil penelusuran DFS.
prosedur PrintDFS (Graph G, adrNode N);

graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

// Definisi Tipe Data
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode first;
};

// Prosedur dan Fungsi sesuai soal
void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);


void PrintDFS(Graph G, adrNode N);
// Helper untuk mereset status visited sebelum DFS dijalankan
void ResetVisited(Graph G);

adrNode FindNode(Graph G, infoGraph X);

#endif
```
graph.cpp
```C++
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    // Alokasi Node Baru
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode temp = G.first;
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = P;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        // Karena Graph Tidak Berarah, buat edge dua arah.
        
        // 1. Buat Edge dari N1 ke N2
        adrEdge E1 = new ElmEdge;
        E1->Node = N2;
        E1->Next = N1->firstEdge; // Insert First pada list edge N1
        N1->firstEdge = E1;

        // 2. Buat Edge dari N2 ke N1
        adrEdge E2 = new ElmEdge;
        E2->Node = N1;
        E2->Next = N2->firstEdge; // Insert First pada list edge N2
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung dengan: ";
        adrEdge E = P->firstEdge;
        if (E == NULL) {
            cout << "(tidak ada)";
        }
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

// Fungsi tambahan untuk mencari pointer node berdasarkan Char
adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->Next;
    }
    return NULL;
}

// Helper: Reset status visited semua node menjadi 0
void ResetVisited(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}

// Algoritma DFS (Rekursif)
void PrintDFS(Graph G, adrNode N) {
    if (N == NULL) {
        return;
    }

    // 1. Tandai node saat ini sudah dikunjungi
    N->visited = 1;
    
    // 2. Tampilkan info node
    cout << N->info << " ";

    // 3. Kunjungi semua tetangga (Neighbor)
    adrEdge E = N->firstEdge;
    while (E != NULL) {
        // Jika tetangga belum dikunjungi, lakukan DFS ke tetangga tersebut (Rekursif)
        if (E->Node->visited == 0) {
            PrintDFS(G, E->Node);
        }
        E = E->Next;
    }
}
```
main.cpp
```C++
#include <iostream>
#include "graph.h"
#include "graph.cpp"

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    cout << "=== Menambahkan Node A-H ===" << endl;
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode G_node = FindNode(G, 'G'); // Nama variabel G_node agar tidak bentrok dengan Graph G
    adrNode H = FindNode(G, 'H');

    cout << "=== Menghubungkan Edge sesuai Ilustrasi ===" << endl;
    ConnectNode(A, B);
    ConnectNode(A, C);

    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, G_node);

    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(G_node, H);

    cout << endl << "=== Tampilan Adjacency List Graph ===" << endl;
    PrintInfoGraph(G);

    cout << endl << "=== Hasil Penelusuran DFS ===" << endl;
    
    // Misal mulai DFS dari Node 'A'
    adrNode startNode = FindNode(G, 'A');
    
    // Pastikan reset dulu sebelum mulai
    ResetVisited(G); 
    
    cout << "Start dari Node A: ";
    PrintDFS(G, startNode);
    cout << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan12_modul14/output-unguided2-modul14.png)

Pada file graph.h, didefinisikan struktur utama yang membangun graf tersebut. Struktur ElmNode merepresentasikan sebuah simpul (vertex) yang menyimpan karakter (info), penanda status kunjungan (visited), pointer ke edge pertama (firstEdge), serta pointer ke node berikutnya dalam senarai. Struktur ElmEdge merepresentasikan sisi (garis hubung) yang menyimpan pointer ke node tujuan (Node) dan pointer ke edge berikutnya. Struktur Graph bertindak sebagai pembungkus yang menyimpan pointer ke node awal (first).
Pada file graph.cpp, fungsi InsertNode bertugas menambahkan simpul baru ke dalam graf. Node baru dialokasikan ke memori dan disisipkan di akhir node (Insert Last) agar urutan node (A, B, C...) tetap terjaga sesuai input. Fungsi ConnectNode menghubungkan dua simpul. Karena ini adalah graf tidak berarah, fungsi ini menciptakan hubungan dua arah (simetris) yaitu edge dibuat dari N1 ke N2, dan sebaliknya dari N2 ke N1. Penambahan edge ini dilakukan dengan metode Insert First (disisipkan di awal list edge) untuk efisiensi waktu eksekusi. Fungsi bantuan FindNode digunakan untuk mencari alamat memori suatu node berdasarkan label karakternya agar node-node tersebut dapat dihubungkan.
Fitur utama yang ditambahkan dalam kode ini adalah algoritma Depth First Search (DFS) melalui prosedur PrintDFS. Algoritma ini bekerja secara rekursif untuk menelusuri graf mendalam ke satu cabang sebelum kembali (backtracking). Prosedur ini mengecek apakah node saat ini sudah dikunjungi menggunakan flag visited. Jika belum, node tersebut ditandai, dicetak, dan fungsi akan memanggil dirinya sendiri secara rekursif untuk mengunjungi semua tetangga node tersebut yang belum dikunjungi. Terdapat juga prosedur ResetVisited yang krusial untuk mengembalikan status visited seluruh node menjadi 0 (belum dikunjungi) sebelum algoritma DFS dijalankan, memastikan penelusuran dimulai dengan status yang bersih.
Pada file main.cpp, seluruh komponen disatukan untuk membentuk topologi graf tertentu. Program dimulai dengan inisialisasi graf dan penyisipan node A hingga H. Setelah node dibuat, program menghubungkan node-node tersebut menggunakan ConnectNode sesuai dengan pola yang ditentukan (misalnya A terhubung ke B dan C, lalu berlanjut hingga bermuara ke H). Program kemudian menampilkan struktur graf dalam bentuk adjacency list menggunakan PrintInfoGraph. Terakhir, program mereset status kunjungan dan menjalankan algoritma DFS dimulai dari node 'A', yang akan menghasilkan urutan penelusuran simpul berdasarkan kedalaman hubungan antar node tersebut.

### 3. Soal Unguided 3
Buatlah prosedur untuk menampilkanhasil penelusuran DFS.
prosedur PrintBFS (Graph G, adrNode N);

graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <queue>
using namespace std;

// Definisi Tipe Data
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);


void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);
// Helper untuk mereset status visited sebelum DFS dijalankan
void ResetVisited(Graph G);

adrNode FindNode(Graph G, infoGraph X);

#endif
```
graph.cpp
```C++
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    // Alokasi Node Baru
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode temp = G.first;
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = P;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        // Karena Graph Tidak Berarah, kita buat edge dua arah.
        
        // 1. Buat Edge dari N1 ke N2
        adrEdge E1 = new ElmEdge;
        E1->Node = N2;
        E1->Next = N1->firstEdge; // Insert First pada list edge N1
        N1->firstEdge = E1;

        // 2. Buat Edge dari N2 ke N1
        adrEdge E2 = new ElmEdge;
        E2->Node = N1;
        E2->Next = N2->firstEdge; // Insert First pada list edge N2
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung dengan: ";
        adrEdge E = P->firstEdge;
        if (E == NULL) {
            cout << "(tidak ada)";
        }
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

// Fungsi tambahan untuk mencari pointer node berdasarkan Char
adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->Next;
    }
    return NULL;
}

// Helper: Reset status visited semua node menjadi 0
void ResetVisited(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N == NULL) {
        return;
    }

    // 1. Tandai node saat ini sudah dikunjungi
    N->visited = 1;
    
    // 2. Tampilkan info node
    cout << N->info << " ";

    // 3. Kunjungi semua tetangga (Neighbor)
    adrEdge E = N->firstEdge;
    while (E != NULL) {
        // Jika tetangga belum dikunjungi, lakukan DFS ke tetangga tersebut (Rekursif)
        if (E->Node->visited == 0) {
            PrintDFS(G, E->Node);
        }
        E = E->Next;
    }
}

void PrintBFS(Graph G, adrNode N) {
    if (N == NULL) {
        return;
    }

    // Siapkan Queue untuk menyimpan pointer node
    queue<adrNode> Q;

    // 1. Masukkan node awal ke antrean dan tandai visited
    N->visited = 1;
    Q.push(N);

    // 2. Loop selama antrean tidak kosong
    while (!Q.empty()) {
        // Ambil node paling depan dari antrean
        adrNode current = Q.front();
        Q.pop();

        // Tampilkan info node
        cout << current->info << " ";

        // 3. Masukkan semua tetangga yang belum dikunjungi ke antrean
        adrEdge E = current->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                // Penting: Tandai visited SAAT dimasukkan ke queue
                // agar tidak masuk ganda dari jalur lain
                E->Node->visited = 1; 
                Q.push(E->Node);
            }
            E = E->Next;
        }
    }
}
```
main.cpp
```C++
#include <iostream>
#include "graph.h"
#include "graph.cpp"

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    cout << "=== Menambahkan Node A-H ===" << endl;
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode G_node = FindNode(G, 'G'); // Nama variabel G_node agar tidak bentrok dengan Graph G
    adrNode H = FindNode(G, 'H');

    cout << "=== Menghubungkan Edge sesuai Ilustrasi ===" << endl;
    ConnectNode(A, B);
    ConnectNode(A, C);

    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, G_node);

    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(G_node, H);

    cout << endl << "=== Tampilan Adjacency List Graph ===" << endl;
    PrintInfoGraph(G);

    cout << endl << "=== Hasil Penelusuran DFS ===" << endl;
    
    // Misal mulai DFS dari Node 'A'
    adrNode startNode = FindNode(G, 'A');
    
    // Pastikan reset dulu sebelum mulai
    ResetVisited(G); 
    
    cout << "Start dari Node A: ";
    PrintDFS(G, startNode);
    cout << endl;

    cout << endl << "=== Hasil Penelusuran BFS ===" << endl;
    
    // Reset visited agar bersih sebelum mulai BFS
    ResetVisited(G);

    // Mulai BFS dari Node A
    startNode = FindNode(G, 'A');
    
    cout << "Start dari Node A: ";
    PrintBFS(G, startNode);
    cout << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan12_modul14/output-unguided3-modul14.png)

Pada file graph.h, terdapat penambahan library <queue> untuk implementasi algoritma BFS. Struktur data utamanya terdiri dari ElmNode yang merepresentasikan simpul (vertex) dan ElmEdge yang merepresentasikan sisi (edge). Setiap ElmNode memiliki atribut info (data karakter), firstEdge (pointer ke daftar tetangga), Next (pointer ke node berikutnya dalam graf), dan atribut penting bernama visited. Atribut visited bertipe integer yang berfungsi sebagai penanda ("flag") untuk melacak apakah node tersebut sudah dikunjungi atau belum selama proses penelusuran (traversal).
Pada file graph.cpp, fungsi InsertNode digunakan untuk membentuk graf dengan menambahkan node baru di akhir senarai (Insert Last) agar urutan abjad A-H terjaga. Fungsi ConnectNode bertugas menghubungkan dua node. Karena sifat graf ini tidak berarah, fungsi ini membuat hubungan simetris yaitu jika A dihubungkan ke B, maka sistem akan membuat edge dari A ke B dan juga dari B ke A. Penambahan edge ini dilakukan dengan metode Insert First (disisipkan di awal list edge) untuk efisiensi performa. Terdapat juga fungsi ResetVisited yang sangat penting; fungsi ini mengiterasi seluruh node dan mengembalikan nilai visited menjadi 0. Hal ini wajib dilakukan di antara pemanggilan algoritma pencarian yang berbeda (misalnya setelah DFS selesai dan sebelum BFS dimulai) agar penelusuran berikutnya berjalan seolah-olah graf belum pernah disentuh.
Program ini mengimplementasikan dua metode penelusuran utama. Pertama, DFS (Depth First Search) pada prosedur PrintDFS bekerja secara rekursif. Algoritma ini menelusuri satu cabang sedalam mungkin; ia menandai node saat ini, mencetaknya, lalu memanggil dirinya sendiri untuk setiap tetangga yang belum dikunjungi. Kedua, BFS (Breadth First Search) pada prosedur PrintBFS bekerja secara melebar (level-order) menggunakan struktur data Queue. Logikanya dimulai dengan memasukkan node awal ke antrean. Selama antrean tidak kosong, node paling depan diambil (dequeue) dan dicetak. Kemudian, seluruh tetangga node tersebut yang belum dikunjungi akan ditandai dan dimasukkan ke dalam antrean (enqueue). Pendekatan ini menjamin node-node yang lebih dekat dengan titik awal akan diproses terlebih dahulu dibandingkan node yang lebih jauh.
Pada main.cpp dimulai dengan pembentukan graf yang memuat node A hingga H, program kemudian menghubungkan node-node tersebut sesuai topologi yang diinginkan. Setelah menampilkan bentuk dasar graf melalui Adjacency List, program mendemonstrasikan kedua algoritma penelusuran. Program pertama kali mereset status visited, lalu menjalankan DFS dari node A yang menghasilkan urutan berdasarkan kedalaman jalur. Selanjutnya, program kembali mereset status visited dan menjalankan BFS dari node A, yang menghasilkan urutan penelusuran berdasarkan lapisan/level jarak dari node awal. Penggunaan variabel pointer startNode digunakan ulang untuk menunjuk titik awal penelusuran tanpa melakukan redeklarasi variabel yang dapat menyebabkan error.

## Kesimpulan
Graph merupakan struktur data fundamental yang memodelkan hubungan antar objek melalui himpunan node dan edge, yang diklasifikasikan menjadi graph berarah (directed) dan tidak berarah (undirected). Fleksibilitas struktur ini memungkinkan implementasi pemrograman melalui dua pendekatan utama, yaitu Array 2 Dimensi (Adjacency Matrix) untuk pemetaan statis atau Multi Linked List untuk penanganan data yang lebih dinamis dan efisien. Selain itu, pengolahan data dalam graph sangat bergantung pada pemahaman metode penelusuran, baik menggunakan Breadth First Search (BFS) yang berorientasi pada keluasan level maupun Depth First Search (DFS) yang berorientasi pada kedalaman cabang.

## Referensi
[1] Modul 14 - Praktikum Struktur Data
<br>[2] Trivusi. (2022). Struktur Data Graph: Pengertian, Jenis, dan Kegunaannya. Trivusi Web Resource.
<br>[3] Putra, R. L. S., Sandy, M., & Putri, A. A. (2025). "Implementasi Teori Graf dan Optimisasi Algoritma Dijkstra, BFS dan DFS Dalam Menentukan Jalur Terpendek Jaringan Toko Mixue Di Jabodetabek Berbasis Google Maps". Jurnal Multimedia dan Teknologi Informasi (Jatilima), 7(3), 619-629.
<br>[4] Muhardono, A. (2023). "Penerapan Algoritma Breadth First Search dan Depth First Search pada Game Angka". Jurnal Minfo Polgan, 12(1), 171-182.
