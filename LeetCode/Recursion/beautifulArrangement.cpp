// https://leetcode.com/problems/beautiful-arrangement/description/

class Solution {
public:
    // Find all valid permutations
    // O(k) time where k = number of valid permutations. O(n) space because of recursion tree
    void permute(vector<int> array, int index, int &count){
        if(index == array.size()){
            count++;
            return;
        }
        for(int i = index; i < array.size(); i++){
            swap(array[i], array[index]);
            if(array[index] % (index+1) == 0 || (index+1) % array[index] == 0)
                permute(array, index+1, count);
        }
    }
    int countArrangement(int N){
        int count = 0;
        vector<int> array(N);
        for(int i = 0; i < N; i++)
            array[i] = i+1;
        permute(array, {}, count);
        return count;
    }
};
