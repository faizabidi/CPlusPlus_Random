// https://leetcode.com/problems/transpose-matrix/description/

#include <iostream>
#include <vector>

class Solution {
public:
    void printMatrix(std::vector<std::vector<int>> matrix){
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++)
                std::cout << matrix[i][j] << " ";
            std::cout << std::endl;
        }
    }
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>> A){
        // It's possible that the matrix is not a square matrix
        int rows = A.size(), cols = A[0].size();
        std::vector<std::vector<int>> B(cols, std::vector<int>(rows));
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A[i].size(); j++){
                B[j][i] = A[i][j];
            }
        }
        return B;
    }
};

int main(){
    Solution obj1;

    std::vector<std::vector<int>> matrix = {
        {1,2,3},
        {4,5,6}
    };
    obj1.printMatrix(matrix);
    std::vector<std::vector<int>> transpose = obj1.transpose(matrix);
    obj1.printMatrix(transpose);
    
    return 0;
}