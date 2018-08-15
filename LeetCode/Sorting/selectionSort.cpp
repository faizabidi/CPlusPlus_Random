#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int> array){
	for(auto value : array)
		cout << value << " ";
	cout << endl;
}

// Best, worst, and avg. is O(nxn) time
// O(1) space
std::vector<int> SelectionnSort(std::vector<int> array){
	for(int i = 0; i < array.size(); i++){
		// Find the smallest and swap with array[i]
		int smallest = array[i], index = i;
		for(int j = i+1; j < array.size(); j++){
			if(array[j] < smallest){
				smallest = array[j];
				index = j;
			}
		}
		swap(array[i], array[index]);
	}
	return array;
}

int main(){
	std::vector<int> array = {1,4,0,2,-4,10,122,45,-89};
	//std::vector<int> array = {1,2,3,4};

	array = SelectionnSort(array);
	print(array);

	return 0;
}
