// Graph.h
// Class to abstract the Graph manipulation

#include "../include/Graph.h"
using namespace std;

// ----------------------------------------------------------------
Graph::Graph() {
    // Pre:
    // Pos:
    size = 0;
}

// ----------------------------------------------------------------
Graph::~Graph() {
    // Pre:
    // Pos:

}

// ----------------------------------------------------------------
int Graph::insertNode(string name) {
    // Pre:
    // Pos:
    cityMappingList.push_back(name);
    return ++size;
}

// ----------------------------------------------------------------
void Graph::addEdge(string name1, string name2, int cost) { // public
    // Pre:
    // Pos:
    int pos1, pos2;
    pos1 = getPosMap(name1);
    pos2 = getPosMap(name2);
    if(pos1 < pos2)
        addEdge(pos1, pos2, cost);
    else
        addEdge(pos2, pos1, cost);
}

// ----------------------------------------------------------------
void Graph::addEdge(int nodeFirst, int nodeSecond, int cost) { // private
    // Pre:
    // Pos:
    vector<int> outVector;
    for(int i = 0; i < nodeSecond; i++) {
        if(i == nodeFirst)
            outVector.push_back(cost);
        else
            outVector.push_back(0);
    }
    adjacencyMatrix.insert(adjacencyMatrix.begin() + nodeSecond, outVector);
}

// ----------------------------------------------------------------
void Graph::printGraph() {
    // Pre:
    // Pos:
}

// ----------------------------------------------------------------
int Graph::getPosMap(string name) {
    // Pre:
    // Pos:
    for(int i = 0; i < size ; i++) {
        if (cityMappingList[i] == name) // talvez transformar ambas em lower case?
            return i;
    }
    return -1;
}