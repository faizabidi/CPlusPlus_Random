// https://leetcode.com/contest/weekly-contest-61/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures){
        std::vector<int> ans;
        for(int i = 0; i < temperatures.size(); i++){
            int count = i;
            for(int j = i; j < temperatures.size(); j++){
                if(temperatures[j] > temperatures[i]){
                    count = j;
                    break;
                }
            }
            ans.push_back(count - i);
        }
        return ans;
    }
};

