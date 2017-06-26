//https://leetcode.com/problems/subsets/#/description

#include <iostream>
#include <vector>
#include <cmath>

class Solution{
public:
	void printVector(std::vector<std::vector<int>> array){
		for(int i = 0; i < array.size(); i++){
			std::cout << "{";
			for(int j = 0; j < array[i].size(); j++)
				std::cout << array[i][j];
			std::cout << "}" << std::endl;
		}
	}

	void printVector2(std::vector<int> array){
		for(int i = 0; i < array.size(); i++)
			std::cout << array[i] << " ";
		std::cout << std::endl;
	}

	// Bit manipulation
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

    // Without bit-manipulation
    // REF: https://discuss.leetcode.com/topic/19110/c-recursive-iterative-bit-manipulation-solutions-with-explanations
    std::vector<std::vector<int>> subsets2(std::vector<int> nums){
    	std::vector<std::vector<int>> ans(1, std::vector<int>());

    	for(int i = 0; i < nums.size(); i++){
    		int n = ans.size();
    		// j will keep the count of vector in ans
    		for(int j = 0; j < n; j++){
    			// Push the vector
    			ans.push_back(ans[j]);
    			// Push the number
    			ans.back().push_back(nums[i]);
    		}
    	}
    	return ans;
    }
};

int main(){
	std::vector<int> nums = {1,2,1};

	Solution obj1;
	std::vector<std::vector<int>> subsets = obj1.subsets2(nums);
	obj1.printVector(subsets);

	return 0;
}