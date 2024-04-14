#include <iostream>
#include "Graph.hpp"

namespace ariel {
    class Algorithms {
    public:
        static bool isConnected(Graph g);
        static std::string shortestPath(Graph g, int src, int dest);
        static bool isContainsCycle(Graph g);
        static std::string isBipartite(Graph g);
    };
}