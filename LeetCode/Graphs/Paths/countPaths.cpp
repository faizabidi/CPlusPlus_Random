#include <iostream>
#include <vector>
#include <list>
#include <queue>

struct Edge{
	int source;
	int destination;
};

void addEdge(std::vector<std::list<int>> &adjlist, std::vector<Edge> edges){
	for(int i = 0; i < edges.size(); i++){
		int source = edges[i].source;
		int destination = edges[i].destination;
		adjlist[source].push_back(destination);
	}
}

void printDAG(std::vector<std::list<int>> adjlist){
	for(int i = 0; i < adjlist.size(); i++){
		std::cout << i << "->";
		std::list<int> temp = adjlist[i];
		for(auto it = temp.begin(); it != temp.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
}

// Count all paths from vertex A to vertex 
// Apply a BFS
int countPaths(std::vector<std::list<int>> adjlist, int src, int dest){
	int paths = 0;
	std::queue<int> q;
	q.push(src);
	while(!q.empty()){
		int vertex = q.front();
		q.pop();
		if(vertex == dest)
			paths++;
		// Add all the neighbours of vertex to the queue
		// and again check for all
		for(auto it = adjlist[vertex].begin(); 
							it != adjlist[vertex].end(); it++)
			q.push(*it);		
	}
	return paths;
}

int main(){
	std::vector<std::vector<int>> allEdges = {
		{1,2},
		{3},
		{3},
		{}
	};

	int nodes = allEdges.size();
	// Make it a source, destination data structure
	std::vector<Edge> edges;
	for(int i = 0; i < allEdges.size(); i++){
		int source = i;
		std::vector<int> neighbours = allEdges[i];
		for(int j = 0; j < neighbours.size(); j++){
			int destination = neighbours[j];
			edges.push_back({source, destination});
		}
	}

	std::vector<std::list<int>> adjlist(nodes);
	addEdge(adjlist, edges);
	printDAG(adjlist);
	std::cout << "No. of paths from 0 to 3 = " << 
						countPaths(adjlist, 0, 3) << std::endl;
	return 0;
}
