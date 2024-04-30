#include <iostream>
#include <vector>

namespace ariel {
    class Graph {

    private:
        int n;
        std::vector<std::vector<int>> g;
        int edgecounter = 0;
        int graphtype; // 0 = directed, 1 = undirected

    public:

        Graph(){
            this->n = 0;
            this->edgecounter = 0;
            this->graphtype = 1;
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
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (graph[i][j] != 0 )
                    {
                        this->edgecounter++;
                        if (graph[i][j] != graph[j][i])
                        {
                            this->graphtype = 0;
                        }
                        
                        
                    }
                }
            }
            if (this->graphtype == 1)
            {
                this->edgecounter = this->edgecounter / 2;
            }
            
        
        }

        void printGraph() {
            std::cout << "Graph with " << n << " vertices and " << edgecounter << " edges." << std::endl;
        }

        int getN() {
            return this->n;
        }

    };
}
