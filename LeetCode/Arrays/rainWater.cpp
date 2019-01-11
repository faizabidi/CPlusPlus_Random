// https://leetcode.com/problems/trapping-rain-water/description/

// O(n^2) time and O(1) space
class Solution {
public:
    int trap(vector<int>& height){
        if(height.size() < 2)
            return 0;
        int water = 0;
        for(int i = 0; i < height.size(); i++){
            if(i == 0 || i == height.size() - 1)
                continue;
            else{
                // Find left max
                int left_max = *max_element(height.begin(), height.begin() + i);
                // Find right max
                int right_max = *max_element(height.begin()+i, height.end());
                if(min(left_max, right_max) - height[i] > 0)
                    water += min(left_max, right_max) - height[i];
            }
        }
        return water;
    }
};


// O(n) time and O(2n) space
class Solution {
public:
    int trap(vector<int>& height){
        if(height.size() < 2)
            return 0;
        int water = 0;
        vector<int> left(height.size(), -1), right(height.size(), -1);
        // Find max left side
        left[0] = height[0];
        for(int i = 1; i < height.size(); i++)
            left[i] = max(left[i-1], height[i]);
        // Find max right
        right[height.size()-1] = height[height.size()-1];
        for(int i = height.size() - 2; i >= 0; i--)
            right[i] = max(right[i+1], height[i]);
        // Find the water that can be stored
        for(int i = 0; i < height.size(); i++){
            int value = min(left[i], right[i]) - height[i];
            if(value > 0)
                water += value;
        }
        return water;
    }
};

