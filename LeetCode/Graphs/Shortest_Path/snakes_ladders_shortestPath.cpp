// http://www.techiedelight.com/min-throws-required-to-win-snake-and-ladder-game/

#include <iostream>
#include <vector>
#include <list>
#include <queue>

struct Edge{
    int source;
    int destination;
};

std::vector<Edge> construct_edges(int nodes, std::vector<int> moves){
    std::vector<Edge> edges;
    // From every vertex, a user can go (vertex + 1) to (vertex + 6)
    // If there's a snake or a ladder then the neighbour becomes the vertex that they point to
    for(int i = 0; i < nodes; i++){
        int source = i;
        for(int j = 1; j <= 6 && i + j <= nodes; j++){
            // If it's not a snake or a ladder on that j
            if(moves[j + i] == -1){
                int destination = j + i;
                edges.push_back({source, destination});
            }
            // If it's a snake or a ladder on the j
            else{
                int destination = moves[j + i];
                edges.push_back({source, destination});
            }
        }
    }
    return edges;
}

void addEdge(std::vector<Edge> edges, std::vector<std::list<int>> &adjList){
    for(int i = 0; i < edges.size(); i++){
        int source = edges[i].source;
        int destination = edges[i].destination;
        // Directed graph
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

// Apply BFS to find the shortest path between 1 and 100
// There is a zeroth vertex as well before the first vertex
std::vector<int> shortestPath(int nodes, int start, 
                    std::vector<std::list<int>> adjList){

    std::queue<int> q;
    std::vector<int> distances(nodes + 1, -1);
    q.push(start);
    distances[start] = 0;

    while(!q.empty()){
        int a = q.front();
        q.pop();
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
    // We choose 101 = 100 vertices on the game + 1 for the zeroth vertex
    int nodes = 101;
    std::vector<int> moves(nodes, -1);

    // Snakes
    moves[17] = 7;
    moves[54] = 34;
    moves[62] = 19;
    moves[64] = 60;
    moves[87] = 36;
    moves[93] = 73;
    moves[95] = 75;
    moves[98] = 79;

    // Ladders
    moves[1] = 38;
    moves[4] = 14;
    moves[9] = 31;
    moves[23] = 42;
    moves[28] = 84;
    moves[51] = 67;
    moves[72] = 91;
    moves[80] = 99;

    // Construct a vector of edges
    // There will be a total of 101 vertices
    std::vector<Edge> edges = construct_edges(nodes, moves);

    // Add all edges
    std::vector<std::list<int>> adjList(nodes);
    addEdge(edges, adjList);

    // Print the graph
    std::cout << "The snake and ladder adjacency graph looks like\n";
    printGraph(nodes, adjList);

    std::cout << "Distances between node 0 to 100\n";
    std::vector<int> distances = shortestPath(nodes, 0, adjList); 
    for(int i = 0; i < nodes; i++)
        std::cout << "Vertex 0 to " << i << " = " << distances[i] << std::endl;

    std::cout << "You can win this game in " << distances[nodes - 1] << " moves!\n";

    return 0;
}
