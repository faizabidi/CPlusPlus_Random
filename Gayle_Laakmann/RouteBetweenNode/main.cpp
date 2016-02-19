#include <iostream>
#include "bfsRoute.cpp"

int main ()
{

	Graph g(6);
	g.addEdge (0, 1);
	g.addEdge (0, 2);
	g.addEdge (0, 4);
	g.addEdge (1, 2);
	g.addEdge (2, 0);
	g.addEdge (2, 3);
	//g.addEdge (3, 3);
	g.addEdge (5, 6);

	if (g.checkRouteBFS (2, 5))
		std::cout << "Route exists between 2 and 5\n";
	else
		std::cout << "No route between 2 and 5\n";

	if (g.checkRouteBFS (2, 4))
		std::cout << "Route exists between 2 and 4\n";
	else
		std::cout << "No route between 2 and 4\n";

	return 0;
}