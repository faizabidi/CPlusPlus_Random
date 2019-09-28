// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/


// Using binary search
class Solution {
public:
    void kthSmallestHelper(vector<vector<int>> matrix, int &count, int &more_than_mid, int                                                                                  &less_than_mid, int mid){
        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] <= mid)
                    count++;
                // Just more than mid's value
                if(matrix[i][j] > mid)
                    more_than_mid = min(more_than_mid, matrix[i][j]);
                // Just less than equal to mid's value
                if(matrix[i][j] <= mid)
                    less_than_mid = max(less_than_mid, matrix[i][j]);
            }
        }
    }
    int kthSmallest(vector<vector<int>>& matrix, int k){
        if(matrix.size() < 1)
            return 0;
        int low = matrix[0][0];
        int high = matrix[matrix.size()-1][matrix[0].size()-1];
        while(low < high){
            int mid = (low + high)/2;
            // Count number of elements less than mid's value
            // Also keep track of the number just more than the mid's value
            // and the largest number just less than the mid's value
            int count = 0, more_than_mid = INT_MAX, less_than_mid = INT_MIN;
            kthSmallestHelper(matrix, count, more_than_mid, less_than_mid, mid);
            if(count == k)
                return less_than_mid;
            else if(count < k)
                low = more_than_mid;
            else
                high = less_than_mid;
        }
        return low;
    }
};

// Using heap
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k){
        // Maintain a max. heap
        priority_queue<int> pq;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                pq.push(matrix[i][j]);
                if(pq.size() > k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};
