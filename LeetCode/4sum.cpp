// https://leetcode.com/problems/4sum-ii/#/description

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0;
        // Store all combination sums of AB and CD in a hashmap
        std::map<int, int> AB, CD;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A.size(); j++){
                int sum1 = A[i] + B[j];
                int sum2 = C[i] + D[j];
                AB[sum1]++;
                CD[sum2]++;
            }
        }
        std::map<int, int>::iterator it;
        for(it = AB.begin(); it != AB.end(); it++){
            if(CD.find(-it->first) != CD.end())
                ans += it->second * CD[-it->first];
        }
        return ans;
    }
};