// http://www.techiedelight.com/arrival-departure-time-vertices-dfs/

#include <iostream>
#include <vector>
#include <list>
#include <stack>

void printVector(std::vector<int> array){
    for(int i = 0; i < array.size(); i++)
        std::cout << i << ":" << array[i] << std::endl;
}

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
        for(it = adjList[i].begin(); it != adjList[i].end(); it++){
            std::cout << *it << "->";
        }
        std::cout << "NULL\n";
    }
}

// Recursive DFS to calculate 
void dfs(std::stack<int> &s, std::vector<std::list<int>> adjList, 
    std::vector<bool> &visited, int &time, std::vector<int> &arrival, 
                        std::vector<int> &departure){

    if(s.empty())
        return;

    int start = s.top();
    s.pop();

    // Arrival time of node
    arrival[start] = ++time;
    //std::cout << arrival[start];
    
    if(!visited[start]){
        std::cout << start << " ";
        visited[start] = true;
    }

    std::list<int>::iterator it;
    for(it = adjList[start].begin(); it != adjList[start].end(); it++){
        if(!visited[*it]){
            s.push(*it);
            dfs(s, adjList, visited, time, arrival, departure);
        }
    }

    // Departure time of node
    departure[start] = ++time;
}


int main(){
    std::vector<Edge> edges{
        {0, 1},
        {0, 2},
        {2, 3},
        {2, 4},
        {3, 1},
        {3, 5},
        {4, 5},
        {6, 7}
    };

    int nodes = 8;
    std::vector<std::list<int>> adjList(nodes);

    addEdge(edges, adjList);

    printGraph(nodes, adjList);

    std::stack<int> s;
    s.push(0);
    std::vector<bool> visited(nodes, false);
    int time = -1;
    std::vector<int> arrival(nodes), departure(nodes);
    dfs(s, adjList, visited, time, arrival, departure);
    std::cout << std::endl;

    std::cout << "Arrival and departure time of nodes starting with node 0\n";
    for(int i = 0; i < nodes; i++)
        std::cout << "Node " << i << ":" << arrival[i] << "," << 
                            departure[i] << std::endl;

    return 0;
}
