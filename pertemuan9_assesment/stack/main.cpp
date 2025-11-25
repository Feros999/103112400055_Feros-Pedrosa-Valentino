#include <iostream>
#include "StackMahasiswa.h" 

using namespace std;

int main() {
    StackMahasiswa stackMhs;
    
    createStack(stackMhs);

    cout << "=== MELAKUKAN INPUT DATA (PUSH) ===" << endl;
    Push(stackMhs, {"Venti", "11111", 75.7, 82.1, 65.5});
    Push(stackMhs, {"Xiao", "22222", 87.4, 88.9, 81.9});
    Push(stackMhs, {"Kazuha", "33333", 92.3, 88.8, 82.4});
    Push(stackMhs, {"Wanderer", "44444", 95.5, 85.5, 90.5});
    Push(stackMhs, {"Lynette", "55555", 77.7, 65.4, 79.9});
    Push(stackMhs, {"Chasca", "66666", 99.9, 93.6, 87.3});

    View(stackMhs);

    Pop(stackMhs);

    View(stackMhs);

    Mahasiswa mhsUpdate = {"Heizou", "77777", 99.9, 88.8, 77.7};
    Update(stackMhs, 3, mhsUpdate);

    View(stackMhs);

    SearchNilaiAkhir(stackMhs, 85.5, 95.5);

    MaxNilaiAkhir(stackMhs);

    return 0;
}