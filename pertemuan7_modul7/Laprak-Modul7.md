# <h1 align="center">Laporan Praktikum Modul 7 - STACK</h1>
<p align="center">Feros Pedrosa Valentino - 103112400055</p>

## Dasar Teori
Stack merupakan salah satu bentuk struktur data dimana prinsip operasi yang digunakan seperti
tumpukan. Seperti halnya tumpukan, elemen yang bisa diambil terlebih dahulu adalah elemen yang
paling atas, atau elemen yang pertama kali masuk, prinsip ini biasa disebut LIFO (Last In First Out)[1]. Dalam stack ada dua operasi utama, yaitu operasi penyisipan(Push) dan operasi pengambilan(Pop). Push adalah operasi menyisipkan elemen pada tumpukan data. Fungsi ini sama dengan fungsi insert first pada list biasa. Pop adalah operasi pengambilan data dalam list. Operasi ini mirip dengan operasi delete first dalam list linear karena elemen yang paling pertama kali diakses adalah elemen paling atas atau elemen paling awal saja. Dan ada Operasi lainnya yaitu Atas atau Intip untuk Mengakses elemen atas tanpa menghapusnya dan isEmpty untuk Memeriksa apakah tumpukan kosong[2]. Primitif-primitif dalam stack pada dasarnya sama dengan primitif-primitif pada list lainnya. Malahan primitif dalam stack lebih sedikit, karena dalam stack hanya melakukan operasi-operasi terhadap elemen paling atas. Primitif-primitif dalam stack yaitu createStack(), isEmpty(), alokasi(), dealokasi(), Fungsi– fungsi pencarian, dan fungsi– fungsi primitif lainnya. Di bahasa C++, stack dapat diimplementasikan menggunakan array statis dengan ukuran tetap seperti MaxEl=20 dan top=-1 untuk kondisi kosong, yang sederhana namun berisiko overflow, atau linked list dengan node berisi data dan pointer next untuk ukuran dinamis tanpa batas [3].


## Guided 

### 1. Guided 1

stack.h
```C++
#ifndef STACK_H
#define STACK_H
#define Nil NULL

#include <iostream>
using namespace std; 

typedef struct node *address; 

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```
stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```

Program ini merupakan implementasi struktur data stack (tumpukan) menggunakan linked list di bahasa C++, yang terdiri dari tiga file utama: stack.h sebagai header yang mendefinisikan struktur node (berisi data integer dan pointer next) serta stack (dengan pointer top), serta prototipe fungsi; stack.cpp yang mengimplementasikan fungsi-fungsi seperti isEmpty untuk mengecek stack kosong, createStack untuk inisialisasi, alokasi dan dealokasi untuk manajemen memori node, push untuk menambahkan elemen ke puncak stack, pop untuk menghapus elemen dari puncak, update untuk mengubah data pada posisi tertentu (dari top), view untuk menampilkan isi stack dari atas ke bawah, dan searchData untuk mencari data spesifik; serta main.cpp yang mendemonstrasikan penggunaan dengan membuat stack kosong, mengalokasikan lima node (dengan data 1 hingga 5), melakukan push untuk membangun stack (menjadi 5-4-3-2-1 dari top), menampilkan isi, melakukan pop dua kali (menghapus 5 dan 4, tersisa 3-2-1), mengupdate posisi 2 dan 1 (dengan input user, serta gagal pada posisi 4 karena invalid), menampilkan hasil update, dan mencari data 4 (tidak ditemukan) serta 9 (tidak ditemukan), dengan semua operasi memberikan feedback melalui output konsol untuk menunjukkan keberhasilan atau error seperti stack kosong atau posisi tidak valid. Implementasi ini mengikuti prinsip LIFO (Last In, First Out) dan menggunakan pointer untuk navigasi linked list, memungkinkan operasi dinamis tanpa batas ukuran tetap.

### 2. Guided 2

stack.h
```C++
#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack{
    infotype info[MaxEl]; //Array untuk menyimpan elemen stack
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x); //Menambahkan elemen ke dalam stack
infotype pop(Stack &S); //Mengambil elemen teratas dari stack
void printInfo(Stack S);
void balikStack(Stack &S); //Membalik urutan elemen dalam stack

#endif
```
stack.cpp
```C++
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```
main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```

