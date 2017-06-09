// https://www.hackerrank.com/challenges/missing-numbers

#include <iostream>
#include <vector>
#include <map>

void printVector(std::vector<int> array){
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

void printMap(std::map<int, int> map){
	std::map<int, int>::iterator it;
	for(it = map.begin(); it != map.end(); it++)
		std::cout << it->first << ":" << it->second << std::endl;
}

std::vector<int> missingNumbers(std::vector<int> array1, std::vector<int> array2){
	std::vector<int> ans;
	std::map<int, int> map1, map2;
	
	for(int i = 0; i < array1.size(); i++)
		map1[array1[i]]++;
	

	for(int i = 0; i < array2.size(); i++)
		map2[array2[i]]++;

	std::cout << "Map1...\n";
	printMap(map1);
	std::cout << "Map2...\n";
	printMap(map2);

	std::map<int, int>::iterator it;
	// Iterate through the first hashmap and look if the keys it has exists in the other hashmap.
	// If not, add it to the ans vector 
	// If found, check if the values of the two match. If they don't, add it to the ans vector
	// If they do match, do nothing
	std::cout << "Checking map 1...\n";
	for(it = map1.begin(); it != map1.end(); it++){
		// Check if it not exists in the other hashmap
		if(!map2[it->first]){
			std::cout << it->first << " does not exist in map 2\n";
			ans.push_back(it->first);
		}
		else{
			std::cout << it->first << " exists in map 2\n";
			if(it->second != map2[it->first]){
				std::cout << it->first << " exists in map 2 but frequencies are different\n";
				ans.push_back(it->first);
			}
		}
	}

	// Do not need to check for keys that exists in map 1 since those are already checked in the above for loop
	std::cout << "Checking map 2 now...\n";
	for(it = map2.begin(); it != map2.end(); it++){
		// Check if it not exists in the other hashmap
		if(!map1[it->first]){
			std::cout << it->first << " does not exist in map 1\n";
			ans.push_back(it->first);
		}
	}
	std::sort(ans.begin(), ans.end());
	return ans;
}

int main(){
	int n;
	std::cin >> n;
	std::vector<int> array1(n);
	for(int i = 0; i < n; i++)
		std::cin >> array1[i];

	int m;
	std::cin >> m;
	std::vector<int> array2(m);
	for(int i = 0; i < m; i++)
		std::cin >> array2[i];

	std::vector<int> ans = missingNumbers(array1, array2);
	printVector(ans);
			
	return 0;
}