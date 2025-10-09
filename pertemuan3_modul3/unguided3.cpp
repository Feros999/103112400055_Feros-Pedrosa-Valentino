#include <iostream>
using namespace std;

void tampilArray(int arr[][3], int baris = 3, int kolom = 3) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void tukarElemenArray(int arr1[][3], int arr2[][3], int i, int j) {
    int temp = arr1[i][j];
    arr1[i][j] = arr2[i][j];
    arr2[i][j] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    // 2 buah array 2D integer berukuran 3x3
    int arr1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int arr2[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };
    
    // 2 buah pointer integer
    int a = 100;
    int b = 200;
    int *ptr1 = &a;
    int *ptr2 = &b;
    
    cout << "Isi array 1 awal:" << endl;
    tampilArray(arr1);
    
    cout << "Isi array 2 awal:" << endl;
    tampilArray(arr2);
    
    cout << "Setelah menukar elemen pada posisi (1,1) antara array 1 dan 2:" << endl;
    tukarElemenArray(arr1, arr2, 1, 1);
    tampilArray(arr1);
    tampilArray(arr2);
    
    // Demonstrasi tukar pointer
    cout << "Nilai yang ditunjuk pointer 1 dan 2 awal: " << *ptr1 << " dan " << *ptr2 << endl;
    tukarPointer(ptr1, ptr2);
    cout << "Setelah menukar nilai yang ditunjuk pointer: " << *ptr1 << " dan " << *ptr2 << endl;
    
    return 0;
}