# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Feros Pedrosa Valentino - 103112400055</p>

## Dasar Teori
ADT adalah TYPE dan sekumpulan PRIMITIF (operasi dasar) terhadap TYPE tersebut. Selain itu, dalam sebuah ADT yang lengkap, disertakan pula definisi invarian dari TYPE dan aksioma yang berlaku. ADT merupakan definisi STATIK[2]. Dalam C++, ADT dapat dibuat dalam sebuah Class. Class memiliki data dan fungsi[1]. Data dan fungsi yang dideklarasi private tidak dapat diakses secara langsung oleh client, sementara data dan fungsi yang dideklarasi public akan bersifat publik dan dapat diakses oleh client secara langsung. ADT didefinisikan sebagai model matematis untuk suatu tipe data yang menentukan sekumpulan operasi abstrak yang dapat dilakukan pada data tersebut, tanpa mempedulikan bagaimana implementasinya secara detail [3]. Dalam konteks struktur data, ADT memisahkan antarmuka (interface) dari implementasi (implementation). Hal ini memungkinkan pengembang untuk fokus pada "apa yang dilakukan" (what) daripada "bagaimana dilakukan" (how). 
ADT memiliki beberapa karakteristik utama yang mendukung abstraksi dan fleksibilitasnya. Pertama, abstraksi dicapai melalui prinsip encapsulation dalam pemrograman berorientasi objek, di mana detail internal data seperti array atau linked list disembunyikan, dan hanya operasi yang diperlukan yang diekspos [4]. Kedua, setiap ADT didefinisikan oleh sekumpulan operasi primitif, termasuk constructor untuk membuat instance baru (misalnya, membuat stack kosong), destructor untuk membersihkan sumber daya, accessor operations seperti isEmpty() atau size() yang mengakses data tanpa mengubahnya [3], mutator operations seperti push() untuk stack atau enqueue() untuk queue yang mengubah data, serta predicate operations seperti isFull() yang mengembalikan nilai boolean. Selain itu, ADT menentukan tipe data dan domain nilai yang valid serta rentang operasi yang diperbolehkan, dengan independensi implementasi yang memungkinkan berbagai cara realisasi (misalnya, array atau pointer) asalkan antarmuka tetap konsisten [3].


## Guided 

### 1. Guided 1 (mahasiswa)

mahasiswa.h
```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H

//Defini Tipe (Struct)
struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

//Deklarasi Primitif (Fungsi)
void inputMhs(struct mahasiswa &m);
float rata2(mahasiswa m);

#endif
```

mahasiswa.cpp
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

//Realisasi dari Fungsi inputMhs
void inputMhs(struct mahasiswa &m){
    cout << "Input NIM: ";
    cin >> m.nim;
    cout << "Input Nilai 1: ";
    cin >> m.nilai1;
    cout << "Input Nilai 2: ";
    cin >> m.nilai2;
}

//Realisasi dari Fungsi rata2
float rata2(mahasiswa m){
    return (float)(m.nilai1 + m.nilai2) / 2;
}
```

main.cpp
```C++
#include <iostream>
#include "mahasiswa.h"
#include <cstdlib>

using namespace std;

