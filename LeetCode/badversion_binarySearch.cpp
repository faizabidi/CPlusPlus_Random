// https://leetcode.com/problems/first-bad-version/#/description

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n){
        int low = 1, mid = 0, high = n;
        while(low <= high){
            mid = low + (high - low) / 2;
            // If bad version found
            if(isBadVersion(mid))
                high = mid - 1;
            // If not a bad version
            else
                low = mid + 1;
        }
        return low;
    }
};