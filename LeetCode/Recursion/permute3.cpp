// https://leetcode.com/problems/permutation-sequence/


class Solution{
public:
    void getPermutationHelp(vector<string> &permutations, string str, string temp, int index, int &k){
        if(index == str.size()){
            k--;
            permutations.push_back(temp);
            return;
        }
        if(k == 0)
            return;
        for(int i = index; i < str.size(); i++){
            temp.push_back(str[i]);
            swap(str[i], str[index]);
            getPermutationHelp(permutations, str, temp, index+1, k);
            temp.pop_back();
            if(k == 0)
                return;
        }
    }
    string getPermutation(int n, int k){
        int k_orig = k;
        string str = "";
        for(int i = 0; i < n; i++)
            str += to_string(i+1);
        vector<string> permutations;
        getPermutationHelp(permutations, str, "", 0, k);
        return permutations[k_orig-1];
    }
};
