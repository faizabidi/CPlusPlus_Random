// https://leetcode.com/problems/climbing-stairs/description/
// O(n) time and O(n) space
// Memoized solution

class Solution {
public:
    int climbStairs_helper(map<int, int> &hashmap, int n){
        // Base cases
        // No more stairs left to climb, reached at the top
        if(n == 0)
            return 1;
        // When climbed more than needed
        if(n < 0)
            return 0;
        // Check if in hashmap
        if(hashmap[n]){
            cout << "Was already in hashmap\n";
            return hashmap[n];
        }
        else{
            // Climbed 1 step, left = n - 1
            int oneStep = climbStairs_helper(hashmap, n - 1);
            // Climbed 2 steps, left = n - 2
            int twoSteps = climbStairs_helper(hashmap, n - 2);
            cout << "Adding " << n << " to hashmap\n";
            hashmap[n] = oneStep+twoSteps;
        }
        return hashmap[n];
    }
    int climbStairs(int n){
        map<int, int> hashmap;
        int ways = climbStairs_helper(hashmap, n);
        return ways;
    }
};