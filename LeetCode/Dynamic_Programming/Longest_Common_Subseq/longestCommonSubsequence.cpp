// https://www.geeksforgeeks.org/longest-common-subsequence/

#include <iostream>
#include <vector>

template <class T>
void printVector(std::vector<T> array){
    for(int i = 0; i < array.size(); i++)
        std::cout << array[i];
    std::cout << std::endl;
}

template<typename T>
void print_matrix(std::vector<std::vector<T>> matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}
/***************************************************************************/
// Recusrion - find all subseqeneces and compare
// O(2^n) + O(nxm)
// https://www.youtube.com/watch?v=KCEPvdLqlYI
void allSubsequences_helper(std::string str, std::string temp, 
                            int index, std::vector<std::string> &ans){
    // Base case
    if(index == str.size()){
        ans.push_back(temp);
        return;
    }

    // Inlcude
    allSubsequences_helper(str, temp + str[index], index + 1, ans);

    // Exclude
    allSubsequences_helper(str, temp, index + 1, ans);
}
int lcs(std::string str1, std::string str2){
    std::string temp;
    std::vector<std::string> str1_subs, str2_subs;

    allSubsequences_helper(str1, temp, 0, str1_subs);
    allSubsequences_helper(str2, temp, 0, str2_subs);

    // Now compare the two vectors and look for the longest common subsequence
    std::string ans;
    for(int i = 0; i < str1_subs.size(); i++){
        if( std::find(str2_subs.begin(), str2_subs.end(), str1_subs[i]) != str2_subs.end()){
            
            if(str1_subs[i].size() > ans.size())
                ans = str1_subs[i];
        }
    }
    std::cout << ans << std::endl;
    // Just return the length of the longest common subsequence
    return ans.size();
}
/***************************************************************************/
// Recursive LCS solution
// O(2^n)
int lcs_recursive(std::string str1, std::string str2,                                          int index1, int index2){
    
    // Base case
    if(index1 == str1.size() || index2 == str2.size())
        return 0;

    if(str1[index1] == str2[index2])
        return 1 + lcs_recursive(str1, str2, index1 + 1, index2 + 1);
    else
        return std::max(lcs_recursive(str1, str2, index1 + 1, index2), 
                            lcs_recursive(str1, str2, index1, index2 + 1));

}
/***************************************************************************/
// DP solution - bottoms-up approach
// O(nxm)
// https://www.youtube.com/watch?v=cfCdtJSu5pc
// DP solution
void lcs_dp(std::string str1, std::string str2){
    int rows = str1.size() + 1;
    int cols = str2.size() + 1;
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
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
    print_matrix(matrix);
    std::cout << "Length of LCS is " 
                << matrix[rows - 1][cols - 1] << std::endl;
}
/***************************************************************************/
int main(){
    std::string str1 = "AGGTAB";
    std::string str2 = "GXTXAYB";
    
    std::cout << lcs(str1, str2) << std::endl;
    //std::cout << lcs_recursive(str1, str2, 0, 0) << std::endl;
    lcs_dp(str1, str2);

    return 0;
}
