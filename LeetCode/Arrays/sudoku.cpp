#include <iostream>
#include <vector>

using namespace std;

// Check if a number can be inserted at a position
bool check(vector<vector<int>> matrix, int num, int i, int j){
    // Check that row
    for(int row = 0; row < 9; row++){
        if(matrix[row][j] == num)
            return false;
    }
    // Check column
    for(int col = 0; col < 9; col++){
        if(matrix[i][col] == num)
            return false;
    }
    // Check in the 3x3 sub-matrix
    int row, col;
    if(i < 3)
        i = 0;
    else if(i < 6)
        i = 3;
    else
        i = 6;
    if(j < 3)
        j = 0;
    else if(j < 6)
        j = 3;
    else
        j = 6;
    for(int row = i; row < i+3; row++){
        for(int col = j; col < j+3; col++){
            if(matrix[row][col] == num)
                return false;
        }
    }
    // Else return true that this is a possible number to be inserted here
    return true;
}

// Check if all values in the matrix are non-zero
bool checkMatrixFilled(vector<vector<int>> matrix, int &row, int &col){
    for(row = 0; row < 9; row++){
        for(col = 0; col < 9; col++){
            if(matrix[row][col] == 0)
                return false;
        }
    }
    return true;
}

// Solve using backtracking
bool solveSudoku(vector<vector<int>> &matrix){
    int row, col;
    // Success is when the entire matrix is filled
    if(checkMatrixFilled(matrix, row, col))
        return true;
    // Insert a possible number between 1 to 9
    for(int k = 1; k <= 9; k++){
        if(check(matrix, k, row, col)){
            matrix[row][col] = k;
            // Check if a valid sudoku is formed
            if(solveSudoku(matrix))
                return true;
            // Otherwise, make it zero again and check for the next number 
            // in the for loop
            matrix[row][col] = 0;
        }
    }
    // When no suitable number can be inserted, function returns false
    return false;
}

// Print the matrix
void print(vector<vector<int>> matrix){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main(){
    // 0 means empty cell
    vector<vector<int>> matrix1 = {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };
    vector<vector<int>> matrix = {
        {0,0,0,0,0,0,2,0,0},
        {0,8,0,0,0,7,0,9,0},
        {6,0,2,0,0,0,5,0,0},
        {0,7,0,0,6,0,0,0,0},
        {0,0,0,9,0,1,0,0,0},
        {0,0,0,0,2,0,0,4,0},
        {0,0,5,0,0,0,6,0,3},
        {0,9,0,4,0,0,0,7,0},
        {0,0,6,0,0,0,0,0,0}
    };
    cout << "Original matrix\n";
    print(matrix);
    cout << "\nSolving the sudoku....\n";
    if(solveSudoku(matrix))
        print(matrix);
    else
        cout << "Invalid sudoku\n";

    return 0;
}
