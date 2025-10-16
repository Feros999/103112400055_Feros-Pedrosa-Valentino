#include "Singlylist.h"

void createList(List& L) { L.first = nullptr; }

Node* alokasi(int x) {
    Node* P = new Node;
    P->info = x;
    P->next = nullptr;
    return P;
}

void insertFirst(List& L, Node* P) {
    P->next = L.first;
    L.first = P;
}

void insertAfter(Node* Prec, Node* P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(List& L, Node* P) {
    if (L.first == nullptr)
        L.first = P;
    else {
        Node* Q = L.first;
        while (Q->next != nullptr)
            Q = Q->next;
        Q->next = P;
    }
}

void printList(const List& L) {
    Node* P = L.first;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List& L) {
    if (L.first != nullptr) {
        Node* P = L.first;
        L.first = P->next;
        delete P;
    }
}

void deleteLast(List& L) {
    if (L.first != nullptr) {
        if (L.first->next == nullptr) {
            delete L.first;
            L.first = nullptr;
        } else {
            Node* P = L.first;
            while (P->next->next != nullptr)
                P = P->next;
            delete P->next;
            P->next = nullptr;
        }
    }
}

void deleteAfter(Node* Prec) {
    if (Prec != nullptr && Prec->next != nullptr) {
        Node* P = Prec->next;
        Prec->next = P->next;
        delete P;
    }
}

int nbList(const List& L) {
    int count = 0;
    Node* P = L.first;
    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List& L) {
    Node* P = L.first;
    while (P != nullptr) {
        Node* temp = P;
        P = P->next;
        delete temp;
    }
    L.first = nullptr;
}