#include <iostream>
using namespace std;

int main() {
    float bilanganPertama, bilanganKedua;
    float hasilPenjumlahan, hasilPengurangan, hasilPerkalian, hasilPembagian;
    
    cout << "Masukkan bilangan pertama: ";
    cin >> bilanganPertama;
    cout << "Masukkan bilangan kedua: ";
    cin >> bilanganKedua;
    
    hasilPenjumlahan = bilanganPertama + bilanganKedua;
    hasilPengurangan = bilanganPertama - bilanganKedua;
    hasilPerkalian = bilanganPertama * bilanganKedua;
    hasilPembagian = bilanganPertama / bilanganKedua; 
    
    cout << "Hasil penjumlahan: " << hasilPenjumlahan << endl;
    cout << "Hasil pengurangan: " << hasilPengurangan << endl;
    cout << "Hasil perkalian: " << hasilPerkalian << endl;
    cout << "Hasil pembagian: " << hasilPembagian << endl;
    
    return 0;
}