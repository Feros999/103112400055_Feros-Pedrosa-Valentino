#include <iostream>
#include <iomanip>
#include "QueuePengiriman.h"

using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);
    
    int pilihan;
    Paket tempPaket;

    do {
        cout << "\n--- Komaniya Express ---" << endl;
        cout << "1. Input Data Paket (enQueue)" << endl;
        cout << "2. Hapus Data Paket (deQueue)" << endl;
        cout << "3. Tampilkan queue paket" << endl;
        cout << "4. Hitung Total Biaya Pengiriman" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan anda : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\nMasukkan Data Paket:" << endl;
                cout << "Kode Resi   : "; cin >> tempPaket.KodeResi;
                cout << "Nama Pengirim: "; cin >> tempPaket.NamaPengirim;
                cout << "Berat (kg)  : "; cin >> tempPaket.BeratBarang;
                cout << "Tujuan      : "; cin >> tempPaket.Tujuan;
                enQueue(Q, tempPaket);
                break;

            case 2:
                deQueue(Q);
                break;

            case 3:
                viewQueue(Q);
                break;

            case 4:
                // Bagian B (Hitung Biaya)
                cout << "\nTotal Biaya Pengiriman: Rp " 
                     << fixed << setprecision(2) << TotalBiayaPengiriman(Q) << endl;
                break;
            
            case 99: 
                enQueue(Q, {"123456", "Hutao", 14, "Sumeru"});
                enQueue(Q, {"234567", "Ayaka", 10, "Fontaine"});
                enQueue(Q, {"345678", "Bennet", 7, "Natlan"});
                enQueue(Q, {"456789", "Furina", 16, "Liyue"});
                enQueue(Q, {"567890", "Nefer", 6, "Inazuma"});
                cout << "Data soal otomatis dimuat!" << endl;
                break;

            case 0:
                cout << "Keluar dari program." << endl;
                break;

            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    return 0;
}