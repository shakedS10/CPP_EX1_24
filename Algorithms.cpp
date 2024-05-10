#include <iostream>
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <stack>
#include <climits>
#include <queue>
#include <vector>


using namespace std;
using namespace ariel;
        bool Algorithms::isConnected(Graph g){
            //run dfs from all the vertex and mark all the vertices that are reachable with another temp array
            //if all the vertices are reachable continue to the next vertex
            //else return false
            bool isConnect = true;
            for(size_t i = 0; i < g.getN(); i++){
                std::vector<bool> visited(g.getN(), false);
                std::stack<size_t> st;
                st.push(i);
                visited[i] = true;
                
                while (!st.empty()) {
                    size_t node = st.top();
                    st.pop();
                    
                    // Visit all adjacent nodes of 'node'
                    for (size_t i = 0; i < g.getN(); ++i) {
                        if (g.getGraph()[node][i] != 0 && !visited[i]) {
                            st.push(i);
                            visited[i] = true;
                        }
                    }
                }
                for (size_t i = 0; i < g.getN(); i++)
                {
                    if(visited[i] == false){
                        isConnect = false;
                        break;
                    }
                }
            }
            return isConnect;
        }






        std::string Algorithms::shortestPath(Graph g, size_t src, size_t dest){

            // Run bellman ford algorithm to find the shortest path from src to dest
            // If there is a negative cycle return "Negative cycle detected"
            // Else return the shortest path
            size_t n = g.getN();
            std::vector<int> dist(n, INT_MAX);
            dist[src] = 0;
            std::vector<int> parent(n, -1);
            std::string myg = "";
            // for (size_t i = 0; i < n; i++)
            // {
            //     for (size_t j = 0; j < n; j++)
            //     {
            //         myg = myg + std::to_string(g.getGraph()[i][j]) + " ";
            //     }
            //     myg = myg + "\n";
            // }
            
            for (size_t i = 0; i < n - 1; i++)
            {
                for (size_t u = 0; u < n; u++)
                {
                    for (size_t v = 0; v < n; v++)
                    {
                        if (g.getGraph()[u][v] != 0 && dist[u] != INT_MAX && dist[u] + g.getGraph()[u][v] < dist[v])
                        {
                            dist[v] = dist[u] + g.getGraph()[u][v];
                            parent[v] = u;
                        }
                    }
                }
            }
            if(dist[dest] == INT_MAX){
                return "-1";
            }
            for (size_t u = 0; u < n; u++)
            {
                for (size_t v = 0; v < n; v++)
                {
                    if (g.getGraph()[u][v] != 0 && dist[u] != INT_MAX && dist[u] + g.getGraph()[u][v] < dist[v])
                    {
                        std::cout << "Negative cycle detected" << std::endl;
                        return "-1";
                        
                    }
                }
            }
            
            //reconstruct the path
            std::string path = std::to_string(dest);
            size_t temp = dest;
            for (size_t i = 0; i < dest - src; i++)
            {
                path = std::to_string(parent[temp]) + "->" + path;
                temp = (size_t)parent[temp];
            }
            return path;
            
            
        }





        bool Algorithms::isContainsCycle(Graph g){
            bool isCycle = false;
            for(size_t i = 0; i < g.getN(); i++){
                std::vector<bool> visited(g.getN(), false);
                std::stack<std::pair<size_t, size_t>> st;
                st.push({i, -1}); // {node, parent}
                visited[i] = true;
                while (!st.empty()) {
                    size_t node = st.top().first;
                    size_t parent = st.top().second;
                    st.pop();
                    // Visit all adjacent nodes of 'node'
                    for (size_t j = 0; j < g.getN(); ++j) {
                        if (g.getGraph()[node][j] != 0) {
                            if (!visited[j]) {
                                st.push({j, node});
                                visited[j] = true;
                            } else if (j != parent && (parent == -1 || j != parent)) {
                                isCycle = true;
                                break;
                            }
                        }
                    }
                    if(isCycle)
                        break;
                }
                if(isCycle)
                    break;
            }
            return isCycle;
        }


        std::string Algorithms::isBipartite(Graph g){
            //run bfs from vertex 0 and color the vertices with 2 colors
            //if there is a vertex that has the same color as its parent return 0
            //else return the colors of the vertices
            std::vector<int> color(g.getN(), -1);
            std::queue<size_t> q;
            q.push(0);
            color[0] = 0;
            bool isBipartite = true;
            while (!q.empty())
            {
                size_t node = q.front();
                q.pop();
                for (size_t i = 0; i < g.getN(); i++)
                {
                    if (g.getGraph()[node][i] != 0)
                    {
                        if (color[i] == -1)
                        {
                            color[i] = 1 - color[node];
                            q.push(i);
                        }
                        else if (color[i] == color[node])
                        {
                            isBipartite = false;
                            break;
                        }
                    }
                }
            }
            if(isBipartite){
                std::vector<int> A;
                std::vector<int> B;
                for (size_t i = 0; i < g.getN(); i++)
                {
                    if(color[i] == 0){
                        A.push_back(i);
                    }
                    else{
                        B.push_back(i);
                    }
                }
                std:: string res = "The graph is bipartite: A={";
                for (size_t i = 0; i < A.size(); i++)
                {
                    res += std::to_string(A[i]);
                    if(i != A.size() - 1){
                        res += ", ";
                    }
                }
                res += "}, B={";
                for (size_t i = 0; i < B.size(); i++)
                {
                    res += std::to_string(B[i]);
                    if(i != B.size() - 1){
                        res += ", ";
                    }
                }
                res += "}";
                return res;
            }
            else{
                return "0";
            }
        }

