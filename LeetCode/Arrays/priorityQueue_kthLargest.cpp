// https://leetcode.com/problems/kth-largest-element-in-a-stream/


// Time complexity: O(n) to build the min priority queue
// Space complexity: O(k+1) for the priority queue
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        key = k;
        // Maintain the size of the pq to be max. of k
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size() > key)
                pq.pop(); // Pop the smallest element out of the pq, which would be on the top
        }
    }
    
    int add(int val){
        pq.push(val);
        if(pq.size() > key)
            pq.pop();
        return pq.top();
    }
private:
    vector<int> array;
    int key;
    priority_queue<int, vector<int>, greater<int>> pq; // Store in ascending order from top to bottom
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
