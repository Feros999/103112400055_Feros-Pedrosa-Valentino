#include "graph.h"

int main() {
    Graph G;
    createGraph(G);

    addNode(G, 'A');
    addNode(G, 'B');
    addNode(G, 'C');
    addNode(G, 'D');
    addNode(G, 'E');

    connect(G, 'A', 'B'); 
    
    connect(G, 'C', 'B'); 
    
    connect(G, 'E', 'B'); 
    
    connect(G, 'D', 'C');

    printGraph(G);

    analyzeCriticalPoints(G);

    return 0;
}