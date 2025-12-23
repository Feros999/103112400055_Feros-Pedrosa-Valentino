#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>

using namespace std;

struct Node; 

struct Edge {
    Node *dest;
    Edge *nextEdge;
};

struct Node {
    char id;
    bool visited;
    bool isLockdown;
    
    Edge *firstEdge;
    Node *next;
};

struct Graph {
    Node *firstNode;
};

void createGraph(Graph &G);

void addNode(Graph &G, char id);

void connect(Graph &G, char srcId, char destId);

Node* findNode(Graph G, char id);

void printGraph(Graph G);

void resetVisited(Graph G);

void DFS(Node* curr);

void analyzeCriticalPoints(Graph G);

#endif