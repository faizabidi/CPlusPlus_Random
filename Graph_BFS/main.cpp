/*Time Complexity: O(V+E) where V is number of vertices...
... in the graph and E is number of edges in the graph.*/

#include <iostream>
#include "bfs.cpp"

int main ()
{
	Graph g(4);

	g.addEdge (0, 1);
	g.addEdge (0, 2);
	g.addEdge (1, 2);
	g.addEdge (2, 0);
	g.addEdge (2, 3);
	g.addEdge (3, 3);

	std::cout << "BFS traversal starting from node 2\n";
	g.BFS (2);

	std::cout << "BFS traversal starting from node 0\n";
	g.BFS (0);

	return 0;
}