// Unweighted graph
// http://www.techiedelight.com/graph-implementation-using-stl/

#include <iostream>
#include <vector>
#include <list>

struct Edge{
    int source;
    int destination;
    int weight;
};

void addEdge(std::vector<Edge> edges, std::vector<std::list<std::pair<int, int>>> &adjList){
    for(int i = 0; i < edges.size(); i++){
        int source = edges[i].source;
        int destination = edges[i].destination;
        int weight = edges[i].weight;
        adjList[source].push_back(std::make_pair(destination, weight));
        // If it was an undirected gragh then uncomment the below line
        //adjList[destination].push_back(std::make_pair(source, weight));
    }
}

// Adjacency list representation of graph
void printGraph(std::vector<std::list<std::pair<int, int>>> adjList, 
                                int nodes){

    for(int i = 0; i < nodes; i++){
        std::cout << i << "->";
        std::list<std::pair<int, int>>::iterator it;
        for(it = adjList[i].begin(); it != adjList[i].end(); it++){
            std::cout << "(" << it->first << ", " << it->second << ")" << "->";
        }
        std::cout << "NULL\n";
    }
}

int main(){
    // Edge from x to y with weight w
    std::vector<Edge> edges = {
        {0, 1, 6},
        {1, 2, 7},
        {2, 0, 5},
        {2, 1, 4},
        {3, 2, 10},
        {4, 5, 1},
        {5, 4, 3}
    };

    int nodes = 6;

    std::vector<std::list<std::pair<int, int>>> adjList(nodes);
    addEdge(edges, adjList);
    printGraph(adjList, nodes);
    
    return 0;
}
