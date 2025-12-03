#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = Nil;

    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 2);
    insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 5);
    insertNode(root, 7);

    cout << "Preorder  : ";
    printPreorder(root);
    cout << "\n";

    cout << "Postorder : ";
    printPostorder(root);
    cout << "\n";

    return 0;
}