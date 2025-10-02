# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua) </h1>
<p align="center">Feros Pedrosa Valentino - 103112400055</p>

## Dasar Teori
Array merupakan struktur data yang digunakan untuk menyimpan sekumpulan data dalam satu tempat[1]. C++ tidak mempunyai tipe variabel yang dapat dipakai untuk menyimpan suatu string. Karena string merupakan kumpulan dari karakter-karakter maka string dapat disimpan dalam suatu karakter array. Deklarasi suatu array selalu memakai tanda kurung [ ], yang bilangan didalamnya menunjukkan jumlah tempat yang dipesan untuk array tersebut. Variabel pointer sering dikatakan sebagai variabel yang menunjuk ke obyek lain. Pada kenyataan yang sebenarnya, variabel pointer berisi alamat dari suatu obyek lain (yaitu obyek yang dikatakan ditunjuk oleh pointer). Array satu dimensi adalah kumpulan elemen-elemen identik yang tersusun dalam satu baris, tetapi isi dari elemen tersebut boleh berbeda[2]. Dapat disebut juga dengan istilah vektor yang menggambarkan data dalam suatu urutan. Array dua dimensi yang sering digambarkan sebagai sebuah matriks merupakan perluasan dari sebuah array satu dimensi. Jika array satu dimensi hanya terdiri dari sebuah baris dengan beberapa kolom elemen maka array dua dimensi terdiri dari beberapa baris dan beberapa kolom elemen yang bertipe sama. Pendeklarasian array dua dimensi hampir sama dengan pendeklarasian array satu dimensi, kecuali bahwa array dua dimensi terdapat dua jumlah elemen array yang terdapat di dalam kurung siku dan keduanya boleh tidak sama. Array merupakan bagian dari struktur data yaitu termasuk kedalam struktur data sederhana yang dapat di definisikan sebagai pemesanan alokasi memory sementara pada komputer. Pointer adalah variabel yang menyimpan atau menunjuk suatu alamat memori, bukan menyimpan suatu nilai data[3]. Karena itu, pointer tidak berhubungan langsung dengan kata yang aktual. Dengan kata lain, variabel pointer hanya berisi alamat variable yang lain hanya berisi data tertentu. Variabel pointer memiliki kelebihan dibanding variabel dengan tipe data lain yaitu bersifat dinamis. Pointer berfungsi untuk menyimpan alamat dari sebuah variabel dan dapat mengakses nilai yang ada di alamat 
tersebut, pointer dapat mengubah nilai, menampilkan nilai atau menampilkan alamat dari variabel yang disimpannya. Pointer sama seperti variabel lain, harus di deklarasikan terlebih dahulu sebelum digunakan.  Operator pada pointer ada dua, yaitu operator* dan operator&. Operator deference (&) yaitu mendeklarasikan suatu variabel didalam penggantian memori. Operator ini biasa disebut dengan “address of”. Operator Reference (*) yaitu dapat mengakses secara langsung nilai yang terdapat didalam variabel yang berpointer, hal ini dapat dilakukan dengan menambahkan identifier asterisk (*). Operator ini biasa disebut dengan “value pointed by”. Prosedur merupakan suatu program terpisah dalam blok sendiri yang berfungsi sebagai subprogram. Prosedur biasanya digunakan pada program yang terstruktur karena dapat memecah-mecah program yang rumit menjadi program-program bagian yang lebih sederhana dalam bentuk prosedur-prosedur, cukup dituliskan sekali dan dapat dipergunakan atau dipanggil berulangkali jika dibutuhkan, membuat kode program lebih mudah dibaca, dapat digunakan untuk menyembunyikan detail program[4]. Fungsi merupakan suatu program terpisah dalam blok sendiri yang berfungsi sebagai subprogram. Sama seperti halnya dengan prosedur, namun tetap ada perbedaannya yaitu fungsi mempunyai pengembalian nilai atau mengembalikan sebuah nilai (memiliki return value) dari tipe tertentu (tipe dasar atau tipe bentukan).

