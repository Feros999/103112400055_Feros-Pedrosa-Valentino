# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Feros Pedrosa Valentino - 103112400055</p>

## Dasar Teori
Struktur pemrograman C++ terdiri dari tiga bagian utama yaitu bagian deklarasi include untuk menyertakan library, bagian deklarasi namespace (opsional) untuk menggunakan fungsi-fungsi standar, dan bagian fungsi utama (main()) tempat kode program utama ditulis dan dieksekusi. Pada bahasa pemrograman C++ ini variabel adalah identitas yang digunakan untuk menampung nilai. Bahasa pemrograman ini termasuk kategori strongly typed, artinya sebelum melakukan deklarasi, harus menginput tipe datanya dahulu[1]. Dalam bahasa pemrograman C++ ini ada beberapa syntax dasar diantaranya adalah include, using namespace std, dan fungsi main. Ada beberapa data structure dalam bahasa C++ yaitu variabel, struct, dan object. Struktur pada bahasa pemrograman C++ ini adalah header dan program utama, deklarasi variabel dan konstanta, tipe data bahasa C++, struktur kontrol pada C++. Percabangan berguna untuk menyelesaikan persoalan dan mengambil satu keputusan dari beberapa pilihan sesuai kondisi yang sedang dialami program tersebut[2]. Ada beberapa bentuk percabangan di bahasa pemrograman C++ yaitu Percabangan if, Percabangan if/else, Percabangan if/else/if, Percabangan Switch/Case, Percabangan Bersarang (Nested). Perulangan digunakan untuk mengulangi beberapa perintah kode hingga kondisi terpenuhi. Pada bahasa pemrograman C++ ini bisa menggunakan pernyataan for, WHILE dan DO-WHILE[3]. Struct adalah cara untuk mengelompokkan beberapa variabel terkait ke dalam satu tempat[4]. Setiap variabel dalam struktur dikenal sebagai anggota struktur. Struct memiliki beberapa fungsi utama diantaranya adalah Pengelompokan Data yang berguna untuk membantu mengelola dan mengorganisasi data yang saling terkait menjadi satu kesatuan logis, Membuat Tipe Data Baru yang berguna untuk pembuatan tipe data baru yang lebih kompleks daripada tipe data primitif seperti int atau float. 

### A. Dasar Pemrograman<br/>
#### 1. Struktur Program C++
Secara umum, pembagian struktur bahasa pemrograman C++ adalah[5]:
1. Pendeklarasian library yang digunakan pada program,
2. Pendefinisian konstanta,
3. Pendefinisian tipe data bentukan / record type / struktur,
4. Pendeklarasian variabel,
5. Pendeklarasian fungsi dan prosedur,
6. Program utama.
#### 2. Pengenal (Identifier)
Identifier merupakan nama yang biasa digunakan untuk variabel, konstanta, fungsi atau objek lain yang didefinisikan oleh program. Aturan yang digunakan untuk menentukan identifier[5]:
1. Harus diawali dengan huruf (A....Z, a....z) atau garis bawah (_).
2. Karakter selanjutnya bisa berupa huruf, digit atau karakter garis bawah () atau dollar ($).
3. Panjang maksimal identifier adalah 32 karakter, jika lebih maka yang dianggap adalah 32 karakter awal.
4. Tidak boleh mengandung spasi.
5. Tidak boleh menggunakan operator aritmatika.
#### 3. Tipe Data Dasar
Data merupakan suatu nilai yang dapat dinyatakan dalam bentuk konstanta atau variabel. Data berdasarkan jenisnya dibagi dalam 5 kelompok, yang dinamakan sebagai tipe data dasar. Kelima kelompok tersebut yaitu[5]:
1. Bilangan bulat (integer).
2. Bilangan real presisi - tunggal.
3. Bilangan real presisi - ganda.
4. Karakter.
5. Tak bertipe.
#### 4. Variabel
Variabel dalam program digunakan untuk menyimpan nilai, nilai variabel bisa berubah-ubah selama program berjalan. Aturan penamaan variabel sesuai dengan aturan penamaan identifier. Bentuk umum pendeklarasian suatu variabel dalam bahasa pemrograman C dapat ditulis sebagai tipe_data nama_variabel; [5].
#### 5. Konstanta
Konstanta menyatakan nilai yang selalu tetap. Seperti halnya dengan variabel, konstanta juga mempunyai tipe. Untuk mendeklarasikan suatu nilai yang sifatnya konstan kita cukup menambahkan kata const di depan tipe data dan variabel[5].

