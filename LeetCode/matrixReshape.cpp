#include <iostream>
#include <vector>

class Solution{
public:
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& nums, int r, int c) {
        int rows = nums.size();
        int cols = nums[0].size();
        if(r * c != rows * cols)
            return nums;
        
        // Store all numbers in an array
        std::vector<int> numbers;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++)
                numbers.push_back(nums[i][j]);
        }
        
        // Store the numbers in a vector of vectors
        int k = 0;
        std::vector<std::vector<int>> ans;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                ans[i][j] = numbers[k];
                k++;
            }
        }
        return ans;
    }
};

int main(){
    Solution obj1;
    return 0;
}