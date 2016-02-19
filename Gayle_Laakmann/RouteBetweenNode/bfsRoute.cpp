#include "bfsRoute.h"
#include <list>

Graph::Graph (int v)
{
	this->vertices = v;
	//each vertex will have its own list
	//so, v number of lists
	adj = new std::list<int>[v];
}

void Graph::addEdge (int v, int w)
{
	adj[v].push_back (w);
}

bool Graph::checkRouteBFS (int v, int w)
{
	if (v == w)
		return true;


	//mark all nodes as unvisited
	bool *visited = new bool[vertices];
	for (int i = 0; i < vertices; i++)
		visited[i] = false;

	//create a queue to add vertices
	std::list<int> queue;

	//add the v vertex in the list
	queue.push_back (v);

	//mark the vertex as true
	visited[v] = true;

	//keep an iterator for the queue
	std::list<int>::iterator i;

	while (!queue.empty())
	{
		v = queue.front ();
		//std::cout << v << " ";

		//pop the vertex from queue
		queue.pop_front ();

		for (i = adj[v].begin(); i != adj[v].end (); i++)
		{
			
			if (*i == w)
				return true;

			//else, continue doing the BFS
			//if unvisited node, add to queue
			if (visited[*i] == false)
				queue.push_back (*i);
		}

	}

	//if vertex can't be reached, return false
	return false;
}