### A. Array<br/>
Array merupakan kumpulan data dengan nama yang sama dan setiap elemen bertipe data sama. Untuk mengakses setiap komponen / elemen array berdasarkan indeks dari setiap elemen[5].
#### 1. Array Satu Dimensi
Adalah array yang hanya terdiri dari satu larik data saja. Dalam C++ data array disimpan dalam memori pada lokasi yang berurutan. Elemen pertama memiliki indeks 0 dan selemen selanjutnya memiliki indeks 1 dan seterusnya. Jadi jika terdapat array dengan 5 elemen maka elemen pertama memiliki indeks 0 dan elemen terakhir memiliki indeks 4.
#### 2. Array Dua Dimensi
Bentuk array dua dimensi ini mirip seperti tabel. Jadi array dua dimensi bisa digunakan untuk menyimpan data dalam bentuk tabel. Terbagi menjadi dua bagian, dimensi pertama dan dimensi kedua. Cara akses, deklarasi, inisialisasi, dan menampilkan data sama dengan array satu dimensi, hanya saja indeks yang digunakan ada dua.
#### 3. Array Berdimensi Banyak
Merupakan array yang mempunyai indeks banyak, lebih dari dua. Indeks inilah yang menyatakan dimensi array. Array berdimensi banyak lebih susah dibayangkan, sejalan dengan jumlah dimensi dalam array.

### B. Pointer<br/>

#### 1. Data dan Memori
Semua data yang ada digunakan oleh program komputer disimpan di dalam memori (RAM) komputer. Memori dapat digambarkan sebagai sebuah array 1 dimensi yang berukuran sangat besar. Seperti layaknya array, setiap cell memory memiliki "indeks" atau "alamat" unik yang berguna untuk identitas yang biasa kita sebut sebagai "address".
Saat program berjalan, Sistem Operasi akan mengalokasikan space memory untuk setiap variabel, objek, atau array yang kita buat[5].
#### 2. Pointer dan Alamat
Variabel pointer merupakan dasar tipe variabel yang berisi integer dalam format heksadesimal. Pointer digunakan untuk menyimpan alamat memori variabel lain sehingga pointer dapat mengakses nilai dari variabel yang alamatnya ditunjuk.
#### 3. Pointer dan Array
Ada keterhubungan yang kuat antara array dan pointer. Banyak operasi yang bisa dilakukan dengan array juga bisa dilakukan dengan pointer.
#### 4. Pointer dan String
Pointer berfungsi sebagai variabel yang menyimpan alamat memori, berperan penting dalam memanipulasi memori secara efisien. Di sisi lain, string adalah larik karakter yang diakhiri dengan karakter null (\0), yang digunakan secara luas untuk menangani teks.

### C. Fungsi<br/>
Fungsi merupakan blok dari kode yang dirancang untuk melaksanakan tugas khusus dengan tujuan[5]:
1. Program menjadi terstruktur, sehingga mudah dipahami dan mudah dikembangkan. Program dibagi menjadi beberapa modul yang kecil.
2. Dapat mengurangi pengulangan kode (duplikasi kode) sehingga menghemat ukuran program.
Pada umumnya fungsi memerlukan masukan yang dinamakan sebagai parameter. Masukan ini selanjutnya diolah oleh fungsi. Hasil akhir fungsi berupa sebuah nilai (nilai balik fungsi).

### D. Prosedur<br/>
Dalam bahasa pemrograman C++, prosedur adalah istilah yang sering digunakan untuk merujuk pada fungsi yang tidak mengembalikan nilai. Dalam istilah C++, prosedur ini dikenal sebagai fungsi void. Fungsi-fungsi ini melakukan tugas tertentu tetapi tidak memberikan nilai balik (return value) kepada pemanggilnya. Sebaliknya, fungsi yang mengembalikan nilai, seperti int atau double, memberikan hasil yang dapat digunakan lebih lanjut dalam program[5].

### E. Parameter Fungsi<br/>

