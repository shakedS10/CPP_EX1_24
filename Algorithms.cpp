#include <iostream>
#include "Graph.hpp"
#include <stack>

namespace ariel {
    class Algorithms {
    public:
        static bool isConnected(Graph g){
            //run dfs from all the vertex and mark all the vertices that are reachable with another temp array
            //if all the vertices are reachable continue to the next vertex
            //else return false
            for(int i = 0; i < g.getN(); i++){
                std::vector<bool> visited(g.getN(), false);
                std::stack<int> st;
                st.push(i);
                visited[i] = true;
                
                while (!st.empty()) {
                    int node = st.top();
                    st.pop();
                    
                    // Visit all adjacent nodes of 'node'
                    for (int i = 0; i < g.getN(); ++i) {
                        if (g.getGraph()[node][i] != 0 && !visited[i]) {
                            st.push(i);
                            visited[i] = true;
                        }
                    }
                }
                for (int i = 0; i < g.getN(); i++)
                {
                    if(visited[i] == false){
                        return false;
                    }
                }
            }
            return true;
        }
        static std::string shortestPath(Graph g, int src, int dest);
        static bool isContainsCycle(Graph g);
        static std::string isBipartite(Graph g);
    };
}