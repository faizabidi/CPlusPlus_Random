// https://leetcode.com/problems/reverse-words-in-a-string-iii/#/description

#include <iostream>

class Solution{
public:
    std::string reverseWords(std::string s){
        std::string temp = s;
        for(int i = 0; i < temp.size(); i++){
            std::cout << "Hello1\n";
            int j = i;
            while(temp[i] != ' ' && i < temp.size())
                i++;
            std::cout << "i = " << i << std::endl;
            //Swap now
            int k = i - 1;
            while(j < k){
                std::swap(temp[k], temp[j]);
                j++;
                k--;
            }
        }
        return temp;
    }
};

int main(){
    Solution obj1;
    std::cout << obj1.reverseWords("Let's take LeetCode contest");
    return 0;
}