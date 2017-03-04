// https://leetcode.com/problems/partition-equal-subset-sum/?tab=Description

#include <iostream>
#include <vector>

bool canPartition(std::vector<int> array){
	// Save it in a new vector
	std::vector<int> tempArray = array;
	std::cout << "Size of array is " << tempArray.size() << std::endl;
	
	// Find the max number in the tempArray
	std::vector<int>::iterator max;
	max = std::max_element(tempArray.begin(), tempArray.end());
	int MAX = *max;
	std::cout << "Max sum is " << *max << std::endl;
	
	// Find its coordinates and sum all excluding it
	int max_index = std::distance(tempArray.begin(), max);
	std::cout << "Max index = " << max_index << std::endl;
	int sum_left = 0;
	for(int i = 0; i < tempArray.size(); i++){
		if(i != max_index)
			sum_left += tempArray[i];
	}
	std::cout << "Sum left is " << sum_left << std::endl;
	std::cout << "Max sum is " << *max << std::endl;
 	// Check both the values
	if(sum_left == MAX)
		return true;
	return false;
}

int main(){
	std::vector<int> array = {1,1};
	if(canPartition(array))
		std::cout << "Can\n";
	else
		std::cout << "Can't\n";

	return 0;
}