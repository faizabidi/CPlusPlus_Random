// https://leetcode.com/problems/climbing-stairs/

#include <iostream>
#include <vector>

class Solution{
public:

    // Iterative
    int climbStairs(int n){
    	int first = 0;
    	int second = 1;
    	int third = 0;
    	
    	for(int i = 0; i < n; i++){
    		third = first + second;
    		first = second;
    		second = third;
    	}
    	return third;
    }

    // Recursive
    int climbStairs2(int n){
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

int main(){
	Solution obj1;
	int num_stairs;
	std::cout << "Enter number of stairs: ";
	std::cin >> num_stairs;

	std::cout << obj1.climbStairs2(num_stairs);

	return 0;
}