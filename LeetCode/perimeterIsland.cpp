#include <iostream>
#include <vector>

class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>> grid){
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    // Check left
                    if(j - 1 >= 0 && grid[i][j - 1] == 0)
                        count++;
                    // Check right
                    if(j + 1 < grid[i].size() && grid[i][j + 1] == 0)
                        count++;
                    // Check top
                    if(i - 1 >= 0 && grid[i - 1][j] == 0)
                        count++;
                    // Check bottom
                    if(i + 1 < grid.size() && grid[i + 1][j] == 0)
                        count++;
                    // If 0th column
                    if(j == 0)
                        count++;
                    // If last column
                    if(j == grid[i].size() - 1)
                        count++;
                    // If 0th row
                    if(i == 0)
                        count++;
                    // If bottom row
                    if(i == grid.size() - 1)
                        count++;
                }
            }
        }
        return count;
    }

    // Better version
    int islandPerimeter2(std::vector<std::vector<int>> grid){
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    if(i - 1 < 0 || grid[i - 1][j] == 0)
                        count++;
                    if(i + 1 == grid.size() || grid[i + 1][j] == 0)
                        count++;
                    if(j - 1 < 0 || grid[i][j - 1] == 0)
                        count++;
                    if(j + 1 == grid.size() || grid[i][j + 1] == 0)
                        count++;
                }
            }
        }
        return count;
    }
};

int main(){
    Solution obj1;

    std::vector<std::vector<int>> grid = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}};

    std::cout << obj1.islandPerimeter2(grid);

    return 0;
}