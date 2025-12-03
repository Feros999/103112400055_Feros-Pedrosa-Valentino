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