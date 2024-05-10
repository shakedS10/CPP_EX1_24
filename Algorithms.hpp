#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include <iostream>
#include "Graph.hpp"

namespace ariel {
    class Algorithms {
    public:
        static bool isConnected(Graph g);
        static std::string shortestPath(Graph g, size_t src, size_t dest);
        static bool isContainsCycle(Graph g);
        static std::string isBipartite(Graph g);
    };
}
#endif