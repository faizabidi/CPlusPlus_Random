#include <iostream>
#include <map>
#include <vector>

int main(){
	std::vector<int> array = {1,2,3,4,5};
	std::map<std::pair<int, int>, int> hashmap;
	for(int i = 0; i < array.size(); i++){
		int sum = 0;
		for(int j = i; j < array.size(); j++){
			sum += array[j];
			hashmap[std::make_pair(i, j)] = sum;
		}
	}

	// Print it
	std::map<std::pair<int, int>, int>::iterator it;
	for(it = hashmap.begin(); it != hashmap.end(); it++)
		std::cout << it->first.first << it->second << " ";

	return 0;
}