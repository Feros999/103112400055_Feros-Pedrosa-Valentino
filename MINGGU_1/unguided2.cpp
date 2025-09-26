#include <iostream>
#include <string>
using namespace std;

int main() {
    int angkaMasukan;
    cout << "Masukkan angka bulat positif (0-100): ";
    cin >> angkaMasukan;
    string tulisanAngka;
    
    if (angkaMasukan < 0 || angkaMasukan > 100) {
        cout << "Angka harus antara 0 hingga 100!" << endl;
        return 1;
    }
    
    if (angkaMasukan == 0) {
        tulisanAngka = "nol";
    } else if (angkaMasukan == 100) {
        tulisanAngka = "seratus";
    } else if (angkaMasukan < 10) {
        string daftarSatuan[10] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
        tulisanAngka = daftarSatuan[angkaMasukan];
    } else if (angkaMasukan < 20) {
        string daftarBelasan[10] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", 
                                    "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
        tulisanAngka = daftarBelasan[angkaMasukan - 10];
    } else {
        int nilaiPuluhan = angkaMasukan / 10;
        int nilaiSatuan = angkaMasukan % 10;
        string daftarPuluhan[10] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};
        tulisanAngka = daftarPuluhan[nilaiPuluhan];
        
        if (nilaiSatuan > 0) {
            string daftarSatuan[10] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
            tulisanAngka += " " + daftarSatuan[nilaiSatuan];
        }
    }
    
    cout << angkaMasukan << " : " << tulisanAngka << endl;
    
    return 0;
}