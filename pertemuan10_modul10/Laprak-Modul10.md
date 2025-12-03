# <h1 align="center">Laporan Praktikum Modul 10 - TREE (Bagian Pertama)</h1>
<p align="center">Feros Pedrosa Valentino - 103112400055</p>

## Dasar Teori
Tree atau pohon adalah struktur data non-linier yang bersifat hierarkis, berbeda dengan array atau linked list yang bersifat linier. Struktur ini merepresentasikan hubungan data yang menyerupai struktur pohon, di mana elemen-elemen data dihubungkan melalui sisi (edge) dan memiliki hubungan 'orang tua-anak' (parent-child). Sebuah tree terdiri dari sekumpulan node (simpul), di mana terdapat satu node khusus yang disebut sebagai root (akar), dan node lainnya terbagi menjadi himpunan-himpunan yang saling lepas yang disebut sebagai subtree (sub-pohon) [1]. Penggunaan struktur data tree sangat krusial dalam ilmu komputer, terutama untuk menyelesaikan masalah yang melibatkan pencarian data yang efisien, manipulasi data hierarkis (seperti sistem file komputer), dan algoritma pengurutan [2].

Dalam terminologi tree, terdapat beberapa istilah kunci yang harus dipahami. Root adalah node teratas yang tidak memiliki parent. Setiap node dapat memiliki node lain yang terhubung di bawahnya yang disebut child (anak), dan node di atasnya disebut parent. Node yang tidak memiliki child sama sekali disebut sebagai leaf (daun) atau external node. Selain itu, konsep height (tinggi) dan depth (kedalaman) digunakan untuk mengukur struktur pohon; depth dari sebuah node adalah panjang jalur dari root ke node tersebut, sedangkan height dari tree adalah panjang jalur terpanjang dari root ke leaf [3]. Pemahaman mengenai terminologi ini penting untuk menganalisis kompleksitas algoritma yang bekerja pada struktur tree.

Salah satu varian tree yang paling umum digunakan dalam pemrograman adalah Binary Tree (Pohon Biner). Dalam Binary Tree, setiap node dibatasi hanya boleh memiliki paling banyak dua orang anak, yang secara spesifik disebut sebagai left child (anak kiri) dan right child (anak kanan). Struktur ini memungkinkan operasi pencarian dan penyisipan data yang lebih terstruktur dibandingkan pohon umum (general tree). Secara rekursif, sebuah binary tree dapat didefinisikan kosong, atau terdiri dari sebuah root dengan dua binary tree terpisah yang disebut sub-pohon kiri dan sub-pohon kanan [2]. Jenis khusus dari binary tree meliputi Full Binary Tree, Complete Binary Tree, dan Perfect Binary Tree, yang masing-masing memiliki aturan penempatan node yang spesifik [4].

Implementasi tree (khususnya binary tree) umumnya dilakukan menggunakan konsep Dynamic Memory Allocation melalui struct atau class. Sebuah node direpresentasikan sebagai sebuah objek yang memiliki setidaknya tiga komponen utama: satu variabel untuk menyimpan data (misalnya bertipe int atau char), dan dua variabel pointer yang menunjuk ke node kiri (left) dan node kanan (right). Penggunaan pointer ini memungkinkan struktur pohon tumbuh secara dinamis sesuai kebutuhan memori saat program dijalankan. Jika sebuah node tidak memiliki anak, maka pointer anak tersebut akan bernilai NULL, yang menandakan akhir dari jalur tersebut [5].


## Guided 

### 1. Guided 1
rekursif pangkat 2

