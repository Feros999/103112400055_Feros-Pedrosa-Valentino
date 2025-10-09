#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

struct List {
    Node* first;
    Node* last;
};

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

Node* createNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void insertLast(List &L, int x) {
    Node* p = createNode(x);
    if (L.first == NULL) {
        L.first = L.last = p;
    } else {
        L.last->next = p;
        L.last = p;
    }
}

// Fungsi mencari nilai X dalam list
Node* searchX(List L, int X) {
    Node* p = L.first;
    while (p != NULL && p->info != X)
        p = p->next;
    return p;
}

// Prosedur menghapus elemen sesuai aturan soal
void deleteByRule(List &L, int X) {
    Node* p = searchX(L, X);

    if (p == NULL) {
        cout << "Tidak ada elemen bernilai " << X << " dalam list." << endl;
        return;
    }

    // Jika X di awal list
    if (p == L.first) {
        L.first = L.first->next;
        if (L.first == NULL) L.last = NULL;
        delete p;
        cout << "Elemen " << X << " di awal list dihapus." << endl;
    }
    // Jika X di akhir list
    else if (p == L.last) {
        Node* q = L.first;
        while (q->next != L.last) q = q->next;
        delete L.last;
        L.last = q;
        L.last->next = NULL;
        cout << "Elemen " << X << " di akhir list dihapus." << endl;
    }
    // Jika X di tengah → hapus elemen setelah X
    else {
        Node* hapus = p->next;
        if (hapus != NULL) {
            p->next = hapus->next;
            if (hapus == L.last) L.last = p;
            cout << "Elemen setelah " << X << " (nilai " << hapus->info << ") dihapus." << endl;
            delete hapus;
        } else {
            cout << "Tidak ada elemen setelah " << X << " untuk dihapus." << endl;
        }
    }
}

void printList(List L) {
    if (L.first == NULL) {
        cout << "List kosong." << endl;
        return;
    }
    Node* p = L.first;
    cout << "Isi list: ";
    while (p != NULL) {
        cout << p->info;
        if (p->next != NULL) cout << " -> ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    List L;
    createList(L);
    int n, nilai, X;

    cout << "Masukkan jumlah elemen list: ";
    cin >> n;

    cout << "Masukkan " << n << " nilai untuk elemen list:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nilai ke-" << i + 1 << ": ";
        cin >> nilai;
        insertLast(L, nilai);
    }

    cout << "\nList yang dibuat: ";
    printList(L);

    cout << "\nMasukkan nilai X: ";
    cin >> X;

    cout << "\n=== Proses Penghapusan ===" << endl;
    deleteByRule(L, X);

    cout << "\nList setelah proses: ";
    printList(L);

    return 0;
}
