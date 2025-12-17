#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    // Alokasi Node Baru
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode temp = G.first;
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = P;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        // Karena Graph Tidak Berarah, kita buat edge dua arah.
        
        // 1. Buat Edge dari N1 ke N2
        adrEdge E1 = new ElmEdge;
        E1->Node = N2;
        E1->Next = N1->firstEdge; // Insert First pada list edge N1
        N1->firstEdge = E1;

        // 2. Buat Edge dari N2 ke N1
        adrEdge E2 = new ElmEdge;
        E2->Node = N1;
        E2->Next = N2->firstEdge; // Insert First pada list edge N2
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung dengan: ";
        adrEdge E = P->firstEdge;
        if (E == NULL) {
            cout << "(tidak ada)";
        }
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

// Fungsi tambahan untuk mencari pointer node berdasarkan Char
adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->Next;
    }
    return NULL;
}

// Helper: Reset status visited semua node menjadi 0
void ResetVisited(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N == NULL) {
        return;
    }

    // 1. Tandai node saat ini sudah dikunjungi
    N->visited = 1;
    
    // 2. Tampilkan info node
    cout << N->info << " ";

    // 3. Kunjungi semua tetangga (Neighbor)
    adrEdge E = N->firstEdge;
    while (E != NULL) {
        // Jika tetangga belum dikunjungi, lakukan DFS ke tetangga tersebut (Rekursif)
        if (E->Node->visited == 0) {
            PrintDFS(G, E->Node);
        }
        E = E->Next;
    }
}

void PrintBFS(Graph G, adrNode N) {
    if (N == NULL) {
        return;
    }

    // Siapkan Queue untuk menyimpan pointer node
    queue<adrNode> Q;

    // 1. Masukkan node awal ke antrean dan tandai visited
    N->visited = 1;
    Q.push(N);

    // 2. Loop selama antrean tidak kosong
    while (!Q.empty()) {
        // Ambil node paling depan dari antrean
        adrNode current = Q.front();
        Q.pop();

        // Tampilkan info node
        cout << current->info << " ";

        // 3. Masukkan semua tetangga yang belum dikunjungi ke antrean
        adrEdge E = current->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                // Penting: Tandai visited SAAT dimasukkan ke queue
                // agar tidak masuk ganda dari jalur lain
                E->Node->visited = 1; 
                Q.push(E->Node);
            }
            E = E->Next;
        }
    }
}