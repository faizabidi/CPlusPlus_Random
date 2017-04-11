// https://leetcode.com/problems/detect-capital/#/description

#include <iostream>

class Solution {
public:
    bool detectCapitalUse(std::string word){
        // If first letter is capital
        int i = 0;
        int j = i + 1;
        // Check if first letter is a capital
        if(int(word[i]) >= 65 && int(word[i]) < 97){
            // Check if the second letter is also a capital
            if(int(word[j]) >= 65 && int(word[j]) < 97){
                // Now, make sure all are capital
                while(j < word.size()){
                    if(int(word[j]) >= 97 && int(word[j]) <= 122)
                        return false;
                    j++;
                }
            }
            // Else, make sure nothing else is a capital
            else if(int(word[j]) >= 97 && int(word[j]) <= 122){
                while(j < word.size()){
                    if(int(word[j]) >= 65 && int(word[j]) < 97)
                        return false;
                    j++;
                }
            }
        }
        // Else, make sure all are lower case
        else{
            while(j < word.size()){
                if(int(word[j]) >= 65 && int(word[j]) < 97)
                    return false;
                j++;
            }
        }
        return true;
    }
};

int main(){
    std::string str;
    std::cin >> str;
    Solution obj1;
    if(obj1.detectCapitalUse(str))
        std::cout << "All good!\n";
    else
        std::cout << "Bad\n";
    return 0;
}