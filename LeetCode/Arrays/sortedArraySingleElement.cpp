// https://leetcode.com/problems/single-element-in-a-sorted-array/
/*
Given a sorted array consisting of only integers where every element appears exactly twice except for one element which appears exactly once. Find this single element that appears only once.


Input: [1,1,2,3,3,4,4,8,8]
Output: 2

1. lo = 0; hi = 9; mid = 9/2 = 4
a[4] = 3
Go right

2. lo = 4, hi = 9; mid = 


Input: [3,3,7,7,10,11,11]
Output: 10

Note: Your solution should run in O(log n) time and O(1) space.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int singleNonDuplicate(vector<int> nums){
        // Idea is this - https://leetcode.com/problems/single-element-in-a-sorted-array/discuss/100754/Java-Binary-Search-short-(7l)-O(log(n))-w-explanations
        int start = 0, end = nums.size() - 1;
        while(start < end){
            cout << start << ", " << end << endl;
            int mid = (start + end) / 2;
            // If mid is odd, go left
            if(mid % 2 == 1)
                mid--;
            // If not, check the number next to it.
            // If it's not equal, the number should be on the left side of the array
            if(mid + 1 < nums.size() && nums[mid] != nums[mid+1])
                end = mid;
            // If it's same, jump start by two places since the numbers appear in pairs
            else
                start += 2;
        }
        return nums[start];
    }
};



int main(){
    Solution obj1;
    //vector<int> array = {1,1,2,3,3,4,4,8,8};
    //vector<int> array = {3,3,7,7,10,11,11};
    //vector<int> array = {1,1,2};
    vector<int> array = {1};
    cout << obj1.singleNonDuplicate(array) << endl;

    return 0;
}
