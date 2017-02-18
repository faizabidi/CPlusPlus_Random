// https://www.hackerrank.com/challenges/ctci-recursive-staircase

#include <iostream>
#include <vector>

// Recursion
int ways(int n){
	// Ref: https://github.com/charles-wangkai/hackerrank/blob/master/ctci-recursive-staircase/Solution.java
	// Ref: http://algorithms.tutorialhorizon.com/dynamic-programming-stairs-climbing-puzzle/
	if(n == 1)
		return 1;
	else if(n == 2)
		return 2;
	else if (n == 3)
		return 4;
	else
		return ways(n - 1) + ways(n - 2) + ways(n - 3);
}

// Non-recursive
int ways2(int n){
	int ppp = 0, pp = 1, p = 1;
	int sum = 0;
	for(int i = 0; i < n - 1; i++){
		sum = ppp + pp + p;
		ppp = pp;
		pp = p;
		p = sum;
	}
	return p;
}

// Dynamic programming
int ways3(int n){
	if(n == 1)
		return 1;
	else if(n == 2)
		return 2;
	else if (n == 3)
		return 4;
	std::vector<int> table(n);
	table[0] = 1;
	table[1] = 2;
	table[2] = 4;
	for(int i = 3; i < n; i++)
		table[i] = table[i - 1] + table[i - 2] + table[i - 3];
	return table.back();
}

int main(){
    int s;
    std::cin >> s;
    for(int i = 0; i < s; i++){
        int n;
        std::cin >> n;
        std::cout << ways3(n) << std::endl;
    }
    return 0;
}
