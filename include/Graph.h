// Graph.h
// Class to abstract the Graph manipulation

#include <vector>
#include <iomanip>
using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

class Graph {
    public:
        Graph();
        ~Graph();
        int insertNode(string name);
        void addEdge(int node1, int node2);
        int deleteNode(string name);
        void removeEdge(int node1, int node2);
        int getPosMap(string name);
    private:
        vector<vector<int>> adjacencyMatrix;
        vector<string> cityMappingList;
        int size;
};

#endif