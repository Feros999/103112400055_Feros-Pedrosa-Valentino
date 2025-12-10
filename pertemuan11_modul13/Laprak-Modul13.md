# <h1 align="center">Laporan Praktikum Modul 13 - MULTI LINKED LIST</h1>
<p align="center">Feros Pedrosa Valentino - 103112400055</p>

## Dasar Teori
Multi Linked List (atau Multi List) merupakan sekumpulan list yang berbeda yang memiliki suatu keterhubungan satu sama lain[1]. Struktur ini memperluas konsep linked list standar dengan memungkinkan setiap elemen (node) memiliki lebih dari satu pointer, sehingga data dapat diorganisir dalam berbagai dimensi atau urutan logis yang berbeda secara bersamaan[2]. Dalam implementasi yang umum, struktur ini sering kali membagi peran elemen menjadi List Induk (Parent List) dan List Anak (Child List), di mana setiap elemen pada list induk berfungsi sebagai kepala yang menunjuk ke sebuah list anak tersendiri[1]. Fleksibilitas pointer ini menjadikan Multi Linked List solusi yang efisien untuk menangani relasi data yang kompleks, seperti relasi one-to-many atau representasi graf[3].

Penerapan struktur Parent-Child ini dapat dilihat pada kasus data pegawai dan keluarganya, di mana list pegawai (induk) memiliki pointer yang menunjuk ke list keluarga (anak) masing-masing[1]. Keterhubungan ini menciptakan aturan manipulasi memori yang ketat; dalam operasi penambahan data anak (insert), sistem harus terlebih dahulu mengetahui posisi elemen induknya agar data dapat dikaitkan dengan tepat[1]. Demikian pula dalam operasi penghapusan (delete), jika sebuah elemen induk dihapus dari memori, maka seluruh elemen anak yang berasosiasi dengan induk tersebut juga harus dihapus secara otomatis untuk menjaga integritas data[1]. Selain model hirarkis ini, Multi Linked List secara teoritis juga sering digunakan untuk merepresentasikan Matriks Jarang (Sparse Matrix)—yaitu matriks yang didominasi oleh nilai nol—guna menghemat penggunaan memori dibandingkan array statis[4].

## Guided 

### 1. Guided 1

multilist.h
```C++
#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>

using namespace std;

typedef struct nodeParent *NodeParent; //alias pointer ke struct nodeParent
typedef struct nodeChild *NodeChild;   //alias pointer ke struct nodeChild

struct nodeChild {
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
};

struct listAnak { //list child
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    string idKategoriMakanan;
    string namaKategoriMakanan;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk { //list parent
    NodeParent first;
    NodeParent last;
};

//create list
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alookasi
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &nodeInduk);

//alokasi & dealokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan);
void dealokasiNodeChild(NodeChild &nodeAnak);

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);

//operasi print
void printStrukturMLL(listInduk &LInduk);

#endif
```
multilist.cpp
```C++
#include "multilist.h"
#include <iostream>

using namespace std;

//create list
void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//alokasi & delaokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}
void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}
```
main.cpp
```C++
#include "multilist.h"
#include <iostream>

using namespace std;

int main(){
    //1. inisialisasi list
    listInduk LInduk;
    createListInduk(LInduk);

    //2. membuat data parent (kategori makanan)
    NodeParent K01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, K01);
    NodeParent K02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, K02);
    NodeParent K03 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(LInduk, K03);
    cout << endl;

    //3. memasukkan data child (menu makanan) ke kategori tertentu
    // --> Isi kategori makanan berat (K01)
    NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng Spesial");
    insertLastChild(K01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
    insertLastChild(K01->L_Anak, M02);
    // --> Isi kategori minuman (K02)
    NodeChild D02 = alokasiNodeChild("D02", "Jus Alpukat");
    insertLastChild(K02->L_Anak, D02);
    NodeChild D01 = alokasiNodeChild("D01", "Es Teh Manis");
    insertLastChild(K02->L_Anak, D01);
    // --> Isi kategori dessert (K03)
    NodeChild S01 = alokasiNodeChild("S01", "Puding Coklat");
    insertLastChild(K03->L_Anak, S01);
    cout << endl;

    //4. print mll setelah insert-insert
    printStrukturMLL(LInduk);
    cout << endl;

    //5. searching node child
    findChildByID(LInduk, "D01");
    cout << endl;
    //6. delete node child
    deleteAfterChild(K01->L_Anak, M01);
    cout << endl;
    //7. delete node parent
    deleteAfterParent(LInduk, K02);
    cout << endl;
    //8. print mll setelah delete-delete
    printStrukturMLL(LInduk);
    cout << endl;
    return 0;
}
```
Program ini mengimplementasikan struktur data multi linked list untuk mengelola data kategori makanan (sebagai parent) dan menu makanan (sebagai child). Struktur terdiri dari nodeParent yang menyimpan informasi kategori (ID dan nama) serta list anak (listAnak) berisi nodeChild dengan detail menu (ID dan nama), keduanya menggunakan doubly linked list untuk navigasi maju dan mundur. Fungsi utama meliputi pembuatan list kosong, alokasi/dealokasi node, penyisipan node di akhir list (insertLastParent dan insertLastChild), penghapusan node setelah node tertentu (deleteAfterParent dan deleteAfterChild), serta penghapusan seluruh list anak (hapusListAnak). Ada juga operasi pencarian child berdasarkan ID (findChildByID) dan pencetakan struktur multilist (printStrukturMLL) untuk menampilkan data secara hierarkis.
Di program utama (main.cpp), list induk diinisialisasi, lalu tiga kategori makanan (Makanan Berat, Minuman, Dessert) ditambahkan sebagai parent. Setiap kategori diisi dengan beberapa menu sebagai child, seperti Nasi Goreng Spesial dan Ayam Bakar Madu di Makanan Berat. Struktur ditampilkan, kemudian dilakukan pencarian child dengan ID "D01" (Es Teh Manis), penghapusan child setelah M01 (menghapus M02), dan penghapusan parent setelah K02 (menghapus K03 beserta child-nya). Terakhir, struktur diperbarui dan ditampilkan kembali, menunjukkan operasi CRUD dasar pada multilist.


