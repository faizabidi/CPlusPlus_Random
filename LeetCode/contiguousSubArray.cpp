// https://leetcode.com/problems/contiguous-array/#/description

#include <iostream>
#inlcude <vector>

class Solution {
public:
    int findMaxLength(std::vector<int> nums){
        int ans;
        for(int i = 0; i < nums.size(); i++){
        	int sum ;
        	if(nums[i] == 0)
        		sum = -1;
        	else
        		sum = 0;
        	for(int j = i + 1; j < nums.size(); j++){
        		if(nu)
        		sum += nums[j];
        		if(sum == 0)
        			ans = j + 1;
        	}
        }
    }
};

int main(){
	std::cout << "Enter the length of the array:";
	int len;
	std::cin >> len;

	std::cout << "Enter the array:";
	std::vector<int> array(len);

	for(int i = 0; i < len; i++)
		std::cin >> array[i];

	std::cout << findMaxLength(array);

	return 0;
}
