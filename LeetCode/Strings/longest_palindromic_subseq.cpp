// https://leetcode.com/problems/longest-palindromic-subsequence/description/
// https://www.youtube.com/watch?v=U4yPae3GEO0

#include <iostream>
#include <vector>

void printMatrix(std::vector<std::vector<int>> matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int longestPalindromeSubseq(std::string str){
    if(str.size() < 2)
        return str.size();

    std::vector<std::vector<int>> matrix(str.size(), 
                            std::vector<int>(str.size(), 0));

    // Length of 1
    for(int i = 0; i < str.size(); i++)
        matrix[i][i] = 1;

    // Length of 2
    for(int i = 1; i < str.size(); i++){
        if(str[i-1] == str[i])
            matrix[i-1][i] = 2;
        else
            matrix[i-1][i] = 1;
    }

    // Length > 2
    for(int len = 3; len <= str.size(); len++){
        for(int i = 0; i < str.size() - len + 1; i++){
            int j = len + i - 1;
            if(str[i] == str[j])
                matrix[i][j] = 2 + matrix[i+1][j-1];
            else
                matrix[i][j] = std::max(matrix[i+1][j], matrix[i][j-1]);
        }
    }

    return matrix[0][str.size() - 1];
}

int main(){
    //std::string str = "abcda"; // Ans = 3
    //std::string str = "abba"; // Ans = 4
    std::string str = "abcdeaba"; // Ans = 4
    std::cout << longestPalindromeSubseq(str) << std::endl;

    return 0;
}
