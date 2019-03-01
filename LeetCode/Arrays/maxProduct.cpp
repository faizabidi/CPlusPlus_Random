// https://leetcode.com/problems/maximum-product-of-three-numbers/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // If all numbers are negative
        int size = nums.size();
        if(nums[size-1] < 0)
            return nums[size-1]*nums[size-2]*nums[size-3];
        // If there is at least 1 positive number
        int firstNum = nums[size-1];
        int case1 = nums[0]*nums[1];
        int case2 = nums[size-2]*nums[size-3];
        return max(firstNum*case1, firstNum*case2);
    }
};