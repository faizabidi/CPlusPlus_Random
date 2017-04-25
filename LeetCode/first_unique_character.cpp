// https://leetcode.com/problems/first-unique-character-in-a-string/#/description

class Solution {
public:
    int firstUniqChar(string s){
        std::unordered_map<char, int> hashmap;
        std::vector<char> array;
        
        // Store it in a hashmap
        for(int i = 0; i < s.size(); i++)
            hashmap[s[i]]++;
                
        for(int i = 0; i < s.size(); i++){
            if(hashmap[s[i]] == 1)
                return i;
        }
        return -1;
    }
};