## Unguided 

### 1. Soal Unguided 1
Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h” : 
Type Struct golonganHewan < 
     idGolongan : String 
     namaGolongan : String 
> 
Type Struct dataHewan <  
     idHewan : String 
     namaHewan : String 
     habitat : String 
     ekor : Boolean //TRUE jika berekor, FALSE jika tidak berekor 
     bobot : float //dalam kg 
> 
typedef struct nodeParent *NodeParent; //alias pointer ke struct nodeParent 
typedef struct nodeChild *NodeChild; //alias pointer ke struct nodeChild
Type Struct nodeChild < 
     isidata : dataHewan 
     next : NodeChild 
     prev : NodeChild 
> 
Type Struct listChild < 
     first : NodeChild  
     last : NodeChild 
> 
Type Struct nodeParent < 
     isidata : golonganHewan 
     next : NodeParent 
     prev : NodeParent 
     L_Child : listChild 
> 
Type Struct listParent < 
     first : NodeParent 
     last : NodeParent 
> 
Function isEmptyParent(input/output LParent : listParent) : Boolean 
Function isEmptyChild(input/output LChild : listChild) : Boolean 
Procedure createListParent(input/output LParent : listParent) 
Procedure createListChild(input/output LChild : listChild)
Function allocNodeParent(input idGol : String, namaGol : String) : NodeParent 
Function allocNodeChild(input idHwn : String, namaHwn : String, habitat : String, tail : Boolean, weight : float) : NodeChild 

Procedure deallocNodeParent(input/output NParent : NodeParent) 
Procedure deallocNodeChild(input/output NChild : NodeChild) 

Procedure insertFirstParent(input/output LParent : listParent, newNParent : NodeParent) 
Procedure insertLastParent(input/output LParent : listParent, newNParent : NodeParent) 
Procedure deleteFirstParent(input/output LParent : listParent) 
Procedure deleteAfterParent(input/output LParent : listParent, NPrev : NodeParent) 
 
Procedure insertFirstChild(input/output LChild : listChild, newNChild : NodeChild) 
Procedure insertLastChild(input/output LChild : listChild, newNChild : NodeChild) 
Procedure deleteFirstChild(input/output LChild : listChild) 
Procedure deleteAfterChild(input/output LChild : listChild, NPrev : NodeChild) 
 
Procedure printMLLStructure(input/output LParent : listParent) 
Procedure deleteListChild(input/output LChild : listChild) 

Kemudian buatlah implementasi ADT Multi Linked List tersebut pada file “MultiLL.cpp”.

