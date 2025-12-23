#include "bst.h"

bool isEmpty(adrNode root) {
    return root == NULL;
}

void createTree(adrNode &root) {
    root = NULL;
}

adrNode newNode(string nama, float berat, string tier) {
    adrNode p = new Node;
    p->namaMember = nama;
    p->beratBadan = berat;
    p->tierMember = tier;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(adrNode &root, adrNode p) {
    if (root == NULL) {
        root = p;
    } else {
        if (p->beratBadan < root->beratBadan) {
            insertNode(root->left, p);
        } else if (p->beratBadan > root->beratBadan) {
            insertNode(root->right, p);
        } else {
            cout << "Duplicate berat badan " << p->beratBadan << " ignored." << endl;
        }
    }
}

void inOrder(adrNode root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->beratBadan << " - ";
        inOrder(root->right);
    }
}

void mostLeft(adrNode root) {
    if (root == NULL) return;
    adrNode curr = root;
    while (curr->left != NULL) {
        curr = curr->left;
    }
    cout << "Node MostLeft : " << curr->beratBadan << endl;
}

void mostRight(adrNode root) {
    if (root == NULL) return;
    adrNode curr = root;
    while (curr->right != NULL) {
        curr = curr->right;
    }
    cout << "Node MostRight : " << curr->beratBadan << endl;
}

void searchByBeratBadan(adrNode root, float targetBerat) {
    adrNode curr = root;
    adrNode parent = NULL;
    bool found = false;

    // 1. Proses Pencarian (Iterative agar mudah tracking parent)
    while (curr != NULL) {
        if (curr->beratBadan == targetBerat) {
            found = true;
            break;
        }
        parent = curr;
        if (targetBerat < curr->beratBadan) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    // 2. Output Hasil
    if (found) {
        cout << "Data ditemukan didalam BST!" << endl;
        
        cout << "--- Data Node Yang Dicari ---" << endl;
        cout << "Nama Member : " << curr->namaMember << endl;
        cout << "Berat Badan : " << curr->beratBadan << endl;
        cout << "Tier Member : " << curr->tierMember << endl;
        cout << "-----------------------------" << endl;

        cout << endl << "--- Data Parent ---" << endl;
        if (parent != NULL) {
            cout << "Nama Member : " << parent->namaMember << endl;
            cout << "Berat Badan : " << parent->beratBadan << endl;
            cout << "Tier Member : " << parent->tierMember << endl;
            cout << "-----------------------------" << endl;

            adrNode sibling = NULL;

            if (parent->left == curr) {
                sibling = parent->right;
            } else {
                sibling = parent->left;
            }

            if (sibling != NULL) {
                cout << "Sibling : " << sibling->namaMember << " (" << sibling->beratBadan << ")" << endl;
            } else {
                cout << "Tidak Memiliki Sibling" << endl;
            }
        } else {
            cout << "Node ini adalah Root (Tidak punya parent)" << endl;
            cout << "-----------------------------" << endl;
            cout << "Tidak Memiliki Sibling" << endl;
        }
        cout << "-----------------------------" << endl;

        cout << endl << "--- Data Child Kiri ---" << endl;
        if (curr->left != NULL) {
            cout << "Nama Member : " << curr->left->namaMember << endl;
            cout << "Berat Badan : " << curr->left->beratBadan << endl;
            cout << "Tier Member : " << curr->left->tierMember << endl;
        } else {
            cout << "Tidak memiliki Child Kiri" << endl;
        }
        cout << "-----------------------------" << endl;

        cout << endl << "--- Data Child Kanan ---" << endl;
        if (curr->right != NULL) {
            cout << "Nama Member : " << curr->right->namaMember << endl;
            cout << "Berat Badan : " << curr->right->beratBadan << endl;
            cout << "Tier Member : " << curr->right->tierMember << endl;
        } else {
            cout << "Tidak memiliki Child Kanan" << endl;
        }
        cout << "-----------------------------" << endl;

    } else {
        cout << "Data dengan berat badan " << targetBerat << " tidak ditemukan." << endl;
    }
}