// https://leetcode.com/contest/leetcode-weekly-contest-39/problems/sum-of-square-numbers/

#include <iostream>
#include <cmath>

class Solution{
public:
    bool judgeSquareSum(int c){
        for(int i = 0; i <= sqrt(c); i++){
            int sum_left = (c - i*i);
            if(sqrt(sum_left) == floor(sqrt(sum_left))){
                for(int j = i; j <= sqrt(sum_left); j++){
                    if(i*i + j*j > c)
                    	break;
                    if(i*i + j*j == c)
                        return true;
                }
            }
        }
        return false;
    }
};

int main(){
	Solution obj1;
	if(obj1.judgeSquareSum(5))
		std::cout << "True\n";
	else
		std::cout << "False\n";

	return 0;
}