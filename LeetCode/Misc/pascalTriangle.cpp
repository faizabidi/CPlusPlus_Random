// https://leetcode.com/problems/pascals-triangle/description/

class Solution {
public:
    vector<vector<int>> generate(int numRows){
        vector<vector<int>> pascalsTriangle;
        if(numRows == 0)
            return pascalsTriangle;
        // Edge case 1
        pascalsTriangle.push_back({1});
        if(numRows == 1)
            return pascalsTriangle;
        // Edge case 2
        pascalsTriangle.push_back({1,1});
            if(numRows == 2)
            return pascalsTriangle;
        for(int i = 2; i < numRows; i++){
            vector<int> prevRow = pascalsTriangle[i - 1];
            // Insert a one at the beginnning
            vector<int> currRow = {1};
            // Iterate through the previous row
            for(int j = 1; j < prevRow.size(); j++){
                int num = prevRow[j] + prevRow[j-1];
                // Add it to current row
                currRow.push_back(num);
            }
            // Insert one at the end as well
            currRow.push_back(1);
            // Add it to the pascalsTriangle
            pascalsTriangle.push_back(currRow);
        }
        return pascalsTriangle;
    }
};