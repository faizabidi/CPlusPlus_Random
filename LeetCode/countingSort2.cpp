//https://www.hackerrank.com/challenges/countingsort2/problem

#include <iostream>
#include <vector>
#include <map>

void calculate(std::vector<int> array, int size){
	std::map<int, int> hashmap;
	for(int i = 0; i <= 99; i++)
		hashmap[i] = 0;
	for(int i = 0; i < size; i++)
	   hashmap[array[i]]++;

	// Print the values of the hashmap
	std::map<int, int>::iterator it;
	for(it = hashmap.begin(); it != hashmap.end(); it++){
		int count = it->second;
		while(count > 0){
			std::cout << it->first << " ";
			count--;
		}
	}
	std::cout << std:: endl;
}

int main(){
	int size;
	std::cin >> size;

	std::vector<int> array(size);
	for(int i = 0; i < size; i++)
		std::cin >> array[i];

	calculate(array, size);
}
