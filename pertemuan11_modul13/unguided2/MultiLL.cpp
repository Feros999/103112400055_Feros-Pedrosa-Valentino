#include "MultiLL.h"

bool isEmptyParent(listParent LParent) {
    return LParent.first == NULL;
}

bool isEmptyChild(listChild LChild) {
    return LChild.first == NULL;
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}

void printMLLStructure(listParent LParent) {
    NodeParent P = LParent.first;
    int i = 1;
    while (P != NULL) {
        cout << "Parent " << i << endl;
        cout << "ID Golongan   : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
        
        if (isEmptyChild(P->L_Child)) {
            cout << "(tidak ada child)" << endl;
        } else {
            NodeChild C = P->L_Child.first;
            int j = 1;
            while (C != NULL) {
                cout << " - Child " << j << ":" << endl;
                cout << "   ID Hewan    : " << C->isidata.idHewan << endl;
                cout << "   Nama Hewan  : " << C->isidata.namaHewan << endl;
                cout << "   Habitat     : " << C->isidata.habitat << endl;
                cout << "   Ekor        : " << C->isidata.ekor << endl;
                cout << "   Bobot       : " << C->isidata.bobot << endl;
                C = C->next;
                j++;
            }
        }
        cout << endl;
        P = P->next;
        i++;
    }
}

void searchHewanByEkor(listParent LParent, bool tail) {
    NodeParent P = LParent.first;
    int idxParent = 1; 

    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        int idxChild = 1; 
        
        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                cout << "Data ditemukan pada list anak dari node parent " << P->isidata.namaGolongan << " pada posisi ke-" << idxChild << "!" << endl;
                
                cout << "--- Data Child ---" << endl;
                cout << "ID Child      : " << C->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << idxChild << endl;
                cout << "Nama Hewan    : " << C->isidata.namaHewan << endl;
                cout << "Habitat       : " << C->isidata.habitat << endl;
                cout << "Ekor          : " << C->isidata.ekor << endl;
                cout << "Bobot         : " << C->isidata.bobot << endl;
                cout << "-------------------------------------------" << endl;
                
                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent     : " << P->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << idxParent << endl;
                cout << "Nama golongan : " << P->isidata.namaGolongan << endl;
                cout << "-------------------------------------------" << endl;
                cout << endl;
            }
            C = C->next;
            idxChild++;
        }
        P = P->next;
        idxParent++;
    }
}