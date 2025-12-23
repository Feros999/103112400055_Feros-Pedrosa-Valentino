#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

using namespace std;

typedef struct Node* adrNode;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    
    adrNode left;
    adrNode right;
};

bool isEmpty(adrNode root);

void createTree(adrNode &root);

adrNode newNode(string nama, float berat, string tier);

void insertNode(adrNode &root, adrNode p);

void searchByBeratBadan(adrNode root, float targetBerat);

void mostLeft(adrNode root);

void mostRight(adrNode root);

void inOrder(adrNode root);

#endif