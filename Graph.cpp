//214695108 shakedshvartz2004@gmail.com
#include <iostream>
#include <vector>
#include "Graph.hpp"
using namespace std;
using namespace ariel;


        void Graph::loadGraph(std::vector<std::vector<int>> graph) {
            if(graph.size() == 0){
                throw std::invalid_argument("Graph is empty");
            }
            if (graph.size() != graph[0].size())
            {
                throw std::invalid_argument("Graph is not a square matrix");
            }
            this->edgecounter = 0;
            this->graphtype = 1;
            this->n = graph.size();
            this->g = graph;
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < n; j++)
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
        
        }
        

        void Graph::printGraph() {
            std::cout << "Graph with " << n << " vertices and " << edgecounter << " edges." << std::endl;
        }

        size_t ariel::Graph::getN() {
            return this->n;
        }

        std::vector<std::vector<int>> ariel::Graph::getGraph() {
            return this->g;
        }


