// https://www.hackerrank.com/challenges/quicksort2
// Worst case: O(n*n)
// Best case: O(nLogn)
// Sorting In Place: Yes

#include <iostream>
#include <vector>

void print(std::vector<int> array){
	for(auto value : array)
		std::cout << value << " ";
	std::cout << std::endl;
}

void merge(std::vector<int> left, std::vector<int> right, 
						std::vector<int> &array, int pivot){

	array = left;
	array.push_back(pivot);
	array.insert(array.end(), right.begin(), right.end());
}

// Partion an array around a pivot
void partition(std::vector<int> array, std::vector<int> &left, 
								std::vector<int> &right, int pivot){

	for(int i = 0; i < array.size(); i++){
		if(array[i] < pivot)
			left.push_back(array[i]);
		else if(array[i] > pivot)
			right.push_back(array[i]);
	}
}

void quickSort(std::vector<int> &array){
	std::vector<int> left, right;
	if(array.size() <= 1)
		return;
	int pivot = array[array.size() - 1];
	
	partition(array, left, right, pivot);
	quickSort(left);
	quickSort(right);
	merge(left, right, array, pivot);
}

int main(){
	// std::vector<int> array = {-1,10,7,9,1,2,-100,0};
	std::vector<int> array = {10, 9, 8, 7, 6, 5};
	quickSort(array);
	print(array);

	return 0;
}
