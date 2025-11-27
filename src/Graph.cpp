// Graph.h
// Class to abstract the Graph manipulation

#include <iostream>
#include <iomanip> 
#include <queue>
#include "../include/Graph.h"
using namespace std;

// ----------------------------------------------------------------
Graph::Graph() {
    // Pre: nenhuma.
    // Pos: inicializa o tamanho como zero.
    size = 0;
}

// ----------------------------------------------------------------
Graph::~Graph() {
    // Pre:
    // Pos:

}

// ----------------------------------------------------------------
int Graph::insertNode(string name) {
    // Pre: o nome de uma cidade a ser adicionada.
    // Pos: incrementa o tamanho e insere a cidade tanto na matriz de
    // adjacencias (com os custos inicializados como + infinito) quanto 
    // no vetor de posicoes.
    size++;
    vector<int> tempVector(size, infinity);
    cityMappingList.push_back(name);
    adjacencyMatrix.push_back(tempVector);
    return size;
}

// ----------------------------------------------------------------
void Graph::addEdge(string name1, string name2, int cost) { // public
    // Pre: o nome de duas cidades a serem conectadas e a distancia entre elas.
    // Pos: converte as cidades em suas posicoes e chama o metodo privado.
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
    // Pre: as posicoes das cidades a serem conectadas e sua distancia.
    // Pos: atualiza a matriz de adjacencias.
    adjacencyMatrix[nodeSecond][nodeFirst] = cost;
}

// ----------------------------------------------------------------
int Graph::deleteNode(string name) {
    // Pre: o nome de uma cidade a ser removida.
    // Pos: remove a cidade tanto do vetor de posicoes quanto da matriz
    // de adjacencias, ajustando seu tamanho.
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
    // Pre: o nome das cidades as quais serao removidas a conexao 
    // entre si.
    // Pos: chama o metodo privado.
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
    // Pre: a posicao das cidades as quais serao removidas a conexao 
    // entre si.
    // Pos: atualiza co custo na mariz de adjacencias para + infinito.
    adjacencyMatrix[nodeSecond][nodeFirst] = infinity;
}

// ----------------------------------------------------------------
void Graph::simpleBreadthFirstSearch(string searchRootName) {
    // Pre: o nome da raiz da busca.
    // Pos: faz uma busca das cidades conectadas a UMA cidade dada.
    int posSearchRoot = getPosMap(searchRootName);
    int connectedVector[size] = {0};
    breadthFirstSearch(posSearchRoot, connectedVector, 1);
    cout << "Connect vector: [";
    for(int i = 0; i < size - 1; i++) {
        cout << connectedVector[i] << ", ";
    }
    cout << connectedVector[size - 1] << "]" << endl;
}

// ----------------------------------------------------------------
void Graph::deepBreadthFirstSearch() {
    // Pre: nenhuma.
    // Pos: busca por TODAS as cidades conectadas entre si, separando-
    // as pelas conexões
    int connectedVector[size] = {0};
    int nodesTested = 0;
    int iteration = 1;
    int nextDisconnectedNode = 0;
    while(nodesTested < size) {
        nodesTested += breadthFirstSearch(nextDisconnectedNode, connectedVector, iteration);
        for(int i = 0; i < size; i++)
            if(connectedVector[i] == 0) {
                nextDisconnectedNode = i;
                break;
            }
        iteration ++;
    }
    cout << "Connect vector: [";
    for(int i = 0; i < size - 1; i++) {
        cout << connectedVector[i] << ", ";
    }
    cout << connectedVector[size - 1] << "]" << endl;
}

// ----------------------------------------------------------------
int Graph::breadthFirstSearch(int searchRoot, int* connectedVector, int it) { // private
    // Pre: posicao da raiz da busca, um vetor de conexoes a ser manipulado e 
    // a iteracao atual.
    // Pos: faz uma busca das cidades conectadas a raiz e atualiza o vetor de
    // conexoes. Metodo generico, privado  e de uso comum a simpleBreadthFirstSearch 
    // e deepBreadthFirstSearch.
    queue<int> q;
    int aux, v = searchRoot;
    int connectedItems = 1;

    string visitedNodes = (" " + to_string(v));
    connectedVector[v] = it;
    q.push(v);

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int w = 0; w < size; w++) {
            // percorre a matriz triangular inferior
            if (v > w) aux = adjacencyMatrix[v][w];
            else aux = adjacencyMatrix[w][v];

            if (aux != infinity && !connectedVector[w]) {
                connectedVector[w] = it;
                connectedItems ++;
                q.push(w);
                visitedNodes += (" " + to_string(w));
            }
        }
    }
    cout << "It. " << it << "; visited nodes:" << visitedNodes << "." << endl;
    return connectedItems;
}

// ----------------------------------------------------------------
void Graph::printGraph() {
    // Pre: nenhuma.
    // Pos: imprime a matriz de adjacencias numa formatacao amigavel.
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
    // Pre: nome de uma cidade.
    // Pos: retorna sua posicao na  matriz.
    for(int i = 0; i < size ; i++) {
        if (cityMappingList[i] == name) // talvez transformar ambas em lower case?
            return i;
    }
    return -1;
}

// ----------------------------------------------------------------
int Graph::getEdge(string name1, string name2) { // public
    // Pre: nome de duas cidades conectadas.
    // Pos: chama o  metodo privado.
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

// ----------------------------------------------------------------
int Graph::getEdge(int nodeFirst, int nodeSecond) { // private
    // Pre: a posicao de duas cidades conectadas.
    // Pos: retorna a distancia entre elas.
    int aux = adjacencyMatrix[nodeSecond][nodeFirst];
    return aux == infinity ? -1 : aux;
}