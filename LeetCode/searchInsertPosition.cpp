// https://leetcode.com/problems/search-insert-position/#/description

#include <iostream>
#include <vector>

class Solution{
public:
    int searchInsert(std::vector<int> nums, int target){
        int low = 0, mid = 0;
        int high = nums.size() - 1;
        while(low <= high){
            mid = (low + high) / 2;
            if(target == nums[mid])
                return mid;
            else if(target > nums[mid])
                low = mid + 1;
            else if(target < nums[mid])
                high = mid - 1;
        }
        if(nums[mid] > target)
            return mid;
        else
            return mid + 1;
    }
};

int main(){
    Solution obj1;
    std::vector<int> array = {5,7,7,8,8,10};
    std::cout << obj1.searchInsert(array, 8);
    return 0;
}