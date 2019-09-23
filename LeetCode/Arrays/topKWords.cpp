// https://leetcode.com/problems/top-k-frequent-words/

// Time complexity: O(n) for hashmap build-up + O(n) for pq build-up + O(k) for parsing the pq + O(n) for reversing
// Space complexity: O(n) for hashmap, O(k) for priority queue
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> orig_hashmap;
        for(int i = 0; i < words.size(); i++)
            orig_hashmap[words[i]]++;
        
        // Build min heap - smallest at top
        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
        for(auto it = orig_hashmap.begin(); it != orig_hashmap.end(); it++){
            //cout << "CurrWord = " << it->first << endl;
            pair<string, int> currVal = make_pair(it->first, it->second);
            pq.push(currVal);
            //cout << "pq.top() = " << pq.top().first << endl;
            if(pq.size() > k){
                pq.pop();
                //cout << "Popping\n";
            }
        }
        
        vector<string> ans;
        while(k > 0){
            ans.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    struct Compare{
        bool operator()(pair<string, int> p1, pair<string, int> p2){
            if(p1.second != p2.second)
                return p1.second > p2.second;
            return p1.first < p2.first;
        }
    };    
};
