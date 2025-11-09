// Graph.h
// Class to abstract the Graph manipulation

#include "../include/Graph.h"
using namespace std;

// ----------------------------------------------------------------
Graph::Graph() {
    size = 0;
}

// ----------------------------------------------------------------
Graph::~Graph() {

}

// ----------------------------------------------------------------
int Graph::insertNode(string name) {
    cityMappingList.push_back(name);
    return ++size;
}

// ----------------------------------------------------------------
int Graph::getPosMap(string name) {
    for(int i = 0; i < size ; i++) {
        if (cityMappingList[i] == name) // talvez transformar ambas em lower case?
            return i;
    }
    return -1;
}