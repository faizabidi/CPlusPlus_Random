// https://leetcode.com/problems/longest-palindromic-subsequence/description/
// https://www.youtube.com/watch?v=U4yPae3GEO0
// https://www.youtube.com/watch?v=yZWmS6CXbQc&t=325s
// https://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence/

#include <iostream>
#include <vector>
#include <map>

void printMatrix(std::vector<std::vector<int>> matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
/*********************************************/
// Using recursion, find the length
// O(2^n)
int LPS_recursion(std::string str, int start, int end){
    // Base cases

    // length is 1
    if(start == end)
        return 1;

    // Length is 2 and both characters same and contiguous
    if(str[start] == str[end] && start + 1 == end)
        return 2;

    // If both characters are same and not contiguous
    if(str[start] == str[end])
        return 2 + LPS_recursion(str, start+1, end - 1);

    // If both characters are not same
    // One time include 1 of them and the other time the other
    return std::max(LPS_recursion(str, start+1, end), 
                                LPS_recursion(str, start, end - 1));
}
/*********************************************/
// Using memoization
// O(nxn) time and O(nxn) space + O(n) space for the recursive stack
int LPSeq_memoization_helper(std::string str, int start, int end, 
                                std::map<std::pair<int, int>, int> &hashmap){

    // Check if in hashmap
    std::pair<int, int> key = {start, end};
    if(hashmap[key])
        return hashmap[key];

    if(start > end)
        return 0;
    if(start == end)
        return 1;

    if(str[start] == str[end])
        hashmap[key] =  2 + LPSeq_memoization_helper(str, start+1, 
                                                            end-1, hashmap);
    else{
        int include_start = LPSeq_memoization_helper(str, start, 
                                                            end-1, hashmap);
        int include_end = LPSeq_memoization_helper(str, start+1, 
                                                            end, hashmap);
        hashmap[key] = std::max(include_start, include_end);
    }
    return hashmap[key];
}

int LPSeq_memoization(std::string str){
    int start = 0, end = str.size() - 1;
    std::map<std::pair<int, int>, int> hashmap;
    int len = LPSeq_memoization_helper(str, start, end, hashmap);
    return len;
}
/*********************************************/
// Using tabulation
// O(nxn) time and O(nxn) space
// Print the longest palindromic subseq
std::string print_LPSeq(std::vector<std::vector<int>> matrix, std::string str){
    std::string start = "", end = "", ans = "";

    int i = 0, j = matrix.size() - 1;
    while(i < matrix.size() && j >= 0 && i <= j){
        // If they are equal
        if(str[i] == str[j]){
            if(i != j){
                start += str[j], end += str[j];
                i++, j--;
            }
            else{
                start += str[j];
                i++, j--;
            }
        }
        // If they are not equal, move in the max direction
        else if(matrix[i+1][j] > matrix[i][j-1])
            i++;
        else
            j--;

    }
    ans = start + end;
    return ans;
}

// Calculate the longest palindromic subseq
int longestPalindromeSubseq(std::string str){
    if(str.size() < 2){
        std::cout << str << std::endl;
        return str.size();
    }

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

    std::string ans = print_LPSeq(matrix, str);
    std::cout << ans << std::endl;
    return matrix[0][str.size() - 1];
}
/*********************************************/


int main(){
    std::string str = "abcda"; // Ans = aba, 3
    //std::string str = "abba"; // Ans = abba, 4
    //std::string str = "abcdeaba"; // Ans = abcba, 5
    //std::string str = "abca"; // Ans = aba, 3
    //std::string str = "BBABCBCAB"; // Ans = BABCBAB, 7
    //std::string str = "GEEKSFORGEEKS"; // Ans = EEKEE, 5
    //std::string str = "a";
    std::cout << longestPalindromeSubseq(str) << std::endl;

    std::cout << LPS_recursion(str, 0, str.size() - 1) << std::endl;

    std::cout << LPSeq_memoization(str) << std::endl;

    return 0;
}
