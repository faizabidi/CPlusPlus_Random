// https://www.geeksforgeeks.org/detect-cycle-undirected-graph/

#include <iostream>
#include <queue>
#include <vector>
#include <list>

struct Edge{
	int source;
	int destination;
};

void addEdge(std::vector<Edge> edges, std::vector<std::list<int>> &graph){
	for(int i = 0; i < edges.size(); i++){
		int source = edges[i].source;
		int destination = edges[i].destination;
		graph[source].push_back(destination);
		graph[destination].push_back(source);
	}
}

void printGraph(int nodes, std::vector<std::list<int>> graph){
	for(int i = 0; i < nodes; i++){
		std::cout << i << ":";
		std::list<int>::iterator it;
		for(it = graph[i].begin(); it != graph[i].end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
}

// Check if there's a cycle using DFS
// Idea is that there can't be two parents of a given VISITED node.
// Visit all the nodes in a DFS fashion and keep track of the parent nodes. 
// If you visit an already visited node, check its parent. If it matches with the DFS call you are using then good! Else, there's a cycle.
// Returns true if there's a cycle. Else, false.
bool checkCycle_DFS(int start, std::vector<std::list<int>> graph, 
				std::vector<bool> &visited, std::vector<int> &parent){

	std::cout << "Running DFS(" << start << ")\n";
	visited[start] = true;
	//std::cout << start << " ";
	std::list<int>::iterator it;
	for(it = graph[start].begin(); it != graph[start].end(); it++){
		if(!visited[*it]){
			parent[*it] = start;
			std::cout << "Parent of " << *it << " = " << start << std::endl;
			if(checkCycle_DFS(*it, graph, visited, parent))
				return true;
		}
		else{
			std::cout << *it << " is an already visited vertex with parent = " << parent[*it] << std::endl;
			// Check its parent
			if(parent[start] != *it){
				std::cout << *it << " is not the parent of " << start << std::endl << "Parent of " << start << " = " << parent[start] << std::endl << "Found a cycle at vertex " 
											<< *it << std::endl;
				return true;
			}
		}
	}
	return false;
}

// Same idea as above except using BFS and iteratively
// Returns true if there's a cycle
bool checkCycle_BFS(int start, int nodes, std::vector<std::list<int>> graph){
	std::vector<int> parent(nodes, -1);
	parent[start] = -1;

	std::queue<int> q;
	q.push(start);

	std::vector<bool> visited(nodes, false);
	visited[start] = true;

    std::cout << "Parent of " << start << " = " << parent[start] << std::endl;
	while(!q.empty()){
        int start = q.front();
		q.pop();
        std::cout << "Running BFS(" << start << ")\n";
		//std::cout << start << " ";
		std::list<int>::iterator it;
		for(it = graph[start].begin(); it != graph[start].end(); it++){
            if(!visited[*it]){
				visited[*it] = true;
				parent[*it] = start;
                q.push(*it);
                std::cout << "Parent of " << *it << " = " 
                                            << parent[*it] << std::endl;
			}
			else{
                std::cout << *it << " is an already visited vertex with parent = " << parent[*it] << std::endl;
				// Check its parent
				if(*it != parent[start]){
                    std::cout << *it << " is not the parent of " << start << std::endl << "Found a cycle at vertex " 
                                                    << *it << std::endl;
					return true;
                }
			}
		}
	}
	return false;
}

// Check if there's a cycle using topological sort
// Using Kahn's algorithm
std::vector<int> calcIndegree(std::vector<Edge> edges, int nodes){
    std::vector<int> inDegree(nodes, 0);
    for(int i = 0; i < edges.size(); i++){
        int source = edges[i].source;
        int destination = edges[i].destination;
        inDegree[source]++;
        inDegree[destination]++;
    }
    return inDegree;
}

// Returns true if there's a cycle
bool checkCycle_kahn(int start, std::vector<Edge> edges, int nodes, 
                std::vector<std::list<int>> graph){
    std::vector<int> inDegree = calcIndegree(edges, nodes);
    // Do a BFS
    std::vector<bool> visited(nodes, false);
    std::queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        std::list<int>::iterator it;
        for(it = graph[start].begin(); it != graph[start].end(); it++){
            if(!visited[*it]){
                visited[*it] = true;
                inDegree[*it]--;
                inDegree[start]--;
                q.push(*it);
            }
        }
    }
    // Check the in-degree vector. It should all be zeros if no cycle.
    for(int i = 0; i < inDegree.size(); i++){
        if(inDegree[i] > 0)
            return true;
    }
    return false;
}

int main(){
	// Vertex 0 is an un-connected vertexs
	std::vector<Edge> edges2 = {
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
		{9, 11},
		{11, 12}
	}; // Cycle at vertex 8. At 11 using BFS.

	int nodes2 = 13;

	std::vector<Edge> edges1 = 
	{
		{0, 1},
		{1, 2},
		{1, 3},
		{2, 4},
		{2, 3}
	}; // Cycle at vertex 1 using DFS. At 3 using BFS.

	int nodes1 = 5;

	std::vector<Edge> edges = 
	{
		{0, 1},
		{1, 2},
		{1, 3}
	}; // No cycle

	int nodes = 4;

	std::vector<std::list<int>> graph(nodes);
	addEdge(edges, graph);
	std::cout << "Graph is\n";
	printGraph(nodes, graph);

	/*****************************************/
	// Using DFS starting at vertex 1
	std::vector<bool> visited1(nodes, false);
	std::vector<int> parent1(nodes, -1);
	if(checkCycle_DFS(1, graph, visited1, parent1))
		std::cout << "Using DFS - Cycle in the graph.\n";
	else
		std::cout << "Using DFS - No cycle in the graph.\n";
	/*****************************************/

	/*****************************************/
	// Using BFS starting at vertex 1
	if(checkCycle_BFS(1, nodes, graph))
		std::cout << "Using BFS - Cycle in the graph.\n";
	else
		std::cout << "Using BFS - No cycle in the graph.\n";
	/*****************************************/

    /*****************************************/
    // Using topological sort
    // Applying Kahn's topological sorting
    if(checkCycle_kahn(1, edges, nodes, graph))
        std::cout << "Using Kahn - Cycle in the graph.\n";
    else
        std::cout << "Using Kahn - No cycle in the graph.\n";
    /*****************************************/    

	return 0;
}