Program ini merupakan implementasi struktur data stack (tumpukan) menggunakan array statis di bahasa C++, dengan kapasitas maksimal 20 elemen, yang terdiri dari tiga file: stack.h sebagai header yang mendefinisikan struktur Stack (berisi array info untuk menyimpan elemen dan integer top untuk indeks puncak), serta prototipe fungsi; stack.cpp yang mengimplementasikan fungsi-fungsi seperti CreateStack untuk inisialisasi stack kosong (top = -1), isEmpty dan isFull untuk pengecekan kondisi, push untuk menambahkan elemen ke puncak jika belum penuh, pop untuk mengambil elemen teratas jika tidak kosong, printInfo untuk menampilkan isi stack dari top ke bottom, dan balikStack untuk membalik urutan elemen menggunakan dua stack temporary sebagai bantuan; serta main.cpp yang mendemonstrasikan penggunaan dengan membuat stack kosong, melakukan serangkaian push (menambahkan 3, 4, 8) dan pop (menghapus 8), lalu push lagi (2, 3), pop (menghapus 3), dan push (9), sehingga stack akhir berisi 3, 4, 2, 9 dari bottom ke top, menampilkan isi awal, membalik stack (menjadi 9, 2, 4, 3), dan menampilkan hasil akhir, dengan semua operasi mengikuti prinsip LIFO (Last In, First Out) dan memberikan pesan error jika stack kosong atau penuh. 


## Unguided 

### 1. Soal Unguided 1
Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”
Type infotype : integer
Type Stack<
    info: array [20] of integer
    top: integer
>
procedure CreateStack( input/output S :Stack)
procedure push(input/output S: Stack,
                inputx: infotype)
function pop(input/output t S: Stack)
    →infotype
procedure printInfo(input S :Stack)
procedure balikStack(input/output S: Stack)

Buatlah implementasi ADT Stack menggunakan Array pada file “stack.cpp” dan “main.cpp”
int main(){
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    Push(S,3);
    Push(S,4);
    Push(S,8);
    pop(S)
    Push(S,2);
    Push(S,3);
    pop(S);
    Push(S,9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}

stack.h
```C++
#ifndef STACK_H
#define STACK_H

#define MaxEl 20
typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```
stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

// Fungsi untuk membuat stack baru dengan menginisialisasi top = -1 (kosong)
void CreateStack(Stack &S) {
    S.top = -1;  // Inisialisasi top dengan -1 menandakan stack kosong
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (S.top < MaxEl - 1) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh (meskipun tidak terjadi dalam contoh ini)
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (S.top != -1) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;
    }
    return x;
}

// Fungsi untuk menampilkan isi stack dari top ke bottom
void printInfo(Stack S) {
    if (S.top == -1) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong (meskipun tidak terjadi dalam contoh ini)
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (S.top != -1) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (S.top != -1) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (temp1.top != -1) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (temp2.top != -1) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```
main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan7_modul7/output-unguided1-modul7.png)

Program ini terdiri dari header stack.h, file implementasi stack.cpp, dan program utama main.cpp. Di stack.h, didefinisikan struktur Stack dengan array info berukuran maksimal 20 elemen (MaxEl) dan variabel top untuk menunjukkan indeks elemen teratas, serta deklarasi fungsi-fungsi dasar seperti CreateStack untuk inisialisasi stack kosong (dengan top = -1), push untuk menambahkan elemen baru ke puncak stack, pop untuk mengambil dan menghapus elemen teratas, printInfo untuk menampilkan isi stack dari atas ke bawah dengan penanda [TOP], dan balikStack untuk membalik urutan elemen dalam stack. Implementasi di stack.cpp menunjukkan operasi stack berbasis prinsip LIFO (Last In, First Out), di mana push menambah elemen jika stack belum penuh, pop mengambil elemen teratas jika stack tidak kosong, dan keduanya memberikan pesan error jika kondisi tidak terpenuhi, meskipun dalam contoh ini tidak terjadi. Fungsi balikStack menggunakan dua stack temporary (temp1 dan temp2) untuk membalik urutan elemen dengan cara memindahkan semua elemen dari stack asal ke temp1 (membalik urutan pertama kali), lalu ke temp2 (membalik lagi), dan akhirnya kembali ke stack asal (urutan sudah benar). Di main.cpp, program dimulai dengan membuat stack baru, kemudian melakukan serangkaian operasi: push nilai 3, 4, dan 8 , pop untuk menghapus 8 , push 2 dan 3 , pop lagi untuk menghapus 3 , push 9 , lalu mencetak isi stack, setelah itu membalik stack dengan balikStack, dan mencetak lagi dengan [TOP] 3 4 2 9.

### 2. Soal Unguided 2
Tambahkan prosedur pushAscending(in/out S : Stack, in x : integer)
int main()
{
cout << "Hello world!" << endl;
Stack S;
createStack(S);
pushAscending(S,3);
pushAscending(S,4);
pushAscending(S,8);
pushAscending(S,2);
pushAscending(S,3);
pushAscending(S,9);
printInfo(S);
cout << "balik stack" << endl;
balikStack(S);
printInfo(S);
return 0;
}

stack.h
```C++
#ifndef STACK_H
#define STACK_H

#define MaxEl 20
typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);

