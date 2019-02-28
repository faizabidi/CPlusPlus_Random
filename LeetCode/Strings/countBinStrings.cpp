// https://leetcode.com/problems/count-binary-substrings/

class Solution {
public:
    int countBinarySubstrings(string s){
        int ans = 0;
        // Make groups
        vector<int> groups;
        for(int i = 0; i < s.size(); i++){
            int j = i+1, count = 1;
            while(j < s.size() && s[j] == s[i])
                count++, j++;
            i = j - 1;
            groups.push_back(count);
        }
        // Go through the groups to find the minimum
        for(int i = 0; i < groups.size(); i++){
            if(i+1 < groups.size())
                ans += min(groups[i], groups[i+1]);
        }
        return ans;
    };
};