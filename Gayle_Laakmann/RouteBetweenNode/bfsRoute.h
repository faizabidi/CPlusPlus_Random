#ifndef bfsRoute_h
#define bfsRoute_h
#include <list>
class Graph
{
public:
	Graph (int v);
	
	void addEdge (int v, int w);
	
	//see if a route exists between two vertices
	bool checkRouteBFS (int v, int w);

private:
	int vertices;
	//pointer to point to my adjacency lists
	std::list<int> *adj;
};

#endif
