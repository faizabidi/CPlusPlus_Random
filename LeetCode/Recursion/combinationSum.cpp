// https://leetcode.com/problems/combination-sum/

class Solution{
public:
    void combinationSumHeper(set<vector<int>> &checkSet, vector<int> array, vector<int> temp, int target){
        if(target == 0){
            // Check if this combination already found
            sort(temp.begin(), temp.end());
            checkSet.insert(temp);
            return;
        }
        if(target < 0)
            return;
        for(int i = 0; i < array.size(); i++){
            temp.push_back(array[i]);
            combinationSumHeper(checkSet, array, temp,target-array[i]);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        set<vector<int>> checkSet;
        combinationSumHeper(checkSet, candidates, {}, target);
        for(auto it = checkSet.begin(); it != checkSet.end(); it++)
            ans.push_back(*it);
        return ans;
    }
};