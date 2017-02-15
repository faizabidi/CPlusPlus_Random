// Binary search runs in at worst logarithmic time, making O(log n) comparisons

#include <iostream>
#include <vector>

bool binarySearch(std::vector<int> array, int num_search){
	int low = 0;
	int high = array.size() - 1;
	while(low <= high){
		int mid = (low + high) / 2;
		std::cout << "Mid is " << mid << std::endl;
		
		// If found
		if(array[mid] == num_search){
			std::cout << "Index found is " << mid << std::endl;
			return true;
		}

		if(array[mid] > num_search){
			high = mid - 1;
			std::cout << array[mid] << " High\n";
		}
		else if (array[mid] < num_search){
			low = mid + 1;
			std::cout << array[mid] << " Low\n";
		}
	}
	return false;
}

int main(){
	int n;
	std::cout << "Enter size of array:";
	std::cin >> n;

	std::vector<int> array(n);
	std::cout << "Enter a sorted array:";
	for(int i = 0; i < n; i++)
		std::cin >> array[i];

	std::cout << "Enter number to be searched for:";
	int search_num;
	std::cin >> search_num;

	if(binarySearch(array, search_num))
		std::cout << "Number found!\n";
	else
		std::cout << "Number not found\n";

	return 0;
}