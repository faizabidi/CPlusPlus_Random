#include "bfs.h"
#include <list>

Graph::Graph (int v)
{
	this->vertices = v;

	//create a list of lists for each vertex
	adj = new std::list<int>[v];
}

void Graph::addEdge (int v, int w)
{
	adj[v].push_back (w);
}

void Graph::BFS (int s)
{
	//mark all vertices as false visited initially
	bool *visited = new bool[vertices];
	for (int i = 0; i < vertices; i++)
	{
		visited[i] = false;
		//std::cout << visited[i] << " ";
	}

	std::list<int> queue;

	visited[s] = true;
	queue.push_back (s);

	std::list<int>::iterator i;

	while (!queue.empty ())
	{
		//print the first node and mark it as visited
		s = queue.front ();
		std::cout << s << " ";
		queue.pop_front ();
		
		//check all neighbours of vertex x
		for (i = adj[s].begin (); i != adj[s].end (); i++)
		{
			//if node hasn't been visited, mark it, and add to queue
			if (!visited[*i])
			{
				//push vertex to the queue
				visited[*i] = true;
				queue.push_back (*i);
			}
		}
	}
	std::cout << std::endl;
}