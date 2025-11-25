#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* next;
};

Node* head = nullptr;

void insertLast(string name) {
    Node* newNode = new Node();
    newNode->name = name;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteName(string target) {
    if (head == nullptr) return;

    if (head->name == target) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->name != target) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr) {
        prev->next = current->next;
        delete current;
    }
}

void viewList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->name << " ";
        temp = temp->next;
    }
    cout << endl;
}

void countEvenLength() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->name.length() % 2 == 0) {
            count++;
        }
        temp = temp->next;
    }
    cout << "Jumlah nama dengan huruf genap: " << count << endl;
}

int main() {
    int choice;
    string inputName;

    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> inputName;
                insertLast(inputName);
                break;
            case 2:
                cout << "Masukkan nama untuk delete: ";
                cin >> inputName;
                deleteName(inputName);
                break;
            case 3:
                viewList();
                break;
            case 4:
                countEvenLength();
                break;
            case 0:
                break;
            default:
                break;
        }
    } while (choice != 0);

    return 0;
}