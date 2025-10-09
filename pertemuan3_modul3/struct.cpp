#include<iostream>
using namespace std;

struct mahasiswa{
    string nama;
    float nilai1, nilai2;
};

void inputMhs(struct mahasiswa &m){
    cout << "Masukkan nama mahasiswa: ";
    cin >> m.nama;
    cout << "Input Nilai 1: ";
    cin >> m.nilai1;
    cout << "Input Nilai 2: ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m){
    return float (m.nilai1 + m.nilai2) / 2;
}

int main(){
    mahasiswa mhs; //pemanggilan struct (ADT)
    inputMhs(mhs); //pemangilan prosedur
    cout << "Rata-rata: " << rata2(mhs) << endl;
    return 0;
}