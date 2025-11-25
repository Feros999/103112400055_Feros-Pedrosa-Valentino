#include "StackMahasiswa.h"
#include <iomanip>

float hitungNilaiAkhir(Mahasiswa M) {
    return (0.2 * M.NilaiTugas) + (0.4 * M.NilaiUTS) + (0.4 * M.NilaiUAS);
}

bool isEmpty(StackMahasiswa &S) {
    return S.Top == -1;
}

bool isFull(StackMahasiswa &S) {
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa &S) {
    S.Top = -1;
}

void Push(StackMahasiswa &S, Mahasiswa M) {
    if (isFull(S)) {
        cout << "Stack Penuh! Tidak bisa push data " << M.Nama << endl;
    } else {
        S.Top++;
        S.dataMahasiswa[S.Top] = M;
        cout << "[PUSH] Berhasil menambahkan: " << M.Nama << endl;
    }
}

void Pop(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong! Tidak bisa pop." << endl;
    } else {
        cout << "[POP] Menghapus data teratas: " << S.dataMahasiswa[S.Top].Nama << endl;
        S.Top--;
    }
}

void Update(StackMahasiswa &S, int posisi, Mahasiswa M) {
    int index = posisi - 1;
    if (index < 0 || index > S.Top) {
        cout << "Posisi tidak valid atau data tidak ada di posisi tersebut." << endl;
    } else {
        S.dataMahasiswa[index] = M;
        cout << "[UPDATE] Data pada posisi " << posisi << " berhasil diubah menjadi " << M.Nama << endl;
    }
}

void View(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong." << endl;
        return;
    }
    cout << "\n--- Isi Stack (Atas ke Bawah) ---" << endl;
    for (int i = S.Top; i >= 0; i--) {
        float na = hitungNilaiAkhir(S.dataMahasiswa[i]);
        cout << "Posisi " << (i + 1) << " | " 
             << S.dataMahasiswa[i].Nama << " (" << S.dataMahasiswa[i].NIM << ") "
             << "| NA: " << fixed << setprecision(2) << na << endl;
    }
    cout << "---------------------------------\n" << endl;
}

void SearchNilaiAkhir(StackMahasiswa &S, float min, float max) {
    cout << "--- Hasil Search (Range NA: " << min << " - " << max << ") ---" << endl;
    bool found = false;
    for (int i = S.Top; i >= 0; i--) {
        float na = hitungNilaiAkhir(S.dataMahasiswa[i]);
        if (na >= min && na <= max) {
            cout << "Ditemukan pada Posisi " << (i + 1) << ": " 
                 << S.dataMahasiswa[i].Nama << " (NA: " << na << ")" << endl;
            found = true;
        }
    }
    if (!found) cout << "Tidak ada data yang ditemukan dalam rentang tersebut." << endl;
    cout << endl;
}

void MaxNilaiAkhir(StackMahasiswa &S) {
    if (isEmpty(S)) return;

    float maxVal = -1;
    int maxIdx = -1;

    for (int i = 0; i <= S.Top; i++) {
        float na = hitungNilaiAkhir(S.dataMahasiswa[i]);
        if (na > maxVal) {
            maxVal = na;
            maxIdx = i;
        }
    }

    cout << "--- Mahasiswa Nilai Akhir Terbesar ---" << endl;
    cout << "Nama   : " << S.dataMahasiswa[maxIdx].Nama << endl;
    cout << "NIM    : " << S.dataMahasiswa[maxIdx].NIM << endl;
    cout << "Nilai  : " << maxVal << endl;
    cout << "Posisi : " << (maxIdx + 1) << endl; 
    cout << "--------------------------------------" << endl;
}