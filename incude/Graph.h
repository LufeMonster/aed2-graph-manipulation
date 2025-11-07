// Graph.h
// Class to abstract the Graph manipulation

#include <vector>
#include <iomanip>
using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

class Graph {
    public:
       
    private:
        vector<vector<int>> adjacencyMatrix;
        vector<string> cityMappingList;
};

#endif