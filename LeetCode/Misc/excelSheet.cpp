// https://leetcode.com/problems/excel-sheet-column-number/description/

#include <iostream>
#include <cmath>

class Solution {
public:
    int titleToNumber(std::string s){
        int row = 0, num = 0;
        int size = s.size() - 1;
        for(int i = 0; i < s.size(); i++){
            // Convert to integer
            num = int(s[i]) - 64;
            row += pow(26, size)*num;
            size--;
        }
        return row;
    }
};

int main(){
    Solution obj1;
    std::string str = "ZY";
    std::cout << obj1.titleToNumber(str) << std::endl;
    
    return 0;
}