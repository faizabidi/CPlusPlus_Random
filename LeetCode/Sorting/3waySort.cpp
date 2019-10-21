// https://leetcode.com/problems/sort-colors/

// Time: O(n)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size()-1, index = 0;
        while(index <= high){
            if(nums[index] == 0){
                swap(nums[index], nums[low]);
                low++, index++;
            }
            else if(nums[index] == 1)
                index++;
            else{
                swap(nums[index], nums[high]);
                high--;
            }
        }
    }
};


// Using for loop
// Time: O(n)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        for(int i = 0; i < nums.size(); i++){
            if(i > high)
                break;
            if(nums[i] == 0){
                swap(nums[i], nums[low]);
                low++;
            }
            else if(nums[i] == 2){
                swap(nums[high], nums[i]);
                i--, high--;
            }
        }
    }
};