#endif
```
stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

// Fungsi untuk membuat stack baru dengan menginisialisasi top = -1 (kosong)
void CreateStack(Stack &S) {
    S.top = -1;  // Inisialisasi top dengan -1 menandakan stack kosong
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (S.top < MaxEl - 1) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh (meskipun tidak terjadi dalam contoh ini)
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (S.top != -1) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong (meskipun tidak terjadi dalam contoh ini)
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack dari top ke bottom
void printInfo(Stack S) {
    if (S.top == -1) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong (meskipun tidak terjadi dalam contoh ini)
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (S.top != -1) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (S.top != -1) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (temp1.top != -1) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (temp2.top != -1) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}

// Fungsi untuk push elemen secara ascending (menyisipkan x agar stack terurut ascending dari bottom ke top)
void pushAscending(Stack &S, infotype x) {
    Stack temp;  // Stack temporary untuk menyimpan elemen yang lebih besar dari x
    CreateStack(temp);

    // Pop elemen dari S yang lebih besar dari x dan pindahkan ke temp
    while (S.top != -1 && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    // Push x ke S
    push(S, x);

    // Push kembali elemen dari temp ke S
    while (temp.top != -1) {
        push(S, pop(temp));
    }
}
```
main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan7_modul7/output-unguided2-modul7.png)

Program ini terdiri dari header stack.h, file implementasi stack.cpp, dan program utama main.cpp. Di stack.h, didefinisikan struktur Stack dengan array info berukuran maksimal 20 elemen (MaxEl) dan variabel top untuk menunjukkan posisi elemen teratas, serta deklarasi fungsi-fungsi seperti CreateStack untuk inisialisasi stack kosong, push untuk menambahkan elemen, pop untuk mengambil elemen teratas, printInfo untuk menampilkan isi stack dari atas ke bawah, balikStack untuk membalik urutan elemen, dan pushAscending untuk menyisipkan elemen baru secara terurut ascending dari bawah ke atas. Implementasi di stack.cpp menunjukkan operasi stack berbasis LIFO, dengan penanganan kondisi stack penuh atau kosong melalui pesan error, meskipun dalam contoh ini tidak terjadi. Fungsi balikStack menggunakan dua stack temporary (temp1 dan temp2) untuk membalik urutan elemen dengan cara memindahkan elemen bolak-balik, sementara pushAscending memanfaatkan stack temporary untuk mem-pop elemen yang lebih besar dari nilai baru, menyisipkan nilai tersebut, lalu mem-push kembali elemen dari temporary, sehingga stack selalu terjaga urutannya. Di main.cpp, program dimulai dengan membuat stack baru, kemudian memanggil pushAscending berulang kali untuk menyisipkan nilai 3, 4, 8, 2, 3, dan 9 secara terurut, menghasilkan stack yang ascending dari bottom ke top (misalnya, 2, 3, 3, 4, 8, 9), setelah itu mencetak isi stack, membalik urutannya dengan balikStack (menjadi descending dari top ke bottom), dan mencetak lagi.

### 3. Soal Unguided 3
Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.
int main()
{
cout << "Hello world!" << endl;
Stack S;
createStack(S);
getInputStream(S);
printInfo(S);
cout << " balik stack " << endl;
balikStack(S);
printInfo(S);
return 0;
} 

