// https://leetcode.com/problems/is-subsequence/


// O(n) time and O(1) space
class Solution {
public:
    bool isSubsequence(string s, string t){
        if(s.size() < 1)
            return true;
        for(int i = 0; i < t.size(); i++){
            if(t[i] == s[0]){
                int j = i+1, k = 1;
                while(j < t.size() && k < s.size()){
                    if(t[j] == s[k])
                        k++;
                    j++;
                }
                if(k != s.size())
                    return false;
                else
                    return true;
            }
        }
        return false;
    }
};