### B. Input / Output<br/>
#### 1. Output
1. Fungsi cout() digunakan untuk mencetak data yang bertipe numerik, atau teks, baik konstanta ataupun variabel.
2. Penggunaan penentu format sangat berkaitan erat dengan suatu tipe data. Artinya suatu tipe data memimilik penentu format masing-masing. Format tersebut dipakai di bahasa C, sedangkan pada C++ tidak harus dipakai.
3. Penentu Lebar Field berguna kita mencetak data bertipe float, seringkali tampilan yang diberikan tampak kurang manis. Misalnya desimal yang dicetak terlalu banyak. Kita dapat mengatur lebar field dan jumlah desimal yang ingin dicetak pada layar dengan cara memberikan tambahan format %f.
4. Disebut escape sequence, karena notasi '\' dianggap sebagai karakter "escape" (menghindar), dalam arti bahwa karakter yang terdapat setelah tanda '\' dianggap merupakan bukan teks biasa[5].
#### 2. Input
1. Fungsi cin() merupakan salah satu fungsi yang digunakan untuk meminta inputan keyboard dari user.
2. Penentu format untuk fungsi cin() tidak sama seperti penentu format seperti pada printf() (digunakan pada C atau C++). Pada cin(), kita tidak perlu menggunakan penentu format seperti pada printf(). cin menggunakan operator >> untuk langsung memasukkan nilai yang diinput user ke dalam variabel yang ditentukan.
3. Fungsi getchar() merupakan fungsi yang digunakan untuk membaca satu karakter dari input standar. Fungsi ini akan menunggu pengguna menekan sebuah tombol pada keyboard, lalu mengembalikan karakter tersebut. Fungsi ini sering digunakan untuk membaca input karakter tunggal dari pengguna.
Berbeda dengan cin, yang memungkinkan pengguna memasukkan lebih dari satu karakter dan membutuhkan menekan tombol enter untuk menyelesaikan input, getchar() hanya membaca satu karakter dan tidak memerlukan enter untuk melanjutkan eksekusi program. Begitu satu karakter diketikkan, program akan langsung melanjutkan ke perintah berikutnya[5].

### C. Operator<br/>
Operator adalah suatu simbol yang digunakan untuk melakukan sesuatu operasi atau manipulasi. 
#### 1. Operator Aritmatika
Misalkan terdapat ungkapan sebagai berikut: A+B / C+D. Untuk mengubah jenjang dapat digunakan tanda kurung '()' (sebagai operator jenjang tertinggi) sebagai berikut: (A+B) / (C+D).
#### 2. Operator Pengerjaan (Assignment)
Operator ini digunakan untuk memindahkan nilai dari suatu ungkapan ke suatu pengenal. Di samping operator pengerjaan yang umumnya digunakan di bahasa-bahasa pemrograman, bahasa C++ menyediakan beberapa operator pengerjaan lain. 
Misal: A += 7, ekuivalen dengan, A = A + 7
#### 3. Operator Logika
Operasi logika membandingkan dua buah nilai logika. Nilai logika adalah nilai benar atau salah. Misalnya:
1. (kar > 'A') && (kar < 'Z') 
Hasil operasi && bernilai benar hanya jika kar > 'A' dan kar < 'Z'
2. (pilihan == 'Y') || (pilihan == 'y') 
Hasil operasi logika || bernilai benar jika pilihan berupa 'Y' atau 'y'.
3. ! operand 
Hasil operand ! akan bernilai benar jika operand bernilai salah dan sebaliknya.
#### 4. Operator Unary
Ada 2 jenis tipe operator unary yaitu operator unary tipe yang berfungsi menghasilkan tipe data yang diinginkan walau berasal dari operand-operand dengan tipe berbeda dan operator unary sizeof yang digunakan untuk mengetahui ukuran memory dari operandnya dalam satuan byte.
#### 5. Operator sizeof
Operator sizeof menghasilkan ukuran dari variabel atau suatu tipe pada saat kompilasi program. Penggunaan sizeof dengan operan (berupa variabel atau tipe) yang ditempatkan dalam tanda kurung. Operator ini sangat bermanfaat untuk menghitung besarnya sebarang tipe atau variabel, terutama untuk variabel dan tipe yang kompleks (seperti struktur). 
#### 6. Operator Increment dan Decrement
Bahasa C++ menyediakan 2 operator yang tidak biasa untuk increment dan decrement. Operator increment ++ akan menambahkan nilai 1 dari variabel, sedangkan operator decrement mengurangi variabel dengan nilai 1. Kedua operator ini bisa diletakkan sebelum variabel (prefix, contoh: ++i), dan sesudah variabel (postfix, contoh: i++). Effect dari keduanya sama yaitu akan menambahkan nilai 1 ke variabel i. Akan tetapi, untuk ekspresi ++i dan i++ ada bedanya. Jika ekspresi ++i maka variabel akan di-increment dulu sebelum digunakan sedangkan untuk operator i++ maka nilai i akan digunakan terlebih dahulu setelah itu baru di-increment[5].