#### 1. Parameter Formal dan Prameter Aktual
Parameter formal adalah variabel yang ada pada daftar paramerter ketika mendefinisikan fungsi. Parameter aktual adalah parameter (tidak selamanya menyatakan variabel) yang dipakai untuk memanggil fungsi[5].
#### 2. Cara melewatkan Parameter
1. Pemanggilan dengan Nilai (call by value)
Pada pemanggilan dengan nilai, nilai dari parameter aktual akan disalin kedalam parameter formal, jadi parameter aktual tidak akan berubah meskipun parameter formalnya berubah.
2. Pemanggilan dengan Pointer (call by pointer)
Pemanggilan dengan pointer merupakan cara untuk melewatkan alamat suatu variabel ke dalam suatu fungsi. Dengan cara ini dapat mengubah nilai dari variabel aktual yang dilewatkan ke dalam fungsi. Jadi cara ini dapat mengubah variabel yang ada diluar fungsi.
3. Pemanggilan dengan Referensi (Call by Reference)
Pemanggilan dengan referensi merupakan cara untuk melewatkan alamat suatu variabel kedalam suatu fungsi. Dengan cara ini dapat mengubah nilai dari variabel aktual yang dilewatkan ke dalam fungsi. Jadi cara ini dapat mengubah variabel yang ada diluar fungsi. 


## Guided 

### 1. Guided 1 (Array 1 dimensi)

```C++
#include<iostream>
using namespace std;

int main(){
    int arr[5];
    
    for (int i = 0; i < 5; i++){
        cout << "Masukkan value indeks ke-" << i << ": ";
        cin >> arr[i];
    }
    int j = 0;
    while (j < 5){
        cout << "Isi indeks ke-" << j << ": " << arr[j] << endl;
        j++;
    }
    return 0;
}
```
Program diatas dibuat dalam bahasa C++ yang berfungsi untuk memasukkan dan menampilkan nilai dari sebuah array dengan ukuran 5. Program dimulai dengan mendeklarasikan sebuah array bertipe integer bernama arr yang memiliki 5 elemen. Selanjutnya, program menggunakan sebuah loop for yang berjalan dari indeks 0 hingga 4 untuk meminta input dari pengguna. Pada setiap perulangan, program menampilkan pesan yang meminta pengguna memasukkan nilai untuk indeks tertentu, kemudian nilai tersebut disimpan ke dalam array pada posisi indeks yang sesuai. Setelah semua nilai dimasukkan, program menggunakan loop while untuk menampilkan isi dari setiap elemen array. Loop ini berjalan dari indeks 0 hingga 4, dan pada setiap iterasi mencetak nilai yang tersimpan di indeks tersebut. Program ini memungkinkan pengguna untuk mengisi array dengan nilai yang diinginkan dan kemudian menampilkan semua nilai tersebut secara berurutan. Terakhir, program akan mengembalikan nilai 0 yang menandakan bahwa program berjalan dengan sukses.


### 2. Guided 2 (Array 2 dimensi)

```C++
#include<iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1,2}, 
        {3,4}
    };
    int arrB[2][2] = {
        {2,3}, 
        {4,5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    //penjumlahan matriks 2x2
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);

    cout << endl;

    //perkalian matriks 2x2
    for (int i = 0; i < 2; i++){            //perulangan baris
        for (int j = 0; j < 2; j++){        //perulangan kolom
            for (int k = 0; k < 2; k++){    //perulangan perkalian
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian : " << endl;
    tampilkanHasil(arrD);

    return 0;
}
```
Program diatas dibuat dalam bahasa C++ yang berfungsi untuk melakukan operasi dasar pada matriks berukuran 2x2, yaitu penjumlahan dan perkalian matriks. Pogram ini mendefinisikan dua matriks yang dikenal sebagai arrA dan arrB, masing-masing dengan dimensi 2x2 dan nilai yang sudah ditentukan sebelumnya. Setelah itu, program mendefinisikan dua matriks untuk menyimpan hasilnya, yaitu arrC untuk hasil penjumlahan dan arrD untuk hasil perkalian. Pada bagian penjumlahan, program melakukan iterasi pada setiap elemen matriks dengan dua loop bersarang, kemudian menjumlahkan elemen-elemen yang sesuai dari arrA dan arrB, dan menyimpan hasilnya di arrC. Selanjutnya, hasil penjumlahan ditampilkan dengan menggunakan fungsi tampilkanHasil yang mencetak elemen-elemen matriks secara baris demi baris. Untuk perkalian, program menerapkan tiga loop bersarang untuk menghitung hasil perkalian matriks sesuai dengan aturan perkalian matriks, yaitu dengan menjumlahkan hasil kali elemen dari baris arrA dan elemen dari kolom arrB. Hasil dari perkalian disimpan di arrD dan ditampilkan dengan metode yang sama.


