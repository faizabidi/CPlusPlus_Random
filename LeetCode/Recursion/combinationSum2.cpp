// https://leetcode.com/problems/combination-sum-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> combinationSum2(vector<int> candidates, int target){
        vector<vector<int>> ans;
        combinationSum2Helper(ans, candidates, {}, 0, target);
        return ans;
    }
private:
	void combinationSum2Helper(vector<vector<int>> &ans, vector<int> array, vector<int> temp, int index, int target){

		// Base conditions
		if(target == 0){
			sort(temp.begin(), temp.end());
			auto it = find(ans.begin(), ans.end(), temp);
			if(it == ans.end())
				ans.push_back(temp);
			return;
		}

		if(index == array.size() || target < 0)
			return;

		for(int i = index; i < array.size(); i++){
			// Include the number and recurse
			temp.push_back(array[i]);
			combinationSum2Helper(ans, array, temp, i+1, target-array[i]);
			temp.pop_back();
		}
	}
};

int main(){
	Solution obj1;

	vector<int> array = {10,1,2,7,6,1,5};
	int target = 8;
	//vector<int> array = {1,1,2};
	//int target = 4;

	vector<vector<int>> ans = obj1.combinationSum2(array, target);

	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}

	return 0;
}