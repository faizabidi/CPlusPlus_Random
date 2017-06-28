#include <iostream>
#include <vector>

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

	// Backtracking
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> nums){
    	std::vector<std::vector<int>> ans;
    	std::vector<int> temp;
    	std::sort(nums.begin(), nums.end());
    	subsetsWithDup_helper(ans, nums, temp, 0);

    	return ans;
    }

private:
	void subsetsWithDup_helper(std::vector<std::vector<int>> &ans, 
		std::vector<int> nums, std::vector<int> temp, int index){
		
		if(std::find(ans.begin(), ans.end(), temp) == ans.end())
			ans.push_back(temp);

		for(int i = index; i < nums.size(); i++){
			temp.push_back(nums[i]);
			subsetsWithDup_helper(ans, nums, temp, i + 1);
			temp.pop_back();
		}

	}
};

int main(){
	std::vector<int> array = {1,2,2};

	Solution obj1;
	std::vector<std::vector<int>> ans = obj1.subsetsWithDup(array);
	obj1.printVector(ans);

	return 0;
}