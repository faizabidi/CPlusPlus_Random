#include <iostream>
#include <vector>

// Recursive solution
int fib_recursive(int n){
	if(n <= 1)
		return n;
	return fib_recursive(n - 2) + fib_recursive(n - 1);
}

// Memoization or top-down - build table on demand
int fib_memoization(int n, std::vector<int> &table){
	if(n <= 1)
		return n;
	// Check if not in table
	if(table[n - 1] == -1)
		table[n - 1] = fib_memoization(n - 2, table) + 
						fib_memoization(n - 1, table);
	// If in table, return that
	return table[n -1];
}

int main(){
	int n;
	std::cin >> n;
	//std::cout << fib_recursive(n) << std::endl;
	std::vector<int> table(n);
	// Initialize the table
	for(int i = 0; i < n; i++)
		table[i] = -1;
	std::cout << fib_memoization(n, table) << std::endl;
	return 0;
}