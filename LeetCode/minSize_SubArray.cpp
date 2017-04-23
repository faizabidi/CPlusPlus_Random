// https://leetcode.com/problems/minimum-size-subarray-sum/#/description

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& array){
        int ans = INT_MAX;
        bool flag = false;
        for(int i = 0; i < array.size(); i++){
            int sum = 0, count = 0;
            for(int j = i; j < array.size(); j++){
                sum += array[j];
                count++;
                if(sum >= s){
                    flag = true;
                    if(count < ans)
                        ans = count;
                    break;
                }
            }
        }
        if(!flag)
            return 0;
        return ans;
    }
};