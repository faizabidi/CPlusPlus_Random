#include <iostream>
#include <vector>
#include <queue>

// Iteratively
// O(n+m), where n = vertices and m = edges
void bfs_iterative(int start, std::vector<std::vector<int>> graph, 
					std::vector<bool> &visited){

	std::queue<int> q;
	q.push(start);
	visited[start] = true;
	while(!q.empty()){
		int start = q.front();
		q.pop();
		std::cout << start << " ";
		std::vector<int>::iterator it;
		//for(it = graph[start].begin(); it != graph[start].end(); it++){
		for(int j = 0; j < graph.size(); j++){
			if(graph[start][j] == 1 && !visited[j]){
				q.push(j);
				visited[j] = true;
			}
		}
	}
}

// Recursively
// O(n+m), where n = vertices and m = edges
void bfs_recursively(std::queue<int> &q, 
			std::vector<std::vector<int>> graph, std::vector<bool> &visited){

	if(q.empty())
		return;

	int start = q.front();
	q.pop();
	std::cout << start << " ";
	visited[start] = true;
	for(int j = 0; j < graph.size(); j++){
		if(graph[start][j] == 1 && !visited[j]){
			visited[j] = true;
			q.push(j);
		}
	}
	bfs_recursively(q, graph, visited);
}

int main(){
	std::vector<std::vector<int>> graph = 
	{
		{0, 1, 0, 1},
		{0, 0, 1, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	// Iteratively starting from 0
	std::vector<bool> visited1(graph.size(), false);
	for(int i = 0; i < graph.size(); i++){
		if(!visited1[i])
			bfs_iterative(i, graph, visited1);
	}
	std::cout << std::endl;
	//bfs_iterative(3, graph, visited);
	//bfs_iterative(2, graph, visited);
	//bfs_iterative(1, graph, visited);

	// Recursively starting from 0
	std::vector<bool> visited2(graph.size(), false);
	std::queue<int> q;
	for(int i = 0; i < graph.size(); i++){
		if(!visited2[i]){
			q.push(i);
			bfs_recursively(q, graph, visited2);
		}
	}
	std::cout << std::endl;

	return 0;
}
