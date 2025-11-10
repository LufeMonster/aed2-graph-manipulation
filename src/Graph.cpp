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
    vector<int> tempVector;
    cityMappingList.push_back(name);
    size++;
    for(int i = 0; i < size; i++) {
        tempVector.push_back(infinity);
    }
    adjacencyMatrix.push_back(tempVector);
    return size;
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
    vector<int> tempVector;
    tempVector = adjacencyMatrix[nodeSecond];
    tempVector[nodeSecond] = cost;
    adjacencyMatrix[nodeSecond] = tempVector;
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