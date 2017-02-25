// https://www.hackerrank.com/challenges/equal

#include <iostream>
#include <vector> 
#include <algorithm>

bool checkSameValues(std::vector<int> array){
	for(int i = 0; i < array.size() - 1; i++){
		if(array[i] != array[i + 1])
			return false;
	}
	return true;
}

void addValue(std::vector<int> &array, int value){
	for(int i = 0; i < array.size(); i++)
		array[i] += value;
}

void printArray(std::vector<int> array){
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

int minOps(std::vector<int> array){
	int count = 0;
	int t = 0;
	// While all values are not same in the array
	while(true){
		std::vector<int>::iterator max, min;

		max = std::max_element(array.begin(), array.end());
		min = std::min_element(array.begin(), array.end());
		
		int max_position = distance(array.begin(), max);
		int min_position = distance(array.begin(), min);


		if(*max - *min >= 3){
			std::cout << "Adding 5\n";
			// ADD 5 to each element except the max one
			addValue(array, 5);
			// Subtract 5 from the max value
			array[max_position] -= 5;
		}
		else if(*max - *min < 5 && *max - *min > 1){
			std::cout << "Adding 2\n";
			//ADD 2 to each element except the max one
			addValue(array, 2);
			// Subtract 2 from the max value
			array[max_position] -= 2;
		}
		else{
			std::cout << "Adding 1\n";
			// ADD 1 to each element except the max one
			addValue(array, 1);
			// Subtract 1 from the max value
			array[max_position] -= 1;
		}
		count++;
		printArray(array);
		// Check if all values in the vector are same
		if(checkSameValues(array))
			break;
	}
	/*while(!checkSameValues(array)){
		std::vector<int>::iterator max, min;

		max = std::max_element(array.begin(), array.end());
		min = std::min_element(array.begin(), array.end());
		
		int max_position = distance(array.begin(), max);
		int min_position = distance(array.begin(), min);


		if(*max - *min >= 3){
			std::cout << "Adding 5\n";
			// ADD 5 to each element except the max one
			addValue(array, 5);
			// Subtract 5 from the max value
			array[max_position] -= 5;
		}
		else if(*max - *min < 5 && *max - *min > 1){
			std::cout << "Adding 2\n";
			//ADD 2 to each element except the max one
			addValue(array, 2);
			// Subtract 2 from the max value
			array[max_position] -= 2;
		}
		else{
			std::cout << "Adding 1\n";
			// ADD 1 to each element except the max one
			addValue(array, 1);
			// Subtract 1 from the max value
			array[max_position] -= 1;
		}
		count++;
		printArray(array);
	}*/
	return count;
}

int main(){
	int testCases;
	std::cin >> testCases;

	while(testCases-- > 0){
		int num;
		std::cout << "Number of colleagues:";
		std::cin >> num;

		std::cout << "Enter chocolates each colleague has:";
		std::vector<int> array(num);
		for(int i = 0; i < num; i++)
			std::cin >> array[i];

		std::cout << "Minimum operations = " << minOps(array) << std::endl;
	}
    return 0;
}
