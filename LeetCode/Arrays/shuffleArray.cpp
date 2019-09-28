// https://leetcode.com/problems/shuffle-an-array/


// Time complexity: O(n)
class Solution{
public:
    Solution(vector<int>& nums){
        array = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset(){
        return array;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle(){
        vector<int> nums = array;
        // Shuffle with equal probabilty
        for(int i = 0; i < nums.size(); i++){
            int randomIndex = rand()%nums.size();
            // Swap it
            swap(nums[i], nums[randomIndex]);
        }
        return nums;
    }
private:
    vector<int> array;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */