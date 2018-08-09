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
int longest_increasing_subseq2(std::vector<int> nums){
    if(nums.size() == 0)
        return 0;
    std::vector<int> LIC(nums.size(), 1);
    int max = 1;
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                LIC[i] = std::max(LIC[i], LIC[j] + 1);
                if(LIC[i] > max)
                    max = LIC[i];
            }
        }
    }
    return max;
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
