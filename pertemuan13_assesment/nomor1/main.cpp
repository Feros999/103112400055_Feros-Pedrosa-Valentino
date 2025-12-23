#include "bst.h"

int main() {
    adrNode root;

    createTree(root);

    insertNode(root, newNode("Rizkina Azizah", 60, "Basic"));

    insertNode(root, newNode("Hakan Ismail", 50, "Bronze"));
    insertNode(root, newNode("Olivia Saevali", 65, "Silver"));

    insertNode(root, newNode("Felix Pedrosa", 47, "Gold"));
    insertNode(root, newNode("Gamel Al Ghifari", 56, "Platinum"));
    insertNode(root, newNode("Hanif Al Faiz", 70, "Basic"));

    insertNode(root, newNode("Mutiara Fauziah", 52, "Bronze"));
    insertNode(root, newNode("Davi Ilyas", 68, "Silver"));
    insertNode(root, newNode("Abdad Mubarok", 81, "Gold"));

    cout << "=== Traversal InOrder ===" << endl;
    inOrder(root);
    cout << endl << endl;

    mostLeft(root);
    mostRight(root);
    cout << endl;

    searchByBeratBadan(root, 70);

    return 0;
}