Kemudian pada file “main.cpp”  lakukan operasi INSERT sebagaimana sehingga bentuk dari multi linked listnya seperti ini : 
Keterangan isi data setiap node : 
❖ List Parent :  
1) idGolongan : G001 
namaGolongan : Aves 
2) idGolongan : G002 
namaGolongan : Mamalia 
3) idGolongan : G003 
namaGolongan : Pisces 
4) idGolongan : G004 
namaGolongan : Amfibi 
5) idGolongan : G005 
namaGolongan : Reptil 
❖ List Child G001 :  
1) idHewan : AV001 
namaHewan : Cendrawasih 
habitat : Hutan 
ekor : True 
bobot : 0,3 
2) idHewan : AV002 
namaHewan : Bebek 
habitat : Air 
ekor : True 
bobot : 2 
❖ List Child G002 :  
1) idHewan : M001 
namaHewan : Harimau 
habitat : Hutan 
ekor : True 
bobot : 200 
2) idHewan : M003 
namaHewan : Gorila 
habitat : Hutan 
ekor : False 
bobot : 160 
3) idHewan : M002 
namaHewan : Kucing 
habitat : Darat 
ekor : True 
bobot : 4 
❖ List Child G004 :  
1) idHewan : AM001 
namaHewan : Kodok 
habitat : Sawah 
ekor : False 
bobot : 0,2 

Setelah melakukan INSERT, lakukan operasi PRINT dengan memanggil prosedur printMLLStructure(). (Lampirkan screenshot output hasil print pada laporan)

MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child; 
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);

void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void insertLastParent(listParent &LParent, NodeParent newNParent);
void insertLastChild(listChild &LChild, NodeChild newNChild);

void printMLLStructure(listParent LParent);

#endif
```
MultiLL.cpp
```C++
#include "MultiLL.h"

bool isEmptyParent(listParent LParent) {
    return LParent.first == NULL;
}

bool isEmptyChild(listChild LChild) {
    return LChild.first == NULL;
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}

void printMLLStructure(listParent LParent) {
    NodeParent P = LParent.first;
    int i = 1;
    while (P != NULL) {
        cout << "Parent " << i << endl;
        cout << "ID Golongan   : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
        
        if (isEmptyChild(P->L_Child)) {
            cout << "(tidak ada child)" << endl;
        } else {
            NodeChild C = P->L_Child.first;
            int j = 1;
            while (C != NULL) {
                cout << " - Child " << j << ":" << endl;
                cout << "   ID Hewan    : " << C->isidata.idHewan << endl;
                cout << "   Nama Hewan  : " << C->isidata.namaHewan << endl;
                cout << "   Habitat     : " << C->isidata.habitat << endl;
                cout << "   Ekor        : " << C->isidata.ekor << endl;
                cout << "   Bobot       : " << C->isidata.bobot << endl;
                C = C->next;
                j++;
            }
        }
        cout << endl;
        P = P->next;
        i++;
    }
}
```
main.cpp
```C++
#include "MultiLL.h"

