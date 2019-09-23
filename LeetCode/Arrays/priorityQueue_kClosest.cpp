// https://leetcode.com/problems/k-closest-points-to-origin/

// Using priority queues (min heap)
// Time complexity - nlogn
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K){
        // Insert based on distance from origin
        priority_queue<vector<int>, vector<vector<int>>, CustomCompare> pq;
        
        for(int i = 0; i < points.size(); i++){
            pq.push(points[i]);
            if(pq.size() > K)
                pq.pop();
        }
        vector<vector<int>> ans;
        int i = 0;
        while(i < K){
            ans.push_back(pq.top());
            pq.pop();
            i++;
        }
        return ans;
    }
private:
	// Overload the operator
    struct CustomCompare{
        bool operator()(vector<int> p1, vector<int> p2){
            return (p1[0]*p1[0]+p1[1]*p1[1]) < (p2[0]*p2[0]+p2[1]*p2[1]);
        }
    };
};

// Using vectors, sort in ascending order from left to right
// Time complexity - nlogn
class Solution {
public:
    static bool compare(vector<int> p1, vector<int> p2){
        return (p1[0]*p1[0]+p1[1]*p1[1]) < (p2[0]*p2[0]+p2[1]*p2[1]);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // Sort this vector based on distance from origin
        sort(points.begin(), points.end(), compare);
        vector<vector<int>> ans(points.begin(), points.begin()+K);
        return ans;
    }
};
