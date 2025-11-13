// Graph.h
// Class to abstract the Graph manipulation

#include <vector>
#include <iomanip>
#include <limits>
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
        void removeEdge(string name1, string name2);
        void printGraph();
        int getPosMap(string name);
        int getEdge(string name1, string name2);
    private:
        vector<vector<int>> adjacencyMatrix;
        vector<string> cityMappingList;
        const int infinity = numeric_limits<int>::max();
        int size;
        void addEdge(int nodeFirst, int nodeSecond, int cost);
        void removeEdge(int nodeFirst, int nodeSecond);
        int getEdge(int nodeFirst, int nodeSecond);

};

#endif