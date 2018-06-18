// https://leetcode.com/problems/letter-case-permutation/description/


// O(m*2^n)
class Solution {
public:
    void letterCasePermutation_helper(string S, int index, 
        vector<string> &ans, string temp){

        if(index == S.size()){
            if(find(ans.begin(), ans.end(), temp) == ans.end())
                ans.push_back(temp);
            return;
        }
        // Make uppercase
        letterCasePermutation_helper(S, index+1, ans, 
                                temp + char(toupper(S[index])));

        // Make lowercase
        letterCasePermutation_helper(S, index+1, ans, 
                                temp + char(tolower(S[index])));

    }
    vector<string> letterCasePermutation(string S){
        vector<string> ans;
        string temp = "";
        letterCasePermutation_helper(S, 0, ans, temp);
        return ans;
    }
};