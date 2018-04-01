#include <iostream>
#include <vector>
#include <list>
#include <queue>

struct Edge{
    int source;
    int destination;
};

void addEdge(std::vector<Edge> edges, std::vector<std::list<int>> &adjList){
    for(int i = 0; i < edges.size(); i++){
        int source = edges[i].source;
        int destination = edges[i].destination;
        // Un-directed graph
        adjList[source].push_back(destination);
        adjList[destination].push_back(source);
    }
}

void printGraph(int nodes, std::vector<std::list<int>> adjList){
    for(int i = 0; i < nodes; i++){
        std::cout << i << ":";
        std::list<int>::iterator it;
        for(it = adjList[i].begin(); it != adjList[i].end(); it++)
            std::cout << *it << "->";
        std::cout << "NULL\n";
    }
}

// Apply BFS
std::vector<int> shortestPath(int nodes, int start, 
                    std::vector<std::list<int>> adjList){

    std::queue<int> q;
    std::vector<int> distances(nodes, -1);
    q.push(start);
    distances[start] = 0;

    while(!q.empty()){
        int a = q.front();
        q.pop();
        std::cout << a << " ";
        std::list<int>::iterator it;
        for(it = adjList[a].begin(); it != adjList[a].end(); it++){
            if(distances[*it] == -1){
                q.push(*it);
                distances[*it] = distances[a] + 1;
            }
        }
    }
    std::cout << std::endl;
    return distances;

}

int main(){
    std::vector<Edge> edges = {
        {1, 2},
        {1, 3},
        {1, 4},
        {2, 5},
        {2, 6},
        {5, 9},
        {5, 10},
        {4, 7},
        {4, 8},
        {7, 11},
        {7, 12}
    };

    int nodes = 15; // Vertex 0, 13, and 14 are single nodes without any connections

    // Create am adjacency graph
    std::vector<std::list<int>> adjList(nodes);

    // Add all nodes
    addEdge(edges, adjList);

    // Print the adjacency graph
    printGraph(nodes, adjList);

    std::cout << "BFS starting from node 5\n";
    std::vector<int> distances = shortestPath(nodes, 5, adjList); 

    std::cout << "Shortest path from vertex 5 to all the nodes\n";
    for(int i = 0; i < nodes; i++){
        std::cout << "Shortest distance between node 5 and " <<  i << " = " << distances[i] << std::endl;
    }

    return 0;
}
