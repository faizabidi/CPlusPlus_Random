// Time complexity - Best and worst case - O(nlog(n))
// Space complexity - O(n)

#include <iostream>
#include <vector>

void print(std::vector<int> array){
	for(auto value : array)
		std::cout << value << " ";
	std::cout << std::endl;
}

// Merge two sorted arays
std::vector<int> mergeArray(std::vector<int> array1, std::vector<int> array2){
	std::vector<int> mergedArray;
	int i = 0, j = 0;
	while(i < array1.size() && j < array2.size()){
		if(array1[i] <= array2[j])
			mergedArray.push_back(array1[i++]);
		else if(array1[i] > array2[j])
			mergedArray.push_back(array2[j++]);
	}
	while(i < array1.size())
		mergedArray.push_back(array1[i++]);
	while(j < array2.size())
		mergedArray.push_back(array2[j++]);
	return mergedArray;
}

// MergeSort
void mergeSort(std::vector<int> &array){
	if(array.size() == 1)
		return;
	std::vector<int> firstHalf, secondHalf;
	int i = 0;
	while(i < array.size() / 2)
		firstHalf.push_back(array[i++]);
	while(i < array.size())
		secondHalf.push_back(array[i++]);
	mergeSort(firstHalf);
	mergeSort(secondHalf);
	array = mergeArray(firstHalf, secondHalf);
}

int main(){
	std::vector<int> array = {1,5,6,9,0,-1,20};
	mergeSort(array);
	print(array);

	return 0;
}
