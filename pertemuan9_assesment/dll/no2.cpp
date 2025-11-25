#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* tail = nullptr;

void insertLast(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void deleteLast() {
    if (head == nullptr) return;

    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
}

void viewList() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void reverseList() {
    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        current = current->prev;
    }

    if (temp != nullptr) {
        head = temp->prev;
        
        Node* t = head;
        while(t->next != nullptr){
            t = t->next;
        }
        tail = t;
    }
}

int main() {
    int choice;
    int inputVal;

    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> inputVal;
                insertLast(inputVal);
                break;
            case 2:
                deleteLast();
                break;
            case 3:
                viewList();
                break;
            case 4:
                reverseList();
                cout << "List setelah di-reverse: ";
                viewList();
                break;
            case 0:
                break;
            default:
                break;
        }
    } while (choice != 0);

    return 0;
}