int main() {
    listParent L;
    createListParent(L);

    NodeParent P1 = allocNodeParent("G001", "Aves");
    insertLastParent(L, P1);
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(L, P2);
    NodeParent P3 = allocNodeParent("G003", "Pisces");
    insertLastParent(L, P3);
    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(L, P4);
    NodeParent P5 = allocNodeParent("G005", "Reptil");
    insertLastParent(L, P5);

    insertLastChild(P1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(P1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2.0));

    insertLastChild(P2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(P2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(P2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));

    insertLastChild(P4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    cout << "--- OUTPUT NOMOR 1 ---" << endl;
    printMLLStructure(L);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan11_modul13/output-unguided1-modul13.png)

Program ini dirancang untuk membangun struktur data Multi Linked List yang bersifat Doubly Linked List (memiliki pointer next dan prev), baik pada level Induk (Parent) maupun level Anak (Child). Dalam file MultiLL.h, didefinisikan dua struktur data utama yaitu golonganHewan yang menyimpan ID dan nama golongan sebagai data Parent, serta dataHewan yang menyimpan detail spesifik hewan (seperti habitat, ekor, dan bobot) sebagai data Child. Konsep hierarki terlihat jelas pada struct nodeParent, di mana setiap node Parent memiliki sebuah variabel bertipe listChild bernama L_Child. Variabel inilah yang bertugas menampung daftar anak yang spesifik untuk setiap golongan, sehingga memungkinkan terbentuknya relasi one-to-many antara golongan hewan dan data hewannya.
Pada file implementasi MultiLL.cpp, terdapat fungsi-fungsi manajemen memori dan pointer. Fungsi alokasi allocNodeParent sangat krusial karena selain membuat node baru untuk golongan, fungsi ini juga secara otomatis menginisialisasi list anak (createListChild) di dalam node tersebut agar siap diisi. Untuk penambahan data, digunakan metode insertLastParent dan insertLastChild yang menempatkan node baru di posisi terakhir list. Karena ini adalah Doubly Linked List, logika penyambungan node memperhatikan dua arah pointer (menghubungkan next node lama ke node baru, dan prev node baru ke node lama). Fungsi printMLLStructure menggunakan perulangan bersarang (nested loop) yaitu perulangan luar menelusuri setiap node Parent (Golongan), sementara perulangan dalam menelusuri list Child yang ada di dalam Parent tersebut untuk menampilkan data hewan secara terstruktur.
Pada file main.cpp program dimulai dengan menginisialisasi list utama, kemudian membuat dan memasukkan lima node Parent (Aves, Mamalia, Pisces, Amfibi, Reptil) secara berurutan menggunakan insertLastParent. Setelah struktur golongan terbentuk, program memasukkan data hewan ke dalam list anak dari Parent yang relevan. Contohnya, pointer P1 (Aves) diakses list anaknya (P1->L_Child), lalu diisi dengan data "Cendrawasih" dan "Bebek". Hal serupa dilakukan pada P2 (Mamalia) untuk hewan seperti "Harimau" dan "Gorila". Pada akhirnya, fungsi cetak dipanggil untuk menampilkan seluruh hierarki data yang telah disusun, membuktikan bahwa setiap hewan telah tersimpan dalam golongan yang tepat sesuai dengan pointer yang dituju.

### 2. Soal Unguided 2
Tambahkan prosedur searchHewanByEkor(input/output LParent : listParent, input tail : Boolean) yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil prosedur tersebut pada main.cpp. 

MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child; 
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void printMLLStructure(listParent LParent);

void searchHewanByEkor(listParent LParent, bool tail);

#endif
```
MultiLL.cpp
```C++
#include "MultiLL.h"

bool isEmptyParent(listParent LParent) {
    return LParent.first == NULL;
}

bool isEmptyChild(listChild LChild) {
    return LChild.first == NULL;
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}

void printMLLStructure(listParent LParent) {
    NodeParent P = LParent.first;
    int i = 1;
    while (P != NULL) {
        cout << "Parent " << i << endl;
        cout << "ID Golongan   : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
        
        if (isEmptyChild(P->L_Child)) {
            cout << "(tidak ada child)" << endl;
        } else {
            NodeChild C = P->L_Child.first;
            int j = 1;
            while (C != NULL) {
                cout << " - Child " << j << ":" << endl;
                cout << "   ID Hewan    : " << C->isidata.idHewan << endl;
                cout << "   Nama Hewan  : " << C->isidata.namaHewan << endl;
                cout << "   Habitat     : " << C->isidata.habitat << endl;
                cout << "   Ekor        : " << C->isidata.ekor << endl;
                cout << "   Bobot       : " << C->isidata.bobot << endl;
                C = C->next;
                j++;
            }
        }
        cout << endl;
        P = P->next;
        i++;
    }
}

void searchHewanByEkor(listParent LParent, bool tail) {
    NodeParent P = LParent.first;
    int idxParent = 1; 

    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        int idxChild = 1; 
        
        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                cout << "Data ditemukan pada list anak dari node parent " << P->isidata.namaGolongan << " pada posisi ke-" << idxChild << "!" << endl;
                
                cout << "--- Data Child ---" << endl;
                cout << "ID Child      : " << C->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << idxChild << endl;
                cout << "Nama Hewan    : " << C->isidata.namaHewan << endl;
                cout << "Habitat       : " << C->isidata.habitat << endl;
                cout << "Ekor          : " << C->isidata.ekor << endl;
                cout << "Bobot         : " << C->isidata.bobot << endl;
                cout << "-------------------------------------------" << endl;
                
                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent     : " << P->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << idxParent << endl;
                cout << "Nama golongan : " << P->isidata.namaGolongan << endl;
                cout << "-------------------------------------------" << endl;
                cout << endl;
            }
            C = C->next;
            idxChild++;
        }
        P = P->next;
        idxParent++;
    }
}
```
main.cpp
```C++
#include "MultiLL.h"

