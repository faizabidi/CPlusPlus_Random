// Unweighted graph
// http://www.techiedelight.com/graph-implementation-using-stl/

#include <iostream>
#include <vector>
#include <list>

struct Edge{
    int source;
    int destination;
};

void addEdge(std::vector<Edge> edges, std::vector<std::list<int>> &adjList){
    for(int i = 0; i < edges.size(); i++){
        int source = edges[i].source;
        int destination = edges[i].destination;
        adjList[source].push_back(destination);
    }
}

// Adjacency list representation of graph
void printGraph(std::vector<std::list<int>> adjList, int nodes){
    for(int i = 0; i < nodes; i++){
        std::cout << i << "->";
        std::list<int>::iterator it;
        for(it = adjList[i].begin(); it != adjList[i].end(); it++)
            std::cout << *it << "->";
        std::cout << "NULL\n";
    }
}

int main(){
    std::vector<Edge> edges = {
        {0, 2},
        {0, 3},
        {0, 1},
        {1, 2},
        {1, 3},
    };

    int nodes = 4;

    std::vector<std::list<int>> adjList(nodes);
    addEdge(edges, adjList);
    printGraph(adjList, nodes);
    
    return 0;
}
