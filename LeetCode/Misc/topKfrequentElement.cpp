// https://leetcode.com/problems/top-k-frequent-elements/description/

class Solution {
public:
    // O(nlogn) time and O(n) space
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

    // O(n) time and O(n) space
    vector<int> topKFrequent(vector<int>& nums, int k){
        map<int, int> hashmap;
        int maxSize = 0;
        vector<int> ans;
        for(auto value : nums)
            hashmap[value]++;
        // Bucket sort the hashmap
        vector<vector<int>> sortedArrayFreq(nums.size() + 1);
        for(auto it = hashmap.begin(); it != hashmap.end(); it++)
            sortedArrayFreq[it->second].push_back(it->first);
        // We need to build a vector of size k from this sortedArrayFreq
        for(int i = sortedArrayFreq.size() - 1; i >= 0; i--){
            if(ans.size() == k)
                break;
            vector<int> temp = sortedArrayFreq[i];
            if(temp.size() > 0){
                int j = 0;
                while(ans.size() < k && j < temp.size()){
                    ans.push_back(temp[j]);
                    j++;
                }
            }
        }
        return ans;
    }
};