### D. Pemodifikasi Tipe<br/>
Pemodifikasi tipe (type modifier) dapat dikenakan diawal tipe data kecuali untuk void.
#### 1. Unsigned
Tipe data ini digunakan bila kita hanya ingin bekerja dengan data yang bernilai positif saja.
#### 2. Short
Tipe data ini kadangkala disamakan dengan integer dan kadangkala juga dibedakan, tergantung pada sistem dan jenis komputer yang digunakan.
#### 3. Long
Tipe data ini digunakan untuk menaikkan kapasitas dari suatu variabel[5].

### E. Kondisional<br/>
Untuk menyelesaikan suatu masalah diperlukan pengambilan keputusan, Bahasa C++ menyediakan beberapa jenis pernyataan berupa operator kondisi sebagai berikut.
1. Pernyataan if
2. Pernyataan if-else
3. Pernyataan switch Pernyataan pengambilan keputusan di atas memerlukan suatu kondisi sebagai basis pada pengambilan keputusan. Kondisi umum yang dipakai keadaan benar atau salah.
#### 1. Bentuk 1
Arti dari perintah if adalah jika kondisi benar maka pernyataan akan dijalankan. Sedangkan kondisi ditulis di antara tanda kurung, dapat berupa ungkapan yang memiliki nilai benar atau salah. Dan pernyataan berupa sebuah pernyataan tunggal pernyataan majemuk atau pernyataan kosong.
#### 2. Bentuk 2
Arti dari pernyataan if-else 
1. Jika kondisi benar, maka pernyataan1 dijalankan.
2. Jika kondisi salah, maka pernyataan2 yang akan dijalankan.
pernyataan1 dan pernyataan2 dapat berupa sebuah pernyataan tunggal, pernyataan majemuk ataupun pernyataan kosong.
#### 3. Bentuk 3
Bentuk ketiga menggunakan pernyataan switch, merupakan pernyataan yang dirancang khusus untuk menangani pengambilan keputusan yang melibatkan banyak alternatif.
Pengujian pada switch akan dimulai dari kondisi1, kalau nilai kondisi1 cocok maka pernyataan1 dilakukan, bila tidak cocok akan diteruskan pada pengecekan pernyataan2. Bila tidak ditemukan kondisi yang cocok maka statement pada default akan dilakukan[5].

### F. Perulangan<br/>
Perulangan digunakan untuk mengefisienkan waktu dan meringkas kode program dalam pengeksekusian sub-program yang sama. Hal yang terpenting dalam perulangan adalah harus ada kondisi berhenti.
#### 1. Perulangan dengan for dan while
Perulangan for dan while biasa digunakan saat kondisi ekspresi terpenuhi. Jika tidak maka perulangan akan terhenti.
#### 2. Perulangan dengan do ... while
Pada dasarnya struktur perulangan do...while sama saja dengan struktur while, hanya saja pada proses perulangan dengan while, seleksi berada di while yang letaknya di atas sementara pada perulangan do...while, seleksi while berada di bawah batas perulangan. Jadi dengan menggunakan struktur do...while sekurang-kurangnya akan terjadi satu kali perulangan[5].

