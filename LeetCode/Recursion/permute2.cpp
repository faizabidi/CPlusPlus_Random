// https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    void permuteUniqueHelper(vector<vector<int>> &ans, vector<int> nums, set<vector<int>> &hashset, vector<int> temp, int index){
        if(index == nums.size()){
            auto it = hashset.find(temp);
            if(it == hashset.end()){
                hashset.insert(temp);
                ans.push_back(temp);
            }
            return;
        }
        for(int i = index; i < nums.size(); i++){
            temp.push_back(nums[i]);
            // Swap
            swap(nums[i], nums[index]);
            permuteUniqueHelper(ans, nums, hashset, temp, index+1);
            // Pop for back-tracking
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums){
        //sort(nums.begin(), nums.end());
        set<vector<int>> hashset;
        vector<vector<int>> ans;
        permuteUniqueHelper(ans, nums, hashset, {}, 0);
        return ans;
    }
};

