#include <iostream>
#include <vector>

using namespace std;

// O(2^n) time and O(n) space because of recursion

class Solution{
public:
    vector<vector<int>> subsets(vector<int> &nums){
    	vector<vector<int>> powerSet;
    	subsetsHelper(powerSet, nums, {}, 0);
    	return powerSet;
    }

    // Print the power set
    void print(vector<vector<int>> powerSet){
    	for(int i = 0; i < powerSet.size(); i++){
    		for(int j = 0; j < powerSet[i].size(); j++)
    			cout << powerSet[i][j] << " ";
    		cout << endl;
    	}
    }
private:
	void subsetsHelper(vector<vector<int>> &powerSet, vector<int> array, vector<int> temp, int index){

		powerSet.push_back(temp);

		if(index == array.size())
			return;

		for(int i = index; i < array.size(); i++){
			temp.push_back(array[i]);
			subsetsHelper(powerSet, array, temp, i+1);
			temp.pop_back();
		}

	}
};

int main(){
	vector<int> array = {1,2,3};
	Solution obj1;

	vector<vector<int>> powerSet = obj1.subsets(array);
	obj1.print(powerSet);

	return 0;
}
