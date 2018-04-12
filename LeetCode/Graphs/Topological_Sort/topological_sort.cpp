#include <iostream>
#include <vector>
#include <list>
#include <stack>

void printVector(std::vector<int> arrray){
	for(int i = 0; i < arrray.size(); i++)
		std::cout << i << ":" << arrray[i] << " ";
	std::cout << std::endl;
}

struct Edge{
	int source;
	int destinatation;
};

void addEdge(std::vector<Edge> edges, std::vector<std::list<int>> &adjList){
	for(int i = 0; i < edges.size(); i++){
		int source = edges[i].source;
		int destinatation = edges[i].destinatation;
		adjList[source].push_back(destinatation);
	}
}

void printGraph(std::vector<std::list<int>> adjList, int N){
	for(int i = 0; i < N; i++){
		std::cout << i << ":";
		std::list<int>::iterator it;
		for(it = adjList[i].begin(); it != adjList[i].end(); it++)
			std::cout << *it << "->";
		std::cout << "NULL\n";
	}
}

// Do a DFS traversal recursively
void DFS_recursion(std::vector<std::list<int>> adjList, 
							std::vector<bool> &visited, std::stack<int> &s, 
							std::vector<int> &arrival_time, 
							std::vector<int> &departure_time, int &time){
	
	if(s.empty())
		return;

	int start = s.top();
	s.pop();
	arrival_time[start] = time++;

	// Add all its vertices to the stack
	std::list<int>::iterator it;
	for(it = adjList[start].begin(); it != adjList[start].end(); it++){
		if(!visited[*it]){
			s.push(*it);
			visited[*it] = true;
			DFS_recursion(adjList, visited, s, arrival_time, departure_time, time);
		}
	}
	departure_time[start] = time++;
}

int main(){
	std::vector<Edge> edges1 = {
		{0, 6},
		{1, 2},
		{1, 4},
		{1, 6},
		{3, 0},
		{3, 4},
		{5, 1},
		{7, 0},
		{7, 1}
	};

	std::vector<Edge> edges = {
		{0, 1},
		{0, 2},
		{2, 3},
		{2, 4},
		{3, 1},
		{3, 5},
		{4, 5},
		{6, 7}
	};



	int N = 8;

	std::vector<std::list<int>> adjList(N);

	// Add all the edges
	addEdge(edges, adjList);

	// Print the graph
	printGraph(adjList, N);

	// DFS search using recursive method
	std::vector<bool> visited(N, false);
	std::stack<int> s;
	s.push(0);
	std::vector<int> arrival_time(N, 0), departure_time(N, 0);
	int time = 0;
	DFS_recursion(adjList, visited, s, arrival_time, departure_time, time);
	std::cout << std::endl;
	printVector(arrival_time);
	printVector(departure_time);

	return 0;
}

