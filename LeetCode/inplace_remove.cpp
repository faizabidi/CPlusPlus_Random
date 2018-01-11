// https://leetcode.com/problems/remove-element/description/

#include <iostream>
#include <vector>

class Solution{
public:
	void printVector(std::vector<int> array){
		for(int i = 0; i < array.size(); i++)
			std::cout << array[i] << " ";
		std::cout << std::endl;
	}
    int removeElement(std::vector<int> &nums, int val){
    	// Edge case of empty vector
    	if(nums.size() == 0)
            return 0;

    	// Edge case when the element to be removed is not in the vector
    	if(std::find(nums.begin(), nums.end(), val) == nums.end())
    		return nums.size();

    	// We have to do this in-place. 
    	// Meaning that without using any temporary data structure
    	int len = 0;
    	for(int i = 0; i < nums.size(); i++){
    		printVector(nums);
    		bool found = false;
    		if(nums[i] == val){
    			for(int j = i + 1; j < nums.size(); j++){
    				if(nums[j] != val){
    					found = true;
    					std::swap(nums[i], nums[j]);
    					break;
    				}
    				// Else, all the elements left in the array are only the ones to be removed
    				else
    					found = false;
    			}
    			if(!found)
    				return i;
    		}
    	}
    	return 0;
    }
    // Better version
    int removeElement2(std::vector<int> &nums, int val){
    	int j = 0;
    	for(int i = 0; i < nums.size(); i++){
    		if(nums[i] != val){
    			std::swap(nums[i], nums[j]);
    			j++;
    		}
    	}
    	return j;
    }
};

int main(){
	std::vector<int> array = {3,2,2,3};
	//std::vector<int> array = {2,3};
	Solution obj1;
	std::cout << obj1.removeElement2(array, 3) << std::endl;

	return 0;
}
