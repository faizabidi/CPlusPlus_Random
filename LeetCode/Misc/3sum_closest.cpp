// https://leetcode.com/problems/3sum-closest/description/


// O(nxn)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if(nums.size() < 3)
            return 0;
        int closest = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2; i++){
            int low = i + 1, high = nums.size() - 1;
            while(low < high){
                int sum = nums[i] + nums[low] + nums[high];
                if(sum == target)
                    return target;
                if(abs(target - sum) < abs(target - closest))
                        closest = sum;
                else if(sum > target)
                    high--;
                else if(sum < target)
                    low++;
            }
        }
        return closest;
    }
};