// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem

#include <vector>
#include <iostream>
#include <cmath>

int revDigits(int n){
	std::vector<int> array;
	while(n >= 1){
		array.push_back(n % 10);
		n = n / 10;
	}
	int ans = 0;
	int size = array.size() - 1;
	for(int i = 0; i < array.size(); i++){
		ans += array[i] * pow(10, size);
		size--;
	}
	return ans;
}

int calculate(int i, int j, int k){
	int count = 0;
	std::vector<int> array;
	// Store all numbers between i and j
	while(i <= j){
		array.push_back(i);
		i++;
	}
	// Check for whole numbers 
	
	for(int a = 0; a < array.size(); a++){
		float ans = (array[a] - revDigits(array[a])) / float(k);
		std::cout << array[a] << ", " << revDigits(array[a]) << std::endl;
		if(ans == int(ans))
			count++;
	}
	return count;
}


int main() {
    int i, j, k;
    std::cin >> i >> j >> k;
    std::cout << calculate(i, j, k);   
    return 0;
}
