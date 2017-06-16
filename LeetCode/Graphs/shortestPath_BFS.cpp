#include <iostream>
#include <list>
#include <vector>
#include <queue>

// http://www.eecs.yorku.ca/course_archive/2006-07/W/2011/Notes/BFS_part2.pdf

class Graph{
public:
	Graph(int v){
		vertices = v;
		// Have to resize adj else will get segmentation fault while adding vertices
		adj.resize(vertices);
	}
		
	// Connect the two vertices
	void add(int v, int w){
		adj[v].push_back(w);
	}

	// BFS from each node
	void bfs(){
		if(adj.size() == 0)
			return;

		for(int i = 0; i < vertices; i++){
			// Create a vector of bools and initialize all to false
			std::cout << "BFS starting from vertex " << i << ":";
			std::vector<bool> visited(vertices);
			for(int i = 0; i < vertices; i++)
				visited[i] = false;

			bfs_helper(i, visited);
			std::cout << std::endl;
		}
	}

	// Shortest path from source (0) to each node
	void bfs_ShortestPath(int source){
		for(int i = 0; i < vertices; i++){
			std::vector<int> previous(vertices);
			std::vector<bool> visited(vertices);

			// Initialize all the values to -1
			for(int i = 0; i < previous.size(); i++)
				previous[i] = -1;

			// Initialize all nodes as not visited
			for(int i = 0; i < visited.size(); i++)
				visited[i] = false;

			std::queue<int> q;
			q.push(source);
			visited[source] = true;

			// Copy the private data
			std::vector<std::list<int>> adj1 = adj;

			while(!q.empty()){
				int temp = q.front();
				q.pop();
				std::list<int>::iterator it;
				for(it = adj1[temp].begin(); it != adj1[temp].end(); it++){
					// If node is not visited
					if(!visited[*it]){
						q.push(*it);
						visited[*it] = true;
						previous[*it] = temp;
					}
				}
			}

			// Print the prev table
			std::cout << "Previous table is\n";
			for(int i = 0; i < previous.size(); i++)
				std::cout << i << ":" << previous[i] << std::endl;

			std::cout << "Path between " << source << " and " << i << " is\n";
			int current = i;
			while(previous[current] != -1){
				std::cout << current << " ";
				current = previous[current];	
			}
			std::cout << source << std::endl;
		}
	}

	void print_AdjacencyMatrix(){
		for(int i = 0; i < adj.size(); i++){
			std::list<int>::iterator it;
			std::cout << i << ":";
			for(it = adj[i].begin(); it != adj[i].end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;
		}
	}
	
private:
	int vertices;
	std::vector<std::list<int>> adj;

	void bfs_helper(int v, std::vector<bool> visited){
		std::queue<int> q;
		q.push(v);

		// Mark it as visited
		visited[v] = true; 

		while(!q.empty()){
			int temp = q.front();
			q.pop();
			std::cout << temp << " ";

			// Check if the list of vertices attached to this vertex have been visited or not. If not visited, add them to the queue
			std::list<int>::iterator it;
			for(it = adj[temp].begin(); it != adj[temp].end(); it++){
				if(!visited[*it]){
					// Add it to the queue and mark it visited
					q.push(*it);
					visited[*it] = true;
				}
			}
		}
	}
};

int main(){
	Graph obj1(6);

	obj1.add(0, 1);
	obj1.add(1, 3);
	obj1.add(1, 4);
	obj1.add(3, 2);
	obj1.add(4, 2);
	obj1.add(4, 5);
	obj1.add(2, 1);

	std::cout << "Adjacency matrix is\n";
	obj1.print_AdjacencyMatrix();

	std::cout << "BFS search starting from all nodes\n";
	obj1.bfs();

	std::cout << "All shortest paths from vertex 0 to others\n";
	obj1.bfs_ShortestPath(0);

	return 0;
}