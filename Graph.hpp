#pragma once
#include <vector>
#include <iostream>

namespace ariel {
    class Graph {
    protected:
        int n;
        std::vector<std::vector<int>> g;
        int edgecounter = 0;

    public:
        Graph();
        void loadGraph(std::vector<std::vector<int>> graph);
        void printGraph();
        int getN();
        std::vector<std::vector<int>> getGraph();
    };
}
