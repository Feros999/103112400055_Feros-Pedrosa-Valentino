#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float akhir;
};

float hitungAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa data[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> n;

    if (n > 10 || n < 1) {
        cout << "Jumlah mahasiswa tidak valid!" << endl;
        return 1;
    }

    // Input data mahasiswa
    for (int i = 0; i < n; i++) {
        cout << "\n--- Data Mahasiswa ke-" << (i + 1) << " ---" << endl;
        cout << "Nama: ";
        cin.ignore();
        getline(cin, data[i].nama);
        cout << "NIM: ";
        cin >> data[i].nim;
        cout << "Nilai UTS: ";
        cin >> data[i].uts;
        cout << "Nilai UAS: ";
        cin >> data[i].uas;
        cout << "Nilai Tugas: ";
        cin >> data[i].tugas;

        data[i].akhir = hitungAkhir(data[i].uts, data[i].uas, data[i].tugas);

        cout << "Nilai Akhir: " << data[i].akhir << endl;
    }

    cout << "\n=== DAFTAR DATA MAHASISWA ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << (i + 1) << ":" << endl;
        cout << "Nama: " << data[i].nama << endl;
        cout << "NIM: " << data[i].nim << endl;
        cout << "UTS: " << data[i].uts << endl;
        cout << "UAS: " << data[i].uas << endl;
        cout << "Tugas: " << data[i].tugas << endl;
        cout << "Nilai Akhir: " << data[i].akhir << endl;
    }

    return 0;
}