### 3. Guided 3 (Array dan Pointer)

```C++
#include<iostream>
using namespace std;

int main(){
    int arr[] = {10,20,30,40,50};
    int* ptr = arr; //pointer yang menunjuk ke elemen pertama array

    //mengakses elemen array menggunakan pointer
    for (int i = 0; i < 5; ++i){
        cout << "Elemen array ke-" << i+1 << " menggunakan pointer: " <<*(ptr + i) << endl;
    }

    //mengakses elemen array menggunakan indeks
    for (int i = 0; i < 5; ++i){
        cout << "Elemen array ke-" << i+1 << " menggunakan indeks: " << arr[i] << endl;
    }

    return 0;
}
```
Program diatas dibuat dalam bahasa C++ yang berfungsi untuk menunjukkan dua cara berbeda untuk mengakses elemen-elemen dalam sebuah array. Program ini menggambarkan sebuah array bernama arr yang terdiri dari lima elemen dengan tipe integer, yaitu 10, 20, 30, 40, dan 50. Selanjutnya, sebuah pointer bernama ptr dibuat dan diatur untuk menunjukkan ke elemen pertama dari array tersebut. Pada tahap awal, program memanfaatkan pointer untuk mendapatkan nilai-nilai dari elemen array dengan mengubah posisi pointer menggunakan operasi penjumlahan pointer, yakni *(ptr + i), di mana i merujuk pada indeks elemen yang ingin diakses. Hasil akses ini lalu ditampilkan di layar beserta informasi mengenai nomor elemen tersebut. Pada tahap berikutnya, program mengakses elemen-elemen array secara langsung dengan menggunakan indeks arr[i] dan menampilkan hasilnya. 


### 4. Guided 4 (Fungsi dan Prosedur)

```C++
#include<iostream>
using namespace std;

int cariMax(int arr[], int ukuran){
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++){
        if (arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran){
    int totalJumlah = 0;
    for (int i = 0; i < ukuran; i++){
        totalJumlah += arr[i];
    }
    cout << "Total penjumlahan: " << totalJumlah << endl;

    int totalKali = 1;
    for (int i = 0; i < ukuran; i++){
        totalKali *= arr[i];
    }
    cout << "Total perkalian: " << totalKali << endl;
}

int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++){
        cout << "Masukkan nilai array ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Nilai terbesar dalam array: " << cariMax(arr, ukuran) << endl;

    operasiAritmatika(arr, ukuran);
    return 0;
}
```
Program diatas dibuat dalam bahasa C++ yang berfungsi untuk untuk menerima input nilai-nilai dari pengguna ke dalam sebuah array, kemudian melakukan beberapa operasi pada array tersebut, yaitu mencari nilai terbesar, menghitung total penjumlahan, dan menghitung total perkalian dari elemen-elemen array. Program dimulai dengan mendeklarasikan sebuah array arr yang berkapasitas 5, kemudian meminta inputan dari pengguna untuk setiap nilai elemen array melalui perulangan. Setelah semua nilai dimasukkan, program memanggil fungsi cariMax yang menerima array dan ukuran sebagai parameter. Fungsi ini mencari dan mengembalikan nilai terbesar dalam array dengan membandingkan setiap elemen satu per satu. Selanjutnya, program memanggil fungsi operasiAritmatika yang juga mendapatkan array dan ukurannya, di mana fungsi ini menghitung jumlah total dari semua elemen array dengan menjumlahkan masing-masing elemen dalam sebuah loop, sekaligus menghitung perkalian total dari semua elemen dengan mengalikan setiap elemen satu per satu. Hasil dari kedua operasi tersebut kemudian ditampilkan di layar.


