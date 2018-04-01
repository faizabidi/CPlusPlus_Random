// https://www.geeksforgeeks.org/bipartite-graph/
// http://www.techiedelight.com/bipartite-graph/

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
        // And because it's an undirected grapgh
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

bool check_bipartite(int nodes, int start, 
                            std::vector<std::list<int>> adjList){

    std::vector<bool> visited(nodes, false);
    std::queue<int> q;
    visited[start] = true;

    // -1 means no colour is assigned. 0 means red and 1 means blue
    std::vector<int> colours(nodes, -1);

    q.push(start);
    // Assign it red colour
    colours[start] = 0;

    while(!q.empty()){
        int a = q.front(); 
        q.pop();
        
        std::list<int>::iterator it;
        for(it = adjList[a].begin(); it != adjList[a].end(); it++){
            if(!visited[*it]){
                q.push(*it);
                // It won't have any colour assigned yet
                // Assign a colour opposite to the parent
                colours[*it] = ((colours[a] == 0) ? 1 : 0);
                std::cout << "Colour of " << *it << " = " << colours[*it] << std::endl;
                // Mark it as visited
                visited[*it] = true;
            }
            // If this vertex has already been visited
            // Check if the colour of the parent is different from this vertix
            else if(visited[*it]){
                if(colours[a] == colours[*it])
                    return false;
            }
        }
    }
    return true;
}

int main(){
    // Un-directed graph
    // Vertex 0 is an un-connected node
    int nodes1 = 10;
    std::vector<Edge> edges1 = {
        {1, 2},
        {2, 3},
        {2, 8},
        // Add this edge to make it non-bipartite
        //{2, 4},
        {3, 4},
        {4, 6},
        {5, 7},
        {5, 9},
        {8, 9}
    };

    // Another example of a non-bipartite grapgh
    int nodes2 = 10;
    std::vector<Edge> edges2 = {
        {1, 3},
        {1, 4},
        {2, 4},
        {2, 7},
        {3, 5},
        {4, 5},
        {4, 6},
        {5, 6},
        {5, 8},
        {6, 9},
        {6, 7},
        {8, 9}
    };

    // Create an adjacency graph
    std::vector<std::list<int>> adjList(nodes2);

    // Add all nodes
    addEdge(edges2, adjList);

    // Print the adjacency graph
    printGraph(nodes2, adjList);

    if(check_bipartite(nodes2, 1, adjList))
        std::cout << "It's a bipartite grapgh.\n";
    else
        std::cout << "It's NOT a bipartite graph.\n";

    return 0;
}
