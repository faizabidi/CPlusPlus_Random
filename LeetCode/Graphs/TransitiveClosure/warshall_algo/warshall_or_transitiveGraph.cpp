// http://cs.winona.edu/lin/cs440/ch08-2.pdf

#include <iostream>
#include <vector>

void printGrapgh(std::vector<std::vector<int>> graph){
	for(int i = 0; i < graph.size(); i++){
		std::vector<int>::iterator it;
		for(it = graph[i].begin(); it != graph[i].end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
}

// O(n*n*n)
void warshall_algo(std::vector<std::vector<int>> &graph){
	for(int k = 0; k < graph.size(); k++){
		for(int i = 0; i < graph.size(); i++){
			for(int j = 0; j < graph.size(); j++){
				if(graph[i][j] != 1){
					if(graph[i][k] == 1 && graph[k][j] == 1)
						graph[i][j] = 1;
				}
			}
		}
	}
}

int main(){
	std::vector<std::vector<int>> graph = 
	{
		{0, 1, 0},
		{0, 0, 1},
		{0, 0, 0}
	}; /* Ans = 0 1 1 
	  			0 0 1 
	  			0 0 0*/ 


	std::vector<std::vector<int>> graph1 = 
	{
		{0, 1, 0, 0},
		{0, 0, 0, 1},
		{0, 0, 0, 0},
		{1, 0, 1, 0}
	}; /* Ans = 1 1 1 1 
				1 1 1 1 
				0 0 0 0 
				1 1 1 1 */

	std::vector<std::vector<int>> graph2 = 
	{
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{1, 0, 0, 1},
		{0, 0, 0, 0}
	}; /*Ans = 1 1 1 1 
			   1 1 1 1 
			   1 1 1 1 
			   0 0 0 0*/

	std::vector<std::vector<int>> graph3 = 
	{
		{0, 0, 1, 0},
		{1, 0, 0, 1},
		{0, 0, 0, 0},
		{0, 1, 0, 0}
	}; /*Ans = 0 0 1 0 
			   1 1 1 1 
			   0 0 0 0 
			   1 1 1 1*/


	std::cout << "Original graph\n";
	printGrapgh(graph);

	std::cout << "Transitive graph\n";
	warshall_algo(graph);
	printGrapgh(graph);

	return 0;
}
