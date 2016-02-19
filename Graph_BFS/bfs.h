#include <list>

class Graph
{
public:
	//default constructor
	Graph (int v);

	void addEdge (int v, int w);

	void BFS (int s);
private:
	//number if vertices
	int vertices;

	//list for each vertex
	std::list<int> *adj;
};