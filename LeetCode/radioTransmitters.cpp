// https://www.hackerrank.com/challenges/hackerland-radio-transmitters

#include <vector>
#include <iostream>
#include <algorithm>

void printVector(std::vector<int> array){
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

// If the houses were consecutively placed
int radio_transmitters1(std::vector<int> array, int range){
	int radios = 0;
	int smallest = *std::min_element(array.begin(), array.end());
	int biggest = *std::max_element(array.begin(), array.end());
	int num_elements = biggest - smallest + 1;
	
	std::cout << "Number of elements = " << num_elements << std::endl;
	
	int sum = 0;
	while(sum < num_elements){
		sum += (2 * range + 1);
		radios++;
	}
	return radios;
}


// Houses are not consecutively placed
int radio_transmitters2(std::vector<int> array, int range){
	int radios = 0;
	std::sort(array.begin(), array.end());
	printVector(array);
	for(int i = 0; i < array.size(); i++){
		// Check if (array[i] + range) exists
		if(std::find(array.begin(), array.end(), array[i] + range) != array.end()){
			std::cout << array[i] + range << " exists in the array!\n";
			std::cout << "Installed transmitter at " << array[i] + range << std::endl;
			radios++;
			// Delete all numbers within the range of array[i] + 2 * range
			int value = array[i] + 2 * range;
			std::vector<int> temp;
			for(int j = 0; j < array.size(); j++){
				if(array[j] > value)
					temp.push_back(array[j]);
			}
			// Copy temp back to array
			array = temp;
			std::cout << "New array = ";
			printVector(array);
			// Re-initialize i
			i = -1;
		}
		else{
			// Check if any number greater than array[i] but less than array[i] + range exists
			int value = array[i] + range - 1;
			bool flag = false;
			while(value > array[i]){
				// Check if this value exists
				if(std::find(array.begin(), array.end(), value) != array.end()){
					flag = true;
					break;
				}
				value--;
			}
			// If some value exists
			if(flag){
				radios++;
				std::cout << value << " exists in the array!\n";
				std::cout << "Installed transmitter at " << value << std::endl;
				std::vector<int> temp;
				value += range;
				for(int j = 0; j < array.size(); j++){
					if(array[j] > value)
						temp.push_back(array[j]);
				}
				// Copy temp back to array
				array = temp;
				std::cout << "New array = ";
				printVector(array);
				// Re-initialize i
				i = -1;
			}
			else{
				radios++;
				std::cout << "Installed transmitter at " << value << std::endl;
				std::vector<int> temp;
				for(int j = 0; j < array.size(); j++){
					if(array[j] > value)
						temp.push_back(array[j]);
				}
				// Copy temp back to array
				array = temp;
				std::cout << "New array = ";
				printVector(array);
				// Re-initialize i
				i = -1;
			}
		}
	}
	return radios;
}

int main() {
    int n;
    std::cin >> n;

    int range;
    std::cin >> range;

    std::vector<int> array(n);
    for(int i = 0; i < n; i++)
    	std::cin >> array[i];

    std::cout << radio_transmitters2(array, range);  
    return 0;
}
