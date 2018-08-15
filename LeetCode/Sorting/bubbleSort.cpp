#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int> array){
	for(auto value : array)
		cout << value << " ";
	cout << endl;
}


// Best is O(n) time
// Worst and avg. is O(nxn) time
// O(1) space
std::vector<int> BubbleSort(std::vector<int> array){
	for(int i = 1; i < array.size(); i++){
		bool flag = true;
		for(int j = 1; j < array.size() - i + 1; j++){
			if(array[j-1] > array[j]){
				swap(array[j-1], array[j]);
				flag = false;
			}
		}
		if(flag)
			return array;
	}
	return array;
}

int main(){
	std::vector<int> array = {1,4,0,2,-4,10,122,45,-89};
	//std::vector<int> array = {1,2,3,4};

	array = BubbleSort(array);
	print(array);

	return 0;
}
