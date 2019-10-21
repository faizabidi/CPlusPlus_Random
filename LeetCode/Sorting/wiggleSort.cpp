// https://leetcode.com/problems/wiggle-sort/


// Time: O(n)
class Solution{
public:
    void wiggleSort(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            // Even index
            if(i%2 == 0 && i+1 < nums.size()){
                if(nums[i] > nums[i+1])
                    swap(nums[i], nums[i+1]);
            }
            // Odd index
            else{
                if(i+1 < nums.size()){
                    if(nums[i] < nums[i+1])
                        swap(nums[i], nums[i+1]);
                }
            }
        }
    }
};
