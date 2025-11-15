// Graph.h
// Class to abstract the Graph manipulation

#include <iostream>
#include <iomanip> 
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
    size++;
    vector<int> tempVector(size, infinity);
    cityMappingList.push_back(name);
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

    // Verifica se cidades existem
    if (pos1 == -1 || pos2 == -1) {
        cout << "Error: city not found in graph. Try again..." << endl;
        return;
    } 

    if (pos1 == pos2) {
        cout << "Error: cities are the same. Try again..." << endl;
        return;
    }

    if (pos1 < pos2)
        addEdge(pos1, pos2, cost);
    else
        addEdge(pos2, pos1, cost);
}

// ----------------------------------------------------------------
void Graph::addEdge(int nodeFirst, int nodeSecond, int cost) { // private
    // Pre:
    // Pos:
    adjacencyMatrix[nodeSecond][nodeFirst] = cost;
}

// ----------------------------------------------------------------
int Graph::deleteNode(string name) {
    // Pre:
    // Pos:
    size--;
    vector<int> tempVector;
    int pos = getPosMap(name);
    cout << "pos: " << pos << endl;
    cityMappingList.erase(cityMappingList.begin() + pos);
    for(int i = pos; i < size; i++) {
        tempVector = adjacencyMatrix[i + 1];
        tempVector.erase(tempVector.begin() + pos);
        adjacencyMatrix[i] = tempVector;
        cout << "i: " << i << endl;
    }
    adjacencyMatrix.erase(adjacencyMatrix.begin() + size);
    return pos;
}

// ----------------------------------------------------------------
void Graph::removeEdge(string name1, string name2) { // public
    // Pre:
    // Pos:
    int pos1, pos2;
    pos1 = getPosMap(name1);
    pos2 = getPosMap(name2);
    if (pos1 < pos2)
        removeEdge(pos1, pos2);
    else
        removeEdge(pos2, pos1);
}

// ----------------------------------------------------------------
void Graph::removeEdge(int nodeFirst, int nodeSecond) { // private
    // Pre:
    // Pos:
    adjacencyMatrix[nodeSecond][nodeFirst] = infinity;
}

// ----------------------------------------------------------------
void Graph::printGraph() {
    // Pre:
    // Pos:
    int aux;

    // Imprimir header da tabela
    cout << left << setw(16) << "CITIES" 
         << right << setw(10) << "ID";
    for (int i = 0; i < adjacencyMatrix.size(); i++) {
        cout << setw(5) << i;
    }
    cout << endl;

    // Imprimir custo 
    for (int i = 0; i < adjacencyMatrix.size(); i++) {
        cout << left << setw(16) << cityMappingList[i]
             << right << setw(10) << (" (" + to_string(i) + ")");
        
        for (int j = 0; j < adjacencyMatrix[i].size(); j++) {
            if (i > j) aux = adjacencyMatrix[i][j];
            else aux = adjacencyMatrix[j][i];

            if (aux == infinity) cout << setw(5) << "INF";
            else cout << setw(5) << aux;
        }
        cout << endl;
    }
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

int Graph::getEdge(string name1, string name2) {
    // Pre:
    // Pos:
    int pos1, pos2;
    pos1 = getPosMap(name1);
    pos2 = getPosMap(name2);

    // Verifica se cidades existem
    if (pos1 == -1 || pos2 == -1) {
        cout << "Error: city not found in graph. Try again..." << endl;
        return -1;
    } 

    if (pos1 < pos2) return getEdge(pos1, pos2);
    else return getEdge(pos2, pos1);
}

int Graph::getEdge(int nodeFirst, int nodeSecond) {
    // Pre:
    // Pos:
    return adjacencyMatrix[nodeSecond][nodeFirst];
}