#ifndef dfs_h
#define dfs_h

#include <list>

class Graph
{
public:
	Graph (int v);

	void addEdge (int v, int w);

	void DFS (int v);
	//~Graph();

private:
	//number of vertices in the graph
	int vertices;

	//there would be an adjacent list for each vertex
	//adj will point to an array index, which would have tht list
	std::list<int> *adj;

	void DFSUtil (int v, bool visited[]);

};

#endif