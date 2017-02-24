// https://leetcode.com/problems/house-robber/?tab=Description

class Solution{
public:
    int rob(vector<int>& nums){
        // If nothing in list
        if(nums.size() == 0)
            return 0;
        // If only 1 item in list
        if(nums.size() == 1)
            return nums[0];
        // If only two items in list
        if(nums.size() == 2)
            return std::max(nums[0], nums[1]);
            
        // Else, more than 2 items
        vector<int> ans;
        ans.push_back(nums[0]);
        ans.push_back(std::max(nums[0], nums[1]));
        
        for(int i = 2; i < nums.size(); i++)
            ans.push_back(std::max(ans[i - 1], ans[i - 2] + nums[i]));
            
        return ans.back();
    }
};