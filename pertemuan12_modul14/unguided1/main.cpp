#include <iostream>
#include "graph.h"
#include "graph.cpp"

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    cout << "=== Menambahkan Node A-H ===" << endl;
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode G_node = FindNode(G, 'G'); // Nama variabel G_node agar tidak bentrok dengan Graph G
    adrNode H = FindNode(G, 'H');

    cout << "=== Menghubungkan Edge sesuai Ilustrasi ===" << endl;
    ConnectNode(A, B);
    ConnectNode(A, C);

    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, G_node);

    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(G_node, H);

    cout << endl << "=== Tampilan Adjacency List Graph ===" << endl;
    PrintInfoGraph(G);

    return 0;
}