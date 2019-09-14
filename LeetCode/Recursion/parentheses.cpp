// https://leetcode.com/problems/generate-parentheses/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Time complexity - hard to find it. As per the solutions people posted, it would be (4^n)/(n*sqrt(n))

// But if I was to make all possible permutations without using open and close concept, time complexity would be O(2^(2n) * n).
class Solution{
public:
    // Check if a valid parentheses
    bool check(string str){
        stack<char> s;
        int i = 0;
        while(i < str.size()){
            // If an opening bracket
            if(str[i] == '(')
                s.push(str[i]);
            // If a closing bracket
            else if(str[i] == ')'){
                // If stack is empty, just add this closing bracket
                if(s.empty())
                    s.push(str[i]);
                else{
                    // Check what's at the top of the stack
                    char ch = s.top();
                    // If an opening bracket, just pop it
                    if(ch == '(')
                        s.pop();
                    // Else, add this closing bracket to the stack
                    else
                        s.push(str[i]);
                }   
            }
            i++;
        }
        // If stack is not empty, it's not a valid parentheses
        if(!s.empty())
            return false;
        return true;
    }

    void generateParenthesisHelper(vector<string> &ans, int n, 
        string temp, int index, int open, int close){
        
        // If the number of opening or closing bracket will be more than n it would mean an invalid combination
        if(open > n || close > n)
            return;
        
        if(index == n*2){
            // If a valid permutation
            if(check(temp) && temp.size() == n*2)
                ans.push_back(temp);
            return;
        }

        temp.push_back('(');
        generateParenthesisHelper(ans, n, temp, index+1, open+1, close);
        temp.pop_back();
        temp.push_back(')');
        generateParenthesisHelper(ans, n, temp, index+1, open, close+1);
    }

    vector<string> generateParenthesis(int n){
        // Generate all valid possibilities
        vector<string> ans;
        string temp;
        generateParenthesisHelper(ans, n, temp, 0, 0, 0);
        return ans;
    }
};

int main(){
    Solution obj1;

    vector<string> ans = obj1.generateParenthesis(10);
    for(auto value : ans)
        cout << value << endl;
    return 0;
}
