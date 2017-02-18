// https://www.hackerrank.com/challenges/ctci-merge-sort

#include <iostream>
#include <vector>

void printVector(std::vector<int> array){
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

void merge(std::vector<int> left, std::vector<int> right, std::vector<int> &array, int &counter){
	int i = 0, j = 0;
	
	std::vector<int> tempResult;

	while(i < left.size() && j < right.size()){
		if(left[i] <= right[j])
			tempResult.push_back(left[i++]);
		else{
			counter = counter + left.size() - i;
			tempResult.push_back(right[j++]);
		}
	}
	// Left over in left or right
	while(i < left.size())
		tempResult.push_back(left[i++]);
	
	while(j < right.size())
		tempResult.push_back(right[j++]);

	array = tempResult;
}

void countInversions(std::vector<int> &array, int &counter){
	if(array.size() <= 1)
		return; 

	std::vector<int> left;
	std::vector<int> right;

	int mid = (array.size() + 1) / 2;

	for(int i = 0; i < mid; i++)
		left.push_back(array[i]);
	for(int i = mid; i < array.size(); i++)
		right.push_back(array[i]);

	countInversions(left, counter);
	countInversions(right, counter);
	merge(left, right, array, counter);
}

int main(){
	int datasets;
	int counter = 0;
	std::cout << "How many datasets? ";
	std::cin >> datasets;

	for(int i = 0; i < datasets; i++){
		int elements;
		std::cout << "How many elements? ";
		std::cin >> elements;

		std::vector<int> array(elements);
		std::cout << "Enter elements:";
		for(int j = 0; j < elements; j++)
			std::cin >> array[j];

		countInversions(array, counter);
		printVector(array);
		std::cout << counter << std::endl;
	}

	return 0;
}