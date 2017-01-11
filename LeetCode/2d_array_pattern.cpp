// https://www.hackerrank.com/challenges/30-2d-arrays

#include <iostream>
#include <vector>

void inputArray(std::vector<std::vector<int> > &array2D){
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++)
			std::cin >> array2D[i][j];
	}
}

void printArray(std::vector<std::vector<int> > array2D){
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++)
			std::cout << array2D[i][j] << " ";
		std::cout << std::endl;
	}
}

int sumHourGlass(std::vector<std::vector<int> > array2D){
	int MAX_SUM = INT_MIN;
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			if(i + 2 < 6 && j + 2 < 6){
				int sum = 0;
				sum = array2D[i][j] + array2D[i][j+1] + array2D[i][j+2] + \
						  array2D[i+1][j+1] + \
						  array2D[i+2][j] + array2D[i+2][j+1] + array2D[i+2][j+2];
				if(sum > MAX_SUM)
					MAX_SUM = sum;
			}
		}
		
	}
	return MAX_SUM;
}

int main(){
	// Define a 6x6 matrix
	std::vector<std::vector<int> > array2D(6, std::vector<int>(6));
	
	std::cout << "Enter the 6x6 2D matrix" << std::endl;
	inputArray(array2D);

	std::cout << "Array entered is" << std::endl;
	printArray(array2D);

	std::cout << "Max. sum of all the hour glasses found = " \
		<< sumHourGlass(array2D) << std::endl;

	return 0;
}