int main(){
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "Rata-rata nilai adalah: " << rata2(mhs) << endl;
    system("pause");

    return 0;
}
```
Program diatas dibuat dalam bahasa C++ dan mengimplementasikan konsep modularitas dengan memisahkan definisi, implementasi, dan penggunaan fungsi menggunakan tiga file terpisah.  File header "mahasiswa.h" mendefinisikan struct "mahasiswa" yang berisi array karakter "nim" untuk nomor induk mahasiswa (ukuran 10) serta dua integer "nilai1" dan "nilai2", diikuti deklarasi fungsi "inputMhs" (menggunakan referensi struct untuk input data) dan "rata2" (mengembalikan float rata-rata nilai). File "mahasiswa.cpp" merealisasikan kedua fungsi tersebut: "inputMhs" menggunakan cout dan cin untuk memasukkan NIM serta kedua nilai ke dalam struct, sementara "rata2" menghitung rata-rata aritmatika dengan konversi ke float untuk menghindari pembagian integer. File "main.cpp" berisi fungsi utama yang membuat variabel struct "mhs", memanggil "inputMhs" untuk mengisi data, menampilkan hasil rata-rata melalui cout, menambahkan "system('pause')" untuk menjeda eksekusi dan mengakhiri program dengan return 0.

### 2. Guided 2 (struct)

```C++
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
```
Program diatas dibuat dalam bahasa C++ yang berfungsi untuk mengelola data mahasiswa.  Struct bernama "mahasiswa" didefinisikan dengan anggota string "nama" dan dua float "nilai1" serta "nilai2" untuk menyimpan informasi mahasiswa. Fungsi "inputMhs" menerima referensi struct mahasiswa (&m) untuk menginput nama dan kedua nilai melalui cin, memungkinkan modifikasi data secara efisien tanpa duplikasi. Fungsi "rata2" berguna untuk menghitung rata-rata aritmatika dari nilai1 dan nilai2 dengan mengembalikan hasil pembagian (m.nilai1 + m.nilai2) / 2 sebagai float. Di fungsi main, sebuah variabel struct "mhs" dibuat, kemudian dipanggil inputMhs untuk mengisi data, dan terakhir rata-rata ditampilkan menggunakan cout beserta hasil dari fungsi rata2.


## Unguided 

### 1. Soal Unguided 1
Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan3_modul3/output1-unguided1-modul3.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan3_modul3/output2-unguided1-modul3.png)

Program diatas dibuat dalam bahasa C++ yang berfungsi untuk mengelola data mahasiswa dengan kapasitas maksimal 10 orang, menggunakan array yang mencakup field nama (string), NIM (string), nilai UTS, UAS, tugas (float), serta nilai akhir (float). Fungsi hitungAkhir menghitung nilai akhir berdasarkan rumus 0.3 × UTS + 0.4 × UAS + 0.3 × tugas. Di fungsi main, program pertama-tama meminta input jumlah mahasiswa n dan memvalidasi agar berada antara 1 hingga 10; jika tidak valid, program berhenti dan akan menampilkan pesan tidak valid. Selanjutnya, melalui loop for, program menginput data untuk setiap mahasiswa yaitu nama diambil menggunakan getline setelah cin.ignore() untuk menangani spasi, sementara NIM dan nilai-nilai numerik diinput via cin, diikuti perhitungan dan tampilan nilai akhir secara langsung. Setelah semua input selesai, loop kedua menampilkan daftar lengkap data mahasiswa dalam format terstruktur, termasuk semua field dan nilai akhir.

### 2. Soal Unguided 2
Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h":
Type pelajaran <
    namamapel: string
    kodeMapel: string
>
function create_pelajaran ( namapel: string,
    kodepel: string) → pelajaran
procedure tampil_pelajaran (input pel: pelajaran )

Buatlah implementasi ADT pelajaran pada file "pelajaran.cpp"
Cobalah hasil implementasi ADT pada file "main.cpp"

pelajaran.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

// Definisi tipe data pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodeMapel);

void tampil_pelajaran(pelajaran pel);

#endif
```

pelajaran.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

// Implementasi fungsi create_pelajaran
pelajaran create_pelajaran(string namaMapel, string kodeMapel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodeMapel;
    return p;
}

