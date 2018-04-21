// http://www.techiedelight.com/topological-sorting-dag/

#include <iostream>
#include <vector>
#include <list>

bool compare(std::pair<int, int> a, std::pair<int, int> b){
	return (a.second > b.second);
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
		std::vector<bool> &visited, int start, std::vector<int> &arrival_time, 
							std::vector<int> &departure_time, int &time){

	arrival_time[start] = time++;

	std::cout << start << " ";
	visited[start] = true;

	// Add all its vertices to the stack
	std::list<int>::iterator it;
	for(it = adjList[start].begin(); it != adjList[start].end(); it++){
		if(!visited[*it]){
			visited[*it] = true;
			DFS_recursion(adjList, visited, *it, arrival_time, departure_time, time);
		}
	}
	departure_time[start] = time++;
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
	};

	int N = 8;

	std::vector<std::list<int>> adjList(N);

	// Add all the edges
	addEdge(edges, adjList);

	// Print the graph
	printGraph(adjList, N);

	// DFS search using recursive method
	std::vector<bool> visited(N, false);
	std::vector<int> arrival_time(N, 0), departure_time(N, 0);
	int time = 0;
	// DFS from all the nodes so that even un-connected nodes get visited
	for(int i = 0; i < N; i++){
		if(!visited[i])
			DFS_recursion(adjList, visited, i, arrival_time, departure_time, time);
	}
	std::cout << "Arrival/departure time of nodes is as follows\n";
	for(int i = 0; i < N; i++)
		std::cout << "Node" << i << ":" << arrival_time[i] << "," << departure_time[i] << std::endl;

	// Print nodes in decreasing order of their departure times
	// That will be the topological sort. 
	std::cout << "Topological sort is\n"; // Ans = 7,5,3,1,4,2,0,6
	std::vector<std::pair<int, int>> array(N);
	for(int i = 0; i < N; i++)
		array[i] = std::make_pair(i, departure_time[i]);
	// Sort this vector in decreasing order of the second int in the pair
	std::sort(array.begin(), array.end(), compare); 
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i].first << " ";
	std::cout << std::endl;

	return 0;
}

