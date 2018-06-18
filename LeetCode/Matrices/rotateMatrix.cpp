#include <iostream>
#include <vector>

void print(std::vector<std::vector<int>> matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void transpose(std::vector<std::vector<int>> &matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = i; j < matrix.size(); j++)
            std::swap(matrix[i][j], matrix[j][i]);
    }
}

void flip(std::vector<std::vector<int>> &matrix){
    for(int i = 0; i < matrix.size(); i++){
        std::vector<int> currentRow = matrix[i];
        int j = 0, k = currentRow.size() - 1;
        while(j < k){
            std::swap(currentRow[j], currentRow[k]);
            j++, k--;
        }
        matrix[i] = currentRow;
    }
}

void rotate(std::vector<std::vector<int>> &matrix){
    // Find the transpose
    transpose(matrix);
    // Flip it
    flip(matrix);
}

int main(){
    std::vector<std::vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    print(matrix);
    // Rotate 90 degree clockwise
    rotate(matrix);
    print(matrix);

    return 0;
}