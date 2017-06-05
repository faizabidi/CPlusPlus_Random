// https://www.hackerrank.com/challenges/insertionsort1

#include <iostream>
#include <vector>

template <typename T>
void printVector(std::vector<T> array){
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

void insertionsort1(std::vector<int> array){
	int unsorted = array.back();
	int position = 0;
	for(int i = array.size() - 1; i >= 0; i--){
		if(unsorted < array[i]){
			array[i + 1] = array[i];
			position = i;
			printVector(array);
		}
	}
	array[position] = unsorted;
	printVector(array);
}

int main(){
	int n;
	std::cin >> n;

	std::vector<int> array(n);
	for(int i = 0; i < n; i++)
		std::cin >> array[i];

	insertionsort1(array);

	return 0;
}