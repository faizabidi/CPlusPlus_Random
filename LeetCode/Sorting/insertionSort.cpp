#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int> array){
	for(auto value : array)
		cout << value << " ";
	cout << endl;
}


// Best is O(n) for sorted array
// Worst and avg. is O(nxn) time
// O(1) space
// Better than bubble sort
std::vector<int> InsertionSort(std::vector<int> array){
	for(int i = 1; i < array.size(); i++){
		if(array[i] < array[i-1]){
			int j = i;
			while(array[j] < array[j-1] && j > 0){
				swap(array[j], array[j-1]);
				j--;
			}
		}
	}
	return array;
}

int main(){
	std::vector<int> array = {1,4,0,2,-4,10,122,45,-89};
	//std::vector<int> array = {1,2,3,4};

	array = InsertionSort(array);
	print(array);

	return 0;
}