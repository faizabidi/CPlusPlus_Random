// https://leetcode.com/problems/partition-labels/description/


// O(n) time and O(n) space
class Solution {
public:
    /*
    1. Pick a letter and keep iterating to the point that that letter doesn't 
    exists anymore in the rest of the string.
    2. For every letter in the group found, make sure that all the letters in that 
    group also satisfy #1
    */
    // Helper function to return the index where last occurenece of the character happens
    int findMaxIndex(string str, char ch){
        // Iterate from the end till you find the char
        for(int i = str.size() - 1; i >= 0; i--){
            if(str[i] == ch)
                return i;
        }
        return 0;
    }
    vector<int> partitionLabels(string S) {
        vector<int> partitions;
        for(int i = 0; i < S.size(); i++){
            int index = findMaxIndex(S, S[i]);
            // For this group, check for all the elements
            // Increment index if you have to
            for(int j = i + 1; j < index; j++){
                int newIndex = findMaxIndex(S, S[j]);
                if(newIndex > index)
                    index = newIndex;
            }
            // We found a group!
            partitions.push_back(index+1 - i);
            // Reset value of i
            i = index;
        }
        return partitions;
    }
};