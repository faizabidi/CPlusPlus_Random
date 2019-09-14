// https://leetcode.com/problems/letter-combinations-of-a-phone-number/


// Time complexity = O(3^n * 4^m) where n = 3 digit letters and m = 4 digit letters like 7 and 9
// Space complexity = O(3^n * 4^m))

class Solution{
public:
    void letterCombinationsHelper(vector<string> &ans, vector<string> allStrings, string temp, int index){
        // Base condition
        if(index == allStrings.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < allStrings[index].size(); i++){
            temp.push_back(allStrings[index][i]);
            letterCombinationsHelper(ans, allStrings, temp, index+1);
            temp.pop_back(); // For backtracking
        }
    }
    
    vector<string> letterCombinations(string digits){
        if(digits.size() == 0)
            return {};
        vector<string> allStrings;
        for(int i = 0; i < digits.size(); i++){
            if(digits[i] == '2')
                allStrings.push_back("abc");
            if(digits[i] == '3')
                allStrings.push_back("def");
            if(digits[i] == '4')
                allStrings.push_back("ghi");
            if(digits[i] == '5')
                allStrings.push_back("jkl");
            if(digits[i] == '6')
                allStrings.push_back("mno");
            if(digits[i] == '7')
                allStrings.push_back("pqrs");
            if(digits[i] == '8')
                allStrings.push_back("tuv");
            if(digits[i] == '9')
                allStrings.push_back("wxyz");
        }
        vector<string> ans;
        letterCombinationsHelper(ans, allStrings, "", 0);
        return ans;
        return {};
    }
};