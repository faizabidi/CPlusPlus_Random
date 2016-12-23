// https://leetcode.com/problems/climbing-stairs/

#include <iostream>
#include <vector>

class Solution{
public:
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
};

int main(){
	Solution obj1;
	int num_stairs;
	std::cout << "Enter number of stairs: ";
	std::cin >> num_stairs;

	std::cout << obj1.climbStairs(num_stairs);

	return 0;
}