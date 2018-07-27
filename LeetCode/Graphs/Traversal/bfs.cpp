// http://www.techiedelight.com/breadth-first-search/

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
        adjList[source].push_back(destination);
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

// Iteratively
// O(n+m), where n = vertices and m = edges
void bfs(int nodes, int start, std::vector<std::list<int>> adjList){
    std::vector<bool> visited(nodes, false);
    std::queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int a = q.front(); 
        q.pop();
        std::cout << a << " ";
        std::list<int>::iterator it;
        for(it = adjList[a].begin(); it != adjList[a].end(); it++){
            if(!visited[*it]){
                q.push(*it);
                visited[*it] = true;
            }
        }
    }
    std::cout << std::endl;
}

// Recursively
// O(n+m), where n = vertices and m = edges
void bfs_recursive(std::queue<int> &q, std::vector<std::list<int>> adjList, 
                                std::vector<bool> &visited){
    if(q.empty())
        return;
    
    int a = q.front(); 
    q.pop();
    std::cout << a << " ";
    std::list<int>::iterator it;
    for(it = adjList[a].begin(); it != adjList[a].end(); it++){
        if(!visited[*it]){
            q.push(*it);
            visited[*it] = true;
        }
    }
    bfs_recursive(q, adjList, visited);
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

    // BFS starting from node 1
    bfs(nodes, 1, adjList); // Ans = 1 2 3 4 5 6 7 8 9 10 11 12

    // BFS starting from node 2
    bfs(nodes, 2, adjList); // And = 2, 5, 6, 9, 10

    // BFS starting from node 2 using recursive BFS
    std::queue<int> q;
    std::vector<bool> visited(nodes, false);
    q.push(2);
    visited[2] = true;
    bfs_recursive(q, adjList, visited);
    std::cout << std::endl;

    return 0;
}
