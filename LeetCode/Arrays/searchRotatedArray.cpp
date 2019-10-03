// https://leetcode.com/problems/search-in-rotated-sorted-array/


// Time: log(n)
class Solution{
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            // If found
            if(nums[mid] == target)
                return mid;
            // Check which side of the array os sorted - left or right of mid
            bool flag = false;
            if(nums[low] <= nums[mid])
                flag = true;
            // If flag is true it means that the left side of the array is sorted
            if(flag){
                if(target >= nums[low] && target < nums[mid])
                    high = mid-1;
                else
                    low = mid+1;
            }
            else{
                if(target > nums[mid] && target <= nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return -1;
    }
};
