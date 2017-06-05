// https://www.hackerrank.com/challenges/insertionsort2
// Time Complexity: O(n*n)
// Sorting In Place: Yes
// Stable: Yes
// Auxiliary Space: O(1)

#include <vector>
#include <iostream>
#include <algorithm>

void printVector(std::vector<int> array){
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

void insertionSort(std::vector<int> array){
	int shifts = 0;
	for(int i = 1; i < array.size(); i++){
		if(array[i] < array[i - 1]){
			std::cout << "Found a smaller!\n";
			int j = i;
			while(array[i] < array[i - 1] && i >= 0){
				shifts++;
				std::swap(array[i], array[i - 1]);
				i--;
			}
			i = j;
		}
		printVector(array);
	}
	std::cout << "Totals shifts = " << shifts << std::endl;
}

int main(){
	int n;
	std::cin >> n;

	std::vector<int> array(n);
	for(int i = 0; i < n; i++)
		std::cin >> array[i];

	insertionSort(array);

    return 0;
}
