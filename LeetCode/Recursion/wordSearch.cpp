// https://leetcode.com/problems/word-search/


// Time: For each letter, there are 4 possible directions. Assuming there are n letters in the matrix and word to be searched is of length m, time complexity might be O(n * 4^m)
class Solution {
public:
    bool dfs(vector<vector<char>> &board, string word, int index, int row, int col){
        // Check if ans found
        if(index == word.size())
            return true;
        // Check if out of bounds
        if(row < 0 || col < 0 || row == board.size() || col == board[row].size() || board[row][col] != word[index])
            return false;
        // Mark it as visited
        char ch = board[row][col];
        board[row][col] = '!';
        // Go up, down, right, left
        bool ret = dfs(board, word, index+1, row-1, col) || 
            dfs(board, word, index+1, row+1, col) || 
            dfs(board, word, index+1, row, col+1) ||
            dfs(board, word, index+1, row, col-1);
        if(ret)
            return true;
        // Backtrack
        board[row][col] = ch;
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(dfs(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};
