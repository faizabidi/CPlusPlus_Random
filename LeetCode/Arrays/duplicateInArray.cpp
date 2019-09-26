// http://keithschwarz.com/interesting/code/?dir=find-duplicate

// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        // Find the intersection point
        while(1){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast)
                break;
        }
        
        // Move forward till we hit slow
        int finder = 0;
        while(1){
            slow = nums[slow];
            finder = nums[finder];
            if(slow == finder)
                return slow;
        }
        return slow;
    }
};


// A tricky way to binary search
class Solution {
public:
    int findDuplicate(vector<int>& nums){
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = (low+high)/2;
            // Count how many numbers less than equal to mid's value not nums[mid]'s value
            int count = 0;
            // O(n) time
            for(auto value : nums){
                if(value <= mid)
                    count++;
            }
            // According to the Pigeonhole principle, let's say that if mid = 2 and we found 
            // 3 items less than 2, it clearly means that one of those 3 items must be a duplicate
            // Note that this is only so because as per the question, it's an array containing 
            // integers between 1 and n.
            // If count <= mid, it means that 1,2 are not duplicated in the array. Which leaves us
            // with 3,4,5 assuming the size of the array is 5.
            if(count <= mid)
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
};
