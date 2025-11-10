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
        void addEdge(string name1, string name2, int cost);
        int deleteNode(string name);
        void removeEdge(string name1, string name2, int cost);
        void printGraph();
        int getPosMap(string name);
    private:
        vector<vector<int>> adjacencyMatrix;
        vector<string> cityMappingList;
        int size;
        void addEdge(int nodeFirst, int nodeSecond, int cost);
        void removeEdge(int nodeFirst, int nodeSecond, int cost);
};

#endif