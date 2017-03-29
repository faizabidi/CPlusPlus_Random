// https://leetcode.com/problems/find-all-duplicates-in-an-array/#/description

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums){
        std::map<int, int> hashmap;
        for(int i = 0; i < nums.size(); i++){
            // If not in hashmap, add it
            if(hashmap.find(nums[i]) == hashmap.end())
                hashmap[nums[i]] = 1;
            else
                hashmap[nums[i]]++;
        }
        std::vector<int> ans;
        std::map<int, int>::iterator it;
        for(it = hashmap.begin(); it != hashmap.end(); it++){
            if(it->second == 2)
                ans.push_back(it->first);
        }
        return ans;
    }
};