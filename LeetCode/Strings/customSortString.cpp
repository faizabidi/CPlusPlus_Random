// https://leetcode.com/problems/custom-sort-string/description/

class Solution {
public:
    // O(n) time and O(n) space
    string subtract(string T, string S){
        string difference;
        map<char, int> T_hashmap, S_hashmap;
        // Add T and S to hashmaps
        for(int i = 0; i < T.size(); i++)
            T_hashmap[T[i]]++;
        for(int i = 0; i < S.size(); i++)
            S_hashmap[S[i]]++;
        // Compare the two to find the diff
        for(auto it = T_hashmap.begin(); it != T_hashmap.end(); it++){
            char key = it->first;
            // Search for this in S
            auto search = S_hashmap.find(key);
            // If not found, add to difference
            if(search == S_hashmap.end()){
                int value = it->second;
                while(value > 0){
                    difference += it->first;
                    value--;
                }
            }
        }
        return difference;
    }
    // O(n) time and O(n) space
    string customSortString(string S, string T) {
        string sortedT;
        map<char, int> hashmap;
        // Add all characters of T into a hashmap
        for(int i = 0; i < T.size(); i++)
            hashmap[T[i]]++;
        // Iterate through S and compare with the hashmap
        for(int i = 0; i < S.size(); i++){
            auto it = hashmap.find(S[i]);
            if(it != hashmap.end()){
                // Add that character in T
                int value = hashmap[S[i]];
                while(value > 0){
                    sortedT += S[i];
                    value--;
                }
            }
        }
        // S and T can also be different
        sortedT += subtract(T, S);
        return sortedT;
    }
};
