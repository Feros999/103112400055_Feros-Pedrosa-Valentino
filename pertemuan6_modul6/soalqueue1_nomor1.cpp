#include <iostream>
#include <string>
using namespace std;

struct infotype {
    char Pekerjaan;
    int waktu;
    int Dikerjakan;
    string Status;
};

struct ElmTugas {
    infotype info;
    ElmTugas* next;
};

struct AntrianTugas {
    ElmTugas* Head;
    ElmTugas* Tail;
};

// Inisialisasi antrian kosong
void InitAntrian(AntrianTugas &Q) {
    Q.Head = NULL;
    Q.Tail = NULL;
}

// PERBAIKAN: Procedure yang benar
void TambahTugas(AntrianTugas &Q, infotype P) {
    ElmTugas* Bantu = new ElmTugas;
    
    // PERBAIKAN 1: Cek alokasi memori
    if (Bantu == NULL) {
        cout << "Alokasi memori gagal!" << endl;
        return;
    }
    
    Bantu->info.Pekerjaan = P.Pekerjaan;
    Bantu->info.waktu = P.waktu;
    Bantu->info.Dikerjakan = 0;
    Bantu->info.Status = "unfinished";
    
    if (Q.Head == NULL) {
        // Antrian kosong
        Q.Head = Bantu;
        Q.Tail = Bantu;
        // PERBAIKAN 2: Buat circular dengan menunjuk ke Head
        Bantu->next = Q.Head;
    } else {
        // PERBAIKAN 3: Urutan yang benar
        Bantu->next = Q.Head;      // Node baru menunjuk ke Head (circular)
        Q.Tail->next = Bantu;      // Tail lama menunjuk ke node baru
        Q.Tail = Bantu;            // Update Tail ke node baru
    }
}

// Fungsi untuk menampilkan antrian
void TampilkanAntrian(AntrianTugas Q) {
    if (Q.Head == NULL) {
        cout << "Antrian kosong!" << endl;
        return;
    }
    
    ElmTugas* current = Q.Head;
    cout << "\n=== Daftar Tugas (Circular Linked List) ===" << endl;
    do {
        cout << "Pekerjaan: " << current->info.Pekerjaan 
             << " | Waktu: " << current->info.waktu 
             << " | Status: " << current->info.Status << endl;
        current = current->next;
    } while (current != Q.Head);
    cout << "==========================================" << endl;
}

// Fungsi untuk simulasi proses tugas
void ProsesTugas(AntrianTugas &Q) {
    if (Q.Head == NULL) {
        cout << "Tidak ada tugas untuk diproses!" << endl;
        return;
    }
    
    ElmTugas* current = Q.Head;
    do {
        current->info.Dikerjakan = current->info.waktu;
        current->info.Status = "finished";
        current = current->next;
    } while (current != Q.Head);
    
    cout << "\nSemua tugas telah selesai diproses!" << endl;
}

int main() {
    AntrianTugas Q;
    InitAntrian(Q);
    
    // Menambahkan tugas sesuai diagram
    infotype tugas1 = {'A', 9, 0, "unfinished"};
    infotype tugas2 = {'B', 7, 0, "unfinished"};
    infotype tugas3 = {'C', 5, 0, "unfinished"};
    infotype tugas4 = {'D', 1, 0, "unfinished"};
    
    cout << "=== Menambahkan Tugas ke Antrian ===" << endl;
    TambahTugas(Q, tugas1);
    cout << "Tugas A ditambahkan" << endl;
    TambahTugas(Q, tugas2);
    cout << "Tugas B ditambahkan" << endl;
    TambahTugas(Q, tugas3);
    cout << "Tugas C ditambahkan" << endl;
    TambahTugas(Q, tugas4);
    cout << "Tugas D ditambahkan" << endl;
    
    // Tampilkan antrian
    TampilkanAntrian(Q);
    
    // Proses semua tugas
    ProsesTugas(Q);
    
    // Tampilkan antrian setelah diproses
    TampilkanAntrian(Q);
    
    return 0;
}