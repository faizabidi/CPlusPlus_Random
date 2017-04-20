// https://leetcode.com/problems/search-for-a-range/#/description

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        bool flag = false;
        std::vector<int> ans;
        int low = 0, mid = 0;
        int high = nums.size() - 1;
        
        // Find the lower bound
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid] == target){
                flag = true;
                int j = mid;
                while(nums[j - 1] == target && j >= 0)
                    j--;
                if( j < 0)
                    j = 0;
                ans.push_back(j);
                break;
            }
            if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        if(!flag){
            ans = {-1, -1};
            return ans;
        }
        
        // Find the upper bound
        low = 0, mid = 0;
        high = nums.size() - 1;
        target += 1;
        flag = false;
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid] == target){
                flag = true;
                int j = mid;
                while(nums[j - 1] == target && j >= 0)
                    j--;
                ans.push_back(j - 1);
                break;
            }
            if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        if(!flag){
            if(nums[mid] > target)
                ans.push_back(mid - 1);
            else
                ans.push_back(mid);
        }
        return ans;
    }
};