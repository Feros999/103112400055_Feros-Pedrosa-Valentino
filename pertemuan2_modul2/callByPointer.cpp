#include<iostream>
using namespace std;

void ubahNilai(int* ptr){
    *ptr = 20; //mengubah nilai yang ditunjuk oleh pointer
}

int main(){
    int x = 10;
    cout << "Nilai sebelum diubah: " << x << endl;

    ubahNilai(&x); //mengirim alamat memori x ke fungsi
    cout << "Nilai setelah diubah: " << x << endl;

    return 0;
}