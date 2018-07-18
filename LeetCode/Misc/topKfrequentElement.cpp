// https://leetcode.com/problems/top-k-frequent-elements/description/

class Solution {
public:
    // Sort in desc order based on second element
    static bool sortDesc(pair<int, int> a, pair<int, int> b){
        //if(a.second > b.second)
        //    return true;
        //return false;
        return (a.second > b.second);
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int, int> hashmap;
        vector<pair<int, int>> sequenceOrder;
        // Add to hashmap and a vector
        for(int i = 0; i < nums.size(); i++)
            hashmap[nums[i]]++;
        // Return the top k keys from the hashmap
        // Add to vector of pairs
        for(auto it = hashmap.begin(); it != hashmap.end(); it++){
            pair<int, int> pair = {it->first, it->second};
            sequenceOrder.push_back(pair);
        }
        // Sort the vector based on second element
        sort(sequenceOrder.begin(), sequenceOrder.end(), sortDesc);
        // Print the k elements
        for(int i = 0; i < k && i < sequenceOrder.size(); i++)
            ans.push_back(sequenceOrder[i].first);
        return ans;
    }
};