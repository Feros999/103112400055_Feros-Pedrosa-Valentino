#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    insertFirst(L, alokasi(9));

    insertAfter(L.first, alokasi(12));

    insertAfter(L.first->next, alokasi(8));

    insertAfter(L.first->next->next, alokasi(0));

    insertLast(L, alokasi(2));

    printList(L);

    return 0;
}