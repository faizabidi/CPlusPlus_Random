// https://leetcode.com/problems/merge-intervals/

// Time: O(nlogn)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals){
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < intervals.size(); i++){
            // Check if this interval overalps with anything in ans
            // If it does, merge them
            checkOverlapAndMerge(ans, intervals[i]);
        }
        return ans;
    }
private:
    // Merge two overlapping arrays
    vector<int> merge(vector<int> array1, vector<int> array2){
        vector<int> ans(2);
        int minVal = min(array1[0], array2[0]);
        int maxVal = max(array1[1], array2[1]);
        ans[0] = minVal, ans[1] = maxVal;
        return ans;
    }
    // Check if two arrays overlap
    bool overalp(vector<int> array1, vector<int> array2){
        // Since both arrays are sorted, array2 >= array1
        // Two arrays don't overlap only in one condition
        if(array2[0] > array1[1])
            return false;
        return true;
    }
    // Helper function to check overlap and merge
    void checkOverlapAndMerge(vector<vector<int>> &matrix, vector<int> array){
        // If empty, just add it
        if(matrix.size() == 0){
            matrix.push_back(array);
            return;
        }
        // Else, search if anything in the matrix will overlap with array
        for(int i = 0; i < matrix.size(); i++){
            if(overalp(matrix[i], array)){
                matrix[i] = merge(array, matrix[i]);
                return;
            }
        }
        // If no overlaps found, just add it
        matrix.push_back(array);
        return;
    }
};
