#include <iostream>
#include <string>
using namespace std;

// Definisi Struktur Buku
struct Buku {
    string judul;
    string penulis;
};

// Definisi Struktur RakBuku (Stack)
struct RakBuku {
    Buku data[12];
    int top;
    static const int KAPASITAS = 12;
    
    RakBuku() {
        top = -1;
    }
};

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(RakBuku S) {
    return S.top == -1;
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(RakBuku S) {
    return S.top == RakBuku::KAPASITAS - 1;
}

// ========== PROSEDUR PUSH ==========
void Push(RakBuku &S, string judul, string penulis) {
    if (isFull(S)) {
        cout << "Rak penuh! Tidak bisa menambah buku." << endl;
    } else {
        S.top++;
        S.data[S.top].judul = judul;
        S.data[S.top].penulis = penulis;
        cout << "Buku '" << judul << "' berhasil ditambahkan ke rak." << endl;
    }
}

// ========== PROSEDUR POP ==========
void Pop(RakBuku &S, string &judul, string &penulis) {
    if (isEmpty(S)) {
        cout << "Rak kosong! Tidak ada buku yang bisa diambil." << endl;
        judul = "";
        penulis = "";
    } else {
        judul = S.data[S.top].judul;
        penulis = S.data[S.top].penulis;
        S.top--;
        cout << "Buku '" << judul << "' diambil dari rak." << endl;
    }
}

// ========== PROSEDUR GET ==========
void Get(RakBuku &S, string judul, string &namaPenulis) {
    RakBuku temp;
    temp.top = -1;
    bool ketemu = false;
    string judulTemp, penulisTemp;
    
    // Cari buku dengan judul tertentu
    while (!isEmpty(S) && !ketemu) {
        Pop(S, judulTemp, penulisTemp);
        
        if (judulTemp == judul) {
            namaPenulis = penulisTemp;
            ketemu = true;
            cout << "Buku ditemukan! Penulis: " << namaPenulis << endl;
        } else {
            // Simpan ke stack temporary
            Push(temp, judulTemp, penulisTemp);
        }
    }
    
    // Kembalikan buku-buku yang sempat diambil
    while (!isEmpty(temp)) {
        Pop(temp, judulTemp, penulisTemp);
        Push(S, judulTemp, penulisTemp);
    }
    
    if (!ketemu) {
        cout << "Buku dengan judul '" << judul << "' tidak ditemukan." << endl;
        namaPenulis = "";
    }
}

// Fungsi untuk menampilkan isi rak
void tampilkanRak(RakBuku S) {
    if (isEmpty(S)) {
        cout << "Rak kosong." << endl;
    } else {
        cout << "\n=== ISI RAK BUKU (dari atas ke bawah) ===" << endl;
        for (int i = S.top; i >= 0; i--) {
            cout << (S.top - i + 1) << ". " << S.data[i].judul 
                << " - " << S.data[i].penulis << endl;
        }
        cout << "Jumlah buku: " << (S.top + 1) << "/" << RakBuku::KAPASITAS << endl;
    }
}

int main() {
    RakBuku rak;
    int pilihan;
    string judul, penulis;
    
    cout << "========================================" << endl;
    cout << "   PROGRAM MANAJEMEN RAK BUKU (STACK)   " << endl;
    cout << "========================================" << endl;
    
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Tambah buku (Push)" << endl;
        cout << "2. Ambil buku teratas (Pop)" << endl;
        cout << "3. Cari buku berdasarkan judul (Get)" << endl;
        cout << "4. Tampilkan isi rak" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        
        switch(pilihan) {
            case 1:
                cout << "Masukkan judul buku: ";
                getline(cin, judul);
                cout << "Masukkan nama penulis: ";
                getline(cin, penulis);
                Push(rak, judul, penulis);
                break;
                
            case 2:
                Pop(rak, judul, penulis);
                if (judul != "") {
                    cout << "Judul: " << judul << endl;
                    cout << "Penulis: " << penulis << endl;
                }
                break;
                
            case 3:
                cout << "Masukkan judul buku yang dicari: ";
                getline(cin, judul);
                Get(rak, judul, penulis);
                break;
                
            case 4:
                tampilkanRak(rak);
                break;
                
            case 5:
                cout << "Terima kasih!" << endl;
                break;
                
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);
    
    return 0;
}