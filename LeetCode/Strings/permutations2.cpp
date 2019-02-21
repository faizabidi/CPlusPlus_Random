// https://leetcode.com/problems/permutations-ii/#/description

#include <iostream>
#include <vector>
#include <map>

class Solution{
public:
    void printVector(std::vector<std::vector<int>> array){
        for(int i = 0; i < array.size(); i++){
            for(int j = 0; j < array[i].size(); j++)
                std::cout << array[i][j] << " ";
            std::cout << std::endl;
        }
    }

    std::vector<std::vector<int>> permuteUnique(std::vector<int> nums){
        std::vector<std::vector<int>> ans;
        // One solution to keep track of duplicates is to keep checking the vector ans for duplicates. 
        // Better solution is to sort the vector nums and that way, the dupliactes would be consecutively placed.
        // REF: https://stackoverflow.com/questions/6917832/permutation-of-string-letters-how-to-remove-repeated-permutations
        std::sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++)
            std::cout << nums[i] << " ";
        std::cout << "\nHello\n";
        permuteUnique_helper(ans, nums, 0, nums.size() - 1);
        return ans;
    }

private:
    void permuteUnique_helper(std::vector<std::vector<int>> &ans, 
        std::vector<int> nums, int index, int size){

        // If it does not exist in the map and index = size
        if(index == size)
            ans.push_back(nums);
        else{
            for(int i = index; i <= size; i++){
                // If i is not equal to index and still the values of both in vector nums is same, don't permute
                std::cout << i << "," << index << std::endl;
                if(i != index && nums[i] == nums[index]){
                    std::cout << "Same. Not permuting\n";
                    continue;
                }
                std::swap(nums[index], nums[i]);                
                permuteUnique_helper(ans, nums, index + 1, size);
                // Backtrack to the original string
                //std::swap(nums[index], nums[i]);
            }
        }
    }
};

int main(){
    //std::vector<int> nums = {1,1,2};
    std::vector<int> nums = {2,1,3};
    Solution obj1;
    std::vector<std::vector<int>> ans = obj1.permuteUnique(nums);
    obj1.printVector(ans);
    return 0;
}