int main() {
    listParent L;
    createListParent(L);

    NodeParent P1 = allocNodeParent("G001", "Aves"); insertLastParent(L, P1);
    NodeParent P2 = allocNodeParent("G002", "Mamalia"); insertLastParent(L, P2);
    NodeParent P3 = allocNodeParent("G003", "Pisces"); insertLastParent(L, P3);
    NodeParent P4 = allocNodeParent("G004", "Amfibi"); insertLastParent(L, P4);
    NodeParent P5 = allocNodeParent("G005", "Reptil"); insertLastParent(L, P5);

    insertLastChild(P1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(P1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2.0));
    insertLastChild(P2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(P2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(P2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));
    insertLastChild(P4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    cout << "--- OUTPUT NOMOR 2 ---" << endl;
    searchHewanByEkor(L, false);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan11_modul13/output-unguided2-modul13.png)

File header MultiLL.h pada dasarnya mempertahankan struktur data yang sama dengan nomor sebelumnya, yaitu menggunakan konsep Multi Linked List dengan Doubly Linked List untuk menghubungkan node Parent (Golongan Hewan) dan node Child (Data Hewan). Perbedaan utama pada file ini adalah adanya penambahan deklarasi fungsi baru bernama searchHewanByEkor. Fungsi ini dirancang menerima dua parameter yaitu list induk (listParent) yang akan ditelusuri dan nilai boolean (tail) yang menjadi kunci pencarian. Penambahan prototipe ini memungkinkan fungsi pencarian dipanggil dari program utama untuk menemukan hewan berdasarkan karakteristik ekornya.
Fokus utama pada file MultiLL.cpp ini terletak pada fungsi searchHewanByEkor. Algoritma ini bekerja dengan metode traversal bertingkat (perulangan bersarang). Perulangan luar menelusuri setiap node Parent menggunakan pointer P, sementara perulangan dalam menelusuri setiap node Child di dalam parent tersebut menggunakan pointer C. Di dalam perulangan terdalam, terdapat logika kondisional if (C->isidata.ekor == tail) yang memeriksa apakah status ekor hewan saat ini cocok dengan nilai yang dicari. Jika cocok, program akan mencetak detail lengkap hewan tersebut beserta informasi induknya. Selain itu, fungsi ini menggunakan variabel penghitung (idxParent dan idxChild) yang terus bertambah (++) selama penelusuran untuk melacak dan menampilkan posisi data secara akurat (misalnya "posisi ke-2") sesuai permintaan soal.
File main.cpp berfungsi untuk membangun data awal dan menjalankan skenario pengujian. Pertama, program membentuk struktur list lengkap dengan memasukkan 5 node golongan hewan dan beberapa node hewan spesifik (seperti Cendrawasih, Harimau, Gorila, dll) menggunakan fungsi insert. Setelah data siap, program memanggil fungsi searchHewanByEkor(L, false). Parameter false di sini menginstruksikan program untuk hanya mencari dan menampilkan hewan yang tidak memiliki ekor (nilai ekor = 0). Berdasarkan data yang dimasukkan, output yang dihasilkan nantinya hanya akan menampilkan data untuk hewan "Gorila" (dari parent Mamalia) dan "Kodok" (dari parent Amfibi), sementara hewan lain yang berekor akan diabaikan.

### 3. Soal Unguided 3
Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan memanggil prosedur printMLLStructure(). Sehingga bentuk dari multi linked listnya berubah menjadi seperi ini :
(Lampirkan screenshot output hasil print setelah dilakukan delete pada laporan).

MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan { string idGolongan; string namaGolongan; };
struct dataHewan { string idHewan; string namaHewan; string habitat; bool ekor; float bobot; };
typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;
struct nodeChild { dataHewan isidata; NodeChild next; NodeChild prev; };
struct listChild { NodeChild first; NodeChild last; };
struct nodeParent { golonganHewan isidata; NodeParent next; NodeParent prev; listChild L_Child; };
struct listParent { NodeParent first; NodeParent last; };

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void printMLLStructure(listParent LParent);
void searchHewanByEkor(listParent LParent, bool tail);

void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);
void deleteFirstChild(listChild &LChild);
void deleteListChild(listChild &LChild);

#endif
```
MultiLL.cpp
```C++
#include "MultiLL.h"

bool isEmptyParent(listParent LParent) {
    return LParent.first == NULL;
}

bool isEmptyChild(listChild LChild) {
    return LChild.first == NULL;
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        insertFirstParent(LParent, newNParent);
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent P = LParent.first;
        // Hapus semua child dulu
        deleteListChild(P->L_Child);
        
        if (LParent.first == LParent.last) {
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = P->next;
            LParent.first->prev = NULL;
            P->next = NULL;
        }
        deallocNodeParent(P);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent del = NPrev->next;
        // Hapus semua child dari node yang akan dihapus
        deleteListChild(del->L_Child);

        NPrev->next = del->next;
        if (del->next != NULL) {
            del->next->prev = NPrev;
        } else {
            LParent.last = NPrev;
        }
        
        del->next = NULL;
        del->prev = NULL;
        deallocNodeParent(del);
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        insertFirstChild(LChild, newNChild);
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild C = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = C->next;
            LChild.first->prev = NULL;
            C->next = NULL;
        }
        deallocNodeChild(C);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild del = NPrev->next;
        NPrev->next = del->next;
        if (del->next != NULL) {
            del->next->prev = NPrev;
        } else {
            LChild.last = NPrev;
        }
        del->next = NULL;
        del->prev = NULL;
        deallocNodeChild(del);
    }
}