```C++
#include<iostream>

using namespace std;

int pangkat_2(int x){ //x adalah pangkatnya
    if(x == 0){ //basis
        return 1;
    } else if (x > 0){ //rekurens
        return 2 * pangkat_2(x-1);
    }
}

int main(){
    cout << "=== REKURSIF PANGKAT 2 ===" << endl;

    int x;
    cout << "masukkan nilai x: "; 
    cin >> x;
    cout << endl;
    cout << "2 pangkat " << x << " adalah : " << pangkat_2(x);

    return 0;
}
```
Program di atas berfungsi untuk menghitung hasil perpangkatan dari basis bilangan 2 (2^x) menggunakan metode rekursif. Inti dari program ini terletak pada fungsi pangkat_2 yang membagi logika menjadi dua bagian utama: basis dan rekurens. Bagian basis (if(x == 0)) bertugas menghentikan rekursi dengan mengembalikan nilai 1 (karena 2^0 = 1). Bagian rekurens (else if (x > 0)) berfungsi memanggil kembali fungsi dirinya sendiri dengan nilai pangkat yang dikurangi satu (x-1), lalu hasilnya dikalikan dengan 2. Di dalam fungsi main, program meminta pengguna memasukkan nilai pangkat x, lalu memanggil fungsi rekursif tersebut dan menampilkan hasil akhirnya.

### 2. Guided 2
BST1

BST1.h
```C++
#ifndef BST1_H
#define BST1_H

#include <iostream>

using namespace std;

typedef int infotype; //alias infotype untuk data integer
typedef struct Node*address; // alias address sebagai pointer ke struct Node(Node*)

struct Node{
    infotype info; //info data yang disimpan(integer)
    address left; //pointer left
    address right; //pointer right
};

//isEmpty & createTree
bool isEmpty(address root); //function untuk mengecek apakah BST kosong atau tidak
void createTree(address &root); //function untuk membuat BST nya (root di-set sebagai NULL)

//alokasi & insert
address newNode(infotype x); //function untuk mengalokasikan node baru
address insertNode(address root, infotype x); //function untuk memasukkan node ke BST

//Traversal
void preOrder(address root); //function traversal tree secara preOrder (tengah - kiri - kanan atau root - child kiri - child kanan)
void inOrder(address root); //function traversal tree secara in-Order (kiri - tengah - kanan atau child kiri - root - child kanan)
void postOrder(address root); //function traversal tree secara postOrder (kiri - kanan - tengah atau child kiri - child kanan - root)

//Utilities
int countNodes(address root); //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
int treeDepth(address root);

#endif
```
BST1.cpp
```C++
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```
main.cpp
```C++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```
Program ini mengimplementasikan struktur data Binary Search Tree (BST). Pada BST1.h, didefinisikan struct Node yang berfungsi sebagai kerangka dasar simpul, menyimpan data integer (info) serta dua pointer (left dan right) untuk menghubungkan antar simpul secara hierarkis. Pada file BST1.cpp berisi logika operasi utama, di mana fungsi insertNode menyisipkan data secara rekursif dengan aturan BST yang ketat yaitu nilai yang lebih kecil dari root akan ditempatkan di sub-pohon kiri, sedangkan nilai yang lebih besar ditempatkan di kanan. Selain itu, terdapat fungsi traversal (penelusuran) meliputi preOrder (Root-Kiri-Kanan), inOrder (Kiri-Root-Kanan), dan postOrder (Kiri-Kanan-Root), serta fungsi utilitas countNodes untuk menghitung total simpul dan treeDepth untuk mengukur kedalaman pohon.
Pada bagian main.cpp, program diuji dengan membuat pohon baru dan menyisipkan serangkaian angka yaitu 20 (sebagai root), diikuti oleh 10, 35, 5, 18, dan 40. Struktur pohon yang terbentuk dari input tersebut akan memiliki root 20, dengan anak kiri 10 (yang memiliki anak 5 dan 18) dan anak kanan 35 (yang memiliki anak 40). Program kemudian memanggil seluruh fungsi traversal untuk menampilkan urutan data yang berbeda-beda, serta mencetak jumlah total node (hasilnya 6) dan kedalaman pohon (hasilnya 2, jika dihitung dari 0).

### 3. Guided 3
BST2

