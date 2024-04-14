#include <iostream>
#include <vector>

namespace ariel {
    class Graph {

    private:
        int n;
        std::vector<std::vector<int>> g;
        int edgecounter = 0;

    public:

        Graph(){
            this->n = 0;
            this->edgecounter = 0;
        }
        void loadgraph(std::vector<std::vector<int>> graph) {
            if(graph.size() == 0){
                throw std::invalid_argument("Graph is empty");
            }
            if (graph.size() != graph[0].size())
            {
                throw std::invalid_argument("Graph is not a square matrix");
            }
            
            this->n = graph.size();
            this->g = graph;
            for (unsigned long i = 0; i < n; i++) {
                for (unsigned long j = 0; j < n; j++)
                {
                    if (g[i][j] != 0 && i!=j) {
                        if(g[j][i] != g[i][j] && g[j][i] != 0){
                            edgecounter+= 2;
                            g[j][i] = 0;
                            g[i][j] = 0;
                        }
                        if (g[j][i] == g[i][j] && g[j][i] != 0)
                        {
                            edgecounter++;
                            g[j][i] = 0;
                            g[i][j] = 0;
                        }
                        else
                            edgecounter++;
                    }
                }
            }
            this->g = graph;
        }

        void printGraph() {
            std::cout << "Graph with " << n << " vertices and " << edgecounter << " edges." << std::endl;
        }

    };
}
