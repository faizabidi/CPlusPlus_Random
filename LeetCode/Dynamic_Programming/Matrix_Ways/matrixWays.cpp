#include <iostream>
#include <vector>


// Brute force
// O(2^n) time and O(n) space becasue of recursion stack
int ways_helper(int n, int i, int j){
	// If you reach the destination
	if(i == n - 1 && j == n - 1)
		return 1;
	// If you go out of the matrix
	if(i == n || j == n)
		return 0;
	// Include the right and top block
	int right =  ways_helper(n, i, j+1);
	int top = ways_helper(n, i+1, j);
	return right + top;
}

int ways(int n){
	int count = ways_helper(n, 0, 0);
	return count;
}

int main(){
	int n = 3;
	std::cout << ways(n);

	return 0;
}