BST2.h
```C++
#ifndef BST2_H
#define BST2_H

#include <iostream>

using namespace std;

typedef int infotype; //alias infotype untuk data integer
typedef struct Node*address; // alias address sebagai pointer ke struct Node(Node*)

struct Node{
    infotype info; //info data yang disimpan(integer)
    address left; //pointer left
    address right; //pointer right
};

//isEmpty & createTree
bool isEmpty(address root); //function untuk mengecek apakah BST kosong atau tidak
void createTree(address &root); //function untuk membuat BST nya (root di-set sebagai NULL)

//alokasi & insert
address newNode(infotype x); //function untuk mengalokasikan node baru
address insertNode(address root, infotype x); //function untuk memasukkan node ke BST

//Traversal
void preOrder(address root); //function traversal tree secara preOrder (tengah - kiri - kanan atau root - child kiri - child kanan)
void inOrder(address root); //function traversal tree secara in-Order (kiri - tengah - kanan atau child kiri - root - child kanan)
void postOrder(address root); //function traversal tree secara postOrder (kiri - kanan - tengah atau child kiri - child kanan - root)

//Utilities
int countNodes(address root); //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
int treeDepth(address root);

//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x); //function untuk melakukan searching data tertentu

//mostleft & mostright
address mostLeft(address root);
address mostRight(address root);

//delete
bool deleteNode(address &root, infotype x);
void deleteTree(address &root); //prosedur untuk menghapus BST (menghapus seluruh node BST)

#endif
```
BST2.cpp
```C++
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```
main.cpp
```C++
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}
```
Program ini merupakan pengembangan lanjutan dari Binary Search Tree (BST) sebelumnya, dengan penambahan fitur krusial untuk manipulasi data, yaitu pencarian (searching), pencarian nilai ekstrem (min/max), dan penghapusan (deletion). Pada BST2.h dan BST2.cpp, fungsi baru searchByData dirancang tidak hanya untuk menemukan apakah data ada, tetapi juga melacak pointer parent secara manual untuk menampilkan informasi hubungan kekerabatan node tersebut (siapa orang tuanya, saudaranya, dan anak-anaknya). Fungsi mostLeft dan mostRight bekerja sederhana dengan menelusuri sisi terkiri untuk nilai minimum dan sisi terkanan untuk nilai maksimum.
Bagian logika terkompleks terdapat pada fungsi deleteNode yang menangani tiga kasus penghapusan yaitu menghapus leaf (node tanpa anak), menghapus node dengan satu anak (langsung menghubungkan parent ke grandchild), dan menghapus node dengan dua anak. Pada kasus ketiga, algoritma menggunakan teknik successor, yaitu mengganti nilai node yang dihapus dengan nilai terkecil dari sub-pohon kanannya (mostLeft(root->right)), lalu menghapus node duplikat tersebut. Selain itu, prosedur deleteTree ditambahkan untuk membersihkan seluruh memori pohon secara rekursif (post-order) agar tidak terjadi kebocoran memori.
Dalam main.cpp, program mendemonstrasikan skenario lengkap yaitu membuat pohon dengan root 30, lalu melakukan pencarian mendetail pada angka 17 (yang dalam kasus ini memiliki dua anak, 16 dan 20, serta saudara 11). Kemudian pengguna diminta menghapus sebuah angka, yang akan memicu logika penghapusan kompleks menggunakan successor. Setelah penghapusan, program memverifikasi struktur baru dengan mencari kembali angka tersebut dan melakukan traversal ulang, sebelum akhirnya menghapus seluruh struktur pohon menggunakan deleteTree.


## Unguided 

### 1. Soal Unguided 1
Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file “bstree.h”:
Type infotype: integer
Type address : pointer to Node
Type Node: <
info : infotype
left, right : address
>
function alokasi( x : infotype ) → address
procedure insertNode( input/output root : address,
input x : infotype )
function findNode( x : infotype, root : address )→address
procedure printInorder( input root : address )

Buatlah implementasi ADT Binary Search Tree pada file “bstree.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”
#include <iostream>
#include "bstree.h"
using namespace std;
int main() {
cout << "Hello World" << endl;
address root = Nil;
insertNode(root,1);
insertNode(root,2);
insertNode(root,6);
insertNode(root,4);
insertNode(root,5);
insertNode(root,3);
insertNode(root,6);
insertNode(root,7);
InOrder(root);
return 0;
}

bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>

#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

#endif
```
bstree.cpp
```C++
#include "bstree.h"

address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root == Nil || root->info == x) {
        return root;
    }
    if (x < root->info) {
        return findNode(x, root->left);
    }
    return findNode(x, root->right);
}

void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}
```
main.cpp
```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    printInorder(root);
    
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan10_modul10/output-unguided1-modul10.png)

penjelasan unguided 1 
Program ini merupakan implementasi sederhana dari struktur data Binary Search Tree (BST). Header file bstree.h mendefinisikan tipe data dan struktur dasar, termasuk typedef untuk infotype sebagai int (tipe data informasi yang disimpan), address sebagai pointer ke struct Node, dan struct Node itu sendiri yang memiliki field info untuk menyimpan nilai, serta pointer left dan right untuk anak kiri dan kanan. File ini juga mendeklarasikan fungsi-fungsi utama seperti alokasi untuk membuat node baru, insertNode untuk menyisipkan nilai ke dalam pohon, findNode untuk mencari nilai tertentu, dan printInorder untuk mencetak pohon dalam urutan inorder (Left-Root-Right).
Di file bstree.cpp, implementasi fungsi-fungsi tersebut dilakukan secara rekursif. Fungsi alokasi membuat node baru dengan mengalokasikan memori menggunakan new, mengisi info dengan nilai x, dan mengatur left serta right ke NULL (yang didefinisikan sebagai Nil). Fungsi insertNode menyisipkan nilai x ke dalam pohon dengan memeriksa apakah root kosong; jika ya, ia membuat node baru, jika tidak, ia membandingkan x dengan info root dan rekursif memanggil insertNode pada subtree kiri jika x lebih kecil atau subtree kanan jika x lebih besar atau sama. Fungsi findNode mencari nilai x dengan cara serupa: jika root kosong atau info root sama dengan x, ia mengembalikan root; jika x lebih kecil, ia mencari di subtree kiri, dan sebaliknya di subtree kanan. Sementara itu, printInorder melakukan traversal inorder dengan mencetak subtree kiri terlebih dahulu, kemudian info root, dan akhirnya subtree kanan, dengan pemisah " - " untuk setiap nilai.
Program utama di main.cpp memulai dengan menginisialisasi root sebagai NULL, lalu menyisipkan serangkaian nilai (1, 2, 6, 4, 5, 3, 6, 7) ke dalam BST menggunakan insertNode. Perlu dicatat bahwa BST ini tidak menangani duplikat secara khusus, sehingga nilai 6 yang dimasukkan dua kali akan tetap disimpan sesuai aturan (di subtree kanan). Terakhir, printInorder dipanggil untuk mencetak pohon dalam urutan inorder, yang akan menghasilkan output seperti "1 - 2 - 3 - 4 - 5 - 6 - 6 - 7 -" tergantung pada struktur pohon yang terbentuk.

### 2. Soal Unguided 2
Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.
➢ fungsihitungJumlahNode( root:address ) : integer
/* fungsi mengembalikan integer banyak node yang ada di dalam BST*/
➢ fungsihitungTotalInfo( root:address, start:integer ) : integer
/* fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST*/
➢ fungsihitungKedalaman( root:address, start:integer ) : integer
/* fungsi rekursif mengembalikan integer kedalaman maksimal dari binary tree */

int main() {
cout << "Hello World" << endl;
address root = Nil;
insertNode(root,1);
insertNode(root,2);
insertNode(root,6);
insertNode(root,4);
insertNode(root,5);
insertNode(root,3);
insertNode(root,6);
insertNode(root,7);
InOrder(root);
cout<<"\n";
cout<<"kedalaman : " << hitungKedalaman(root,0) << endl;
cout<<"jumlah Node : " << hitungNode(root) << endl;
cout<<"total : " << hitungTotal(root) << endl;
return 0;
}

bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>

#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

// Fungsi Tambahan
int hitungNode(address root);
int hitungTotal(address root);
int hitungKedalaman(address root, int start);

#endif
```
bstree.cpp
```C++
#include "bstree.h"

