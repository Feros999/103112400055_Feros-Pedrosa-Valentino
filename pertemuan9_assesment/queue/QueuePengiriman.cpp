#include "QueuePengiriman.h"

bool isEmpty(QueueEkspedisi &Q) {
    return Q.Tail == -1;
}

bool isFull(QueueEkspedisi &Q) {
    return Q.Tail == MAX - 1;
}

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

void enQueue(QueueEkspedisi &Q, Paket P) {
    if (isFull(Q)) {
        cout << "Antrian Penuh! Paket " << P.NamaPengirim << " tidak dapat masuk." << endl;
    } else {
        if (isEmpty(Q)) {
            Q.Head = 0;
            Q.Tail = 0;
            Q.dataPaket[Q.Tail] = P;
        } else {
            Q.Tail++;
            Q.dataPaket[Q.Tail] = P;
        }
        cout << "[ENQUEUE] Berhasil input paket resi: " << P.KodeResi << endl;
    }
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Antrian Kosong! Tidak ada paket untuk dihapus." << endl;
    } else {
        cout << "[DEQUEUE] Paket milik " << Q.dataPaket[Q.Head].NamaPengirim << " diproses/dihapus." << endl;

        if (Q.Head == Q.Tail) {
            Q.Head = -1;
            Q.Tail = -1;
        } else {
            for (int i = 0; i < Q.Tail; i++) {
                Q.dataPaket[i] = Q.dataPaket[i + 1];
            }
            Q.Tail--;
        }
    }
}

void viewQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Antrian Kosong." << endl;
    } else {
        cout << "\n--- Daftar Antrian Paket Komaniya Express ---" << endl;
        for (int i = Q.Head; i <= Q.Tail; i++) {
            cout << i + 1 << ". Resi: " << Q.dataPaket[i].KodeResi 
                 << " | Pengirim: " << Q.dataPaket[i].NamaPengirim 
                 << " | Berat: " << Q.dataPaket[i].BeratBarang << "kg"
                 << " | Tujuan: " << Q.dataPaket[i].Tujuan << endl;
        }
        cout << "---------------------------------------------" << endl;
    }
}

// Bagian B Menghitung Total Biaya
float TotalBiayaPengiriman(QueueEkspedisi &Q) {
    if (isEmpty(Q)) return 0;

    float totalBerat = 0;
    for (int i = Q.Head; i <= Q.Tail; i++) {
        totalBerat += Q.dataPaket[i].BeratBarang;
    }
    
    return totalBerat * 8250;
}