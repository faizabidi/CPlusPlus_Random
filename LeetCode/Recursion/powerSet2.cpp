// https://leetcode.com/problems/subsets-ii/


// Time complexity - 2^n+ nlogn
class Solution {
public:
    void subsetsWithDupHelper(vector<vector<int>> &ans, vector<int> nums, vector<int> temp, int index){
        // Sort temo and check if already in ans
        sort(temp.begin(), temp.end());
        auto it = find(ans.begin(), ans.end(), temp);
        if(it == ans.end())
            ans.push_back(temp);
        
        if(index == nums.size())
            return;
        
        for(int i = index; i < nums.size(); i++){
            temp.push_back(nums[i]);
            subsetsWithDupHelper(ans, nums, temp, i+1);
            // And then backtrack
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        vector<vector<int>> ans;
        subsetsWithDupHelper(ans, nums, {}, 0);
        return ans;
    }
};

// Better solution withou sorting
// Time complexity - 2^n
class Solution {
public:
    void subsetsWithDupHelper(vector<vector<int>> &ans, vector<int> nums, vector<int> temp, int index){
        ans.push_back(temp);
        if(index == nums.size())
            return;
        
        for(int i = index; i < nums.size(); i++){
            if(i != index && nums[i-1] == nums[i])
                continue;
            temp.push_back(nums[i]);
            subsetsWithDupHelper(ans, nums, temp, i+1);
            // And then backtrack
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        subsetsWithDupHelper(ans, nums, {}, 0);
        return ans;
    }
};
