#pragma once
#include <vector>
#include <iostream>

namespace ariel {
    class Graph {
    private:
        int n;
        std::vector<std::vector<int>> g;
        int edgecounter = 0;

    public:
        Graph();
        void loadGraph(std::vector<std::vector<int>> graph);
        void printGraph();
    };
}