### G. Struktur<br/>
Struktur merupakan tipe data bentukan berupa kumpulan dari variabel yang dinyatakan dalam sebuah nama, setiap variabel bisa memiliki tipe yang berlainan. Struktur bisa digunakan untuk mengelompokkan beberapa informasi yang saling berkaitan menjadi satu kesatuan (dalam bahasa pascal, struktur disebut dengan record). 
Tipe data struktur ini cukup rumit, tetapi sangat penting dalam pemrograman bahasa C++, terutama dalam struktur data. Untuk merepresentasikan data sebagian besar akan menggunakan struktur yang dikombinasikan dengan array maupun pointer[5].

### H. Blok Program<br/>
Setiap bahasa komputer disusun dengan struktur yang berbeda. Untuk dapat mengerti bagaimana membuat program maka kita harus dapat memahami struktur dari program tersebut terlebih dahulu[5].


## Guided 

### 1. Guided 1 (input output)

```C++
#include<iostream>
using namespace std;

int main(){
    int angka;
    cout << "masukkan angka : ";
    cin >> angka;
    cout << "Angka yang dimasukkan " << angka << endl;
    return 0;
}
```

Program ini dibuat dalam bahasa C++ yang dirancang untuk menerima input bilangan bulat dari pengguna dan menampilkannya kembali. Program dimulai dengan menyertakan pustaka input/output standar dan mendeklarasikan penggunaan namespace standar. Selanjutnya, fungsi utama didefinisikan sebagai titik masuk eksekusi, di mana sebuah variabel integer dideklarasikan untuk menyimpan nilai angka. Kemudian, pesan dicetak ke layer untuk meminta pengguna memasukkan angka, dan nilai tersebut dibaca langsung dari keyboard. Setelah input selesai, pesan konfirmasi dicetak yang menyatakan angka yang dimasukkan beserta nilainya. Program diakhiri dengan pengembalian nilai nol untuk menandakan eksekusi berhasil.

### 2. Guided 2 (operator aritmatika)

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "masukkan angka 1 : ";
    cin >> angka1;
    cout << "masukkan angka 2 : ";
    cin >> angka2;

    cout << "penjumlahan : " << angka1 + angka2 << endl;
    cout << "pengurangan : " << angka1 - angka2 << endl;
    cout << "perkalian : " << angka1 * angka2 << endl;
    cout << "pembagian : " << angka1 / angka2 << endl;
    cout << "sisa bagi : " << angka1 % angka2 << endl;
    return 0;
}
```

Program ini merupakan program dalam bahasa C++ yang dirancang untuk melakukan operasi aritmatika dasar pada dua bilangan integer, yaitu penjumlahan, pengurangan, perkalian, pembagian, dan sisa bagi. Program dimulai dengan menyertakan pustaka input/output standar dan mendeklarasikan penggunaan namespace standar untuk akses fungsi dasar. Selanjutnya, fungsi utama didefinisikan sebagai titik masuk eksekusi, di mana dua variabel integer dideklarasikan untuk menyimpan nilai angka pertama dan kedua. Kemudian, program akan mencetak pesan secara berurutan meminta pengguna memasukkan angka pertama dan kedua. Setelah input selesai, hasil operasi langsung dicetak ke layar: penjumlahan dari penambahan kedua angka, pengurangan dari pengurangan angka pertama dengan kedua, perkalian, pembagian dari pembagian angka pertama dengan angka kedua, dan sisa bagi dari modulus keduanya. Program diakhiri dengan pengembalian nilai nol untuk menandakan eksekusi berhasil, serta penutupan blok fungsi utama.

### 3. Guided 3 (percabangan)

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "masukkan angka 1 : ";
    cin >> angka1;
    cout << "masukkan angka 2 : ";
    cin >> angka2;

    if (angka1 < angka2) {
        cout << angka1 << " kurang dari " << angka2 << endl;
    } else {
        cout << angka1 << " lebih dari " << angka2 << endl;
    }

    if (angka1 == angka2) {
        cout << angka1 << " sama dengan " << angka2 << endl;
    } else if (angka1 != angka2) {
        cout << "angka berbeda" << endl;
    }

    int pilihan; 
    cout << "MENU" << endl;
    cout << "1. penjumlahan" << endl;
    cout << "2. pengurangan" << endl;
    cout << "masukkan pilihan : " << endl;
    cin >> pilihan;

    switch(pilihan) {
        case 1:
        cout << "penjumlahan : " << angka1 + angka2 << endl;
        cout << endl;
        break;
        case 2:
        cout << "pengurangan : " << angka1 - angka2 << endl;
        cout << endl;
        break;
        default : 
        cout << "pilihan salah" << endl;
    }

    return 0;
}
```

