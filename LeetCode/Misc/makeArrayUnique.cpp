// https://leetcode.com/contest/weekly-contest-112/problems/minimum-increment-to-make-array-unique/

class Solution {
public:
    void print(vector<int> array){
        for(auto value : array)
            cout << value << " ";
        cout << endl;
    }
    // O(nlogn) time and O(1) space
    int minIncrementForUnique(vector<int>& A){
        if(A.size() < 2)
            return 0;
        sort(A.begin(), A.end());
        int count = 0;
        for(int i = 1; i < A.size(); i++){
            //print(A);
            if(A[i] <= A[i-1]){
                count += A[i-1] + 1 - A[i];
                A[i] = A[i-1] + 1;
            }
        }
        return count;
    }
};