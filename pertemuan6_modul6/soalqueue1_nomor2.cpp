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

void InitAntrian(AntrianTugas &Q) {
    Q.Head = NULL;
    Q.Tail = NULL;
}

void TambahTugas(AntrianTugas &Q, infotype P) {
    ElmTugas* Bantu = new ElmTugas;
    
    if (Bantu == NULL) {
        cout << "Alokasi memori gagal!" << endl;
        return;
    }
    
    Bantu->info.Pekerjaan = P.Pekerjaan;
    Bantu->info.waktu = P.waktu;
    Bantu->info.Dikerjakan = 0;
    Bantu->info.Status = "unfinished";
    
    if (Q.Head == NULL) {
        Q.Head = Bantu;
        Q.Tail = Bantu;
        Bantu->next = Q.Head;
    } else {
        Bantu->next = Q.Head;
        Q.Tail->next = Bantu;
        Q.Tail = Bantu;
    }
}

// Fungsi untuk mengecek apakah semua tugas selesai
bool SemuaTugasSelesai(AntrianTugas Q) {
    if (Q.Head == NULL) return true;
    
    ElmTugas* current = Q.Head;
    do {
        if (current->info.Status != "finished") {
            return false;
        }
        current = current->next;
    } while (current != Q.Head);
    
    return true;
}

// Fungsi untuk menghitung jumlah tugas yang belum selesai
int HitungTugasAktif(AntrianTugas Q) {
    if (Q.Head == NULL) return 0;
    
    int count = 0;
    ElmTugas* current = Q.Head;
    do {
        if (current->info.Status != "finished") {
            count++;
        }
        current = current->next;
    } while (current != Q.Head);
    
    return count;
}

// Fungsi untuk menghapus satu tugas dari circular linked list
void HapusTugas(AntrianTugas &Q, char pekerjaan) {
    if (Q.Head == NULL) return;
    
    ElmTugas* current = Q.Head;
    ElmTugas* prev = Q.Tail;
    
    do {
        if (current->info.Pekerjaan == pekerjaan) {
            // Jika hanya ada satu node
            if (current == Q.Head && current == Q.Tail) {
                delete current;
                Q.Head = NULL;
                Q.Tail = NULL;
                return;
            }
            // Jika node yang dihapus adalah Head
            else if (current == Q.Head) {
                Q.Head = current->next;
                Q.Tail->next = Q.Head;
                delete current;
                return;
            }
            // Jika node yang dihapus adalah Tail
            else if (current == Q.Tail) {
                Q.Tail = prev;
                prev->next = Q.Head;
                delete current;
                return;
            }
            // Node di tengah
            else {
                prev->next = current->next;
                delete current;
                return;
            }
        }
        prev = current;
        current = current->next;
    } while (current != Q.Head);
}

// PROCEDURE DAILYTASK - OUTPUT 22 JAM
void DailyTask(AntrianTugas &Q) {
    if (Q.Head == NULL) {
        cout << "Antrian kosong!" << endl;
        return;
    }
    
    int totalWaktu = 0;
    ElmTugas* current = Q.Head;
    
    cout << "\n=== Memproses Tugas (Round Robin) ===" << endl;
    
    // Loop sampai semua tugas selesai
    while (!SemuaTugasSelesai(Q)) {
        // PERBAIKAN KUNCI: Skip tugas yang sudah finished
        if (current->info.Status != "finished") {
            // Proses tugas saat ini
            current->info.Dikerjakan++;
            totalWaktu++;
            
            cout << "Jam ke-" << totalWaktu << ": Mengerjakan tugas " 
                 << current->info.Pekerjaan << " (Progress: " 
                 << current->info.Dikerjakan << "/" << current->info.waktu << ")";
            
            // Cek apakah tugas ini selesai
            if (current->info.Dikerjakan >= current->info.waktu) {
                current->info.Status = "finished";
                cout << " -> SELESAI!";
            }
            cout << endl;
        }
        
        // Pindah ke tugas berikutnya (circular)
        current = current->next;
    }
    
    cout << "\n=== Menghapus Tugas yang Selesai ===" << endl;
    
    // Simpan daftar tugas yang akan dihapus
    char tugasSelesai[10];
    int jumlahSelesai = 0;
    
    current = Q.Head;
    if (current != NULL) {
        do {
            if (current->info.Status == "finished") {
                tugasSelesai[jumlahSelesai] = current->info.Pekerjaan;
                jumlahSelesai++;
            }
            current = current->next;
        } while (current != Q.Head);
    }
    
    // Hapus satu per satu
    for (int i = 0; i < jumlahSelesai; i++) {
        cout << "Menghapus tugas " << tugasSelesai[i] << endl;
        HapusTugas(Q, tugasSelesai[i]);
    }
    
    cout << "\n========== OUTPUT ==========" << endl;
    cout << "Total = " << totalWaktu << " jam" << endl;
    cout << "============================" << endl;
}

void TampilkanAntrian(AntrianTugas Q) {
    if (Q.Head == NULL) {
        cout << "Antrian kosong!" << endl;
        return;
    }
    
    ElmTugas* current = Q.Head;
    cout << "\n=== Daftar Tugas ===" << endl;
    do {
        cout << "Pekerjaan: " << current->info.Pekerjaan 
             << " | Waktu: " << current->info.waktu 
             << " | Dikerjakan: " << current->info.Dikerjakan
             << " | Status: " << current->info.Status << endl;
        current = current->next;
    } while (current != Q.Head);
    cout << "====================" << endl;
}

int main() {
    AntrianTugas Q;
    InitAntrian(Q);
    
    // Menambahkan tugas sesuai soal: A=9, B=7, C=5, D=1
    infotype tugas1 = {'A', 9, 0, "unfinished"};
    infotype tugas2 = {'B', 7, 0, "unfinished"};
    infotype tugas3 = {'C', 5, 0, "unfinished"};
    infotype tugas4 = {'D', 1, 0, "unfinished"};
    
    cout << "=== Menambahkan Tugas ===" << endl;
    TambahTugas(Q, tugas1);
    cout << "Tugas A (waktu: 9 jam) ditambahkan" << endl;
    TambahTugas(Q, tugas2);
    cout << "Tugas B (waktu: 7 jam) ditambahkan" << endl;
    TambahTugas(Q, tugas3);
    cout << "Tugas C (waktu: 5 jam) ditambahkan" << endl;
    TambahTugas(Q, tugas4);
    cout << "Tugas D (waktu: 1 jam) ditambahkan" << endl;
    
    TampilkanAntrian(Q);
    
    // Jalankan DailyTask
    DailyTask(Q);
    
    // Tampilkan antrian setelah DailyTask
    cout << "\n=== Antrian Setelah DailyTask ===" << endl;
    TampilkanAntrian(Q);
    
    return 0;
}
