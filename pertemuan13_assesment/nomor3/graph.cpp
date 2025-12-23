#include "graph.h"

void createGraph(Graph &G) {
    G.firstNode = NULL;
}

Node* createNodeData(char id) {
    Node* newNode = new Node;
    newNode->id = id;
    newNode->visited = false;
    newNode->isLockdown = false;
    newNode->firstEdge = NULL;
    newNode->next = NULL;
    return newNode;
}

void addNode(Graph &G, char id) {
    Node* newNode = createNodeData(id);
    if (G.firstNode == NULL) {
        G.firstNode = newNode;
    } else {
        Node* temp = G.firstNode;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Node* findNode(Graph G, char id) {
    Node* temp = G.firstNode;
    while (temp != NULL) {
        if (temp->id == id) return temp;
        temp = temp->next;
    }
    return NULL;
}

void connect(Graph &G, char srcId, char destId) {
    Node* src = findNode(G, srcId);
    Node* dest = findNode(G, destId);

    if (src != NULL && dest != NULL) {
        // 1. Sambungkan Src -> Dest
        Edge* newEdge1 = new Edge;
        newEdge1->dest = dest;
        newEdge1->nextEdge = src->firstEdge;
        src->firstEdge = newEdge1;

        // 2. Sambungkan Dest -> Src (Karena Undirected)
        Edge* newEdge2 = new Edge;
        newEdge2->dest = src;
        newEdge2->nextEdge = dest->firstEdge;
        dest->firstEdge = newEdge2;
    }
}

void printGraph(Graph G) {
    cout << "Membangun Jaringan Distribusi Vaksin" << endl;
    Node* curr = G.firstNode;
    while (curr != NULL) {
        cout << "Node " << curr->id << " terhubung ke: ";
        Edge* e = curr->firstEdge;
        while (e != NULL) {
            cout << e->dest->id << " ";
            e = e->nextEdge;
        }
        cout << endl;
        curr = curr->next;
    }
    cout << endl;
}

void resetVisited(Graph G) {
    Node* curr = G.firstNode;
    while (curr != NULL) {
        curr->visited = false;
        curr = curr->next;
    }
}

void DFS(Node* curr) {
    if (curr == NULL || curr->visited || curr->isLockdown) return;

    curr->visited = true;

    Edge* e = curr->firstEdge;
    while (e != NULL) {
        if (!e->dest->isLockdown) {
            DFS(e->dest);
        }
        e = e->nextEdge;
    }
}

void analyzeCriticalPoints(Graph G) {
    cout << "Analisis Kota Kritis (Single Point of Failure)" << endl;

    // 1. Hitung Total Kota (Node)
    int totalNodes = 0;
    Node* temp = G.firstNode;
    while (temp != NULL) {
        totalNodes++;
        temp = temp->next;
    }

    // 2. Loop simulasi untuk setiap kota
    Node* target = G.firstNode;
    while (target != NULL) {
        // A. Set status kota target menjadi Lockdown (Simulasi hilang)
        target->isLockdown = true;

        // B. Reset tracking visited
        resetVisited(G);

        // C. Cari titik mulai (Start Node) untuk traversal
        Node* startNode = G.firstNode;
        while (startNode != NULL && startNode->isLockdown) {
            startNode = startNode->next;
        }

        // D. Lakukan Traversal (DFS) untuk menghitung jangkauan
        if (startNode != NULL) {
            DFS(startNode);
        }

        // E. Hitung jumlah kota yang berhasil dijangkau (Visited)
        int visitedCount = 0;
        Node* counter = G.firstNode;
        while (counter != NULL) {
            if (counter->visited) visitedCount++;
            counter = counter->next;
        }

        // F. Evaluasi Status Kritis
        int expectedActiveNodes = totalNodes - 1;
        
        if (visitedCount < expectedActiveNodes) {
            cout << "[PERINGATAN] Kota " << target->id << " adalah KOTA KRITIS!" << endl;
            cout << "-> Jika " << target->id << " lockdown, distribusi terputus." << endl;
        } else {
            cout << "Kota " << target->id << " aman (redundansi oke)." << endl;
        }

        // G. Kembalikan kondisi kota seperti semula (Unlock)
        target->isLockdown = false;
        
        // Lanjut ke kota berikutnya
        target = target->next;
    }
}