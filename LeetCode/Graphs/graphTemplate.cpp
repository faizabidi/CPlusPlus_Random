#include <iostream>
#include <vector>
#include <list>

void print(std::vector<std::list<int> > adjList){
	for(int i = 0; i < adjList.size(); i++){
		std::list<int>::iterator it;
		for(it = adjList[i].begin(); it != adjList[i].end(); it++)
			std::cout << *it << "->";
		std::cout << "NULL\n";
	}
}

int main(){
	int vertices = 4;
	//std::cin >> vertices;

	std::vector<std::list<int> > adjList(vertices);

	adjList[0].push_back(1);
	adjList[0].push_back(2);

	adjList[1].push_back(1);
	adjList[1].push_back(0);

	adjList[2].push_back(0);
	adjList[2].push_back(1);
	adjList[2].push_back(3);

	adjList[3].push_back(2);

	print(adjList);	

	return 0;
}