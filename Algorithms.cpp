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
                vector<bool> visited(g.getN(), false);
                std::stack<size_t> st;
                st.push(i);
                visited[i] = true;
                
                while (!st.empty()) {
                    size_t node = st.top();
                    st.pop();
                    
                    // Visit all adjacent nodes of 'node'
                    for (size_t j = 0; j < g.getN(); ++j) {
                        if (g.getGraph()[node][j] != 0 && !visited[j]) {
                            st.push(j);
                            visited[j] = true;
                        }
                    }
                }
                for (size_t k = 0; k < g.getN(); k++)
                {
                    if(visited[k] == false){
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
            for (size_t i = 0; i < n - 1; i++)
            {
                for (size_t u = 0; u < n; u++)
                {
                    for (size_t v = 0; v < n; v++)
                    {
                        if (g.getGraph()[u][v] != 0 && dist[u] != INT_MAX && dist[u] + g.getGraph()[u][v] < dist[v]) //relaxation
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
                        return "Negative cycle detected";
                        
                    }
                }
            }
            
            //reconstruct the path
            std::string path = std::to_string(dest);
            size_t temp = dest;
            while (parent[temp] != -1)
            {
                path = std::to_string(parent[temp]) + "->" + path;
                temp = (size_t)parent[temp];
            }
            return path;
            
            
        }





       bool Algorithms::isContainsCycle(Graph g) {
        size_t n = g.getN();
        vector<int> color(n, 0);
        vector<size_t> parent(n,(size_t)-1);
        for (size_t v = 0; v < n; v++) {
            if (color[v] == 0 ){
                if(Algorithms::cycledfs(g, v, color, parent,v)){
                    return true;
                }
            }
        }
        return false;

        }

        bool Algorithms::cycledfs(Graph g, size_t v, vector<int> color, vector<size_t> parent, size_t par){
            if(g.getgraphtype()==0){
            color[v] = 1;
            for (size_t i = 0; i < g.getN(); i++)
            {
                if(g.getGraph()[v][i] != 0){
                    if(color[i] == 0){
                        parent[i] = v;
                        if(cycledfs(g, i, color, parent, v)){
                            return true;
                        }
                    }
                    else if(color[i] == 1){
                        size_t temp = v;
                        cout << "Cycle detected: " << temp;
                        while (temp!=i)
                        {
                            cout << "->" << parent[temp];
                            temp = parent[temp];
                        }
                        cout << "" << endl;
                        return true;
                    }
                }
            }
            color[v] = 2;
            return false;
            }
            else{
                color[v] = 1;
                for (size_t i = 0; i < g.getN(); i++)
                {
                    if(g.getGraph()[v][i] != 0){
                            if(i == par){
                                continue;
                            }
                            if(color[i]==1){
                                size_t temp = v;
                                cout << "Cycle detected: " << temp;
                                while (temp!=i)
                                {
                                cout << "->" << parent[temp];
                                temp = parent[temp];
                                }
                                cout << "" << endl;
                                return true;
                            }
                        parent[i] = v;
                        if(cycledfs(g, i, color, parent, parent[i])){
                            return true;
                        }
                    }
                }
                return false;
            }

        }


        std::string Algorithms::isBipartite(Graph g){
            //run dfs from all the vertex and mark all the vertices that are reachable with another temp array
            //color the vertexs with 2 colors if there is a color that cant be painted change isBipartite to false
            //return 0 or the 2 groups
            bool isBipartite = true;
            size_t n = g.getN();
            vector<int> color(n, -1);
            vector<bool> visited(n, false);
            for (size_t i = 0; i < n; ++i) {
                if (!visited[i]) {
                stack<size_t> st;
                st.push(i);
                visited[i] = true;
                color[i] = 0; // Color the first vertex with 0

                while (!st.empty()) {
                    size_t node = st.top();
                    st.pop();

                    // Visit all adjacent nodes of 'node'
                    for (size_t j = 0; j < n; ++j) {
                        if (g.getGraph()[node][j] != 0) {
                            if (!visited[j]) {
                                st.push(j);
                                visited[j] = true;
                                color[j] = 1 - color[node];
                        } 
                        else if (color[j] == color[node]) {
                                isBipartite = false;
                                break;
                        }
                        }   
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

        std::string Algorithms::negativeCycle(Graph g){
            
            size_t n = g.getN();
            std::vector<int> dist(n, INT_MAX);
            dist[0] = 0;
            std::vector<int> parent(n, -1);        
            for (size_t i = 0; i < n - 1; i++)
            {
                for (size_t u = 0; u < n; u++)
                {
                    for (size_t v = 0; v < n; v++)
                    {
                        if (g.getGraph()[u][v] != 0 && dist[u] != INT_MAX && dist[u] + g.getGraph()[u][v] < dist[v]) //relaxation
                        {
                            dist[v] = dist[u] + g.getGraph()[u][v];
                            parent[v] = u;
                        }
                    }
                }
            }
            for (size_t u = 0; u < n; u++)
            {
                for (size_t v = 0; v < n; v++)
                {
                    if (g.getGraph()[u][v] != 0 && dist[u] != INT_MAX && dist[u] + g.getGraph()[u][v] < dist[v])
                    {
                        std::cout << "Negative cycle detected" << std::endl;
                        string negcycle = std::to_string(u)+"->"+std::to_string(v);
                        size_t temp = u;
                        while (parent[temp] != v)
                        {
                            negcycle = std::to_string(parent[temp]) + "->" + negcycle;
                            temp = (size_t)parent[temp];
                        }
                        cout << negcycle << endl;
                        return negcycle;
                    }
                }
            }
            return "-1";

        }
        

        

