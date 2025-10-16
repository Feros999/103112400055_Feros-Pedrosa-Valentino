#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    insertFirst(L, alokasi(9));
    insertAfter(L.first, alokasi(12));
    insertAfter(L.first->next, alokasi(8));
    insertAfter(L.first->next->next, alokasi(0));
    insertLast(L, alokasi(2));

    deleteFirst(L);           // hapus node 9
    deleteLast(L);            // hapus node 2
    deleteAfter(L.first);     // hapus node 8 (setelah 12)

    printList(L);

    cout << endl;
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}