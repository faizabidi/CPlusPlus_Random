#include <iostream>
#include <vector>
#include <stack>

void printGraph(std::vector<std::vector<int>> graph){
	for(int i = 0; i < graph.size(); i++){
		std::vector<int>::iterator it;
		for(it = graph[i].begin(); it != graph[i].end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
}

// Run recursively
void runDFS_recursively(int i, std::vector<std::vector<int>> graph, 
										std::vector<bool> &visited){
	if(visited[i])
		return;
	visited[i] = true;
	std::cout << i << " "; 
	for(int j = 0; j < graph.size(); j++){
		if(graph[i][j] == 1 && !visited[j])
			runDFS_recursively(j, graph, visited);
	}
}

// Run iteratively
void runDFS_iteratively(int start, std::vector<std::vector<int>> graph, 
					std::vector<bool> &visited){

	if(visited[start])
		return;

	std::stack<int> s;
	s.push(start);
	visited[start] = true;
	while(!s.empty()){
		int start = s.top();
		s.pop();
		std::cout << start << " ";
		for(int j = 0; j < graph.size(); j++){
			if(graph[start][j] == 1 && !visited[j]){
				s.push(j);
				visited[j] = true;
			}
		}

	}
}

int main(){
	std::vector<std::vector<int>> graph = 
	{
		{0, 1, 0, 1},
		{0, 0, 1, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	}; // Ans = 0 1 2 3 OR And = 0 3 1 2 


	std::cout << "Original graph\n";
	printGraph(graph);
	
	std::cout << "DFS of the graph starting with 0 using recursion\n";
	std::vector<bool> visited1(graph.size(), false);
	// Run in a for loop to cover even unconnected nodes
	for(int i = 0; i < graph.size(); i++)
		runDFS_recursively(i, graph, visited1);
	std::cout << std::endl;


	std::cout << "DFS of the graph starting with 0 using iteration\n";
	std::vector<bool> visited2(graph.size(), false);
	// Run in a for loop to cover even unconnected nodes
	for(int i = 0; i < graph.size(); i++)
		runDFS_iteratively(i, graph, visited2);
	std::cout << std::endl;

	return 0;
}
