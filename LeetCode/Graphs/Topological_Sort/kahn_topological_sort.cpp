// https://en.wikipedia.org/wiki/Topological_sorting#Kahn.27s_algorithm
// http://www.techiedelight.com/kahn-topological-sort-algorithm/
#include <iostream>
#include <vector>
#include <queue>
#include <list>

struct Edge{
	int source;
	int destination;
};

void printVector(std::vector<int> array){
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

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

// Calculate in-degrees of all the nodes
std::vector<int> calcInDegreeVertices(int nodes, std::vector<Edge> edges){
	std::vector<int> inDegrees(nodes, 0);
	for(int i = 0; i < edges.size(); i++){
		int destination = edges[i].destination;
		inDegrees[destination]++;
	}
	return inDegrees;
}

// O(n+e)
std::vector<int> topologicalSort(int nodes, 
			std::vector<std::list<int>> adjList, std::vector<Edge> edges){

	std::vector<int> l;
	std::queue<int> q;
	// Add all the nodes that have no in-coming connections to s
	std::vector<int> inDegrees = calcInDegreeVertices(nodes, edges);

	for(int i = 0; i < inDegrees.size(); i++){
		if(inDegrees[i] == 0)
			q.push(i);
	}

	std::vector<bool> visited(nodes, false);
	while(!q.empty()){
		int start = q.front();
		q.pop();
		l.push_back(start);
		std::list<int>::iterator it;
		for(it = adjList[start].begin(); it != adjList[start].end(); it++){
			// Delete all its edges
			inDegrees[*it]--;
			if(inDegrees[*it] == 0)
				q.push(*it);
		}
	}
	// If any vertex still has any in-degrees left that means that the graph
	// has cycles in it.
	for(int i = 0; i < inDegrees.size(); i++){
		if(inDegrees[i] != 0)
			std::cout << "Graph has at least one cycle in it. It can't be topologically sorted.\n";
	}
	return l;
}

int main(){
	std::vector<Edge> edges = {
		{0, 6},
		{1, 2},
		{1, 4},
		{1, 6},
		{3, 0},
		{3, 4},
		{5, 1},
		{7, 0},
		{7, 1}
	}; // Ans = 3 5 7 0 1 2 4 6 


	int nodes = 8;
	std::vector<std::list<int>> adjList(8);
	addEdge(edges, adjList);
	printGraph(nodes, adjList);

	std::vector<int> sorted_vertices = topologicalSort(nodes, adjList, edges);
	printVector(sorted_vertices);

	return 0;
}