address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root == Nil || root->info == x) {
        return root;
    }
    if (x < root->info) {
        return findNode(x, root->left);
    }
    return findNode(x, root->right);
}

void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

// Menghitung jumlah node (Count)
int hitungNode(address root) {
    if (root == Nil) {
        return 0;
    }
    return 1 + hitungNode(root->left) + hitungNode(root->right);
}

// Menghitung total nilai info (Sum)
int hitungTotal(address root) {
    if (root == Nil) {
        return 0;
    }
    return root->info + hitungTotal(root->left) + hitungTotal(root->right);
}

// Menghitung kedalaman/tinggi tree (Max Depth)
// Parameter 'start' digunakan sebagai level saat ini
int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return start;
    }
    
    int leftDepth = hitungKedalaman(root->left, start + 1);
    int rightDepth = hitungKedalaman(root->right, start + 1);
    
    if (leftDepth > rightDepth) {
        return leftDepth;
    } else {
        return rightDepth;
    }
}
```
main.cpp
```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    printInorder(root);
    cout << "\n";

    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    
    cout << "jumlah node : " << hitungNode(root) << endl;
    
    cout << "total : " << hitungTotal(root) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan10_modul10/output-unguided2-modul10.png)

Program ini mengimplementasikan struktur data Binary Search Tree (BST). Pada file bstree.h, didefinisikan sebuah struktur bernama Node yang berfungsi sebagai wadah data. Setiap node memiliki tiga komponen: info untuk menyimpan nilai bertipe integer, serta dua pointer bertipe address (yaitu left dan right) yang menunjuk ke anak kiri dan anak kanan. File ini juga mendeklarasikan fungsi-fungsi utama seperti insertNode untuk memasukkan data, findNode untuk mencari data, printInorder untuk mencetak data, serta fungsi statistik tambahan seperti hitungNode, hitungTotal, dan hitungKedalaman.
Pada file bstree.cpp, logika program dijalankan. Fungsi insertNode bekerja secara rekursif dengan aturan dasar BST yaitu jika nilai baru lebih kecil dari nilai node saat ini, ia akan bergerak ke kiri; jika lebih besar, ia bergerak ke kanan. Logika if (x < root->info) ... else if (x > root->info) secara implisit mencegah duplikasi data; artinya jika nilai yang dimasukkan sama dengan nilai yang sudah ada, nilai tersebut akan diabaikan. Fungsi alokasi digunakan untuk menyiapkan memori bagi node baru dengan menginisialisasi pointer kiri dan kanannya menjadi NULL (Nil).
Untuk menampilkan data, program menggunakan metode traversal Inorder (printInorder). Metode ini mengunjungi sub-tree kiri terlebih dahulu, mencetak data node saat ini, lalu mengunjungi sub-tree kanan. Hasilnya adalah data akan tercetak secara berurutan dari nilai terkecil hingga terbesar (sorted). Selain itu, terdapat fungsi hitungNode yang menghitung jumlah node (count) dengan rumus rekursif 1 + kiri + kanan. Fungsi hitungTotal menjumlahkan nilai info seluruh node, dan hitungKedalaman mencari jalur terpanjang (level terdalam) dari root hingga leaf untuk menentukan tinggi pohon.
Dalam main.cpp, sebuah variabel root diinisialisasi sebagai titik awal pohon. Program kemudian memasukkan serangkaian angka yaitu 1, 2, 6, 4, 5, 3, 6, dan 7. Karena aturan BST yang ditulis menolak duplikasi, angka '6' yang dimasukkan kedua kalinya tidak akan ditambahkan ke dalam struktur. Setelah penyisipan selesai, program mencetak urutan angka (akan tampil: 1 - 2 - 3 - 4 - 5 - 6 - 7), lalu menampilkan kedalaman pohon, total banyak node (ada 7 node), dan hasil penjumlahan seluruh angka tersebut.

### 3. Soal Unguided 3
Print tree secara pre-order dan post-order.

bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>

#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

// Fungsi Alokasi & Insert
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);

