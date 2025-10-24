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