// https://leetcode.com/problems/count-and-say
// https://leetcode.com/problems/count-and-say/discuss/15995/Examples-of-nth-sequence

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<string> findAll(){
        vector<string> ans;
        string num = "1";
        ans.push_back(num);
        for(int i = 1; i < 30; i++){
            string currNum = "";
            // Iterate num string
            for(int j = 0; j < num.size(); j++){
                int count = 1;
                int k = j+1;
                while(k < num.size() && num[k] == num[j]){
                    count++;
                    k++;
                }
                currNum += (to_string(count)+(num[j]));
                j = k-1;
            }
            ans.push_back(currNum);
            num = currNum;
        }
        return ans;
    }
    string countAndSay(int n){
        // Build all 30
        vector<string> allNumbers = findAll();
        return allNumbers[n-1];
    }
    template <class T>
    void print(vector<T> array){
        for(auto value : array)
            cout << value << endl << endl;
    }
};

int main(){
    Solution obj1;
    int n;
    cin >> n;
    string num = obj1.countAndSay(n);
    cout << num << endl;

    return 0;
}