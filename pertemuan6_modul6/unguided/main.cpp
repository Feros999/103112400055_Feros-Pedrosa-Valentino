#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    address P;
    infotype data;
    int n;
    
    // ========================================
    // SOAL 1: Input data secara dinamis dari pengguna
    // ========================================
    cout << "Masukkan jumlah kendaraan: ";
    cin >> n;
    cin.ignore(); // membersihkan buffer
    
    for (int i = 0; i < n; i++) {
        cout << "\nKendaraan ke-" << (i + 1) << endl;
        cout << "No polisi: ";
        getline(cin, data.nopol);
        cout << "Warna    : ";
        getline(cin, data.warna);
        cout << "Tahun    : ";
        cin >> data.thnBuat;
        cin.ignore(); // membersihkan buffer
        
        P = alokasi(data);
        insertLast(L, P);
    }
    
    // Tampilkan data awal
    cout << "\n====================================\n";
    cout << "DATA LIST AWAL" << endl;
    cout << "====================================\n";
    printInfo(L);
    
    // ========================================
    // SOAL 2: Mencari elemen berdasarkan input nomor polisi dari pengguna
    // ========================================
    cout << "====================================\n";
    cout << "MENCARI DATA KENDARAAN" << endl;
    cout << "====================================\n";
    string cariNopol;
    cout << "Masukkan nomor polisi yang dicari: ";
    getline(cin, cariNopol);
    
    infotype cari;
    cari.nopol = cariNopol;
    address found = findElm(L, cari);
    
    if (found != Nil) {
        cout << "\nDitemukan:" << endl;
        cout << "no polisi: " << found->info.nopol << endl;
        cout << "warna    : " << found->info.warna << endl;
        cout << "tahun    : " << found->info.thnBuat << endl;
    } else {
        cout << "\nData dengan nomor polisi " << cariNopol << " tidak ditemukan.\n";
    }
    
    // ========================================
    // SOAL 3: Hapus elemen berdasarkan input nomor polisi dari pengguna
    // ========================================
    cout << "\n====================================\n";
    cout << "MENGHAPUS DATA KENDARAAN" << endl;
    cout << "====================================\n";
    string hapusNopol;
    cout << "Masukkan nomor polisi yang akan dihapus: ";
    getline(cin, hapusNopol);
    
    // Cari elemen yang akan dihapus
    infotype hapus;
    hapus.nopol = hapusNopol;
    address toDelete = findElm(L, hapus);
    
    if (toDelete != Nil) {
        // Tentukan posisi elemen yang akan dihapus
        if (toDelete == L.first) {
            // Gunakan deleteFirst
            address temp;
            deleteFirst(L, temp);
            dealokasi(temp);
            cout << "\nData dengan nomor polisi " << hapusNopol << " berhasil dihapus (deleteFirst).\n";
        } else if (toDelete == L.last) {
            // Gunakan deleteLast
            address temp;
            deleteLast(L, temp);
            dealokasi(temp);
            cout << "\nData dengan nomor polisi " << hapusNopol << " berhasil dihapus (deleteLast).\n";
        } else {
            // Gunakan deleteAfter
            address Prec = toDelete->prev;
            address temp;
            deleteAfter(Prec, temp);
            dealokasi(temp);
            cout << "\nData dengan nomor polisi " << hapusNopol << " berhasil dihapus (deleteAfter).\n";
        }
    } else {
        cout << "\nData dengan nomor polisi " << hapusNopol << " tidak ditemukan.\n";
    }
    
    // Tampilkan data setelah penghapusan
    cout << "\n====================================\n";
    cout << "DATA LIST SETELAH PENGHAPUSAN" << endl;
    cout << "====================================\n";
    printInfo(L);
    
    return 0;
}