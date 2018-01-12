// https://leetcode.com/problems/palindrome-number/description/

#include <iostream>

class Solution {
public:
    bool isPalindrome(int x){
        // Edge case of negative numbers
        if (x < 0)
        	return false;
        // Find out the reversed number
        int reversed = 0;
        int temp = x;
        while(temp > 0){
        	reversed = reversed * 10 + temp % 10;
        	temp /= 10;
        }
        std::cout << reversed << std::endl;
        if(x == reversed)
        	return true;
        return false;
    }
};

int main(){
	Solution obj1;
	std::cout << obj1.isPalindrome(1001);
	return 0;
}