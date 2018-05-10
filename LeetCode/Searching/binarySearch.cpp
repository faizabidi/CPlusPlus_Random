// Best case - O(n)
// Worst case - O(log(n))

#include <iostream>
#include <vector>

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

int main(){
	std::vector<int> array = {1,2,3,4,5,6,7,8,9};
	//std::vector<int> array = {1,2};
	int element;
	std::cin >> element;

	if(binarySearch(array, element))
		std::cout << "Found!\n";
	else
		std::cout << "Not found\n";

	return 0;
}
