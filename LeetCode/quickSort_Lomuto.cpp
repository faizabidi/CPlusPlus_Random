#include <iostream>
#include <vector>
#include <algorithm>

void printVector(std::vector<int> array){
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

int partition(std::vector<int> &array, int low, int high){
	int i = low - 1;
	int pivot = array[high];
	std::cout << "Pivot is " << array[high] << std::endl;
	for(int j = low; j < high; j++){
		std::cout << "j = " << j << std::endl;
		std::cout << "i = " << i << std::endl;
		if(pivot >= array[j]){
			i++;
			std::cout << "i = " << i << std::endl;
			std::swap(array[i], array[j]);
			printVector(array);
		}
	}
	std::swap(array[i + 1], array[high]);
	printVector(array);
	return i + 1;
}

void quickSort_Lomuto(std::vector<int> &array, int low, int high){
	std::cout << "Sorting (A, " << low << ", " << high << ")\n";
	printVector(array);
	if(low < high){
		int index = partition(array, low, high);
		std::cout << "Index = " << index << std::endl;
		std::cout << "Low = " << low << std::endl << "High = " << high << std::endl;
		quickSort_Lomuto(array, low, index - 1);
		quickSort_Lomuto(array, index + 1, high);
	}
}

int main(){
	int n;
	std::cin >> n;

	std::vector<int> array(n);
	for(int i = 0; i < n; i++)
		std::cin >> array[i];

	quickSort_Lomuto(array, 0, n - 1);

	return 0;
}