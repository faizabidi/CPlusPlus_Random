// https://leetcode.com/problems/di-string-match/description/

class Solution {
public:
    vector<int> diStringMatch(string S){
        int smallest = 0, largest = S.size();
        vector<int> combination;
        for(int i = 0; i < S.size(); i++){
            if(S[i] == 'I'){
                combination.push_back(smallest);
                smallest++;
            }
            else{
                combination.push_back(largest);
                largest--;
            }
        }
        if(S[S.size() - 1] == 'I')
            combination.push_back(largest);
        else
            combination.push_back(smallest);
        return combination;
    }
};