#include <iostream>
#include <vector>
#include <list>
#include <queue>

class Graph{
public:
	Graph(int v){
		vertices = v;
		adjList.resize(vertices);
	}

	void addEdge(int v, int w){
		adjList[v].push_back(w);
	}

	void DFS_print(int v){
		// Initialize all nodes to not visited
		std::vector<bool> visited(vertices);
		for(int i = 0; i < vertices; i++)
			visited[i] = false;
		DFS_helper(v, visited);
	}

	void BFS_print(int v){
		// Initialize all nodes to not visited
		std::vector<bool> visited(vertices);
		for(int i = 0; i < vertices; i++)
			visited[i] = false;
		BFS_helper(v, visited);
	}
private:
	int vertices;
	std::vector<std::list<int> > adjList;

	void DFS_helper(int vertex, std::vector<bool> visited){
		if(!visited[vertex]){
			// Print it and mark it as visited
			std::cout << vertex << " ";
			visited[vertex] = true;
		}
		std::list<int>::iterator it;
		for(it = adjList[vertex].begin(); it != adjList[vertex].end(); it++){
			if(!visited[*it])
				DFS_helper(*it, visited);
		}
	}

	void BFS_helper(int v, std::vector<bool> visited){
		std::queue<int> q;
		q.push(v);
		// Mark the current node as visited
		visited[v] = true;
		while(!q.empty()){
			int a = q.front();
			q.pop();
			std::cout << a << " ";
			std::list<int>::iterator it;
			for(it = adjList[a].begin(); it != adjList[a].end(); it++){
				if(!visited[*it]){
					// Add to queue and mark it visited
					q.push(*it);
					visited[*it] = true;
				}
			}
		}
		std::cout << std::endl;
	}
};

int main(){
	int vertices;
	std::cout << "Enter vertices:";
	std::cin >> vertices;
	Graph obj1(vertices);

	std::cout << "Enter the graph (e.g. 2, 3):";
	for(int i = 0; i < vertices; i++){
		int v, w;
		std::cin >> v >> w;
		obj1.addEdge(v, w);
	}

	std::cout << "Enter the starting vertex to show the graph:";
	int start_vertex;
	std::cin >> start_vertex;
	obj1.DFS_print(start_vertex);
	std::cout << std::endl;
	obj1.BFS_print(start_vertex);

/* Sample run
// http://cseweb.ucsd.edu/~kube/cls/100/Lectures/lec12/lec12-23.html

Enter vertices:11
Enter the graph (e.g. 2, 3):0 1
1 3
1 4
2 0
2 5
3 2
3 5
3 6
4 1
4 6
6 5
Enter the starting vertex to show the graph:0
0 1 3 2 5 5 6 5 4 6 5 
0 1 3 4 2 5 6 */

	return 0;
}