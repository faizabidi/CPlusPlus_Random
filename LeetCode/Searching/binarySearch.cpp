// Best case - O(1)
// Worst, average case - O(log(n))

#include <iostream>
#include <vector>

// Using iteration
bool binarySearch(std::vector<int> array, int element){
	int start = 0, end = array.size() - 1, mid = 0;

	while(start <= end){
		mid = (start + end ) / 2;
		if(array[mid] == element)
			return true;
		else if(array[mid] > element)
			end = mid - 1;
		else if(array[mid] < element)
			start = mid + 1;
	}
	return false;
}

// Using recursion
bool binarySearch_helper(std::vector<int> array, int start, int end, int val){
	if(start > end)
		return false;
	int mid = (start + end) / 2;
	if(array[mid] == val)
		return true;
	if(array[mid] > val)
		return binarySearch_helper(array, start, mid - 1, val);
	else
		return binarySearch_helper(array, mid+1, end, val);
}

bool binarySearch2(std::vector<int> array, int val){
	return binarySearch_helper(array, 0, array.size(), val);
}

int main(){
	std::vector<int> array = {1,2,3,4,5,6,7,8,9};
	//std::vector<int> array = {1,2};
	int element;
	std::cin >> element;

	if(binarySearch2(array, element))
		std::cout << "Found!\n";
	else
		std::cout << "Not found\n";

	return 0;
}
