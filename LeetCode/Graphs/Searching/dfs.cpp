// http://www.techiedelight.com/depth-first-search/

#include <iostream>
#include <vector>
#include <list>
#include <stack>

struct Edge{
    int source;
    int destination;
};

// Add edges of the graph
void addEdge(std::vector<Edge> edges, std::vector<std::list<int>> &adjList){
    for(int i = 0; i < edges.size(); i++){
        int source = edges[i].source;
        int destination = edges[i].destination;
        adjList[source].push_back(destination);
    }
}

void printGrapgh(int nodes, std::vector<std::list<int>> adjList){
    for(int i = 0; i < nodes; i++){
        std::cout << i << ":";
        std::list<int>::iterator it;
        for(it = adjList[i].begin(); it != adjList[i].end(); it++)
            std::cout << *it << "->";
        std::cout << "NULL\n";
    }
}

// Iterative DFS
void dfs(int start, int nodes, std::vector<std::list<int>> adjList){
    std::stack<int> s;
    std::vector<bool> visited(nodes, false);
 
    s.push(start);

    while(!s.empty()){
        start = s.top();
        s.pop();
        // Check if it's a visited node
        if(!visited[start]){
            std::cout << start << " ";
            visited[start] = true;
        }

        // Add its neighbours to the stack
        std::list<int>::iterator it;
        for(it = adjList[start].begin(); it != adjList[start].end(); it++){
            if(!visited[*it])
                s.push(*it);
        }
    }
    std::cout << std::endl;
}

// TO-DO
// Recursive DFS
void dfs_recursive();

int main(){
    // Node 0 is an un-connected node
    std::vector<Edge> edges = {
        {1, 2},
        {1, 7},
        {1, 8},
        {2, 3},
        {2, 6},
        {3, 4},
        {3, 5},
        {8, 9},
        {8, 12},
        {9, 10},
        {9, 11}
    };

    int nodes = 13;

    std::vector<std::list<int>> adjList(nodes);

    // Add all the edges
    addEdge(edges, adjList);

    // Print the graph
    printGrapgh(nodes, adjList);

    dfs(1, nodes, adjList); // Ans = 1 8 12 9 11 10 7 2 6 3 5 4 

    return 0;
}