Program ini merupakan program dalam bahasa C++ yang dirancang untuk membandingkan dua bilangan integer dan melakukan operasi aritmatika dasar berdasarkan pilihan menu dari pengguna. Program dimulai dengan menyertakan pustaka input/output standar dan mendeklarasikan penggunaan namespace standar. Selanjutnya, fungsi utama didefinisikan sebagai titik masuk eksekusi, di mana dua variabel integer dideklarasikan untuk menyimpan nilai angka pertama dan kedua. Kemudian, program mencetak pesan secara berurutan untuk meminta pengguna memasukkan kedua angka. Setelah input selesai, perbandingan pertama dilakukan: jika angka pertama lebih kecil dari kedua, program akan menampilkan pesan bahwa angka pertama kurang dari kedua; sebaliknya, program akan menampilkan pesan bahwa angka pertama lebih dari kedua. Selanjutnya, perbandingan kedua: jika kedua angka sama, pesan kesamaan dicetak; jika tidak, pesan bahwa angka berbeda dicetak. Kemudian, sebuah variabel untuk pilihan dideklarasikan, diikuti pencetakan menu sederhana yang menampilkan opsi penjumlahan dan pengurangan, serta program meminta pengguna memasukkan pilihan. Berdasarkan pilihan tersebut, struktur pemilihan digunakan: jika pilihan satu, hasil penjumlahan kedua angka dicetak; jika pilihan dua, hasil pengurangan dicetak; jika pilihan lain, pesan kesalahan dicetak. Program diakhiri dengan pengembalian nilai nol untuk menandakan eksekusi berhasil.

### 4. Guided 4 (perulangan)

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1;
    cout << "masukkan angka 1 : ";
    cin >> angka1;
    
    for (int i = 0; i < angka1; i++) { //increment
        cout << i << " - ";
    }
    cout << endl;

    int j = 10;
    while (j > angka1) {
        cout << j << " - ";
        j--; //decrement
    }

    cout << endl;
    int k = 10;
    do {
        cout << k << " - ";
    } while (k < angka1);
    
    return 0;
}
```

Program ini merupakan program dalam bahasa C++ yang dirancang untuk mendemonstrasikan tiga jenis loop iterasi berdasarkan input bilangan integer dari pengguna, dengan mencetak urutan angka menggunakan loop for, while, dan do-while. Program dimulai dengan menyertakan pustaka input/output standar dan mendeklarasikan penggunaan namespace standar. Selanjutnya, fungsi utama didefinisikan sebagai titik masuk eksekusi, di mana sebuah variabel integer dideklarasikan untuk menyimpan nilai angka pertama. Kemudian, program mencetak pesan untuk meminta pengguna memasukkan angka. Setelah input selesai, loop pertama dijalankan dengan iterasi dari nol hingga kurang dari nilai angka, mencetak setiap indeks iterasi diikuti tanda hubung dan spasi, diakhiri pindah ke baris baru. Selanjutnya, sebuah variabel inisialisasi dengan nilai sepuluh dideklarasikan, diikuti loop kedua yang berulang selama variabel tersebut lebih besar dari nilai angka, mencetak nilai variabel diikuti tanda hubung dan spasi, serta mendekrementasikan variabel pada setiap iterasi. Kemudian, pindah ke baris baru dilakukan, diikuti inisialisasi variabel lain dengan nilai sepuluh, dan loop ketiga yang mengeksekusi blok pernyataan terlebih dahulu sebelum memeriksa kondisi, mencetak nilai variabel diikuti tanda hubung dan spasi, serta berulang selama variabel kurang dari nilai angka. Program diakhiri dengan pengembalian nilai nol untuk menandakan eksekusi berhasil.

### 5. Guided 5 (Struct)

```C++
#include <iostream>
using namespace std;

