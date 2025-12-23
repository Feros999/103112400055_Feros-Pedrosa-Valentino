#include "mll.h"

int main() {
    ListParent LP;
    createListParent(LP);
    
    insertFirstParent(LP, alokasiNodeParent("G004", "Romance"));
    insertFirstParent(LP, alokasiNodeParent("G003", "Horror"));
    insertFirstParent(LP, alokasiNodeParent("G002", "Comedy"));
    insertFirstParent(LP, alokasiNodeParent("G001", "Action"));

    adrParent pAction = findParent(LP, "G001");
    if (pAction != NULL) {
        insertLastChild(pAction, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));
    }

    adrParent pComedy = findParent(LP, "G002");
    if (pComedy != NULL) {
        insertLastChild(pComedy, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
        insertLastChild(pComedy, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));
    }

    adrParent pHorror = findParent(LP, "G003");
    if (pHorror != NULL) {
        insertLastChild(pHorror, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));
    }

    adrParent pRomance = findParent(LP, "G004");
    if (pRomance != NULL) {
        insertLastChild(pRomance, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
        insertLastChild(pRomance, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));
    }

    cout << "OUTPUT 1: Struktur Awal MLL" << endl;
    printStrukturMLL(LP);
    cout << endl;

    cout << "OUTPUT 2: Search Film Rating 8.0 - 8.5" << endl;
    searchFilmByRatingRange(LP, 8.0, 8.5);
    cout << endl;

    cout << "Melakukan penghapusan node setelah G001..." << endl << endl;
    deleteAfterParent(LP, "G001");

    cout << "OUTPUT 3: Struktur Setelah Delete G002" << endl;
    printStrukturMLL(LP);

    return 0;
}