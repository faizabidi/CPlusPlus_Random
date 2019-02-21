// https://leetcode.com/problems/groups-of-special-equivalent-strings/

class Solution {
public:
    bool check(string str1, string str2){
        if(str1.size() != str2.size())
            return false;
        string str1_even, str1_odd, str2_even, str2_odd;
        for(int i = 0; i < str1.size(); i++){
            if(i%2 == 0){
                str1_even += str1[i];
                str2_even += str2[i];
            }
            else{
                str1_odd += str1[i];
                str2_odd += str2[i];
            }
        }
        sort(str1_even.begin(), str1_even.end());
        sort(str1_odd.begin(), str1_odd.end());
        sort(str2_even.begin(), str2_even.end());
        sort(str2_odd.begin(), str2_odd.end());
        if(str1_even != str2_even)
            return false;
        if(str1_odd != str2_odd)
            return false;
        return true;
    }
    int numSpecialEquivGroups(vector<string>& A){
        vector<vector<string>> groups;
        vector<bool> visited(A.size(), false);
        for(int i = 0; i < A.size(); i++){
            vector<string> array;
            if(!visited[i]){
                visited[i] = true;
                array.push_back(A[i]);
                for(int j = i+1; j < A.size(); j++){
                    if(!visited[j]){
                        if(check(A[i], A[j])){
                            visited[j] = true;
                            array.push_back(A[j]);
                        }
                    }
                }
            }
            if(array.size() > 0)
                groups.push_back(array);
        }
        return groups.size();
    }
};