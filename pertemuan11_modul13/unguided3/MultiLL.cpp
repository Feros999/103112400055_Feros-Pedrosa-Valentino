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

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        insertFirstParent(LParent, newNParent);
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent P = LParent.first;
        // Hapus semua child dulu
        deleteListChild(P->L_Child);
        
        if (LParent.first == LParent.last) {
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = P->next;
            LParent.first->prev = NULL;
            P->next = NULL;
        }
        deallocNodeParent(P);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent del = NPrev->next;
        // Hapus semua child dari node yang akan dihapus
        deleteListChild(del->L_Child);

        NPrev->next = del->next;
        if (del->next != NULL) {
            del->next->prev = NPrev;
        } else {
            LParent.last = NPrev;
        }
        
        del->next = NULL;
        del->prev = NULL;
        deallocNodeParent(del);
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        insertFirstChild(LChild, newNChild);
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild C = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = C->next;
            LChild.first->prev = NULL;
            C->next = NULL;
        }
        deallocNodeChild(C);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild del = NPrev->next;
        NPrev->next = del->next;
        if (del->next != NULL) {
            del->next->prev = NPrev;
        } else {
            LChild.last = NPrev;
        }
        del->next = NULL;
        del->prev = NULL;
        deallocNodeChild(del);
    }
}

void printMLLStructure(listParent LParent) {
    if (isEmptyParent(LParent)) {
        cout << "List Kosong" << endl;
        return;
    }

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
                cout << "   Ekor        : " << (C->isidata.ekor ? "1" : "0") << endl;
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
    cout << "===========================================" << endl;
    cout << "SEARCH HASIL (Ekor: " << (tail ? "True" : "False") << ")" << endl;
    cout << "===========================================" << endl;

    NodeParent P = LParent.first;
    int idxParent = 1;
    bool found = false;

    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        int idxChild = 1;
        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                found = true;
                cout << "Data ditemukan pada list anak dari node parent " << P->isidata.namaGolongan << " pada posisi ke-" << idxChild << "!" << endl;
                
                cout << "--- Data Child ---" << endl;
                cout << "ID Child      : " << C->isidata.idHewan << endl;
                cout << "Posisi child  : posisi ke-" << idxChild << endl;
                cout << "Nama Hewan    : " << C->isidata.namaHewan << endl;
                cout << "Habitat       : " << C->isidata.habitat << endl;
                cout << "Ekor          : " << (C->isidata.ekor ? "1" : "0") << endl;
                cout << "Bobot         : " << C->isidata.bobot << endl;
                
                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent     : " << P->isidata.idGolongan << endl;
                cout << "Posisi parent : posisi ke-" << idxParent << endl;
                cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
                cout << "-------------------------------------------" << endl;
            }
            C = C->next;
            idxChild++;
        }
        P = P->next;
        idxParent++;
    }

    if (!found) {
        cout << "Data tidak ditemukan." << endl;
    }
}