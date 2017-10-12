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

// Tabulation or bottom-up - build the damn table upfront
int fib_tabulation(int n){
	if(n == 0)
		return 0;
	std::vector<int> table(n);
	// Initialize the table
	for(int i = 0; i < n; i++)
		table[i] = -1;
	// Build the table
	for(int i = 0; i < n; i++){
		if(i == 0 || i == 1)
			table[i] = 1;
		if(table[i] == -1)
			table[i] = table[i - 2] + table[i - 1];
	}
	return table[n - 1];
}

int main(){
	int n;
	std::cin >> n;
	// Recursive
	//std::cout << fib_recursive(n) << std::endl;
	// Memoization
	std::vector<int> table(n);
	// Initialize the table
	for(int i = 0; i < n; i++)
		table[i] = -1;
	//std::cout << fib_memoization(n, table) << std::endl;
	// Tabulation
	std::cout << fib_tabulation(n) << std::endl;
	return 0;
}
