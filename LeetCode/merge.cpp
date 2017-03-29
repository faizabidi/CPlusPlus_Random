// https://leetcode.com/problems/merge-sorted-array/#/description

#include <iostream>
#include <vector>

void input(std::vector<int> &array){
	for(int i = 0; i < array.size(); i++)
		std::cin >> array[i];
}

std::vector<int> merge(std::vector<int> array1, std::vector<int> array2){
	int i = 0, j = 0;
	std::vector<int> merged_array;
	while(i < array1.size() && j < array2.size()){
		if(array1[i] <= array2[j]){
			merged_array.push_back(array1[i]);
			i++;
		}
		else{
			merged_array.push_back(array2[j]);
			j++;
		}
	}
	while(i < array1.size()){
		merged_array.push_back(array1[i]);
		i++;
	}
	while(j < array2.size()){
		merged_array.push_back(array2[j]);
		j++;
	}
	return merged_array;
}

int main(){
	int size1, size2;

	std::cout << "Enter size of array 1:";
	std::cin >> size1;

	std::vector<int> array1(size1);
	std::cout << "Enter the array:";
	input(array1);

	std::cout << "Enter size of array 2:";
	std::cin >> size2;

	std::vector<int> array2(size2);	
	std::cout << "Enter the array:";
	input(array2);

	std::vector<int> merged_array = merge(array1, array2);

	for(int i = 0; i < merged_array.size(); i++)
		std::cout << merged_array[i];
	std::cout << std::endl;

	return 0;
}