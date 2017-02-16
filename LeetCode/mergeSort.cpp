#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int> left, std::vector<int> right){
	std::vector<int> result;
	// Merge the left and the right into result vector
	int i = 0, j = 0;
	while(i < left.size() && j < right.size()){
		if(left[i] <= right[j]){
			result.push_back(left[i]);
			i++;
		}
		else{
			result.push_back(right[j]);
			j++;
		}
	}

	// If some elements still left in left or right
	while(i < left.size())
		result.push_back(left[i++]);
	while(j < right.size())
		result.push_back(right[j++]);
	return result;
}

std::vector<int> mergeSort(std::vector<int> array){
	if(array.size() <= 1)
			return array;

	int mid = (array.size() + 1) / 2;
	std::vector<int> left, right, result;

	for(int i = 0; i < mid; i++)
		left.push_back(array[i]);
	for(int j = mid; j < array.size(); j++)
		right.push_back(array[j]);
	
	//std::cout << "Left sorting\n";
	left = mergeSort(left);
	//std::cout << "Right sorting\n";
	right = mergeSort(right);
	//std::cout << "Merging\n";
	result = merge(left, right);

	return result;
}

int main(){
	int size;

	std::cout << "Size of array:";
	std::cin >> size;

	std::vector<int> array(size);

	for(int i = 0; i < size; i++)
		std::cin >> array[i];

	array = mergeSort(array);

	std::vector<int>::iterator it;
	for(it = array.begin(); it != array.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}