#include <vector>
#include <iostream>

//////////////////////////////////////////////////////////////////////////////
// Brute force - find all sub-sequences
// Recursion seems like a possible solution
// https://leetcode.com/problems/longest-increasing-subsequence/solution/
// O(2^n) & O(nxn)
int longest_increasing_subseq_helper(std::vector<int> array, int prev_val, int current){

	// Base case when you reach the end of the vector
    if(current == array.size())
        return 0;

    int include = 0;
    if(array[current] > prev_val)
    	include = 1 + longest_increasing_subseq_helper(array, 
                                                array[current], current + 1);

    int exclude = longest_increasing_subseq_helper(array, 
                                                prev_val, current + 1);

    return std::max(include, exclude);
}

int longest_increasing_subseq1(std::vector<int> array){
    return longest_increasing_subseq_helper(array, INT_MIN, 0);
}
//////////////////////////////////////////////////////////////////////////////
// DP solution using tabulation
// https://www.youtube.com/watch?v=CE2b_-XfVDk
// O(nxn) && O(n)
int longest_increasing_subseq2(std::vector<int> array){
    std::vector<int> lis;
    std::vector<int> ans;
    if(array.size() == 0)
    	return 0;
    // Initialize the vector to 1 since the LIS at least would be 1 for each element
    for(int i = 0; i < array.size(); i++)
    	ans.push_back(1);

    // Build the vector
    for(int i = 1; i < array.size(); i++){
        std::vector<int> temp_lis;
    	for(int j = 0; j < i; j++){
    		if(array[i] > array[j] && ans[i] < ans[j] + 1){
    			ans[i] = ans[j] + 1;
                temp_lis.push_back(array[j]);
            }
    	}
        if(temp_lis.size() > lis.size())
            lis = temp_lis;
    }
    return *std::max_element(ans.begin(), ans.end());
}
//////////////////////////////////////////////////////////////////////////////

int main(){
    //std::vector<int> array = {50, 3, 10, 7, 40, 80};
    //std::vector<int> array = {3, 10, 2, 1, 20};
    //std::vector<int> array = {3, 2};
    //std::vector<int> array = {10,9,2,5,3,4};
    std::vector<int> array = {10, 22, 9, 33, 21, 50, 41, 60};
    std::cout << longest_increasing_subseq1(array) << std::endl;
    std::cout << longest_increasing_subseq2(array) << std::endl;

    return 0;
}