void printMLLStructure(listParent LParent) {
    if (isEmptyParent(LParent)) {
        cout << "List Kosong" << endl;
        return;
    }

    NodeParent P = LParent.first;
    int i = 1;
    while (P != NULL) {
        cout << "Parent " << i << endl;
        cout << "ID Golongan   : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
        
        if (isEmptyChild(P->L_Child)) {
            cout << "(tidak ada child)" << endl;
        } else {
            NodeChild C = P->L_Child.first;
            int j = 1;
            while (C != NULL) {
                cout << " - Child " << j << ":" << endl;
                cout << "   ID Hewan    : " << C->isidata.idHewan << endl;
                cout << "   Nama Hewan  : " << C->isidata.namaHewan << endl;
                cout << "   Habitat     : " << C->isidata.habitat << endl;
                cout << "   Ekor        : " << (C->isidata.ekor ? "1" : "0") << endl;
                cout << "   Bobot       : " << C->isidata.bobot << endl;
                C = C->next;
                j++;
            }
        }
        cout << endl;
        P = P->next;
        i++;
    }
}

void searchHewanByEkor(listParent LParent, bool tail) {
    cout << "===========================================" << endl;
    cout << "SEARCH HASIL (Ekor: " << (tail ? "True" : "False") << ")" << endl;
    cout << "===========================================" << endl;

    NodeParent P = LParent.first;
    int idxParent = 1;
    bool found = false;

    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        int idxChild = 1;
        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                found = true;
                cout << "Data ditemukan pada list anak dari node parent " << P->isidata.namaGolongan << " pada posisi ke-" << idxChild << "!" << endl;
                
                cout << "--- Data Child ---" << endl;
                cout << "ID Child      : " << C->isidata.idHewan << endl;
                cout << "Posisi child  : posisi ke-" << idxChild << endl;
                cout << "Nama Hewan    : " << C->isidata.namaHewan << endl;
                cout << "Habitat       : " << C->isidata.habitat << endl;
                cout << "Ekor          : " << (C->isidata.ekor ? "1" : "0") << endl;
                cout << "Bobot         : " << C->isidata.bobot << endl;
                
                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent     : " << P->isidata.idGolongan << endl;
                cout << "Posisi parent : posisi ke-" << idxParent << endl;
                cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
                cout << "-------------------------------------------" << endl;
            }
            C = C->next;
            idxChild++;
        }
        P = P->next;
        idxParent++;
    }

    if (!found) {
        cout << "Data tidak ditemukan." << endl;
    }
}
```
main.cpp
```C++
#include "MultiLL.h"

