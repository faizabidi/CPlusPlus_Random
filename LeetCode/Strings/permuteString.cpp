#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void reconstructArray(vector<int> &array, int index){
        vector<int> temp;
        temp.push_back(array[index]);
        for(int i = 0; i < array.size(); i++){
            if(i != index)
                temp.push_back(array[i]);
        }
        array = temp;
    }
    void permute(vector<vector<int>> &ans, vector<int> nums, vector<int> temp,int index){

        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = index; i < nums.size(); i++){
             // Insert into temp
            temp.push_back(nums[i]);
            // Store nums temporarily
            vector<int> tempNum = nums;
            reconstructArray(nums, i);
            permute(ans, nums, temp, index+1);
            // Return nums to its original setting
            nums = tempNum;
            // Reset temp for backtracking
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int> nums){
        vector<vector<int>> ans;
        permute(ans, nums, {}, 0);
        return ans;
        
    }
    template<class T>
    void print(vector<vector<T>> array){
        for(int i = 0; i < array.size(); i++){
            for(int j = 0; j < array[i].size(); j++)
                cout << array[i][j] << " ";
            cout << endl;
        }
    }
    void print2(vector<int> array){
        for(auto value : array)
            cout << value << " ";
        cout << endl;
    }
};

int main(){
    Solution obj1;
    vector<int> array = {1,2,3};
    vector<vector<int>> ans = obj1.permute(array);
    obj1.print(ans);

    return 0;
}
