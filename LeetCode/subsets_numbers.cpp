//https://leetcode.com/problems/subsets/#/description

#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
	void printVector(std::vector<std::vector<int>> array){
		for(int i = 0; i < array.size(); i++){
			for(int j = 0; j < array[i].size(); j++)
				std::cout << array[i][j] << " ";
			std::cout << std::endl;
		}
	}

    std::vector<std::vector<int>> subsets(std::vector<int> nums){
    	std::vector<std::vector<int>> ans;
    	// Total number of distinct combinations = 2^N
    	int N = nums.size();
    	int total = pow(2, N);
    	for(int i = 0; i < total; i++){
    		std::vector<int> temp;
    		for(int j = 0; j < N; j++){
    			if((i >> j) % 2 == 1)
    				temp.push_back(nums[j]);
    		}
    		ans.push_back(temp);
    	}
    	return ans;
    }
};

int main(){
	std::vector<int> nums = {1,2,3};

	Solution obj1;
	std::vector<std::vector<int>> subsets = obj1.subsets(nums);
	obj1.printVector(subsets);

	return 0;
}