//https://leetcode.com/problems/letter-case-permutation/description/

class Solution {
public:
    // O(2^n) time and O(possible combinations) space
    void helper(string str, vector<string> &combinations, int i){
        // Add to combinations if not there already
        auto it = find(combinations.begin(), combinations.end(), str);
        if(it == combinations.end())
            combinations.push_back(str);
        // Base case
        if(i == str.size())
            return;
        // Check if it is an alphabetic character
        if(isalpha(str[i])){
            // Run as lower case
            str[i] = tolower(str[i]);
            helper(str, combinations, i+1);
            // Run as upper case
            str[i] = toupper(str[i]);
            helper(str, combinations, i+1);
        }
        else
            helper(str, combinations, i+1);
    }
    // Main function
    vector<string> letterCasePermutation(string S){
        if(S.size() == 0)
            return {""};
        vector<string> combinations;
        helper(S, combinations, 0);
        return combinations;
    }
};