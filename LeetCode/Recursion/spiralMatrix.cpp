// https://leetcode.com/problems/spiral-matrix/
// Time: O(nxm) where n o rows and m = column

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool checkIfAllVisited(vector<vector<int>> visited){
        for(int i = 0; i < visited.size(); i++){
            for(int j = 0; j < visited[i].size(); j++){
                if(visited[i][j] != INT_MAX)
                    return false;
            }
        }
        return true;
    }
    void helper(vector<vector<int>> &matrix, vector<int> &ans, int row, int col, string directtion){
        // Base condition when all elements get visited
        if(checkIfAllVisited(matrix))
            return;
        // Make sure that we don't run out of bounds
        if(row < 0 || col < 0 || row == matrix.size() || col == matrix[row].size())
            return;

        if(directtion == "right"){
            // Go right till you hit the end or hit a visited element
            while(col < matrix[row].size() && matrix[row][col] != INT_MAX){
                ans.push_back(matrix[row][col]);
                matrix[row][col] = INT_MAX;
                col++;
            }
            helper(matrix, ans, row+1, col-1, "down");
        }
        else if(directtion == "down"){
            // Go down till you hit the end or hit a visited element
            while(row < matrix.size() && matrix[row][col] != INT_MAX){
                ans.push_back(matrix[row][col]);
                matrix[row][col] = INT_MAX;
                row++;
            }
            helper(matrix, ans, row-1, col-1, "left");
        }
        else if(directtion == "left"){
            // Go left till you hit the end or hit a visited element
            while(col >= 0 && matrix[row][col] != INT_MAX){
                ans.push_back(matrix[row][col]);
                matrix[row][col] = INT_MAX;
                col--;
            }
            helper(matrix, ans, row-1, col+1, "up");
        }
        else if(directtion == "up"){
            while(row >= 0 && matrix[row][col] != INT_MAX){
                ans.push_back(matrix[row][col]);
                matrix[row][col] = INT_MAX;
                row--;
            }
            helper(matrix, ans, row+1, col+1, "right");
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        vector<int> ans;
        helper(matrix, ans, 0, 0, "right");
        return ans;
    }
};

int main(){
    vector<vector<int>> matrix1 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<vector<int>> matrix2 = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
        {17,18,19,20}
    };

    Solution obj1;
    vector<int> ans = obj1.spiralOrder(matrix2);
    obj1.print(ans);

    return 0;
}