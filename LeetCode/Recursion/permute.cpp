// https://leetcode.com/problems/permutations/

// Time complexity - O(n!)
// SPace complexity - O(n) because of recursion
class Solution {
public:
    void permuteHelper(vector<vector<int>> &ans, vector<int> nums, vector<int> temp, int index){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = index; i < nums.size(); i++){
            temp.push_back(nums[i]);
            // Swap to bring the index's value to the ith position
            swap(nums[i], nums[index]);
            permuteHelper(ans, nums, temp, index+1);
            temp.pop_back(); // For backtracking
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permuteHelper(ans, nums, {}, 0);
        return ans;
    }
};