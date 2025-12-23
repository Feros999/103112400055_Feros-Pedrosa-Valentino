#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>
using namespace std;

typedef struct NodeChild* adrChild;
typedef struct NodeParent* adrParent;

struct NodeChild {
    string IDFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    
    adrChild next;
    adrChild prev;
};

struct NodeParent {
    string IDGenre;
    string namaGenre;
    
    adrParent next;
    adrParent prev;
    
    adrChild firstChild;
    adrChild lastChild;
};

struct ListParent {
    adrParent first;
    adrParent last;
};

void createListParent(ListParent &L);
adrParent alokasiNodeParent(string id, string nama);
adrChild alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);
void dealokasiNodeParent(adrParent P);
void dealokasiNodeChild(adrChild C);

void insertFirstParent(ListParent &L, adrParent P);
void insertLastChild(adrParent P, adrChild C);
void hapusListChild(adrParent P);
void deleteAfterParent(ListParent &L, string prevID);

adrParent findParent(ListParent L, string idGenre);
void searchFilmByRatingRange(ListParent L, float minRating, float maxRating);
void printStrukturMLL(ListParent L);

#endif