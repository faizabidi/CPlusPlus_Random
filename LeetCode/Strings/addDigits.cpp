// https://leetcode.com/problems/add-digits/description/
#include <iostream>
using namespace std;

class Solution {
public:
    // O(n)
    int addDigits(int num){
        string str = to_string(num);
        int ans = 0;
        while(str.size() > 1){
            for(int i = 0; i < str.size(); i++)
                ans += str[i] - '0';
            str = to_string(ans);
            ans = 0;
        }
        return stoi(str);
    }
};

// Can also be done in one liner - https://leetcode.com/problems/add-digits/discuss/128841/C++-onliner

int main(){
    Solution obj1;
    int ans = obj1.addDigits(38);
    std::cout << ans << std::endl;

    return 0;
}