stack.h
```C++
#ifndef STACK_H
#define STACK_H

#define MaxEl 20
typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif
```
stack.cpp
```C++
#include "stack.h"
#include <iostream>
#include <cctype>  // Untuk isdigit
using namespace std;

// Fungsi untuk membuat stack baru dengan menginisialisasi top = -1 (kosong)
void CreateStack(Stack &S) {
    S.top = -1;  // Inisialisasi top dengan -1 menandakan stack kosong
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (S.top < MaxEl - 1) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (S.top != -1) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack dari top ke bottom
void printInfo(Stack S) {
    if (S.top == -1) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (S.top != -1) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (S.top != -1) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (temp1.top != -1) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (temp2.top != -1) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}

// Fungsi untuk push elemen secara ascending (menyisipkan x agar stack terurut ascending dari bottom ke top)
void pushAscending(Stack &S, infotype x) {
    Stack temp;  // Stack temporary untuk menyimpan elemen yang lebih besar dari x
    CreateStack(temp);

    // Pop elemen dari S yang lebih besar dari x dan pindahkan ke temp
    while (S.top != -1 && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    // Push x ke S
    push(S, x);

    // Push kembali elemen dari temp ke S
    while (temp.top != -1) {
        push(S, pop(temp));
    }
}

// Fungsi untuk membaca input stream dari user hingga enter (newline), push digit sebagai integer
void getInputStream(Stack &S) {
    char c;
    while ((c = cin.get()) != '\n') {  // Baca karakter hingga newline
        if (isdigit(c)) {  // Jika karakter adalah digit
            push(S, c - '0');  // Konversi char ke int dan push
        }
    }
}
```
main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Feros999/103112400055_Feros-Pedrosa-Valentino/blob/main/pertemuan7_modul7/output-unguided3-modul7.png)

Program ini terdiri dari tiga file utama yaitu stack.h sebagai header file, stack.cpp sebagai implementasi fungsi, dan main.cpp sebagai program utama. Di stack.h, didefinisikan struktur Stack yang menggunakan array statis info dengan kapasitas maksimal 20 elemen (MaxEl) dan variabel top untuk menunjukkan indeks elemen teratas, serta deklarasi berbagai fungsi seperti CreateStack untuk inisialisasi stack kosong, push untuk menambahkan elemen, pop untuk mengambil elemen teratas, printInfo untuk menampilkan isi stack dari atas ke bawah, balikStack untuk membalik urutan elemen, pushAscending untuk menyisipkan elemen secara terurut ascending, dan getInputStream untuk membaca input karakter dari pengguna dan hanya mem-push digit sebagai integer. Implementasi di stack.cpp menunjukkan bahwa stack menggunakan prinsip LIFO (Last In, First Out), dengan penanganan error seperti stack penuh atau kosong. Fungsi balikStack, misalnya, menggunakan dua stack temporary untuk membalik urutan elemen dengan cara memindahkan elemen bolak-balik, sementara pushAscending memanfaatkan stack temporary untuk menyisipkan elemen baru pada posisi yang tepat agar stack tetap terurut dari bawah ke atas. Di main.cpp, program dimulai dengan membuat stack baru, kemudian memanggil getInputStream untuk membaca input stream hingga newline dan hanya memproses digit, setelah itu mencetak isi stack, membaliknya dengan balikStack, dan mencetak lagi, sehingga menunjukkan fungsionalitas dasar stack dalam mengelola data secara efisien. 

## Kesimpulan
Stack menunjukkan bahwa stack adalah struktur data linier yang fundamental dengan prinsip LIFO (Last In, First Out), di mana operasi utama seperti push (penyisipan elemen ke puncak), pop (pengambilan elemen dari puncak), atas/intip (akses tanpa penghapusan), dan isEmpty (pengecekan kosong) dilakukan secara efisien hanya pada elemen paling atas, mirip dengan operasi insert/delete first pada list linear namun lebih sederhana karena primitifnya terbatas pada createStack, isEmpty, alokasi, dealokasi, dan fungsi pencarian tambahan. Implementasi stack di bahasa C++ dapat menggunakan array statis untuk kesederhanaan dengan risiko overflow atau linked list untuk fleksibilitas ukuran dinamis, menjadikannya alat penting dalam pemrograman untuk aplikasi seperti evaluasi ekspresi, rekursi, dan lain sebagainya. 

## Referensi
[1] Modul 7 - Praktikum Struktur Data
<br>[2] Singh, R. (2024). Understanding how to use Stack & Queues (C++). Retrieved from https://medium.com/@RobuRishabh/understanding-how-to-use-stack-queues-c-9f1fc06d1c5e
<br>[3] Goodrich, M. T., Tamassia, R., & Mount, D. M. (2011). Data Structures and Algorithms in C++ (2nd ed.). Wiley.