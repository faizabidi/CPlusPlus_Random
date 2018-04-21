#include <iostream>
#include <vector>
#include <queue>

void printGraph(std::vector<std::vector<int>> graph){
	for(int i = 0; i < graph.size(); i++){
		std::vector<int>::iterator it;
		for(it = graph[i].begin(); it != graph[i].end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
}

// Run recursively
// Use dfs to find all paths from a given vertix and add that to the adjacency matrix.
void runDFS(int start, std::vector<std::vector<int>> &graph, 
				std::vector<bool> &visited, std::vector<int> &neighbours){

	visited[start] = true;
	for(int j = 0; j < graph.size(); j++){
		if(graph[start][j] == 1 && !visited[j]){
			neighbours.push_back(j);
			runDFS(j, graph, visited, neighbours);
		}
	}
}

// Use bfs to find all paths
// Iteratively
void runBFS(int start, std::vector<std::vector<int>> graph, 
			std::vector<int> &neighbours){

	std::vector<bool> visited(graph.size(), false);
	std::queue<int> q;
	q.push(start);
	visited[start] = true;
	while(!q.empty()){
		int start = q.front(); 
		q.pop();
		for(int j = 0; j < graph.size(); j++){
			if(graph[start][j] == 1 && !visited[j]){
				q.push(j);
				neighbours.push_back(j);
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
	}; /* Ans = 0 1 1 1 
				0 0 1 0 
				0 0 0 0 
				0 0 0 0 */
	std::vector<std::vector<int>> graph1 = 
	{
		{0, 0, 1, 0},
		{1, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 1, 0, 0}
	}; /* Ans = 0 0 1 0 
				1 0 1 0 
				0 0 0 0 
				1 1 1 0 */

	std::cout << "Original graph\n";
	printGraph(graph);

	// Un-comment below to use DFS instead.
	/*std::cout << "Transitive closure of the graph using DFS\n";
	for(int i = 0; i < graph.size(); i++){
		std::vector<bool> visited(graph.size(), false);
		std::vector<int> neighbours;
		runDFS(i, graph, visited, neighbours);
		for(int j = 0; j < neighbours.size(); j++)
			graph[i][neighbours[j]] = 1;
	}
	printGraph(graph);*/

	std::cout << "Transitive closure of the graph using BFS\n";
	for(int i = 0; i < graph.size(); i++){
		std::vector<int> neighbours;
		runBFS(i, graph, neighbours);
		for(int j = 0; j < neighbours.size(); j++)
			graph[i][neighbours[j]] = 1;
	}
	printGraph(graph);

	return 0;
}
