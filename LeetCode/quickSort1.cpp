// https://www.hackerrank.com/challenges/quicksort1

#include <iostream>
#include <vector>

void printVector(std::vector<int> array){
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

std::vector<int> merge(std::vector<int> left, std::vector<int> right){
	std::vector<int> ans;
	for(int i = 0; i < left.size(); i++)
		ans.push_back(left[i]);
	for(int i = 0; i < right.size(); i++)
		ans.push_back(right[i]);
	return ans;
}

void quicksort1(std::vector<int> array){
	int pivot = array[0];
	std::vector<int> ans;
	std::vector<int> left, right;
	for(int i = 0; i < array.size(); i++){
		if(array[i] < pivot)
			left.push_back(array[i]);
		else
			right.push_back(array[i]);
	}

	ans = merge(left, right);
	array = ans;
	printVector(array);
}

int main(){
	int n;
	std::cin >> n;

	std::vector<int> array(n);
	for(int i = 0; i < n; i++)
		std::cin >> array[i];

	quicksort1(array);

	return 0;

}