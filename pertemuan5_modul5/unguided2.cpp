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