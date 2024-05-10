#ifndef GRAPH_HPP
#pragma once
#define GRAPH_HPP
#include <vector>
#include <iostream>
using namespace std;
namespace ariel {
    class Graph {
    protected:
        size_t n;
        std::vector<std::vector<int>> g;
        int edgecounter = 0;
        int graphtype; // 0 = directed, 1 = undirected

    public:
        Graph(){
            this->n = 0;
            this->edgecounter = 0;
            this->graphtype = 1;
            this->g = std::vector<std::vector<int>>();

        }
        void loadGraph(std::vector<std::vector<int>> graph);
        void printGraph();
        size_t getN();
        std::vector<std::vector<int>> getGraph();
    };
}

#endif