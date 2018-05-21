//

#include <iostream>
#include <vector>

void print(std::vector<int> array){
	for(auto value : array)
		std::cout << value << " ";
	std::cout << std::endl;
}

void flip(std::vector<int> &array, int k){
	std::reverse(array.begin(), array.begin()+k+1);
}


// O(nxn)
void pancakeSort(std::vector<int> &array){
	// Flip at the max element and then flip at the last element
	// This will make sure that the biggest element goes to the end
	int j = 0;
	for(int i = array.size() - 1; i >= 0; i--){
		auto max = std::max_element(array.begin(), array.end() - j++);
		int max_index = std::distance(array.begin(), max);
		// Flip at this index
		flip(array, max_index);
		// Flip again at the end
		flip(array, i);
	}
}

int main(){
	//std::vector<int> array = {5, 4, 3, 2, 1};
	std::vector<int> array = {-5, 4, 0, 16, 1};


	pancakeSort(array);
	print(array);

	return 0;
}