## Unguided 

### 1. Soal Unguided 1
Diketahui 2 buah matriks 3x3 seperti dibawah ini: 
matriksA = [{7,12,22},{31,6,41},{15,19,36}]     
MatriksB = [{11,34,7},{3,25,41},{5,18,33}]
Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan; jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan kaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case seperti berikut ini : 
 --- Menu Program Matriks --- 
1. Penjumlahan matriks 
2. Pengurangan matriks 
3. Perkalian matriks 
4. Keluar 

```C++
#include <iostream>
using namespace std;

const int N = 3;

void tampilMatriks(int M[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

void jumlahMatriks(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void kurangMatriks(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void kaliMatriks(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[N][N] = { {7, 12, 22},
                    {31, 6, 41},
                    {15, 19, 36} };

    int B[N][N] = { {11, 34, 7},
                    {3, 25, 41},
                    {5, 18, 33} };

    int C[N][N]; // Hasil operasi
    int pilihan;

    do {
        cout << "\n--- Menu Program Matriks ---\n";
        cout << "1. Penjumlahan matriks\n";
        cout << "2. Pengurangan matriks\n";
        cout << "3. Perkalian matriks\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                jumlahMatriks(A, B, C);
                cout << "Hasil Penjumlahan Matriks:\n";
                tampilMatriks(C);
                break;
            case 2:
                kurangMatriks(A, B, C);
                cout << "Hasil Pengurangan Matriks:\n";
                tampilMatriks(C);
                break;
            case 3:
                kaliMatriks(A, B, C);
                cout << "Hasil Perkalian Matriks:\n";
                tampilMatriks(C);
                break;
            case 4:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan2_modul2/output-unguided1-modul2.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan2_modul2/output2-unguided1-modul2.png)

Program diatas dibuat dalam bahasa C++ yang berfungsi untuk melakukan operasi dasar pada matriks berukuran 3x3. Program ini memiliki tiga fungsi utama yang berfokus pada penjumlahan, pengurangan, dan perkalian matriks. Matriks yang dipakai adalah matriks A dan matriks B yang telah ditentukan secara statis dengan nilai-nilai tertentu. Fungsi tampilMatriks bertugas untuk menampilkan isi matriks di layar dengan format yang teratur. Fungsi jumlahMatriks melaksanakan penjumlahan elemen dari matriks A dan B, lalu menyimpan hasilnya di matriks C. Fungsi kurangMatriks melakukan pengurangan antara elemen matriks A dan B, dan hasilnya disimpan di matriks C. Sementara itu, fungsi kaliMatriks melaksanakan perkalian antara matriks A dan matriks B mengikuti aturan perkalian matriks, kemudian hasilnya disimpan di matriks C. Program ini juga menyediakan menu interaktif yang memungkinkan pengguna untuk memilih jenis operasi matriks yang ingin dilakukan, yaitu penjumlahan, pengurangan, perkalian, atau keluar dari program. Setelah pengguna memilih jenis operasi, program akan menunjukkan hasil dari operasi tersebut dalam format matriks. Program akan terus aktif dan menampilkan menu sampai pengguna memilih opsi untuk keluar.


### 2. Soal Unguided 2
Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan 
dan perubahan nilainya menggunakan pointer, seperti berikut: 
1) Buatlah 3 variabel integer di fungsi main(): panjang (beri nilai 10), lebar (beri nilai 5), dan 
luas (beri nilai 0). 
2) Deklarasikan dua pointer: ptrPanjang yang menunjuk ke variabel panjang, dan ptrLebar 
yang menunjuk ke variabel lebar.  
3) Hitung luas persegi panjang tersebut dan simpan hasilnya ke dalam variabel luas. 
Syarat: Proses perhitungan ini wajib menggunakan ptrPanjang dan ptrLebar. 
4) Cetak nilai luas ke layar. 
5) Setelah itu, ubah nilai panjang menjadi 12 dan lebar menjadi 6, juga hanya melalui 
pointer ptrPanjang dan ptrLebar. 
6) Cetak nilai panjang dan lebar yang baru untuk membuktikan bahwa 
nilainya telah berubah.

```C++
#include <iostream>
using namespace std;

