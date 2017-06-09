#include <vector>
#include <iostream>
#include <algorithm>

void insertionSort(std::vector<int> array, int &shifts){
	for(int i = 1; i < array.size(); i++){
		if(array[i] < array[i - 1]){
			int j = i;
			while(array[i] < array[i - 1] && i >= 0){
				shifts++;
				std::swap(array[i], array[i - 1]);
				i--;
			}
			i = j;
		}
	}
}

int partition(std::vector<int> &array, int low, int high, int &swaps){
	int i = low - 1;
	int pivot = array[high];
	for(int j = low; j < high; j++){
		if(pivot >= array[j]){
            swaps++;
            i++;
			std::swap(array[i], array[j]);
		}
	}
	std::swap(array[i + 1], array[high]);
    swaps++;
    return i + 1;
}

void quickSort_Lomuto(std::vector<int> &array, int low, int high, int &swaps){
    if(low < high){
		int index = partition(array, low, high, swaps);
        quickSort_Lomuto(array, low, index - 1, swaps);
		quickSort_Lomuto(array, index + 1, high, swaps);
    }
}

int main(){
	int n;
	std::cin >> n;

	std::vector<int> array(n);
	for(int i = 0; i < n; i++)
		std::cin >> array[i];
    
    int shifts = 0;
	insertionSort(array, shifts);
    std::cout << shifts << std::endl;
    
    int swaps = 0;
    quickSort_Lomuto(array, 0, n - 1, swaps);
    std::cout << swaps << std::endl;
    
    std::cout << shifts - swaps;

    return 0;
}