void printPreorder(address root);
void printPostorder(address root);

#endif
```
bstree.cpp
```C++
#include "bstree.h"

address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root == Nil || root->info == x) {
        return root;
    }
    if (x < root->info) {
        return findNode(x, root->left);
    }
    return findNode(x, root->right);
}

// Pre-order: Root -> Left -> Right
void printPreorder(address root) {
    if (root != Nil) {
        cout << root->info << " - ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

// Post-order: Left -> Right -> Root
void printPostorder(address root) {
    if (root != Nil) {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->info << " - ";
    }
}
```
main.cpp
```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = Nil;

    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 2);
    insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 5);
    insertNode(root, 7);

    cout << "Preorder  : ";
    printPreorder(root);
    cout << "\n";

    cout << "Postorder : ";
    printPostorder(root);
    cout << "\n";

    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan10_modul10/output-unguided3-modul10.png)

Program ini merupakan implementasi dari Binary Search Tree (BST). Di file bstree.h, didefinisikan tipe data infotype sebagai integer, serta struktur Node yang memiliki tiga anggota yaitu info untuk menyimpan nilai data, dan left serta right sebagai pointer ke anak kiri dan kanan. Header ini juga mendeklarasikan fungsi-fungsi seperti alokasi untuk membuat node baru, insertNode untuk menyisipkan nilai ke dalam BST dengan aturan bahwa nilai lebih kecil dari root ditempatkan di kiri dan lebih besar di kanan, findNode untuk mencari node berdasarkan nilai, serta printPreorder dan printPostorder untuk menampilkan traversal preorder (root, kiri, kanan) dan postorder (kiri, kanan, root). Implementasi di bstree.cpp menunjukkan fungsi alokasi yang mengalokasikan memori untuk node baru dan menginisialisasinya, insertNode yang menggunakan rekursi untuk menyisipkan node sambil menjaga sifat BST, findNode yang juga rekursif untuk mencari nilai, dan kedua fungsi print yang melakukan traversal rekursif untuk mencetak nilai node dengan pemisah " - ". Sementara itu, main.cpp mendemonstrasikan penggunaan BST dengan membuat root kosong, menyisipkan nilai-nilai 6, 4, 2, 1, 3, 5, dan 7 secara berurutan, lalu mencetak hasil traversal preorder dan postorder. Kode ini menunjukkan BST yang valid, di mana nilai-nilai tersusun dalam struktur pohon biner yang terurut, dengan output preorder menampilkan urutan root terlebih dahulu dan postorder menampilkan root terakhir, sesuai dengan aturan traversal masing-masing.

## Kesimpulan
Tree merupakan struktur data non-linier yang bersifat hierarkis (memiliki hubungan parent-child), yang lebih efisien untuk pencarian dan manipulasi data kompleks dibandingkan struktur linier. Pemahaman terhadap terminologi dasar seperti root, leaf, height, dan depth menjadi pondasi utama dalam analisis struktur ini. Fokus utama dalam pemrograman sering kali terletak pada Binary Tree, yaitu varian di mana setiap node maksimal memiliki dua anak. Secara teknis, implementasi tree dalam C++ dilakukan menggunakan alokasi memori dinamis (dynamic memory allocation) melalui penggunaan pointer pada struct atau class, yang memungkinkan struktur data tersebut tumbuh secara fleksibel dan dinamis.

## Referensi
[1] T. H. Cormen, C. E. Leiserson, R. L. Rivest, and C. Stein, Introduction to Algorithms, 3rd ed. Cambridge, MA: MIT Press, 2009.
<br>[2] M. A. Weiss, Data Structures and Algorithm Analysis in C++, 4th ed. Boston, MA: Pearson Education, 2014.
<br>[3] D. S. Malik, Data Structures Using C++, 2nd ed. Boston, MA: Cengage Learning, 2010.
<br>[4] S. Lipschutz, Schaum's Outline of Data Structures with C, New York: McGraw-Hill Education, 2011.
<br>[5] B. Stroustrup, The C++ Programming Language, 4th ed. Boston, MA: Addison-Wesley, 2013.
