// https://www.hackerrank.com/challenges/find-the-median/problem

#include <vector>
#include <iostream>
#include <algorithm>

double median(std::vector<int> array, int size){
	std::sort(array.begin(), array.end());
	if(size % 2 != 0)
		return array[size / 2];
	return (array[size / 2 - 1] + array[size / 2]) / 2.0;
}

int main(){
	int size;
	std::cin >> size;
	std::vector<int> array(size);
	for(int i = 0; i < size; i++)
		std::cin >> array[i];
	std::cout << median(array, size);
	return 0;
}