int main() {
    const int MAX = 3;
    struct rapot{
        string nama;
        float nilai;
    };
    rapot siswa[MAX];
    
    for(int i = 0; i < MAX; i++) {
        cout << "masukkan nama siswa : ";
        cin >> siswa[i].nama;
        cout << "masukkan nilai siswa : ";
        cin >> siswa[i].nilai;
        cout << endl;
    }

    int j = 0;
    while (j < MAX) {
        cout << "Nama siswa : " << siswa[j].nama << ", Nilai : " << siswa[j].nilai << endl;
        j++;
    } 

    return 0;
}
```

Program ini merupakan program dalam bahasa C++ yang dirancang untuk mengelola data rapor siswa menggunakan struktur data, di mana program menyimpan nama dan nilai untuk tiga siswa secara berurutan dan menampilkannya kembali. Program dimulai dengan menyertakan pustaka input/output standar dan mendeklarasikan penggunaan namespace standar. Selanjutnya, fungsi utama didefinisikan sebagai titik masuk eksekusi, di mana sebuah konstanta integer dengan nilai tiga didefinisikan sebagai ukuran maksimal, diikuti definisi struktur yang berisi anggota string untuk nama dan float untuk nilai, serta deklarasi array dari struktur tersebut dengan ukuran konstanta tersebut. Kemudian, sebuah loop iterasi dijalankan dari nol hingga kurang dari ukuran maksimal, di mana untuk setiap iterasi, pesan dicetak untuk meminta nama siswa dan disimpan ke elemen array, nilai siswa yang juga dibaca dan disimpan, serta pindah ke baris baru setelah setiap input lengkap. Setelah loop input selesai, sebuah variabel inisialisasi dengan nilai nol dideklarasikan, diikuti loop berulang selama variabel tersebut kurang dari ukuran maksimal, di mana untuk setiap iterasi, nama dan nilai siswa dari elemen array yang sesuai dicetak dalam format kalimat lengkap. Program diakhiri dengan pengembalian nilai nol untuk menandakan eksekusi berhasil.


## Unguided 

### 1. Soal Unguided 1
Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/MINGGU_1/output-unguided1-modul1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/MINGGU_1/output2-unguided1-modul1.png)
 
Program ini adalah program C++ yang berguna untuk melakukan operasi aritmatika dasar pada dua bilangan float. Dimulai dengan '#include <iostream>' untuk pustaka I/O dan 'using namespace std;' untuk kemudahan akses fungsi standar, kemudian fungsi utama 'int main()' didefinisikan sebagai titik masuk program. Di dalamnya, variabel 'bilanganPertama' dan 'bilanganKedua' (serta variabel hasil: 'hasilPenjumlahan', 'hasilPengurangan', 'hasilPerkalian', 'hasilPembagian') dideklarasikan bertipe float. Proses input dilakukan dengan 'cout' untuk prompt dan 'cin' untuk membaca nilai kedua bilangan dari pengguna. Selanjutnya, perhitungan dijalankan: penjumlahan, pengurangan, perkalian, dan pembagian disimpan ke variabel hasil masing-masing. Kemudian program akan mencetak hasil menggunakan 'cout' dengan label dan 'endl' untuk pindah baris. Program diakhiri dengan 'return 0;' untuk menandakan eksekusi berjalan.

### 2. Soal Unguided 2
Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/MINGGU_1/output-unguided2-modul1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/MINGGU_1/output2-unguided2-modul1.png)

Program ini merupakan program C++ yang berguna untuk mengonversi angka bulat positif (0-100) menjadi bentuk tulisan. Dimulai dengan `#include <iostream>` dan `#include <string>` untuk library input/output dan pengolahan string, kemudian menggunakan `using namespace std;` untuk kemudahan akses fungsi standar. Fungsi utama `int main()` didefinisikan sebagai titik masuk, di mana variabel `int angkaMasukan` dan `string tulisanAngka` dideklarasikan. Input dilakukan dengan `cout` untuk prompt dan `cin` untuk membaca angka dari pengguna. Validasi input menggunakan `if (angkaMasukan < 0 || angkaMasukan > 100)` untuk menampilkan pesan error dan `return 1;` jika tidak valid. Selanjutnya, logika konversi dimulai: jika `angkaMasukan == 0`, set `tulisanAngka = "nol"`; jika `== 100`, set `"seratus"`; jika `< 10`, gunakan array `daftarSatuan` untuk mengambil tulisan satuan (indeks 1-9); jika `< 20`, gunakan array `daftarBelasan` untuk belasan (indeks 0-9, offset -10); jika tidak, hitung `nilaiPuluhan = angkaMasukan / 10` dan `nilaiSatuan = angkaMasukan % 10`, gunakan array `daftarPuluhan` untuk puluhan, lalu jika `nilaiSatuan > 0`, tambahkan spasi dan tulisan satuan dari array `daftarSatuan`. Terakhir, program akan menampilkan output hasil dengan `cout << angkaMasukan << " : " << tulisanAngka << endl;`, diikuti `return 0;` untuk menandakan eksekusi berhasil.

