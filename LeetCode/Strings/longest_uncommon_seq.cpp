// https://leetcode.com/problems/longest-uncommon-subsequence-i/

class Solution {
public:
    int findLUSlength(string a, string b){
        // Different size
        if(a.size() != b.size())
            return max(a.size(), b.size());
        // Same strings
        if(a == b)
            return -1;
        // Same size, different strings
        // Let's try the longest possible string length
        // It won't be in the other string obviously
        return a.size();
        return 0;
    }
};