int main() {
    listParent L;
    createListParent(L);

    NodeParent P1 = allocNodeParent("G001", "Aves"); insertLastParent(L, P1);
    NodeParent P2 = allocNodeParent("G002", "Mamalia"); insertLastParent(L, P2);
    NodeParent P3 = allocNodeParent("G003", "Pisces"); insertLastParent(L, P3);
    NodeParent P4 = allocNodeParent("G004", "Amfibi"); insertLastParent(L, P4);
    NodeParent P5 = allocNodeParent("G005", "Reptil"); insertLastParent(L, P5);

    insertLastChild(P1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(P1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2.0));
    insertLastChild(P2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(P2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(P2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));
    insertLastChild(P4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    NodeParent temp = L.first;
    while (temp != NULL) {
        if (temp->isidata.idGolongan == "G004") {
            if (temp == L.first) {
                deleteFirstParent(L);
            } else {
                // Delete node setelah node sebelumnya (prev)
                deleteAfterParent(L, temp->prev);
            }
            break; 
        }
        temp = temp->next;
    }

    cout << "--- OUTPUT NOMOR 3 ---" << endl;
    printMLLStructure(L);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan11_modul13/output-unguided3-modul13.png)

File header MultiLL.h pada nomor ini melengkapi struktur data Multi Linked List yang telah dibangun sebelumnya dengan menambahkan fitur penghapusan data. Selain mendefinisikan struktur Parent dan Child, file ini mendeklarasikan sekumpulan fungsi baru khusus untuk operasi delete, yaitu deleteFirstParent, deleteAfterParent, deleteFirstChild, dan deleteListChild. Penambahan fungsi-fungsi ini sangat penting karena dalam struktur data yang dinamis, kemampuan untuk menghapus node dan membebaskan memori sama pentingnya dengan kemampuan menambahkan data.
Pada file MultiLL.cpp terdapat inti logika yang menerapkan prinsip "bersihkan anak sebelum menghapus induk". Sebelum sebuah node Parent dihapus (baik melalui deleteFirstParent atau deleteAfterParent), fungsi tersebut memanggil deleteListChild terlebih dahulu. Fungsi bantuan ini akan menghapus seluruh isi list anak yang terkait dengan Parent tersebut satu per satu hingga kosong. Hal ini dilakukan untuk mencegah memory leak (kebocoran memori), di mana node induk terhapus tetapi data anaknya masih tertinggal di memori tanpa akses. Setelah list anak bersih, barulah pointer next dan prev pada list induk diputus dan disambungkan ulang ke node tetangganya, kemudian memori node Parent tersebut dibebaskan menggunakan perintah delete.
Pada main.cpp, program mensimulasikan kasus nyata penghapusan data tertentu. Setelah seluruh struktur data (Parent G001-G005 beserta anaknya) terbentuk, program melakukan perulangan menelusuri list induk untuk mencari node dengan idGolongan "G004" (Amfibi). Logika program memeriksa posisi node tersebut yaitu jika "G004" berada di posisi pertama, maka fungsi deleteFirstParent dipanggil. Namun, karena "G004" berada di tengah list, program menggunakan deleteAfterParent dengan memberikan parameter node sebelumnya (temp->prev). Setelah operasi ini dieksekusi, node Amfibi beserta anak-anaknya (Kodok) akan hilang dari struktur. Fungsi printMLLStructure yang dipanggil terakhir akan menampilkan sisa list (Parent G001, G002, G003, dan G005) dengan pointer yang sudah tersambung melewati posisi bekas G004.

## Kesimpulan
Multi Linked List (MLL) merupakan struktur data dinamis yang memperluas konsep linked list standar melalui penggunaan pointer jamak, memungkinkan pengorganisasian sekumpulan list berbeda yang saling terhubung dalam dimensi logis yang kompleks. Implementasi utamanya sering mengadopsi model hierarkis Parent-Child yang memfasilitasi relasi one-to-many, di mana setiap elemen induk berfungsi sebagai kepala (head) yang memiliki akses langsung ke sekumpulan elemen anak. Keunggulan struktur ini terletak pada kemampuannya menangani relasi data yang rumit dengan aturan manipulasi memori yang ketat, seperti kewajiban penghapusan data anak secara otomatis saat data induknya dihapus demi menjaga integritas data. Fleksibilitas pointer ini menjadikan MLL solusi yang efisien, tidak hanya untuk merepresentasikan data berjenjang seperti relasi keluarga, tetapi juga untuk optimasi penyimpanan memori pada kasus Matriks Jarang (Sparse Matrix).

## Referensi
[1] Modul 13 - Praktikum Struktur Data
<br>[2] GeeksforGeeks. (2024). Introduction to Multi Linked List.
<br>[3] University of Alberta. (n.d.). Lecture 6: Multi-Linked Lists. Department of Computing Science.
<br>[4] Sahni, S. (2000). Data Structures, Algorithms, and Applications in C++. McGraw-Hill. (Topik: Sparse Matrix Representation).