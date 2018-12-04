// https://leetcode.com/problems/global-and-local-inversions/description/

class Solution {
public:
    // O(nxn) time
    /*bool isIdealPermutation(vector<int>& A){
        int global = 0, local = 0;
        for(int i = 0; i < A.size(); i++){
            if(i+1 < A.size() && A[i] > A[i+1])
                local++;
            for(int j = i+1; j < A.size(); j++){
                if(A[i] > A[j])
                    global++;
            }
        }
        if(local == global)
            return true;
        return false;
    }*/
    /*
    REF: 
    1. https://leetcode.com/problems/global-and-local-inversions/discuss/113661/Generalize-to-any-integer-array-(not-necessarily-a-0-greaterN-permutation)
    2. https://leetcode.com/problems/global-and-local-inversions/discuss/113656/My-3-lines-C++-Solution
    // O(n) time and O(1) space
    */
    bool isIdealPermutation(vector<int>& A){
        if(A.size() < 2)
            return true;
        for(int i = 1; i < A.size(); i++){
            if(A[i-1] > A[i]){
                swap(A[i-1], A[i]);
                i++;
            }
        }
        // Check if array is sorted
        int small = A[0];
        for(int i = 1; i < A.size(); i++){
            if(A[i] < small)
                return false;
            small = A[i];
        }
        return true;
    }
};