// Implementasi prosedur tampil_pelajaran
void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```

mainpelajaran.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan3_modul3/output-unguided2-modul3.png)

Program diatas dibuat dalam bahasa C++ dan merupakan implementasi sederhana dalam bahasa C++ untuk mengelola data mata pelajaran (pelajaran) menggunakan struktur data dan fungsi modular. File header pelajaran.h mendefinisikan struktur pelajaran yang terdiri dari dua anggota yaitu namaMapel (nama mata pelajaran sebagai string) dan kodeMapel (kode mata pelajaran sebagai string), serta mendeklarasikan fungsi create_pelajaran untuk membuat instance struktur dan prosedur tampil_pelajaran untuk menampilkan data tersebut. File pelajaran.cpp berisi implementasi fungsi tersebut yaitu create_pelajaran menginisialisasi struktur dengan nilai nama dan kode yang diberikan, sementara tampil_pelajaran mencetak nama pelajaran dan kode pelajaran. File mainpelajaran.cpp adalah program utama yang mendemonstrasikan penggunaan modul ini dengan membuat variabel string untuk nama "Struktur Data" dan kode "STD", kemudian memanggil create_pelajaran untuk membentuk objek pelajaran dan tampil_pelajaran untuk menampilkannya di layar, menghasilkan output nama dan kode pelajaran tersebut.

### 3. Soal Unguided 3
Buatlah program dengan ketentuan :
-2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
-fungsi/prosedur yang menampilkan isi sebuah array integer 2D
-fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
-fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan3_modul3/output-unguided3-modul3.png)

Program diatas dibuat dalam bahasa C++ dan merupakan demonstrasi penggunaan array 2D dan pointer untuk operasi pertukaran data. Fungsi tampilArray menampilkan isi array 2D berukuran 3x3 dengan loop bersarang, mencetak elemen-elemennya baris demi baris diikuti spasi dan baris baru. Fungsi tukarElemenArray menukar elemen pada posisi baris i dan kolom j antara dua array 2D menggunakan variabel sementara temp, sehingga memungkinkan pertukaran tanpa kehilangan data. Fungsi tukarPointer melakukan hal serupa untuk nilai yang ditunjuk oleh dua pointer integer, dengan dereferencing (*p1 dan *p2) untuk mengakses dan menukar nilai variabel asli. Di fungsi main, dua array 2D arr1 dan arr2 diinisialisasi dengan nilai 1-9 dan 10-18 masing-masing, serta dua variabel a (100) dan b (200) dengan pointer ptr1 dan ptr2 yang menunjukkannya. Program menampilkan isi array awal, menukar elemen pada posisi (1,1) antara kedua array (sehingga 5 dan 14 bertukar), menampilkan hasilnya, kemudian menukar nilai yang ditunjuk pointer (sehingga 100 dan 200 bertukar), dan mencetak perubahan tersebut.

## Kesimpulan
Abstract Data Type (ADT) menjadi fondasi penting dalam struktur data yang menekankan abstraksi melalui pemisahan antarmuka dari implementasi, memungkinkan pengembang fokus pada fungsionalitas esensial tanpa terbebani detail teknis. ADT tidak hanya mencakup tipe data beserta operasi primitif seperti constructor, destructor, accessor, mutator, dan predicate, tetapi juga definisi invarian, aksioma, serta domain nilai yang valid untuk memastikan konsistensi dan independensi implementasi. Karakteristik utamanya, seperti encapsulation yang menyembunyikan detail internal (misalnya, array atau linked list) sambil mengekspos operasi publik, mendukung fleksibilitas dan modularitas dalam pemrograman berorientasi objek. Di bahasa C++, ADT direalisasikan secara efektif melalui class yang membedakan elemen private dari public, sehingga memfasilitasi desain perangkat lunak yang reusable dan mudah dipelihara.

## Referensi
[1] (N.d.). Retrieved from https://rizkimuliono.blog.uma.ac.id/wp-content/uploads/sites/365/2017/05/ADT-Abstract-Data-Type.pdf
<br>[2] Modul 3 - Praktikum Struktur Data
<br>[3] Goodrich, M. T., Tamassia, R., & Mount, D. M. (2011). Data Structures and Algorithms in C++ (2nd ed.). Wiley.
<br>[4] Stroustrup, B. (2013). The C++ Programming Language (4th ed.). Addison-Wesley.
