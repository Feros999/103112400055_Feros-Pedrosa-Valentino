#include "mll.h"
#include <iomanip>

void createListParent(ListParent &L) {
    L.first = NULL;
    L.last = NULL;
}

adrParent alokasiNodeParent(string id, string nama) {
    adrParent P = new NodeParent;
    P->IDGenre = id;
    P->namaGenre = nama;
    P->next = NULL;
    P->prev = NULL;
    P->firstChild = NULL;
    P->lastChild = NULL;
    return P;
}

adrChild alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    adrChild C = new NodeChild;
    C->IDFilm = id;
    C->judulFilm = judul;
    C->durasiFilm = durasi;
    C->tahunTayang = tahun;
    C->ratingFilm = rating;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void dealokasiNodeParent(adrParent P) {
    delete P;
}

void dealokasiNodeChild(adrChild C) {
    delete C;
}

void insertFirstParent(ListParent &L, adrParent P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastChild(adrParent P, adrChild C) {
    if (P->firstChild == NULL) {
        P->firstChild = C;
        P->lastChild = C;
    } else {
        P->lastChild->next = C;
        C->prev = P->lastChild;
        P->lastChild = C;
    }
}

void hapusListChild(adrParent P) {
    adrChild curr = P->firstChild;
    while (curr != NULL) {
        adrChild temp = curr;
        curr = curr->next;
        dealokasiNodeChild(temp);
    }
    P->firstChild = NULL;
    P->lastChild = NULL;
}

void deleteAfterParent(ListParent &L, string prevID) {
    // 1. Cari node predecessor (prev)
    adrParent prec = L.first;
    while (prec != NULL && prec->IDGenre != prevID) {
        prec = prec->next;
    }

    // 2. Cek apakah prec ditemukan dan bukan node terakhir
    if (prec != NULL && prec->next != NULL) {
        adrParent del = prec->next; // Node yang akan dihapus
        
        // 3. Hapus semua child dari node yang akan dihapus (PENTING)
        hapusListChild(del);

        // 4. Ubah pointer next dan prev untuk memutus del
        prec->next = del->next;
        if (del->next != NULL) {
            del->next->prev = prec;
        } else {
            // Jika del adalah elemen terakhir, update L.last
            L.last = prec;
        }

        // 5. Dealokasi memori parent
        dealokasiNodeParent(del);
    }
}

adrParent findParent(ListParent L, string idGenre) {
    adrParent P = L.first;
    while (P != NULL) {
        if (P->IDGenre == idGenre) return P;
        P = P->next;
    }
    return NULL;
}

void searchFilmByRatingRange(ListParent L, float minRating, float maxRating) {
    adrParent P = L.first;
    int idxParent = 1;

    while (P != NULL) {
        adrChild C = P->firstChild;
        int idxChild = 1;
        while (C != NULL) {
            if (C->ratingFilm >= minRating && C->ratingFilm <= maxRating) {
                cout << "Data Film ditemukan pada list child dari node parent " 
                     << P->namaGenre << " pada posisi ke-" << idxChild << "!" << endl;
                
                cout << "--- Data Film (Child) ---" << endl;
                cout << "Judul Film : " << C->judulFilm << endl;
                cout << "Posisi dalam list child : posisi ke-" << idxChild << endl;
                cout << "ID Film : " << C->IDFilm << endl;
                cout << "Durasi Film : " << C->durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << C->tahunTayang << endl;
                cout << "Rating Film : " << C->ratingFilm << endl;
                cout << "-------------------------" << endl;

                cout << "--- Data Genre (Parent) ---" << endl;
                cout << "ID Genre : " << P->IDGenre << endl;
                cout << "Posisi dalam list parent : posisi ke-" << idxParent << endl;
                cout << "Nama Genre : " << P->namaGenre << endl;
                cout << "=========================" << endl;
            }
            C = C->next;
            idxChild++;
        }
        P = P->next;
        idxParent++;
    }
}

void printStrukturMLL(ListParent L) {
    adrParent P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i << " ===" << endl;
        cout << "ID Genre : " << P->IDGenre << endl;
        cout << "Nama Genre : " << P->namaGenre << endl;

        adrChild C = P->firstChild;
        int j = 1;
        while (C != NULL) {
            cout << "   - Child " << j << " :" << endl;
            cout << "     ID Film : " << C->IDFilm << endl;
            cout << "     Judul Film : " << C->judulFilm << endl;
            cout << "     Durasi Film : " << C->durasiFilm << " menit" << endl;
            cout << "     Tahun Tayang : " << C->tahunTayang << endl;
            cout << "     Rating Film : " << C->ratingFilm << endl;
            C = C->next;
            j++;
        }
        cout << "------------------------" << endl;
        P = P->next;
        i++;
    }
}