### 3. Soal Unguided 3
Buatlah program yang dapat memberikan input dan output sbb.

```C++
#include <iostream>
using namespace std;

int main() {
    int masukan;
    cout << "Inputkan sebuah bilangan: ";
    cin >> masukan;

    for (int i = masukan; i >= 1; i--) {
        for (int s = 0; s < masukan - i; s++) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }

    for (int s = 0; s < masukan; s++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/MINGGU_1/output-unguided3-modul1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/MINGGU_1/output2-unguided3-modul1.png)

Program ini merupakan program dengan bahasa C++ yang dirancang untuk menghasilkan pola mirror simetris berdasarkan input bilangan bulat positif dari pengguna, di mana setiap baris menampilkan angka menurun di sisi kiri, diikuti tanda bintang sebagai pemisah, dan angka naik di sisi kanan, dengan spasi menjorok yang bertambah secara bertahap, serta diakhiri dengan baris tunggal berisi bintang yang menjorok penuh. Program dimulai dengan menyertakan pustaka input/output standar dan mendeklarasikan penggunaan namespace standar untuk kemudahan akses fungsi dasar, kemudian mendefinisikan fungsi utama sebagai titik masuk eksekusi. Di dalam fungsi utama, sebuah variabel integer dideklarasikan untuk menyimpan nilai masukan, diikuti dengan pesan prompt yang dicetak ke layar meminta pengguna memasukkan bilangan. Selanjutnya, sebuah loop utama dijalankan mulai dari nilai masukan turun hingga satu, di mana untuk setiap iterasi, terlebih dahulu dilakukan penjorokan dengan mencetak dua spasi sesuai jarak dari baris penuh, kemudian angka-angka dicetak menurun dari nilai saat ini hingga satu diikuti spasi, disusul tanda bintang dan spasi, lalu angka-angka naik dari satu hingga nilai saat ini diikuti spasi, dan akhirnya pindah ke baris baru. Setelah loop utama selesai, sebuah loop tambahan mencetak dua spasi sebanyak nilai masukan kali untuk penjorokan maksimal, diikuti pencetakan tanda bintang tunggal dan pindah baris. Program diakhiri dengan pengembalian nilai nol untuk menandakan eksekusi berhasil, serta penutupan blok fungsi Utama.

## Kesimpulan
Bahasa pemrograman C++ memiliki komponen utama yang terdiri dari bagian include untuk memasukkan library, namespace (yang bersifat opsional) untuk mempermudah akses pada fungsi-fungsi standar, serta fungsi main() yang merupakan tempat untuk menjalankan program. C++ adalah bahasa yang memiliki tipe data yang ketat, sehingga setiap variabel harus didefinisikan dengan tipe data terlebih dahulu. Struktur dasar C++ mencakup deklarasi variabel dan konstanta, tipe data, serta kontrol alur seperti percabangan (if, if/else, switch/case, atau yang bersarang) dan perulangan (for, while, do-while) untuk mengelola logika program. Selain itu, C++ menawarkan struct sebagai cara untuk mengelompokkan data terkait, sehingga dapat menciptakan tipe data baru yang lebih rumit dibandingkan tipe data primitif. Dengan demikian, C++ adalah bahasa yang terorganisir, memiliki kekuatan dalam pengelolaan data, dan mendukung penyelesaian masalah melalui logika percabangan dan perulangan.

## Referensi
[1] Team, J. H. (2025). Mengenal Bahasa Pemrograman C++ untuk Pemula. Retrieved from https://www.jagoanhosting.com/blog/bahasa-pemrograman-c/
<br>[2] Akbar, B. (2022). Percabangan C++. Retrieved from https://blog.rumahcoding.co.id/percabangan-c/
<br>[3] Akbar, B. (2022). Perulangan C++. Retrieved from https://blog.rumahcoding.co.id/perulangan-c/
<br>[4] W3Schools.com. (n.d.). Retrieved from https://www.w3schools.com/cpp/cpp_structs.asp
<br>[5] Modul 1 - Praktikum Struktur Data