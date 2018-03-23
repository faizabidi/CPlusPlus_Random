// https://www.geeksforgeeks.org/printing-longest-common-subsequence/

#include <iostream>
#include <vector>
#include <algorithm>

void printVector(std::vector<std::vector<int>> matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}

void build_lcs_table(std::string str1, std::string str2, std::vector<std::vector<int>> &matrix){
    int rows = str1.size() + 1;
    int cols = str2.size() + 1;
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(i == 0 || j == 0)
                matrix[i][j] = 0;
            else if(str1[i - 1] == str2[j - 1])
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            else if(str1[i - 1] != str2[j - 1])
                matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
        }
    }
}

std::string lcs(std::string str1, std::string str2){
    std::vector<std::vector<int>> matrix(str1.size() + 1, 
                                        std::vector<int>(str2.size() + 1));
    build_lcs_table(str1, str2, matrix);
    printVector(matrix);

    int rows = str1.size() + 1;
    int cols = str2.size() + 1;

    std::string lcs_str;
    int i = rows - 1, j = cols - 1;
    while(i > 0 && j > 0){
        if(str1[i - 1] == str2[j - 1]){
            lcs_str += str2[j - 1];
            i--;
            j--;
        }
        else{
            if(matrix[i - 1][j] > matrix[i][j - 1])
                i--;
            else
                j--;
        }
    }
    std::reverse(lcs_str.begin(), lcs_str.end());
    return lcs_str;
    
}

int main(){
    std::string str1 = "AGGTAB", str2 = "GXTXAYB";
    //std::string str1 = "MZJAWXU", str2 = "XMJYAUZ";

    std::cout << lcs(str1, str2) << std::endl;

    return 0;
}
