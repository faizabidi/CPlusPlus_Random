// REF: http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/

#include <iostream>
#include <vector>

// Recursive
int ways(std::vector<int> array, int n, int sum){
	// If target sum = 0, solution found!
	if(sum == 0)
		return 1;
	// If target sum < 0 or coins <= 0, no solutions exists
	if(sum < 0 || n <= 0)
		return 0;
	// Include the coin or exclude the coin
	return ways(array, n, sum - n) + ways(array, n - 1, sum);
}

// TODO: Dynamic programming

int main(){
	int n;
	std::cin >> n;
	std::vector<int> array(n);
	for(int i = 0; i < n; i++)
		std::cin >> array[i];
	int sum;
	std::cin >> sum;
	std::cout << ways(array, n, sum);
}