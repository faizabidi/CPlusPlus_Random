//Time Complexity of BFS: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.

#include <iostream>
#include "dfs.cpp"

int main ()
{
	Graph g(4);

	g.addEdge (0, 1);
	g.addEdge (0, 2);
	g.addEdge (1, 2);
	g.addEdge (2, 0);
	g.addEdge (2, 3);
	g.addEdge (3, 3);

	std::cout << "DFS traversal starting with vertex 2\n";
	g.DFS (2);

	std::cout << std::endl;

	std::cout << "DFS traversal starting with vertex 2\n";
	g.DFS (1);

	std::cout << std::endl;

	return 0;
}