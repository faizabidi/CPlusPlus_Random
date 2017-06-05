// https://www.hackerrank.com/challenges/quicksort2

#include <vector>
#include <iostream>
#include <algorithm>

void printVector(std::vector<int> array){
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

void merge(std::vector<int> &array, std::vector<int> left, std::vector<int> right, int pivot){
	array.clear();
	for(int i = 0; i < left.size(); i++)
		array.push_back(left[i]);
	array.push_back(pivot);
	for(int i = 0; i < right.size(); i++)
		array.push_back(right[i]);
}

void partition(std::vector<int> array, std::vector<int> &left, std::vector<int> &right, int pivot){
	for(int i = 0; i < array.size(); i++){
		if(array[i] < pivot)
			left.push_back(array[i]);
		else if(array[i] > pivot)
			right.push_back(array[i]);
	}
}

void quickSort(std::vector<int> &array){
	if(array.size() < 2)
		return;
	int pivot = array[0];
	std::vector<int> left, right;
	partition(array, left, right, pivot);
	quickSort(left);
	quickSort(right);
	merge(array, left, right, pivot);
	printVector(array);
}

int main(){
	int n;
	std::cin >> n;

	std::vector<int> array(n);
	for(int i = 0; i < n; i++)
		std::cin >> array[i];

	quickSort(array);

    return 0;
}