int main() {
    int panjang = 10, lebar = 5, luas = 0, keliling = 0;

    int *ptrPanjang = &panjang;
    int *ptrLebar = &lebar;

    cout << "--- Nilai Awal ---" << endl;
    cout << "Panjang: " << *ptrPanjang << endl;
    cout << "Lebar: " << *ptrLebar << endl;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "\n--- Hasil Perhitungan ---" << endl;
    cout << "Luas Persegi Panjang: " << luas << endl;
    cout << "Keliling Persegi Panjang: " << keliling << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "\n--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang Baru: " << *ptrPanjang << endl;
    cout << "Lebar Baru: " << *ptrLebar << endl;
    cout << "Luas Baru: " << luas << endl;
    cout << "Keliling Baru: " << keliling << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan2_modul2/output-unguided2-modul2.png)

Program diatas dibuat dalam bahasa C++ yang berfungsi untuk menghitung luas dan keliling sebuah persegi panjang menggunakan pointer. Di awal program, terdapat dua variabel bertipe integer, yaitu panjang dan lebar, yang masing-masing diberikan nilai awal 10 dan 5. Selanjutnya, dibuat dua pointer bernama ptrPanjang dan ptrLebar, yang menunjukkan alamat memori dari variabel panjang dan lebar. Program menampilkan nilai awal dari panjang dan lebar melalui dereferensi pointer tersebut. Kemudian, program melakukan perhitungan luas dengan mengalikan nilai yang diakses melalui pointer panjang dan lebar, serta menghitung keliling dengan cara dua kali jumlah dari panjang dan lebar. Hasil dari perhitungan luas dan keliling tersebut kemudian diperlihatkan. Setelah itu, nilai yang ditunjuk oleh pointer diubah menjadi 12 untuk panjang dan 6 untuk lebar, yang otomatis mengubah nilai variabel aslinya. Program kembali melakukan perhitungan luas dan keliling dengan nilai yang baru dan menampilkan hasilnya.


## Kesimpulan
Array digunakan untuk menyimpan sekumpulan data dalam satu tempat, baik dalam bentuk satu dimensi (vektor) maupun dua dimensi (matriks), dengan deklarasi yang menggunakan tanda kurung siku [ ]. Array termasuk ke dalam struktur data sederhana yang mengalokasikan memori sementara di komputer. Sementara itu, pointer adalah variabel yang menyimpan alamat memori dari suatu variabel lain, bukan nilai langsungnya. Pointer memiliki kelebihan karena bersifat dinamis dan dapat digunakan untuk mengakses, mengubah, serta menampilkan nilai maupun alamat variabel yang ditunjuk. Penggunaan operator & (address of) dan * (value pointed by) memungkinkan manipulasi memori secara langsung. Selain itu, konsep prosedur dan fungsi juga berperan penting dalam pemrograman terstruktur. Prosedur digunakan untuk membagi program menjadi bagian-bagian kecil yang lebih sederhana tanpa mengembalikan nilai, sedangkan fungsi memiliki kemampuan untuk mengembalikan nilai tertentu.

## Referensi
[1] (N.d.). Retrieved from https://www.petanikode.com/cpp-array/
<br>[2] Pratama, M. A. (2020). STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++.
<br>[3] Arraffi, A. pointer.
<br>[4] Oleh MateriDosen. (n.d.). Perbedaan Fungsi dan Prosedur dalam Bahasa C & C++. Retrieved from https://www.materidosen.com/2017/01/perbedaan-fungsi-dan-prosedur-dalam.html
<br>[5] Modul 2 - Praktikum Struktur Data
