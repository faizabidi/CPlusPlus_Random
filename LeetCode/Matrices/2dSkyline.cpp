// https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/

class Solution {
public:
    pair<int, int> maxValues(vector<vector<int>> grid, int row, int col){
        int maxRow = INT_MIN, maxCol = INT_MIN;
        // Find max row and col
        for(int i = 0; i < grid.size(); i++){
            if(grid[i][col] > maxRow)
                maxRow = grid[i][col];
            if(grid[row][i] > maxCol)
                maxCol = grid[row][i];
        }
        return make_pair(maxRow, maxCol);
    }
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                int currentHeight = grid[i][j];
                // Find max row and col value
                pair<int, int> max = maxValues(grid, i, j);
                // We can increase the height by the min of the pair
                int heightIncrease = min(max.first, max.second);
                ans += heightIncrease - grid[i][j];
            }
        }
        return ans;
    }
};